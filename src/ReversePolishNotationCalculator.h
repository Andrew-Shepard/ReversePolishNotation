//
// Created by andre on 10/30/2021.
//

#ifndef REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H
#define REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H

#include "Stack.h"
class ReversePolishNotationCalculator : public Stack<char> {
    bool isAnOperator(char character);
public:
    //inherit constructor
    using Stack<char>::Stack;
    double evaluate();
    double evaluate(char operation);

};


#endif //REVERSEPOLISHNOTATION_REVERSEPOLISHNOTATIONCALCULATOR_H
