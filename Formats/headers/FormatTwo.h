//
// Created by adham
//

#ifndef SYSPROJECT_FORMATTWO_H
#define SYSPROJECT_FORMATTWO_H
#include <bits/stdc++.h>
#include "IFormat.h"

using namespace std;

class FormatTwo : public IFormat {
public:
    FormatTwo();
    char reg[7] = {'a', 'x', 'l', 'b', 's', 't', 'f'};
    int getRegNumber(char c) {
        for (int i = 0; i < 7; i++) {
            if (c == reg[i]) return i;
        }
        return 0;
    }
    string generateObjCode(string opCode, char reg_one, char reg_two) {
        string res = "";
        res += opCode;
        int reg1 = getRegNumber(reg_one);
        int reg2 = getRegNumber(reg_two);
        res += to_string(reg1);
        res += to_string(reg2);
        return res;
    }
};


#endif
