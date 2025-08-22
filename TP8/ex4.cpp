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