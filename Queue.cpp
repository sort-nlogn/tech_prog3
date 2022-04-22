#include "Queue.hpp"
#include <iostream>

Queue::Node::Node(int val): next(nullptr){
    data = val;
}

Queue::Queue(): head(nullptr), tail(nullptr){

}

void Queue::dealloc_nodes(){
    Node *curr = head, *nxt = nullptr;
    while(curr != nullptr){
        nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    head = nullptr, tail = nullptr;
}

Queue::~Queue(){
    dealloc_nodes();
}


void Queue::insert(int data){
    Node *n = new Node(data);
    if(tail == nullptr){
        head = n;
        tail = n;
    }else{
        tail->next = n;
        tail = n;
    }
}

int Queue::remove(){
    if(head == nullptr)
        throw std::runtime_error("Empty queue!");

    int ans = head->data;
    Node *new_head = head->next;
    delete head;
    head = new_head;
    if(new_head == nullptr)
        tail = nullptr; 
    return ans;
}

void Queue::display(){
    std::cout << "head";
    Queue::Node *curr = head;
    while(curr != nullptr){
        std::cout << "->" << curr->data;
        curr = curr->next;
    }
    std::cout << std::endl;
}