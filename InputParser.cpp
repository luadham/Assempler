//
// Created by adham
//

#include "headers/InputParser.h"

vector<Line> InputParser::getLines() {
    return this->inputLines;
}

int InputParser::getStartLocation() {
    return this->startProgram;
}

InputParser::InputParser(vector<Instruction> instructions) {
    inputFile = "../in.txt";
    this->instructions = instructions;
    readInput();
}
