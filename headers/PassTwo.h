//
// Created by adham
//

#ifndef SYSPROJECT_PASSTWO_H
#define SYSPROJECT_PASSTWO_H
#include <bits/stdc++.h>
#include "Line.h"
#include "SymbolTableLine.h"
#include "Calculator.h"
#include "../Formats/headers/FormatFour.h"
class PassTwo {
private:
    Calculator calculator;
    vector<Line> input;
    vector<SymbolTableLine> symbolTable;
    string getOperandLocation(string operand) {
        for (auto i : symbolTable) {
            if (operand == i.codeLine.operand) return i.locationLine;
        }
        return "";
    }
    void generateObjCodes() {
        FormatFour f;
        cout << f.generateObjCode("75", 0, 0, 0, "1000");

    }
public:
    PassTwo(vector<Line> input, vector<SymbolTableLine> symbolTable);
    /*
     * check n i
     * if 0 1 return 1
     * if 1 0 return 2
     * if 1 1 return 3
     */
    int addressingMode(string operand) {
        if (operand[0] == '#') return 1;
        else if (operand[0] == '@') return 2;
        else return 3;
    }
    /*
     * check if instruction is indexed or not
     */
    bool isIndexed(string operand) {
        for (int i = 0; i < operand.size(); i++) {
            if (operand[i] == ',') return true;
        }
        return false;
    }
    /*
     * @return true if instruction is format four
     */
    bool isFormatFour(string instruction) {
        return instruction[0] == '+';
    }

    /*
     * Calculate Displacement
     * @return displacment in HEX Form
     */
    string displacement(string nextLocation, string operand) {
        int operandAddress = calculator.fromHexToDecimal(getOperandLocation(operand));
        int pcNext = calculator.fromHexToDecimal(nextLocation);
        return calculator.fromDecToHex(operandAddress - pcNext);
    }


};


#endif
