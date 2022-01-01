//
// Created by adham on ٣٠‏/١٢‏/٢٠٢١.
//

#ifndef SYSPROJECT_FORMATSIX_H
#define SYSPROJECT_FORMATSIX_H
#include <bits/stdc++.h>
#include "../../headers/Calculator.h"
#include "IFormat.h"

using namespace std;

class FormatSix : public IFormat {
private:
    Calculator calculator;
public:
    FormatSix();
    string generateObjCode(string opCode, int x, string address, string base) {
        string res = "";
        res += opCode;
        int addrs = calculator.fromHexToDecimal(address);
        int f4 = (addrs & 1)? 1 : 0;
        int f5 = addrs != 0;
        int f6 = addrs != calculator.fromHexToDecimal(base);
        string flags = "";
        flags.append(to_string(x)).append(to_string(f4))
            .append(to_string(f5)).append(to_string(f6));
        flags = Calculator::formBinaryToHex(flags);
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


#endif //SYSPROJECT_FORMATSIX_H
