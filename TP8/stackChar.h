// Stack.h
#ifndef STACK_H
#define STACK_H

#include <string>

struct Element {
    char data;
    Element *next;
};

struct Stack {
    int n;
    Element *top;
};

Stack* createStack();
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, char data);
char pop(Stack* s);
void display(Stack* s);
std::string stackToString(Stack* s);
int getSize(Stack *s);
bool isMatch(char open, char close);
bool isBalanced(const std::string &input);

#endif // STACK_H
