//
// Created by adham
//

#include "headers/PassTwo.h"

PassTwo::PassTwo(vector<Line> input, vector<SymbolTableLine> symbolTable, string base) {
    this->input = input;
    this->base = base;
    this->symbolTable = symbolTable;
    generateObjCodes();
    writeOut_objCode();
    generateHTERec();
    writeOut_htme();
}
