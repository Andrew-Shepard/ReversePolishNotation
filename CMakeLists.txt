cmake_minimum_required(VERSION 3.20)
project(ReversePolishNotation)

set(CMAKE_CXX_STANDARD 17)

add_executable(ReversePolishNotation src/main.cpp src/Stack.h src/ReversePolishNotationCalculator.cpp src/ReversePolishNotationCalculator.h)
add_executable(InfixNotation src/infix.cpp src/Stack.h src/ReversePolishNotationCalculator.cpp src/ReversePolishNotationCalculator.h)
