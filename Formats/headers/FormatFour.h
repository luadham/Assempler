//
// Created by adham
//

#ifndef SYSPROJECT_FORMATFOUR_H
#define SYSPROJECT_FORMATFOUR_H
#include <bits/stdc++.h>
#include "../../headers/Calculator.h"
#include "IFormat.h"

using namespace std;

class FormatFour : public IFormat {
private:
    Calculator calc;
public:
    FormatFour();
    string generateObjCode(string obCode, int x, int b, int p, string address) {
        string res = "";
        res += obCode;
        string flags = "";

        flags.append(to_string(x))
                .append(to_string(b))
                .append(to_string(p))
                .append("1");

        flags = calc.formBinaryToHex(flags);
        res += flags;

        int bits = 5 - address.size();
        while (bits > 0) {
            res += '0';
            bits--;
        }
        res += address;

        return res;
    }
};


#endif
