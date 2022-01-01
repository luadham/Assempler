//
// Created by adham on ٣٠‏/١٢‏/٢٠٢١.
//

#ifndef SYSPROJECT_INPUTPARSER_H
#define SYSPROJECT_INPUTPARSER_H
#include "Instruction.h"
#include "Line.h"
#include "Calculator.h"
#include "SicXeInstructions.h"

class InputParser {
private:
    int startProgram;
    string inputFile;
    Calculator calclator;
    vector<Instruction> instructions;
    vector<Line> inputLines;
    void error(string name, int line) {
        cerr << "Error in Line < " << line << " > " << name << endl;
    }

    bool isExistLable(string label) {
        for (int i = 0; i < inputLines.size(); i++) {
            if (label == inputLines[i].label) {
                error("Exist Line", i + 1);
                return true;
            }
        }
        return false;
    }

    bool isInstruction(string instruction) {
        for (int i = 0; i < instructions.size(); i++) {
            if (instruction == instructions[i].name) return true;
        }
        return false;
    }

    Instruction getInstructionData(string instructionName) {
        Instruction instruction;
        instructionName = convertToLower(instructionName);
        instruction.name = instructionName;
        for (int i = 0; i < instructions.size(); i++) {
            if (instructionName == instructions[i].name) {
                instruction.opCode = instructions[i].opCode;
                instruction.format = instructions[i].format;
                return instruction;
            }
        }
        return instruction;
    }

    bool validLine(Line line) {
        char firstDigit = line.instruction.name[0];
        if (firstDigit == '+' || firstDigit == '$' || firstDigit == '&') return true;
        return isInstruction(line.instruction.name)
               || (line.label != "-" && !isExistLable(line.label));
    }

    string convertToLower(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            res += tolower(s[i]);
        }
        return res;
    }

    void readInput() {
        fstream file;
        string word;
        file.open(inputFile);
        if (file.fail()) {
            cout << "Failed To Open Input File, Please Check Again";
            return;
        }
        int lineNumber = 2;
        while (file >> word) {
            Line line;
            line.label = convertToLower(word);
            file >> word;
            line.instruction = getInstructionData(word);
            file >> word;
            line.operand = convertToLower(word);
            if (line.instruction.name == "start") {
                this->startProgram = calclator.fromHexToDecimal(line.operand);
                continue;
            } else if (line.instruction.name == "end") {
                continue;
            }
            else if (validLine(line))
                inputLines.push_back(line);
            else {
                error("Check Line Again !", lineNumber);
                return;
            }
            lineNumber++;
        }
        file.close();
    }

public:
    InputParser(vector<Instruction> instructions);
    vector<Line> getLines();
    int getStartLocation();

};


#endif
