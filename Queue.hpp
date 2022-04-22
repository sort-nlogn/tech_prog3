#pragma once
#include "List.hpp"

class Queue: public List{
    private:
        struct Node{
            Node(int val);
            Node *next;
            int data;
        };

        Node *head, *tail;

    public:
        Queue();
        ~Queue();
        void dealloc_nodes() override;
        void insert(int data) override;
        int remove() override;
        void display() override;
};