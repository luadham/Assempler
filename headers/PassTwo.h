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
#include "../Formats/headers/FormatFive.h"
#include "../Formats/headers/FormatSix.h"
#include "../ObjCode.h"

class PassTwo {
private:


    vector<Line> input;
    vector<SymbolTableLine> symbolTable;
    Calculator calculator;
    vector<ObjCode> objCodes;
    vector<string> htRec;
    const string outFile = "../out.txt";
    const string htmeFile = "../htme.txt";
    string base;
    string def, ref;
    int startLocation;

    /*
     * Get Operand Location From symbol table
     */
    string getOperandLocation(string operand) {
        for (auto i: symbolTable) {
            if (operand == i.codeLine.label) return i.locationLine;
        }
        return "";
    }

    /*
     * Check if c is alpha char or not
     */
    bool isChar(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }

    /*
     * Generate Obj Code from input
     * @modify objCode Vector
     */
    void generateObjCodes() {
        for (int i = 0; i < symbolTable.size() - 1; i++) {
            int x = 0;
            string operand = symbolTable[i].codeLine.operand;
            string opCode = symbolTable[i].codeLine.instruction.opCode;
            string nextPc = symbolTable[i + 1].locationLine;
            string instruction = symbolTable[i].codeLine.instruction.name;
            string label = symbolTable[i].codeLine.label;
            ObjCode objCodeLine;
            //cout << instruction << endl;
            if (operand[0] != '-' && label[0] != '-' && operand == label) {
                objCodeLine.location = symbolTable[i].locationLine;
                objCodeLine.isModified = false;
                objCodeLine.objCode = getLitralValue(operand);
                objCodes.push_back(objCodeLine);
                continue;
            }
            if (isIndexed(operand) && operand[0] != '=') {
                string i = "", temp = "";
                splitStr(operand, temp, i);
                operand = temp;
                x = 1;
            }
            //cout << operand << endl;
            if (instruction == "word") {
                string res = "";
                int size = 6 - operand.size();
                while (size--) res += '0';
                res += operand;
                objCodeLine.objCode = res;
                objCodeLine.isModified = false;
                objCodeLine.location = symbolTable[i].locationLine;
                objCodes.push_back(objCodeLine);
            } else if (instruction == "byte") {
                objCodeLine.objCode = operand;
                objCodeLine.isModified = false;
                objCodeLine.location = symbolTable[i].locationLine;
                objCodes.push_back(objCodeLine);
            } else if (instruction == "resw" || instruction == "resb") continue;
            else if (instruction[0] == '&') {
                // Format 5
                objCodeLine.isModified = false;
                objCodeLine.location = symbolTable[i].locationLine;
                objCodeLine.objCode = format_five(operand, x, opCode, nextPc);
                objCodes.push_back(objCodeLine);
            } else if (instruction[0] == '$') {
                // Format 6
                objCodeLine.isModified = true;
                objCodeLine.location = symbolTable[i].locationLine;
                objCodeLine.objCode = format_six(operand, x, opCode);
                objCodes.push_back(objCodeLine);
            } else if (instruction[0] == '+') {
                objCodeLine.isModified = true;
                objCodeLine.location = symbolTable[i].locationLine;
                objCodeLine.objCode = format_four(operand, x, opCode);
                objCodes.push_back(objCodeLine);
            } else if (symbolTable[i].codeLine.instruction.format == 1) {
                // Fromat 1
                objCodeLine.isModified = false;
                objCodeLine.objCode = opCode;
                objCodeLine.location = symbolTable[i].locationLine;
                objCodes.push_back(objCodeLine);
            } else if (symbolTable[i].codeLine.instruction.format == 2) {
                // Format 2
                string r1 = "", r2 = "";
                splitStr(operand, r1, r2);
                objCodeLine.location = symbolTable[i].locationLine;
                objCodeLine.isModified = false;
                objCodeLine.objCode = format_two(opCode, r1[0], r2[0]);
                objCodes.push_back(objCodeLine);
            } else if (symbolTable[i].codeLine.instruction.format == 3) {
                // Format 3
                objCodeLine.location = symbolTable[i].locationLine;
                objCodeLine.isModified = false;
                objCodeLine.objCode = format_three(operand, x, opCode, nextPc);
                objCodes.push_back(objCodeLine);
            }
        }
        cout << "Done :v" << endl;
    }

    void printHtRec() {
        for (auto i: htRec) {
            cout << i << endl;
        }
    }

