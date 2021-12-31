//
// Created by adham on ٣٠‏/١٢‏/٢٠٢١.
//
/*
    Convert from Hex to Decimal
    Convert from Decimal to Hex
    Convert String (Number) to int
*/
#ifndef SYSPROJECT_CALCULATOR_H
#define SYSPROJECT_CALCULATOR_H
#include <bits/stdc++.h>
using namespace std;

class Calculator {
private:
    map<char, int> hexChar;
    const int HEX_BASE = 16;
    const int BIN_BASE = 2;
    void initHexChar() {
        hexChar.insert(make_pair('a', 10));
        hexChar.insert(make_pair('b', 11));
        hexChar.insert(make_pair('c', 12));
        hexChar.insert(make_pair('d', 13));
        hexChar.insert(make_pair('e', 14));
        hexChar.insert(make_pair('f', 15));
    }
public:
    Calculator();
    int fromHexToDecimal(string hex);
    string fromDecToHex(int number);
    int fromBinaryToDecimal(string binary);
    string formBinaryToHex(string binary);
    int to_int(string number);
};


#endif //SYSPROJECT_CALCULATOR_H
