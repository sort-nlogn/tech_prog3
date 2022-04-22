#include "Stack.hpp"
#include <iostream>

Stack::Stack(){
    capacity = 1000;
    data = new int[capacity];
    size = 0;
}

void Stack::dealloc_nodes(){
    delete data;
    size = 0;
}

Stack::~Stack(){
    dealloc_nodes();
}

void Stack::insert(int val){
    if(size == capacity)
        throw std::runtime_error("Stack overflow!");

    data[size++] = val;
}

int Stack::remove(){
    if(size == 0)
        throw std::runtime_error("Stack underflow!");

    return data[--size]; 
}

void Stack::display(){
    for(int i = 0; i < size; i++){
        printf("%d ", data[i]);
    }
    printf("<-top\n");
}