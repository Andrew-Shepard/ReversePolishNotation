//
// Created by andre on 10/30/2021.
//

#ifndef REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H
#define REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H

#include "Stack.h"
class ReversePolishNotationCalculator : protected Stack<double> {
private:

public:
    //inherit constructor
    using Stack<double>::Stack;
    double evaluate(char operand);
};


#endif //REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H
