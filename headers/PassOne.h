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

    bool isExistLabel(string label) {
        for (int i = 0; i < lines.size(); i++) {
            if (label == lines[i].label) return true;
        }
        return false;
    }

    bool validOperand(string operand, string instruction);


public:

    PassOne(vector<Line> input, int startLocation);

    vector<SymbolTableLine> getSymbolTable();

    /*
     *  ex: +jsub to jsub
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
        for (int i = 0; i <= cnt; i++) {
            reg1 += str[i];
        }
        for (int i = cnt + 1; i < str.size(); i++) {
            reg2 += str[i];
        }
        reg1.erase(remove(reg1.begin(), reg1.end(), ' '), reg1.end());
        reg2.erase(remove(reg2.begin(), reg2.end(), ' '), reg2.end());
    }

    /*
     * Check if c is alpha char or not
     */
    bool isChar(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
    }



};


#endif
