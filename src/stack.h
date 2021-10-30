//
// Created by andre on 10/29/2021.
//

#ifndef REVERSEPOLISHNOTATION_STACK_H
#define REVERSEPOLISHNOTATION_STACK_H
#include <iostream>
template<typename T>

#define CAPACITY 1000

class Stack {
    T *stack = nullptr;
    T *first = nullptr;
    T *elements = nullptr;
    uint64_t length = 0;
    uint64_t capacity = 0;
public:
       Stack(uint64_t capacity){
            this->capacity = capacity;
            stack = new T[capacity];
            elements = stack;
            first = stack;
       }

       void push(T data) {
           if (length == capacity){
               return;
           }

           length++;

           *first = data;

           if (first != &elements[capacity - 1]) {
               first++;
           }else{
               first = stack;
           }


       }

       void pop(){
           //Moves the focused element to the next in the stack
           if (length == 0){
               return;
           }
           length--;
           if(first != elements){
               first--;
           }
           else{
               first = stack;
           }
       }

       T top(){
           return first;
       }

       void clear() {
            first = stack;
            length = 0;
       }

       uint64_t getLength() {
           return length;
       }

       void printStack() {
            T *p = elements;
            for (uint64_t i = 0; i < length; i++) {
                std::cout << *p << std::endl;
                if (p != &elements[capacity - 1]) {
                    p++;
                } else {
                    p = elements;
                }
            }
       }

       ~Stack() {
           if (stack)
               delete[] stack;
       }

};
#endif //REVERSEPOLISHNOTATION_STACK_H
