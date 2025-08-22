#include <iostream>
using namespace std;

const int SIZE = 7;
int ht[SIZE]; 

int hashFunction(int value) { return value % SIZE; }

void initialize() {
    for (int i = 0; i < SIZE; ++i) ht[i] = 0;
}

void insertData (int value) {
    int index = hashFunction(value);
    ht[index] = value;
}

void displayHT() {
    for (int i = 0; i < SIZE; ++i) {
        cout << "Index: " << i << ", Data: " << ht[i] << '\n';
    }
}

bool searchData(int value) {
    int index = hashFunction(value);
    if (ht[index] == value) {
        cout << value << " is contained in position " << index << endl;
        return true;
    }
    cout << "It is not found" << endl;
    return false;
}

void deleteData(int value) {
    int index = hashFunction(value);
    if (ht[index] == value) {
        ht[index] = 0;  
        cout << value << " is removed successfully\n";
    } else {
        cout << "Failed to delete since " << value << " does not exist\n";
    } 
}

int main() {
    initialize();

    insertData(2);
    insertData(4);
    insertData(7);
    insertData(10);
    displayHT();
    cout << "\n";

    searchData(7);

    deleteData(10);

    displayHT();

    return 0;
}
