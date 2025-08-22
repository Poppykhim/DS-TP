<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-4

Due Date: July 22, 2025 (11:59 AM)

</p>
<br/>

# Stack hold integer as element

## stack.cpp

```C++
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

```

## stack.h

```C++
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

```

# stack hold Character as element

## stackChar.cpp

```C++
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
```

## stackChar.h

```C++
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
```

# Exercise 1

Write a C++ program to implement a stack data structure using an array to store integer numbers. Write
functions for: push(), pop(), peek(), isEmpty(), isFull(), displayStack(). Test the implementation by pushing
and popping several elements.

## Source Code

```C++
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

```

## Output

```C++
Stack contents: 3 2 1
Top element popped: 3
Stack as string: result
```

# Exercise 2

Write a C++ program to implement a stack data structure using a singly linked list to store integer numbers
with the following operations: push(), pop(), peek(), isEmpty(), and function to count and return the
number of elements in the stack, and display function to print all elements in the stack from top to bottom.

## Source Code

```C++
#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack* s = createStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    pop(s);
    push(s,4);

    if (!isEmpty(s)){
        cout << "Number elements of this stack is:" << getSize(s) << endl;
    }
    cout << endl;
    cout << "Nummber in this stack:";
    display(s);
}
```

## Output:

```C++
Number elements of this stack is:3

Nummber in this stack:4 2 1
```

# Exercise 3

Write a program to ask a piece of text from a user. Display the text in a reverse order using stack.
Hint: Push each character in the text into stack. Display stack.

## Source Code:

```C++
#include <iostream>
#include "stackChar.h"
using namespace std;

int main(){
    string txt;
    Stack* s = createStack();
    cout << "Input a text:";
    cin >> txt;

    for (char c: txt){
        push(s, c);
    }
    cout << endl;

    cout << "Stack from top to bottom:";
    display(s);
}
```

## Output:

```C++
Input a text:Hello

Stack from top to bottom:o l l e H
```

# Exercise 4

Write a program to get a number from a user. Use stack to store that number as the binary number
representation in the stack. Finally, display the binary representation from the stack.  
Hint: Divide the integer by 2 then store the remainder in stack. Finally, display data in stack.

## Source Code:

```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    Stack* s = createStack();
    int number;
    cout << "Enter a number:";
    cin >> number;
    intToBinary(s, number);
    display(s);
    return 0;
}
```

## Output:

```C++
Enter a number:10
1 0 1 0

Enter a number:2
1 0
```

# Exercise 5

A letter means push and an asterisk means pop in the following sequence. Give the sequence of values
returned by the pop operations (display top data in queue then delete it) when this sequence of operations
is performed on an initially empty LIFO stack.
E A S _ Y _ Q U E \* \* _ S T _ \* _ I O _ N \* \* \*

## Source Code:

```C++
#include <iostream>
#include "stackChar.h"
using namespace std;


int main() {
    Stack *s = createStack();

    char operations[] = {
        'E', 'A', 'S', '*', 'Y', '*', 'Q', 'U', 'E', '*', '*', '*',
        'S', 'T', '*', '*', '*', 'I', 'O', '*', 'N', '*', '*', '*'
    };

    int size = sizeof(operations) / sizeof(operations[0]);

    cout << "Popped sequence: ";
    for (int i = 0; i < size; i++) {
        if (operations[i] == '*') {
            char popped = pop(s);
            if (popped != '\0')
                cout << popped << " ";
        } else {
            push(s, operations[i]);
        }
    }

    while (!isEmpty(s)) {
        pop(s);
    }
    delete s;

    cout << endl;
    return 0;
}

```

## Output:

```C++
Popped sequence: S Y E U Q T S A O N I E
```

# Exercise 6

Write a program that reads a piece of delimiter symbols containing parentheses, braces and/or curly braces.
The program determines whether its parentheses, braces, and curly braces are "balanced". The program
can be done using stack data structure.
Hint: Process each character of the input.

    • When a character is left delimiter, push it to stack.
    • When a character is right delimiter, pop data from stack and check whether popped element matches
    right delimiter.
    • It is balance when all matching are true and stack is empty when all characters have been processed.

## Source Code

```C++
#include <iostream>
#include "stackChar.h"
using namespace std;
int main() {
    string input;

    do {
        cout << "Enter delimiters: ";
        getline(cin, input);

        if (isBalanced(input)) {
            cout << "Balanced!" << endl;
        } else {
            cout << "Not balanced!" << endl;
        }
    } while(true);

    return 0;
}
```

## Output:

```C++
Enter delimiters: ( ( { } ) )
Balanced!
Enter delimiters: { ( ) )
Not balanced!
Enter delimiters: ( ( ( ) } )
Not balanced!
Enter delimiters: [( )]
Balanced!
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3

```

```
