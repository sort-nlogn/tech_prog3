#include "List.hpp"
#include <iostream>

List::List(): head(nullptr), tail(nullptr), size(0){

}
List::Node::Node(int val): next(nullptr){
    data = val;
}


void List::dealloc_nodes(){
    Node *curr = head, *nxt = nullptr;
    while(curr != nullptr){
        nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    head = nullptr, tail = nullptr;
    size = 0;
}

List::~List(){
    dealloc_nodes();
}

void List::insert(int data){
    int idx;
    printf("Index to insert: ");
    scanf("%d", &idx);

    if(idx < 0 || idx > size){
        throw std::runtime_error("Incorrect index!");

    }

    Node *n = new Node(data);
    size++;

    if(tail == nullptr){
        head = n;
        tail = n;
        return;
    }

    Node *curr = head, *prev = nullptr;
    for(int i = 0; i < idx; i++){
        prev = curr;
        curr = curr->next;
    }

    n->next = curr;

    if(prev == nullptr){
        head = n;
    }
    else{
        prev->next = n;
    }

    if(n->next == nullptr)
        tail = n;
}

int List::remove(){
    int idx;
    printf("Index to insert: ");
    scanf("%d\n", &idx);

    if(idx < 0 && idx >= size)
        throw std::runtime_error("Incorrect index!");


    size--;

    if(head == tail){
        int to_ret = head->data;
        head = nullptr;
        tail = nullptr;
        return to_ret;
    }

    Node *prev = nullptr, *curr = head;

    for(int i = 0; i < idx; i++){
        prev = curr;
        curr = curr->next;
    }

    if(prev == nullptr){
        int to_ret = curr->data;
        head = curr->next;
        delete curr;
        return to_ret;
    }

    int to_ret = curr->data;
    prev->next = curr->next;
    delete curr;
    if(prev->next ==nullptr) 
        tail = prev;
    return to_ret;

}

void List::display(){
    std::cout << "head";
    List::Node *curr = head;
    while(curr != nullptr){
        std::cout << "->" << curr->data;
        curr = curr->next;
    }
    std::cout << std::endl;
}
