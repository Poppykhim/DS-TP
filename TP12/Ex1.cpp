#include <iostream>
using namespace std;

const int SIZE = 20;
int ht[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++) {
        ht[i] = 0;
    }
}

int hashFunction (int value) {
    return value % SIZE;
}

void insertData (int value) {
    int index = hashFunction(value);
    ht[index] = value;
}

void displayHT() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t-->";
        cout << ht[i] << endl;
    }
}

int main () {

    initialize();
    
    insertData(50);
    insertData(700);
    insertData(76);
    insertData(85);
    insertData(92);
    insertData(73);
    insertData(101);

    displayHT();

    return 0;
}