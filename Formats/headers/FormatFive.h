//
// Created by adham
//

#ifndef SYSPROJECT_FORMATFIVE_H
#define SYSPROJECT_FORMATFIVE_H
#include <bits/stdc++.h>
#include "../../headers/Calculator.h"

using namespace std;

class FormatFive {
private:
    Calculator calc;
public:
    FormatFive();
    string generateObjCode(string obCode, int x, int b, int p, string disp) {
        int displacment = calc.fromHexToDecimal(disp);
        int f1 = !(displacment & 1);
        int f2 = displacment == 0;
        // must ckeck number is negative
        return "";
    }
};


#endif //SYSPROJECT_FORMATFIVE_H
