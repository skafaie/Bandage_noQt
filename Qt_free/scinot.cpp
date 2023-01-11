//Copyright 2017 Ryan Wick

//This file is part of Bandage.

//Bandage is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//Bandage is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with Bandage.  If not, see <http://www.gnu.org/licenses/>.


//#include "QStringList"
#include "scinot.h"
#include "math.h"
#include <vector>
#include <string>
#include <sstream>
using namespace std;


SciNot::SciNot() :
    m_coefficient(0.0), m_exponent(0)
{
    normalise();
}

SciNot::SciNot(double coefficient, int exponent) :
    m_coefficient(coefficient), m_exponent(exponent)
{
    normalise();
}

vector<string> tokenize(string s, string del = " ")
{
    vector<string> tokens;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        tokens.push_back(s.substr(start, end - start));
    } while (end != -1);
    return tokens;
}

bool isDouble( string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

bool isInt(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}
SciNot::SciNot(string sciNotString) :
    m_coefficient(0.0), m_exponent(0)
{
   // QStringList parts = sciNotString.split('e');
    vector<string> parts =tokenize (sciNotString, "e");
    if (parts.size() < 1)
        return;
    if (parts.size() < 2)
        m_coefficient = std::stod(parts[0]);
    else
    {
        bool ok = isDouble(parts[0]);
        double coefficient = 0;
        if (!ok)
            return;
        else
            coefficient = std::stod(parts[0]);

        ok = isInt(parts[1]);
        double exponent = 0;
        if (!ok)
            return;
        else
            exponent = std::stoi(parts[1]);

        m_coefficient = coefficient;
        m_exponent = exponent;
    }

    normalise();
}


SciNot::SciNot(double num) :
    m_coefficient(num), m_exponent(0)
{
    normalise();
}


void SciNot::normalise()
{
    if (m_coefficient == 0.0)
    {
        m_exponent = 0;
        return;
    }

    while (fabs(m_coefficient) >= 10.0)
    {
        m_coefficient /= 10.0;
        ++m_exponent;
    }
    while (fabs(m_coefficient) < 1.0)
    {
        m_coefficient *= 10.0;
        --m_exponent;
    }
}


bool SciNot::operator<(SciNot const &other) const
{
    if (isZero())
        return other.isPositive();

    if (isPositive())
    {
        if (other.isNegative() || other.isZero())
            return false;
        else //Both are positive
        {
            if (m_exponent < other.m_exponent) return true;
            if (m_exponent > other.m_exponent) return false;
            return m_coefficient < other.m_coefficient;
        }
    }

    else //It's negative
    {
        if (other.isPositive() || other.isZero())
            return true;
        else //Both are negative
        {
            if (m_exponent > other.m_exponent) return true;
            if (m_exponent < other.m_exponent) return false;
            return m_coefficient < other.m_coefficient;
        }
    }
}

bool SciNot::operator>(SciNot const &other) const
{
    return !(*this < other) && (*this != other);
}
bool SciNot::operator<=(SciNot const &other) const
{
    return (*this < other) || (*this == other);
}
bool SciNot::operator>=(SciNot const &other) const
{
    return (*this > other) || (*this == other);
}
bool SciNot::operator==(SciNot const &other) const
{
    return m_coefficient == other.m_coefficient && m_exponent == other.m_exponent;
}
bool SciNot::operator!=(SciNot const &other) const
{
    return !(*this == other);
}


string SciNot::asString(bool alwaysInSciNot) const
{
    if (!alwaysInSciNot)
    {
        if (isZero())
            return "0";
        if (m_exponent < 3 && m_exponent > -3)
            return to_string(toDouble());
    }

    return to_string(m_coefficient) + "e" + to_string(m_exponent);
}


double SciNot::toDouble() const
{
    return m_coefficient * pow(10.0, m_exponent);
}

bool SciNot::isValidSciNotString(string sciNotString)
{
    /*QStringList parts = sciNotString.split('e');
    bool coefficientOk;
    parts[0].toDouble(&coefficientOk);
    bool exponentOk;
    parts[1].toInt(&exponentOk);*/

    vector<string> parts =tokenize (sciNotString, "e");
    if (parts.size() != 2)
        return false;

    bool coefficientOk = isDouble(parts[0]);
    bool exponentOk = isInt(parts[1]);

    return coefficientOk && exponentOk;
}

void SciNot::power(double p) {
    double newCoefficient = pow(m_coefficient, p);
    double newExponent = m_exponent * p;
    int wholePart = int(newExponent);
    double fractionalPart = newExponent - wholePart;
    m_coefficient = newCoefficient * pow(10.0, fractionalPart);
    m_exponent = wholePart;
    normalise();
}
