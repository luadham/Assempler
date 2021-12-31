//
// Created by adham
//

#ifndef SYSPROJECT_FORMATTHREE_H
#define SYSPROJECT_FORMATTHREE_H
#include <bits/stdc++.h>
#include "../../headers/Calculator.h"
using namespace std;

class FormatThree {
private:
    Calculator calc;
public:
    FormatThree();
    string generateObjCode(string obCode, int x, int b, int p, string disp) {
        string res = "";
        res += obCode;
        string flags = "";
        flags.append(to_string(x)).append(to_string(b)).append(to_string(p)).append("0");
        flags = calc.formBinaryToHex(flags);
        res += flags;
        int bits = 3 - disp.size();
        while (bits--) res += "0";
        res += disp;
        return res;
    }
};


#endif //SYSPROJECT_FORMATTHREE_H
