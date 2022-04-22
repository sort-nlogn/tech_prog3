#pragma once

class List{
    private:
        struct Node{
            Node(int val);
            Node *next;
            int data;
        };

        Node *head, *tail;

        int size;

    public:
        List();
        ~List();
        virtual void dealloc_nodes();
        virtual void insert(int data);
        virtual int remove();
        virtual void display();
};