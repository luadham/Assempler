//
// Created by adham
//

#include "headers/Calculator.h"

Calculator::Calculator() {
    initHexChar();
}

unsigned int Calculator::fromHexToDecimal(string hex) {
    unsigned int res = 0;
    unsigned int power = hex.size() - 1;
    for (int i = 0; i < hex.size(); i++) {
        if (hex[i] >= 'a' && hex[i] <= 'f') {
            res += (int) (pow(HEX_BASE, power) * hexChar[hex[i]]);
        } else {
            res += (int) (pow(HEX_BASE, power) * (hex[i] - '0'));
        }
        power--;
    }
    return res;
}

string Calculator::fromDecToHex(int number) {
    unsigned int n = number;
    if (n == 0) {
        return "0";
    }
    string temp = "";
    while (n) {
        int rem = n % 16;
        if (rem == 10) temp += 'a';
        else if (rem == 11) temp += 'b';
        else if (rem == 12) temp += 'c';
        else if (rem == 13) temp += 'd';
        else if (rem == 14) temp += 'e';
        else if (rem == 15) temp += 'f';
        else temp += to_string(rem);
        n /= 16;
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
            number += (int) pow(BIN_BASE, binary.size() - i - 1);
    }
    return number;
}

string Calculator::formBinaryToHex(string binary) {
    return fromDecToHex(fromBinaryToDecimal(binary));
}

bool Calculator::isNegative(int number) {
    return number < 0;
}

string Calculator::fromDecimalToBinary(int number) {
    string res = "";
    while (number != 0) {
        res.push_back((number % 2)? '0' : '1');
        number /= 2;
    }
    return res;
}


int Calculator::numberOfBits(int number) {
    int cnt = 0;
    while (number != 0) {
        cnt++;
        number >>= 1;
    }
    return cnt;
}

int Calculator::keyConverter(int numberOfBits) {
    string res = "";
    while (numberOfBits--) res += '1';
    return Calculator::fromBinaryToDecimal(res);
}

int Calculator::twosComplement(int number) {
    return onesComplement(number) + 1;
}



