#include "FileUtils.h"
#include <iostream>
#include <fstream>
#include <string>

int forEachLine(string file, function<void(long, string)> func)
{
    ifstream inputFile(file);

    if (!inputFile.is_open())
    {
        cerr << "Can not read file: " << file << endl;
        return 0;
    }
    string line;
    long line_index = 0;
    while (std::getline(inputFile, line))
    {
        // if (0 == line_index % 1000)
        // {
        //     cout << "line_index "
        //          << " - " << line_index << endl;
        //     cout << line << endl;
        // }
        func(line_index, line);
        line_index++;
    }
    inputFile.close();
    return 1;
}