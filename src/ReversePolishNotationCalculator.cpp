//
// Created by andre on 10/30/2021.
//

#include "ReversePolishNotationCalculator.h"
bool ReversePolishNotationCalculator::isAnOperator(std::string entry) {
    char character = entry[0];
    switch (character) {
        case '+':
            return true;
        case '-':
            return true;
        case '/':
            return true;
        case 'x':
            return true;
        default:
            return false;
    }
}

double ReversePolishNotationCalculator::evaluate(){
    std::string top_value = *top();
    if (isAnOperator(top_value)){
        pop();
        return evaluate(top_value);
    }
    return -1;
}

double ReversePolishNotationCalculator::evaluate(std::string operation){
    double operand_1 = 0;
    std::string operand_1_string = "";
    double operand_2 = 0;
    std::string operand_2_string = "";
    //view the top element in the stack

    if (isAnOperator(*top())){
        std::string found_operation = *top();
        pop();
        operand_1 = evaluate(found_operation);
    } else if (length > 0){
        operand_1_string = *top();
        operand_1 = std::stod(operand_1_string);
        pop();
    }

    if (isAnOperator(*top())) {
        std::string found_operation = *top();
        pop();
        operand_2 = evaluate(found_operation);
    } else if (length > 0){
        operand_2_string = *top();
        operand_2 = std::stod(operand_2_string);
        pop();
    }

    switch((char)operation[0]){
        case '+':
            return operand_2 + operand_1;
        case '-':
            return operand_2 - operand_1;
        case '/':
            return operand_2 / operand_1;
        case 'x':
            return operand_2 * operand_1;
        default:
            return -1;
    }
}