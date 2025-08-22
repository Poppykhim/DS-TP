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