    string convertFromCharToNumber(string chars) {
        string res = "";
        for (int i = 0; i < chars.size(); i++) {
            res += calculator.fromDecToHex(chars[i]);
        }
        return res;
    }

    string getLitrStr(string litral) {
        string res = "";
        for (int i = 3; i <= litral.size() - 2; i++) {
            res += litral[i];
        }
        return res;
    }

    string getLitralValue(string litral) {
        char type = litral[1];
        string res = getLitrStr(litral);
        switch (type) {
            case 'C':
                res = convertFromCharToNumber(res);
                break;
            case 'X':
                break;
            case 'D':
                res = calculator.fromDecimalToBinary(calculator.to_int(res));
                break;
            default:
                cout << "Not Valid Char for litral" << endl;
        }
        return res;
    }

    /*
     * Generate HTME Record
     */
    void generateHTERec() {
        // cout << "Adham" << symbolTable[0].locationLine << endl;
        int startAddress = calculator.fromHexToDecimal(symbolTable[0].locationLine);
        int endAddress = calculator.fromHexToDecimal(symbolTable[symbolTable.size() - 1].locationLine);
        string length = calculator.fromDecToHex(endAddress - startAddress + 1);
        string prog_name = symbolTable[0].codeLine.label;
        htRec.push_back(getHRec(prog_name ,length));
        bool refFlag = ref != "";
        bool defFlag = def != "";

        if (defFlag) htRec.push_back(getDefRec(def));
        if (refFlag) htRec.push_back(getRef(ref));

        int cnt = 0;
        string instruction = "", start = objCodes[0].location;
        for (int i = 0; i < objCodes.size(); i++) {
            if (cnt + objCodes[i].objCode.size() <= 60) {
                instruction += objCodes[i].objCode;
                cnt += objCodes[i].objCode.size();
            } else {
                string len = calculator.fromDecToHex(cnt / 2);
                htRec.push_back(getTRec(start, len, instruction));
                start = objCodes[i].location;
                i--;
                instruction = "";
                cnt = 0;
            }
            if (i == objCodes.size() - 1) {
                string len = calculator.fromDecToHex(cnt / 2);
                htRec.push_back(getTRec(start, len, instruction));
            }
        }
        generateMRec();
        htRec.push_back(getERec(symbolTable[0].locationLine));
        printHtRec();
    }

    vector<string> spliter(string str) {
        vector<string> v;
        stringstream ss(str);
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        return v;
    }
    string getDefRec(string def) {
        string res = "";
        vector<string> v = spliter(def);
        vector<string> locations;
        for (int i = 0; i < v.size(); i++) {
            locations.push_back(getOperandLocation(v[i]));
        }
        extendSize(locations);
        for (int i = 0; i < v.size(); i++) {
            res += v[i];
            res += locations[i];
        }
        return "D" + res;
    }
    void extendSize(vector<string> &vec) {
        for (int i = 0; i < vec.size(); i++) {
            int size = 6 - vec[i].size();
            while (size > 0) {
                vec[i] += " ";
                size--;
            }
        }
    }
    string getRef(string ref) {
        string res = "";
        vector<string> v = spliter(ref);
        extendSize(v);
        for (int i = 0; i < v.size(); i++) {
            res += v[i];
        }
        return "R" + res;
    }
    /*
     * Generate Modification Record
     */
    void generateMRec() {
        for (int i = 0; i < objCodes.size(); i++) {
            if (objCodes[i].isModified) {
                htRec.push_back(getMRec(objCodes[i].location));
            }
        }
    }

    /*
     * Return H Rec
     */
    string getHRec(string prog_name, string prog_len) {
        string res = "H";
        res += prog_name;
        string start = calculator.fromDecToHex(startLocation);
        int startSize = 6 - start.size();
        int nameSize = 6 - prog_name.size();
        int lenSize = 6 - prog_len.size();
        while (nameSize--) res += " ";
        while (startSize--) res += "0";
        res += start;
        while (lenSize--) res += "0";
        res += prog_len;
        return res;
    }

    /*
     * Return E Record
     */
    string getERec(string start) {
        string res = "E";
        int size = 6 - start.size();
        while (size--) res += "0";
        res += start;
        return res;
    }

    /*
     * Rteurn T Record
     */
    string getTRec(string start, string len, string instructions) {
        string res = "T";
        int startSize = 6 - start.size();
        while (startSize--) res += "0";
        res += start;
        int lenSize = 2 - len.size();
        while (lenSize--) res += "0";
        res += len;
        res += instructions;
        return res;
    }

