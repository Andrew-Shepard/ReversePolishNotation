//
// Created by andre on 11/6/2021.
//
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ReversePolishNotationCalculator.h"
int main(int argc, char** argv)
{
    ReversePolishNotationCalculator reversePolishNotationCalculator(1000);
    std::stringstream arguments;
    std::string s;
    //ignore the path call and take the arguments
    for (int i = 1; i < argc; ++i){
        arguments << argv[i];
        s = arguments.str();
        reversePolishNotationCalculator.push(s);
        arguments.str("");
        arguments.clear();
    }

    std::cout << reversePolishNotationCalculator.evaluate() << std::endl;

    return 0;
}