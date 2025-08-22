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