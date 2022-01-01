//
// Created by adham
//

#ifndef SYSPROJECT_PASSTWO_H
#define SYSPROJECT_PASSTWO_H
#include <bits/stdc++.h>
#include "Line.h"
#include "SymbolTableLine.h"
#include "Calculator.h"
#include "../Formats/headers/IFormat.h"
#include "../Formats/headers/FormatOne.h"
#include "../Formats/headers/FormatTwo.h"
#include "../Formats/headers/FormatThree.h"
#include "../Formats/headers/FormatFour.h"

class PassTwo {
private:
    vector<Line> input;
    vector<SymbolTableLine> symbolTable;
    Calculator calculator;
    vector<string> objCodes;

    string getOperandLocation(string operand) {
        for (auto i : symbolTable) {
            if (operand == i.codeLine.operand) return i.locationLine;
        }
        return "";
    }
    void generateObjCodes() {
        string s1 = ""; string s2 = "";
        splitStr("adham,adel", s1, s2);
        cout << "s1 : " << s1 << " " << "s2 : " << s2 << endl;
        for (SymbolTableLine inputLine : symbolTable) {
            if (inputLine.codeLine.instruction.format == 1) {
                // Format 1
                FormatOne formatOne;
                objCodes.push_back(formatOne.generateObjCode(inputLine.codeLine.instruction.opCode));
            } else if (inputLine.codeLine.instruction.format == 2){
                // Format 2
                // n i
                FormatTwo formatTwo;
                string reg1 = "";
                string reg2 = "";
                splitStr(inputLine.codeLine.operand, reg1, reg2);
                objCodes.push_back(formatTwo.generateObjCode(inputLine.codeLine.instruction.opCode, reg1, reg2));
            } else if (inputLine.codeLine.instruction.format == 3) {
                // Format 3
                FormatThree formatThree;
                int opCode = addressingMode(inputLine.codeLine.operand) + calculator.fromHexToDecimal(inputLine.codeLine.instruction.opCode);
                int x = isIndexed(inputLine.codeLine.operand);
                int b = (x)? 1 : 0;
                int p = !b;
                string oberand = (x != 3)? getRestOfString(inputLine.codeLine.operand) : inputLine.codeLine.operand;
                int disp = calculator.fromHexToDecimal(getOperandLocation(oberand)) - calculator.fromHexToDecimal(inputLine.locationLine);
                objCodes.push_back(formatThree.generateObjCode(
                        calculator.fromDecToHex(opCode),
                        x, b, p,
                        calculator.fromDecToHex(disp)));
            } else {
                // Format 4
            }
        }
    }

    void printObjCodes() {
        for (int i = 0; i < objCodes.size(); i++) {
            cout << objCodes[i] << endl;
        }
    }

    void splitStr(string str, string &reg1, string &reg2) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ',') break;
            cnt++;
        }
        for (int i = 0; i <= cnt; i++) {
            reg1 += str[i];
        }
        for (int i = cnt + 1; i < str.size(); i++) {
            reg2 += str[i];
        }
        reg1.erase(remove(reg1.begin(), reg1.end(), ' '), reg1.end());
        reg2.erase(remove(reg2.begin(), reg2.end(), ' '), reg2.end());
    }

    string getRestOfString(string str) {
        string res = "";
        for (int i = 1; i < str.size(); i++)
            res += str[i];
        return res;
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
        return Calculator::fromDecToHex(operandAddress - pcNext);
    }


};


#endif
