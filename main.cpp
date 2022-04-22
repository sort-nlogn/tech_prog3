#include <iostream>
#include "List.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

using namespace std;

int get_int(){
    int ans;
    printf("Value to ensert: ");
    scanf("%d", &ans);
    return ans;
}

char select_type(){
    printf("Select class\n1 --- List\n2 --- Stack\n3 --- Queue\n");
    printf(">>");
    return getchar();
}

void display_help(){
    printf("1 --- Insert element\n2 --- Remove element\n3 --- Display\n\
4 --- Exit programm\n\
5 --- Display help\n");
}

template<typename T>
char execute_commands(){
    T l;
    display_help();
    while(1){
        char c = getchar();
        if(c == '\n')
            printf(">>");
        if(c == '1'){
            l.insert(get_int());
        }else if(c == '2'){
            printf("Removed value: %d\n",  l.remove());
        }else if(c == '3'){
            l.display();
            printf("\n");
        }else if(c == '4'){
            l.dealloc_nodes();
            return 0;
        }else if(c == '5'){
            display_help();
        }
    }
    return 0;
}

int main(){
    char type = select_type();
    while(type){
        if(type == '1')
            type = execute_commands<List>();
        else if(type == '2')
            type = execute_commands<Stack>();
        else if(type == '3')
            type = execute_commands<Queue>();
        else{
            printf("No such type. Try again\n");
            getchar();
            type = select_type();
        }
    }
    return 0;
}