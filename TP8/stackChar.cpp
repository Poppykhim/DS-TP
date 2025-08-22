// Stack.cpp
#include "stackChar.h"
#include <iostream>
using namespace std;

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

void push(Stack* s, char data) {
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

char pop(Stack* s) {
    if (isEmpty(s)) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return '\0';
    }
    Element* e = s->top;
    s->top = e->next;
    char value = e->data;
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

int getSize(Stack* s){
    return s->n;
}

bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(const string &input) {
    Stack *s = createStack();

    for (char ch : input) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(s, ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(s);
            if (!isMatch(top, ch)) {
                delete s;
                return false;
            }
        }
    }

    bool balanced = isEmpty(s);
    delete s;
    return balanced;
}