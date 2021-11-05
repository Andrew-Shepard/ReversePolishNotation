#include <iostream>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ReversePolishNotationCalculator.h"
int main(int argc, char** argv)
{
    ReversePolishNotationCalculator reversePolishNotationCalculator(1000);
    std::cout << "You have entered " << argc
         << " arguments:" << "\n";
    std::stringstream arguments;
    //ignore the path call and take the arguments
    for (int i = 1; i < argc; ++i){
        arguments << argv[i];
    }

    std::string s = arguments.str();
    const char* p = s.c_str();

    for (int i = argc-1; i > 0; --i){
        reversePolishNotationCalculator.push(p[i]);
    }

    std::cout << reversePolishNotationCalculator.evaluate() << std::endl;

    return 0;
}
