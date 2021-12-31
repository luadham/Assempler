//
// Created by adham on ٣١‏/١٢‏/٢٠٢١.
//

#ifndef SYSPROJECT_PASSONE_H
#define SYSPROJECT_PASSONE_H
#include <bits/stdc++.h>
#include "InputParser.h"
#include "SymbolTableLine.h"
class PassOne {
private:
    string outFile;
    string symbolTableFile;
    int locationCounter;
    Calculator calculator;
    vector<Line> lines;
    vector<SymbolTableLine> symbolTable;

    void incrementLocationCounter(Line line);
    int getMemorySize(Line line);
    void generateLocationCounter();
    void writeOut();
    void generateSymbolTable();



public:
    PassOne(vector<Line> input, int startLocation);
    vector<SymbolTableLine> getSymbolTable();


};


#endif
