//
// Created by adham
//

#ifndef SYSPROJECT_SICXEINSTRUCTIONS_H
#define SYSPROJECT_SICXEINSTRUCTIONS_H
#include <bits/stdc++.h>

#include "Instruction.h"

class SicXeInstructions {
private:
    string fileName;
    vector<Instruction> instructions;

    void readInstructions() {
        fstream file;
        string word;
        file.open(this->fileName, ios::in);
        if (file.fail()) {
            cout << "Failed To open instruction file, Please Check The Path Carefully" << endl;
            return;
        }
        while (file >> word) {
            Instruction line;
            line.name = word;
            file >> word;
            line.format = word[0] - '0';
            file >> word;
            line.opCode = word;
            this->instructions.push_back(line);
        }
        file.close();
    }

public:
    SicXeInstructions();

    /*
        Read From Instruction.txt file
        @return vector<Instructions>
    */
    vector<Instruction> getInstructions();

    /*
        get type of operand imm, indirect, simple
        @return 1 if Immidate SicXe
        @return 2 if Indirect SicXe
        @return 3 if Simple SicXe
    */
    int getInstructionType(string operand);

    /*
        check if the operand is indexed or not
        @return true if indexed otherwise false
    */
    bool isIndexed(string operand);

    /*
        check if instruction is format four or not
        @return true if format four otherwise false
    */
    bool isFormatFour(string opernad);

    /*
        @return Instruction format
    */

    int getInstructionFormat(string name);



};

#endif
