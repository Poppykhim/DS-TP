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