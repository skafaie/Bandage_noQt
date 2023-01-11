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


/*#include "../ui/mainwindow.h"
#include <QApplication>
#include <QStringList>
#include <QString>
#include <QCommandLineParser>
#include <QTextStream>
#include "../command_line/load.h"
#include "../command_line/info.h"
#include "../command_line/image.h"
#include "../command_line/querypaths.h"
#include "../command_line/reduce.h"
#include "../command_line/commoncommandlinefunctions.h"
#include "../program/memory.h"
#include "../blast/blastsearch.h"
#include "../graph/assemblygraph.h"
#include "../ui/mygraphicsview.h"

#ifndef Q_OS_WIN32
#include <sys/ioctl.h>
#endif //Q_OS_WIN32*/
#include "commoncommandlinefunctions.h"
#include "querypaths.h"
#include "globals.h"
#include "settings.h"
//#include "memory.h"

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    /*vector<string> test11;
    test11.push_back("hi");
    test11.push_back("bye");
    test11.push_back("hello");
    //checkOptionWithoutValue("bye", test11);
    for (int i = 0; i < test11.size(); i++) {
            //std::cout << test11.at(i) << ' ';
            if (iequals(test11.at(i),"byee"))
                cout<<"matched with "<<test11.at(i)<<endl;
    }*/
    
    vector<string> arguments = getArgumentList(argc, argv);

    string first;
   if (arguments.size() > 0)
        first = arguments[0];

    //Create the important global objects.
    g_settings.reset(new Settings());
    //g_assemblyGraph.reset(new AssemblyGraph());
    //g_memory.reset(new Memory());
    
    if (arguments.size() > 0)
    {
        transform(first.begin(), first.end(), first.begin(), ::tolower);
        if (first == "querypaths")
        {
            pop_front(arguments);
            //cout << "Hello World!"<<endl;
            //g_memory->commandLineCommand = BANDAGE_QUERY_PATHS;
            return bandageQueryPaths(arguments);
        }
    }
    
}
