cmake_minimum_required(VERSION 3.21)
project(SysProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(SysProject main.cpp Calculator.cpp headers/Calculator.h InputParser.cpp headers/InputParser.h Line.cpp headers/Line.h Instruction.cpp headers/Instruction.h SicXeInstructions.cpp headers/SicXeInstructions.h Formats/FormatOne.cpp Formats/FormatOne.h Formats/FormatTwo.cpp Formats/FormatTwo.h Formats/FormatThree.cpp Formats/FormatThree.h Formats/FormatFour.cpp Formats/FormatFour.h Formats/FormatFive.cpp Formats/FormatFive.h Formats/FormatSix.cpp Formats/FormatSix.h PassOne.cpp headers/PassOne.h SymbolTableLine.cpp headers/SymbolTableLine.h)
