//
// Created by adham
//

#ifndef SYSPROJECT_FORMATFIVE_H
#define SYSPROJECT_FORMATFIVE_H
#include <bits/stdc++.h>
#include "../../headers/Calculator.h"
#include "IFormat.h"

using namespace std;

class FormatFive : public IFormat {
private:
    Calculator calc;
public:
    FormatFive();
    string generateObjCode(string obCode, int x, int b, int p, int f2, string disp) {
        int obCodeDecimal = calc.fromHexToDecimal(obCode);
        string res = "";
        string flags = "";
        int f1 = !(calc.fromHexToDecimal(disp) & 1);
        int f3 = calc.fromHexToDecimal(disp) == 0;
        flags.append(to_string(f1)).append(to_string(f2));
        obCodeDecimal |= Calculator::fromBinaryToDecimal(flags);
        flags = "";

        flags.append(to_string(x)).append(to_string(b))
        .append(to_string(p)).append(to_string(f3));

        flags = Calculator::formBinaryToHex(flags);
        res += Calculator::fromDecToHex(obCodeDecimal);
        res += flags;

        int bits = 3 - disp.size();
        while (bits--) res += '0';
        res += disp;

        return res;
    }
};


#endif
