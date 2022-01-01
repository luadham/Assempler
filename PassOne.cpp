//
// Created by adham
//

#include "headers/PassOne.h"

PassOne::PassOne(vector<Line> input, int startLocation) {

    symbolTableFile = "symbolTable.txt";
    locationCounter = startLocation;
    this->lines = input;
    generateLocationCounter();
    generateSymbolTable();
}

void PassOne::incrementLocationCounter(Line line) {
    locationCounter += getMemorySize(line);
}

int PassOne::getMemorySize(Line line) {
    char firstDigit = line.instruction.name[0];
    int formats[] = {0, 1, 2, 3,
                     4, 3, 4};
    if (firstDigit == '+') {
        // Format 4
        return formats[4];
    } else if (firstDigit == '&') {
        // Format 5
        return formats[5];
    } else if (firstDigit == '$') {
        // Format 6
        return formats[6];
    } else if (line.instruction.name == "base") {
        return 0;
    } else if (line.instruction.name == "resw") {
        return 3 * Calculator::to_int(line.operand);
    } else if (line.instruction.name == "resb") {
        return Calculator::to_int(line.operand);
    } else if (line.instruction.name == "word") {
        return 3;
    } else if (line.instruction.name == "byte") {
        return 1;
    } else {
        SicXeInstructions sicxe;
        return formats[sicxe.getInstructionFormat(line.instruction.name)];
    }
}

void PassOne::generateLocationCounter() {
    SymbolTableLine locationLine;
    for (int i = 0; i < this->lines.size(); i++) {
        if (i > 0 && lines[i].instruction.name != "word" && lines[i].instruction.name != "resw" &&
            lines[i].instruction.name != "byte" &&
            lines[i].instruction.name != "resb" &&
            lines[i].operand[0] != '#' &&
            lines[i].operand[0] != '=' &&
            !isExistLabe(lines[i].operand)) {
            cout << lines[i].operand << endl;
            cout << "Check Line : " << i + 1 << endl;
            return;
        }
        if (lines[i].instruction.name == "start") {
            locationLine.locationLine = "0";
            locationLine.codeLine = lines[i];
        } else if (lines[i].instruction.name == "end") {
            locationLine.locationLine = Calculator::fromDecToHex(this->locationCounter);;
            locationLine.codeLine = lines[i];
        } else {
            locationLine.locationLine = Calculator::fromDecToHex(this->locationCounter);
            locationLine.codeLine = lines[i];
            incrementLocationCounter(lines[i]);
        }
        this->symbolTable.push_back(locationLine);
    }
}

void PassOne::writeOut() {

}

void PassOne::generateSymbolTable() {
    ofstream file;
    file.open(symbolTableFile);
    cout << "< Symbol Table >\n";
    cout << "-----------------------\n";
    cout << "Loc Counter\tVariable\n";
    file << "Loc Counter\tVariable\n";
    for (int i = 0; i < symbolTable.size(); i++) {
        if (symbolTable[i].codeLine.label == "-")
            continue;
        else {
            cout << symbolTable[i].locationLine << "\t\t" << symbolTable[i].codeLine.label << endl;
            file << symbolTable[i].locationLine << "\t\t" << symbolTable[i].codeLine.label << endl;
        }
    }
    file.close();
    cout << "-----------------------\n";
}

vector<SymbolTableLine> PassOne::getSymbolTable() {
    return this->symbolTable;
}





