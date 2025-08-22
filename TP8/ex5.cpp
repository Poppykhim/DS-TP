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