    /*
     * Return M Record
     */
    string getMRec(string adress) {
        string res = "";
        int size = 6 - adress.size();
        while (size--) res += '0';
        res += adress;
        return "M" + res + "05";
    }

    /*
     * Get Format two Obj code
     * @return objcode
     */
    string format_two(string opCode, char r1, char r2) {
        FormatTwo formatTwo;
        return formatTwo.generateObjCode(opCode, r1, r2);
    }

    /*
     * Get Format Six obj code
     * @return objCode
     */
    string format_six(string operand, int x, string opCode) {
        FormatSix formatSix;
        string _obCode = getOpCode(opCode, operand);
        string validOperand = getRestOfString(operand);
        string address = getOperandLocation(validOperand);
        return formatSix.generateObjCode(_obCode, x, address, getOperandLocation(base));
    }

    /*
     * Get Format Five ObjCode
     * @return objCode
     */
    string format_five(string operand, int x, string opCode, string pc) {
        FormatFive formatFive;
        string validOperand = getRestOfString(operand);
        int b = x;
        int p = !b;
        int operandValue = calculator.fromHexToDecimal(getOperandLocation(operand));
        int f2 = operandValue < calculator.fromHexToDecimal(pc);
        return formatFive.generateObjCode(opCode, x, b, p, f2, displacement(pc, validOperand));
    }

    /*
     * Get objCode for format four
     * @return objCode
     */
    string format_four(string operand, int x, string opCode) {
        FormatFour formatFour;
        string _opCode = getOpCode(opCode, operand);
        string validOperand = getRestOfString(operand);
        int b = x;
        int p = 0;
        string address = getOperandLocation(validOperand);
        return formatFour.generateObjCode(_opCode, x, b, p, address);
    }

    /*
     * Get obj code for format three
     * @return objCode
     */
    string format_three(string operand, int x, string opCode, string pc) {
        FormatThree formatThree;
        string _opCode = getOpCode(opCode, operand);
        string validOperand = (operand[0] == '=') ? operand : getRestOfString(operand);
        int b = x;
        int p = !b;
        return formatThree.generateObjCode(_opCode, x, b, p,
                                           displacement(pc, validOperand));
    }

    /*
     * Calculate opCode with n, i
     * @return new opCode
     */
    string getOpCode(string oldOpCode, string operand) {
        string s = "";
        if (oldOpCode[0] == '0') s += '0';
        int opCode = addressingMode(operand) + calculator.fromHexToDecimal(oldOpCode);
        return s + calculator.fromDecToHex(opCode);
    }


    /*
     * Split string that have ,
     * ex : adham, adel -> st1 = adham; str2 = adel;
     * @param str, str1, str2
     * @modify str1, str2
     */
    void splitStr(string str, string &reg1, string &reg2) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ',') break;
            cnt++;
        }
        for (int i = 0; i < cnt; i++) {
            reg1 += str[i];
        }
        for (int i = cnt + 1; i < str.size(); i++) {
            reg2 += str[i];
        }
        reg1.erase(remove(reg1.begin(), reg1.end(), ' '), reg1.end());
        reg2.erase(remove(reg2.begin(), reg2.end(), ' '), reg2.end());
    }

    /*
     * ex: +jsub to jsub
     *      #param to param
     * @return string without starting symbol
     */
    string getRestOfString(string str) {
        if (isChar(str[0])) return str;
        string res = "";
        for (int i = 1; i < str.size(); i++)
            res += str[i];
        return res;
    }

public:
    PassTwo(int startLocation, vector<Line> input, vector<SymbolTableLine> symbolTable, string base, string def, string ref);

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

    /*
     * Write objCode in file
     */
    void writeOut_objCode() {
        ofstream file;
        file.open(outFile);
        if (file.fail() || file.bad()) {
            cout << "Please Check Out file path" << endl;
            return;
        }
        for (int i = 0; i < objCodes.size(); i++) {
            file << objCodes[i].location << " " << objCodes[i].objCode << endl;
        }
        file.close();
    }

    /*
     * Write htme in file
     */
    void writeOut_htme() {
        ofstream file;
        file.open(htmeFile);
        if (file.fail() || file.bad()) {
            cout << "Please Check Out file path" << endl;
            return;
        }

        for (int i = 0; i < htRec.size(); i++) {
            file << htRec[i] << endl;
        }

        file.close();
    }

};


#endif
