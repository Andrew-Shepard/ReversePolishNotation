//
// Created by andre on 10/30/2021.
//

#ifndef REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H
#define REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H

#include "Stack.h"
class ReversePolishNotationCalculator : public Stack<std::string> {
    bool isAnOperator(std::string character);
public:
    //inherit constructor
    using Stack<std::string>::Stack;
    double evaluate();
    double evaluate(std::string operation);
};


#endif //REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H
