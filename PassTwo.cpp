//
// Created by adham on ٣١‏/١٢‏/٢٠٢١.
//

#include "headers/PassTwo.h"

PassTwo::PassTwo(vector<Line> input, vector<SymbolTableLine> symbolTable) {
    this->input = input;
    this->symbolTable = symbolTable;
    generateObjCodes();
    writeOut();
    generateHTERec();
}
