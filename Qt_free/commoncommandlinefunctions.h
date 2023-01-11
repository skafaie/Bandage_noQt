//Copyright 2017 Ryan Wick

//This file is part of Bandage

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


#ifndef COMMANDCOMMANDLINEFUNCTIONS_H
#define COMMANDCOMMANDLINEFUNCTIONS_H

/*#include "../program/globals.h"
#include <QString>
#include <QStringList>
#include <QColor>
#include <QTextStream>
#include "../program/scinot.h"
#include <QDateTime>
#include <QStringList>
#include "../program/settings.h"
*/

#include "globals.h"
#include "settings.h"
#include "scinot.h"

#include <string>
#include <vector>
using namespace std;

template<typename T>
void pop_front(vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

vector<string> getArgumentList(int argc, char *argv[]);

void outputText(string text);
void outputText(vector<string> text);
bool checkIfFileExists(string filename);
bool isOptionPresent(string option, vector<string>& arguments);
void checkOptionWithoutValue(string option, vector<string>& arguments);
string checkForInvalidOrExcessSettings(vector<string>& arguments);
string checkOptionForString(string option, vector<string>& arguments,
                            vector<string> validOptionsList,
                             string validDescription = "");
bool iequals(const string& a, const string& b);
string checkOptionForInt(string option, vector<string>& arguments, IntSetting setting, bool offOkay);
string checkOptionForFloat(string option, vector<string>& arguments, FloatSetting setting, bool offOkay);
string checkOptionForFile(string option, vector<string>& arguments);
string checkOptionForSciNot(string option, vector<string>& arguments, SciNotSetting setting, bool offOkay);
double getFloatOption(string option, vector<string>& arguments);
string getStringOption(string option, vector<string>& arguments);
int getIntOption(string option, vector<string>& arguments);
bool isOptionAndValuePresent(string option, string value,
                             vector<string>& arguments);
string checkForExcessArguments(vector<string>& arguments);
void parseSettings(vector<string> arguments);
SciNot getSciNotOption(string option, vector<string>& arguments);


/*QStringList getArgumentList(int argc, char *argv[]);

bool checkForHelp(QStringList arguments);
bool checkForHelpAll(QStringList arguments);
bool checkForVersion(QStringList arguments);

QString checkOptionForInt(QString option, QStringList * arguments, IntSetting setting, bool offOkay);
QString checkOptionForString(QString option, QStringList * arguments,
                             QStringList validOptionsList,
                             QString validDescription = "");
QString checkOptionForColour(QString option, QStringList * arguments);
QString checkTwoOptionsForFloats(QString option1, QString option2,
                                 QStringList * arguments,
                                 FloatSetting setting1,
                                 FloatSetting setting2,
                                 bool secondMustBeEqualOrLarger = false);


QColor getColourOption(QString option, QStringList * arguments);
NodeColourScheme getColourSchemeOption(QString option, QStringList * arguments);
GraphScope getGraphScopeOption(QString option, QStringList * arguments);

void getCommonHelp(QStringList * text);
void getSettingsUsage(QStringList *text);

bool createBlastTempDirectory();
void deleteBlastTempDirectory();

QString getElapsedTime(QDateTime start, QDateTime end);

void getGraphScopeOptions(QStringList * text);

QStringList wrapText(QString text, int width, int firstLineIndent, int laterLineIndent);
QString rstrip(const QString& str);


QString getRangeAndDefault(IntSetting setting);
QString getRangeAndDefault(IntSetting setting, QString defaultVal);
QString getRangeAndDefault(FloatSetting setting);
QString getRangeAndDefault(FloatSetting setting, QString defaultVal);
QString getRangeAndDefault(SciNotSetting setting);
QString getRangeAndDefault(int min, int max, int defaultVal);
QString getRangeAndDefault(int min, int max, int defaultVal);
QString getRangeAndDefault(int min, int max, QString defaultVal);
QString getRangeAndDefault(double min, double max, double defaultVal);
QString getRangeAndDefault(double min, double max, QString defaultVal);
QString getRangeAndDefault(QString min, QString max, QString defaultVal);
QString getDefaultColour(QColor colour);

QString getBandageTitleAsciiArt();
bool isOption(QString text);
bool isSectionHeader(QString text);
bool isListItem(QString text);
bool isCommand(QString text);
bool isError(QString text);
void outputText(QString text, QTextStream * out);
void outputText(QStringList text, QTextStream * out);
void getOnlineHelpMessage(QStringList * text);
*/
#endif // COMMANDCOMMANDLINEFUNCTIONS_H
