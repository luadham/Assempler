//
// Created by adham on ٣٠‏/١٢‏/٢٠٢١.
//

#ifndef SYSPROJECT_FORMATSIX_H
#define SYSPROJECT_FORMATSIX_H
#include <bits/stdc++.h>
#include "../../headers/Calculator.h"
using namespace std;

class FormatSix {
public:
    FormatSix();
    string generateObjCode(string opCode, int x, string address, string base) {
        string res = "";
        res += opCode;
        int addrs = Calculator::fromHexToDecimal(address);
        int f4 = !(addrs & 1);
        int f5 = addrs != 0;
        int f6 = addrs != Calculator::fromHexToDecimal(base);
        string flags = "";
        flags.append(to_string(x)).append(to_string(f4))
            .append(to_string(f5)).append(to_string(f6));
        flags = Calculator::formBinaryToHex(flags);
        res += flags;
        int bits = 5 - address.size();
        while (bits--) res += '0';
        res += address;
        return res;
    }
};


#endif //SYSPROJECT_FORMATSIX_H
