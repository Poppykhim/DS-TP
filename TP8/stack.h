// Stack.h
#ifndef STACK_H
#define STACK_H

#include <string>

struct Element {
    int data;
    Element *next;
};

struct Stack {
    int n;
    Element *top;
};

Stack* createStack();
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s);
void display(Stack* s);
std::string stackToString(Stack* s);
int getSize(Stack *s);
void intToBinary(Stack *s, int num);

#endif // STACK_H
