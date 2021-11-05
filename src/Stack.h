//
// Created by andre on 10/29/2021.
//

#ifndef REVERSEPOLISHNOTATION_STACK_H
#define REVERSEPOLISHNOTATION_STACK_H
#include <iostream>
template<typename T>

class Stack {
protected:
    T *stack = nullptr;
    T *first = nullptr;
    T *elements = nullptr;
    uint64_t length = 0;
    size_t capacity = 0;
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
           return *first;
       }

       void clear() {
            first = stack;
            length = 0;
       }

       uint64_t getLength() {
           return length;
       }

       void setCapacity(size_t capacity){
            //create a new array of size changed capacity
            T* new_stack = new T[capacity];
            //loop through the current array and copy each element
            for(int i = 0; i<this->capacity; i++){
                //dont exceed the new size
                if (i <= capacity){
                    new_stack[i] = elements[i];
                }
            }
            // delete the contents of the elements pointer
            delete[] stack;
            // point to the new array
            stack = new_stack;
            //delete the temporary pointer
            delete new_stack;
            new_stack = nullptr;
            // set the objects capacity to the parameterized capacity
            elements = stack;
            first = stack;
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
