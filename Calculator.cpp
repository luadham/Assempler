//
// Created by adham on ٣٠‏/١٢‏/٢٠٢١.
//

#include "headers/Calculator.h"

Calculator::Calculator() {
    initHexChar();
}

int Calculator::fromHexToDecimal(string hex) {
    int res = 0;
    int power = hex.size() - 1;
    for (int i = 0; i < hex.size(); i++) {
        if (hex[i] >= 'a' && hex[i] <= 'f') {
            res += (pow(HEX_BASE, power) * hexChar[hex[i]]);
        } else {
            res += (pow(HEX_BASE, power) * (hex[i] - '0'));
        }
        power--;
    }
    return res;
}

string Calculator::fromDecToHex(int number) {
    if (number == 0) {
        return "0";
    }
    string temp = "";
    while (number) {
        int rem = number % 16;
        if (rem == 10) temp += 'a';
        else if (rem == 11) temp += 'b';
        else if (rem == 12) temp += 'c';
        else if (rem == 13) temp += 'd';
        else if (rem == 14) temp += 'e';
        else if (rem == 15) temp += 'f';
        else temp += to_string(rem);
        number /= 16;
    }
    string res = "";
    for (int i = temp.size() - 1; i >= 0; i--) {
        res += temp[i];
    }
    return res;
}

int Calculator::to_int(string number) {
    int res = 0;
    for (int i = 0; i < number.size(); i++) {
        res *= 10;
        res += (number[i] - '0');
    }
    return res;
}

int Calculator::fromBinaryToDecimal(string binary) {
    int number = 0;
    for (int i = binary.size() - 1; i >= 0; i--) {
        if (binary[i] == '1')
            number += pow(BIN_BASE, binary.size() - i - 1);
    }
    return number;
}

string Calculator::formBinaryToHex(string binary) {
    return fromDecToHex(fromBinaryToDecimal(binary));
}
