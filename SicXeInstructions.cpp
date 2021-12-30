//
// Created by adham
//

#include "headers/SicXeInstructions.h"

SicXeInstructions::SicXeInstructions() {
    fileName = "../instructions.txt";
    readInstructions();
}

vector<Instruction> SicXeInstructions::getInstructions() {
    return this->instructions;
}

int SicXeInstructions::getInstructionFormat(string name) {
    for (int i = 0; i < instructions.size(); i++) {
        if (instructions[i].name == name) {
            return instructions[i].format;
        }
    }
    return -1;
}


int SicXeInstructions::getInstructionType(string operand) {
    if (operand[0] == '@') return 2;
    else if (operand[0] == '#') return 1;
    return 3;
}

bool SicXeInstructions::isIndexed(string operand) {
    for (int i = 0; i < operand.size(); i++) {
        if (operand[i] == ',') return true;
    }
    return false;
}

bool SicXeInstructions::isFormatFour(string opernad) {
    return opernad[0] == '+';
}



