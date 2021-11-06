//
// Created by andre on 11/6/2021.
//
#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ReversePolishNotationCalculator.h"
bool isAnOperator(std::string entry) { // determines if a string is an operator
    char character = entry[0];
    switch (character) {
        case '+': return true;
        case '-': return true;
        case '/': return true;
        case 'x': return true;
        default: return false;
    }
}
int precedence(char c){ //Determines the precedence of an operator
    switch (c){
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
    }
    return -1;
}
int main(int argc, char** argv)
{
    ReversePolishNotationCalculator reversePolishNotationCalculator(1000);
    std::stringstream arguments;
    std::string s;
    Stack<std::string> operations(1000);
    //ignore the path call and take the arguments
    for (int i = 1; i < argc; ++i){
        arguments << argv[i];
        s = arguments.str();
        //if it is an operator
        if(isAnOperator(s)){
            //if the stack is empty push the to the operator stack
            if (operations.getLength() == 0){
                operations.push(s);
            } else{
                //compare the precedence of the operators
                std::string top_operation = *operations.top();
                if (precedence(s[0]) <= precedence(top_operation[0])){
                    // if the new operator exceeds the precedence of the former top then add to the rpn
                    reversePolishNotationCalculator.push(top_operation);
                    operations.pop();
                    operations.push(s);
                } else {
                    //otherwise add it to the stack
                    operations.push(s);
                }
            }
        } else {
            //push operands to the calculator
            reversePolishNotationCalculator.push(s);
        }
        arguments.str("");
        arguments.clear();
    }
    while (operations.getLength() > 0){
        //append the remaining operators to the rpnstack
        reversePolishNotationCalculator.push(*operations.top());
        operations.pop();
    }

    std::cout << reversePolishNotationCalculator.evaluate() << std::endl;

    return 0;
}