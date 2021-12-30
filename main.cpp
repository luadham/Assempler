#include <bits/stdc++.h>
#include "headers/InputParser.h"
#include "headers/PassOne.h"
using namespace std;
int main() {
    /*
     * 1 - Input
     * 2 - Symbol Table
     */
    SicXeInstructions instructions;
    InputParser inputParser(instructions.getInstructions());
    PassOne passOne(inputParser.getLines(), inputParser.getStartLocation());

    return 0;
}
