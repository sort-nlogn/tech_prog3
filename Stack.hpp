#pragma once
#include "List.hpp"

class Stack: public List{
    private:
        int *data; 
        int size;
        int capacity;

    public:
        Stack();
        ~Stack();
        void dealloc_nodes() override;
        void insert(int val) override;
        int remove() override;
        void display() override;
};