//
// Created by andre on 10/30/2021.
//

#include "ReversePolishNotationCalculator.h"

double ReversePolishNotationCalculator::evaluate(char operand){
    double *p = elements;
    double total = 0;
    //Using the stack get the top and then pop the element out
    //if pop is an operator
        //evaluate(operand)
    //if pop is a value
        //pop is value1
        //if pop is an operator
            //evaluate(operand)
        //else if pop is a value
            //this pop is value2
        //then return value1 operand value 2

    /**
    for (uint64_t i = 0; i < length; i++) {
        total += evaluate();
        if (p != &elements[capacity - 1]) {
            p++;
        } else {
            p = elements;
        }
    }**/
}