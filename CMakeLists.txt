cmake_minimum_required(VERSION 3.21)
project(SysProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(SysProject main.cpp Calculator.cpp headers/Calculator.h InputParser.cpp headers/InputParser.h Line.cpp headers/Line.h Instruction.cpp headers/Instruction.h SicXeInstructions.cpp headers/SicXeInstructions.h Formats/FormatOne.cpp Formats/headers/FormatOne.h Formats/FormatTwo.cpp Formats/headers/FormatTwo.h Formats/FormatThree.cpp Formats/headers/FormatThree.h Formats/FormatFour.cpp Formats/headers/FormatFour.h Formats/FormatFive.cpp Formats/headers/FormatFive.h Formats/FormatSix.cpp Formats/headers/FormatSix.h PassOne.cpp headers/PassOne.h SymbolTableLine.cpp headers/SymbolTableLine.h PassTwo.cpp headers/PassTwo.h Formats/headers/IFormat.h ObjCode.cpp ObjCode.h)
