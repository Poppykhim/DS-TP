// Stack.cpp
#include "stack.h"
#include <iostream>

const int MAX_SIZE = 100; 

Stack* createStack() {
    Stack* s = new Stack;
    s->n = 0;
    s->top = nullptr;
    return s;
}

bool isEmpty(Stack* s) {
    return s->n == 0;
}

bool isFull(Stack* s) {
    return s->n >= MAX_SIZE;
}

void push(Stack* s, int data) {
    if (isFull(s)) {
        std::cout << "Stack is full. Cannot push '" << data << "'." << std::endl;
        return;
    }
    Element* e = new Element;
    e->data = data;
    e->next = s->top;
    s->top = e;
    s->n++;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return '\0';
    }
    Element* e = s->top;
    s->top = e->next;
    int value = e->data;
    s->n--;
    delete e;
    return value;
}

void display(Stack* s) {
    Element* e = s->top;
    while (e != nullptr) {
        std::cout << e->data << " ";
        e = e->next;
    }
    std::cout << std::endl;
}

std::string stackToString(Stack* s) {
    Element* e = s->top;
    std::string result = "";
    while (e != nullptr) {
        result = e->data +" result";
        e = e->next;
    }
    return result;
}

int getSize(Stack* s){
    return s->n;
}

void intToBinary(Stack *s,int num)
{
    while (num!=0){
        int digit = num % 2;
        push(s, digit);
        num = num / 2;
    }
}
