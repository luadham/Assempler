//
// Created by adham
//

#include "headers/PassTwo.h"

PassTwo::PassTwo(int startLocation, vector<Line> input, vector<SymbolTableLine> symbolTable, string base, string def, string ref) {
    this->input = input;
    this->base = base;
    this->symbolTable = symbolTable;
    this->def = def;
    this->ref = ref;
    this->startLocation = startLocation;
    generateObjCodes();
    writeOut_objCode();
    generateHTERec();
    writeOut_htme();
}
