#include <iostream>
#include "stack.h"
int main() {
    Stack<int> stack(20);
    for(int i = 0; i < 20; i++){
        stack.push(i);
    }

    stack.printStack();
}
