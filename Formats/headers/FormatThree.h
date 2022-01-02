//
// Created by adham
//

#ifndef SYSPROJECT_FORMATTHREE_H
#define SYSPROJECT_FORMATTHREE_H

#include <bits/stdc++.h>
#include "../../headers/Calculator.h"
#include "IFormat.h"

using namespace std;

class FormatThree : public IFormat {
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

        if (disp[0] == 'f' && disp[1] == 'f') {
            int from = 0;
            for (int i = 0; i < disp.size() - 1; i++) {
                if (disp[i] == 'f' && disp[i + 1] != 'f') {
                    from = i;
                    break;
                }
            }
            string temp = "";
            for(int i = from; i < disp.size(); i++) {
                temp += disp[i];
            }
            int size = 4 - temp.size();
            while (size--) {
                res += 'f';
            }
            res += temp;
        } else {

            int bits = 3 - disp.size();
            while (bits > 0) {
                res += '0';
                bits--;
            }
            res += disp;
        }


        return res;
    }
};


#endif
