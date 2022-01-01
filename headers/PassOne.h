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
    bool validCode;
    vector<SymbolTableLine> symbolTable;
    vector<Line> lines;
    void incrementLocationCounter(Line line);
    int getMemorySize(Line line);
    void generateLocationCounter();
    void writeOut();
    void generateSymbolTable();
    bool isExistLabe(string label) {
        for (int i = 0; i < lines.size(); i++) {
            if (label == lines[i].label) return true;
        }
        return false;
    }


public:

    PassOne(vector<Line> input, int startLocation);
    vector<SymbolTableLine> getSymbolTable();



};


#endif
