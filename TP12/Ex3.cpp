#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;
string ht[SIZE];                

void initialize() {
    for (int i = 0; i < SIZE; i++) ht[i] = "";
}

int hashFunction(const string& s) {
    int sum = 0;
    for (char c : s) sum += static_cast<unsigned char>(c); 
    return sum % SIZE;
}

void insertData (const string& name) {
    int index = hashFunction(name);
    ht[index] = name;
}

bool searchData(const string& name) {
    int index = hashFunction(name);
    if (ht[index] == name) {
         cout << name << " is contained in position " << index << endl;
        return true;
    }
    cout << "It is not found" << endl;
    return false;
}

void deleteData(const string& name) {
    int index = hashFunction(name);
    if (ht[index] == name) {
        ht[index] = "";                       
        cout << name << " is removed successfully\n";
    } else {
        cout << "Failed to delete since " << name << " does not exist\n";
    }
}

void displayHT() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index: " << i << ", String: ";
        if (ht[i].empty()) {
            cout << "-\n";
        } else {
            cout << ht[i] << '\n';
        } 
    }
}

int main() {

    initialize();

    insertData("Bob");

    for (int i = 1; i <= 3; i++) {
        cout << "Enter name #" << i << ": ";
        string name;
        getline(cin >> ws, name);          
        insertData(name);
    }

    cout << endl;
    displayHT();

    cout << endl;
    searchData("Bob");

    cout << endl;
    deleteData("Bob");

    cout << endl;
    displayHT();

    return 0;
}
