#include <bits/stdc++.h>
#include "headers/InputParser.h"
#include "headers/Calculator.h"
#include "headers/PassOne.h"
#include "headers/PassTwo.h"
using namespace std;
int main() {
    // 1 1 0
    // 0 0 1
    // 0 1 0
    cout << Calculator::fromDecToHex(4 - 10) << endl;
    SicXeInstructions instructions;
    InputParser inputParser(instructions.getInstructions());
    PassOne passOne(inputParser.getLines(), inputParser.getStartLocation());
    PassTwo passTwo(inputParser.getLines(), passOne.getSymbolTable());
    return 0;
}
