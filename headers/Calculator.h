//
// Created by adham
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
    static const int HEX_BASE = 16;
    static const int BIN_BASE = 2;
    void initHexChar() {
        hexChar.insert(make_pair('a', 10));
        hexChar.insert(make_pair('b', 11));
        hexChar.insert(make_pair('c', 12));
        hexChar.insert(make_pair('d', 13));
        hexChar.insert(make_pair('e', 14));
        hexChar.insert(make_pair('f', 15));
    }
    static int onesComplement(int number) {
        return number ^ keyConverter(numberOfBits(number));
    }
    
public:
    Calculator();
    /*
     * convert from hex to decimal
     */
    int fromHexToDecimal(string hex);
    /*
     * Convert from decimal to hex
     */
    static string fromDecToHex(int number);
    /*
     * convert from binary to decimal
     */
    static int fromBinaryToDecimal(string binary);
    /*
     * Convert from binary to hex
     */
    static string formBinaryToHex(string binary);
    /*
     * convert from Decimal to Hex
     */
    static string fromDecimalToBinary(int number);
    /*
     * convert any string number to in
     */
    static int to_int(string number);
    /*
     * @return true if number is negative
     */
    static bool isNegative(int number);
    /*
     * @return the pos of last 1 bit in number
     */
    static int numberOfBits(int number);
    /*
     * Get number that will be xor with the number to get one's complement
     */
    static int keyConverter(int numberOfBits);
    /*
     * Convert Number to two's complement
     */
    static int twosComplement(int number);
};


#endif
