//
// Created by adham on ٣١‏/١٢‏/٢٠٢١.
//

#ifndef SYSPROJECT_PASSONE_H
#define SYSPROJECT_PASSONE_H
#include <bits/stdc++.h>
#include "InputParser.h"

class PassOne {
private:
    struct LocationLine {
        string locCounter;
        Line codeLine;
    };

    string outFile;
    string symbolTableFile;
    int locationCounter;
    Calculator calculator;
    vector<Line> lines;
    vector<LocationLine> symbolTable;

    void incrementLocationCounter(Line line);
    int getMemorySize(Line line);
    void generateLocationCounter();
    void writeOut();
    void generateSymbolTable();

public:
    PassOne(vector<Line> input, int startLocation);

};


#endif
