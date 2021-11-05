//
// Created by andre on 10/30/2021.
//

#include "ReversePolishNotationCalculator.h"
bool ReversePolishNotationCalculator::isAnOperator(char character) {
    switch (character) {
        case '+':
            return true;
        case '-':
            return true;
        case '/':
            return true;
        case '*':
            return true;
        default:
            return false;
    }
}

double ReversePolishNotationCalculator::evaluate(){
    char32_t top_value = top();
    if (isAnOperator(top_value)){
        pop();
        return evaluate(top_value);
    }
    return -1;
}

double ReversePolishNotationCalculator::evaluate(char operation){
    double operand_1 = 0;
    std::string operand_1_string = "";
    double operand_2 = 0;
    std::string operand_2_string = "";
    //view the top element in the stack
    std::string top_string(1,top());
    //remove the whitespace
    while (top_string == " "){
        top_string.clear();
        pop();
        top_string.push_back(top());
    }

    if (isAnOperator(top())){
         operand_1 = evaluate(top());
    } else {
        while (top_string != " " || length > 0){
            operand_1_string.push_back(top());
        }
        operand_1 = std::stod(operand_1_string);
    }

    while (top_string == " "){
        top_string.clear();
        pop();
        top_string.push_back(top());
    }

    while (top_string != " " || length > 0){
        operand_2_string.push_back(top());
    }
    operand_2 = std::stod(operand_1_string);

    switch(operation){
        case '+':
            return operand_1 + operand_2;
        case '-':
            return operand_1 - operand_2;
        case '/':
            return operand_1 / operand_2;
        case '*':
            return operand_1 * operand_2;
        default:
            return -1;
    }
}