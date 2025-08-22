// main.cpp
#include <iostream>
#include "stack.h"

int main() {
    Stack* s = createStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);

    std::cout << "Stack contents: ";
    display(s);

    std::cout << "Top element popped: " << pop(s) << std::endl;
    return 0;
}
