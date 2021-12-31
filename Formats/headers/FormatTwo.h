//
// Created by adham 
//

#ifndef SYSPROJECT_FORMATTWO_H
#define SYSPROJECT_FORMATTWO_H
#include <bits/stdc++.h>
using namespace std;

class FormatTwo {
public:
    FormatTwo();
    string generateObjCode(string opCode, string reg_one, string reg_two) {
        string res = "";
        res += opCode;
        res += reg_one;
        res += (reg_two == "")? "0" : reg_two;
        return res;
    }
};


#endif
