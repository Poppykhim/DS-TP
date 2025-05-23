#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct List {
    int n;
    Element *head;
    Element *tail;
}; 

List *createEmptyList() {
    List *ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void add_end(List *ls, int data) {
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;

    if (ls->n == 0) {
        ls->head = e;
    } else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}

void display(List *ls) {
    Element *tmp = ls->head;
    cout << "All data in the list are: ";
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int sum(List *ls) {
    int total = 0;
    Element *e = ls->head;
    while (e != nullptr) {
        total += e->data;
        e = e->next;
    }
    return total;
}

int main() {
    cout << "\t*** A program to store number as many as possible: ***\n";

    List *myList = createEmptyList();
    int input;
    int zeroCount = 0;

    while (true) {
        cout << "Enter a number: ";
        cin >> input;
        if (input == 0) {
            zeroCount++;
            if (zeroCount == 1) {
                cout << "\tYou have entered the number 0 once. Only 1 more left. We will quit the program.\n";
            } else if (zeroCount == 2) {
                cout << "\tYou have entered the number 0 twice so far. The program is going to stop now.\n";
                break;
            }
        } else {
            add_end(myList, input);
        }
    }
    display(myList);
    cout << "Summation of all numbers is: " << sum(myList) << endl;

    return 0;
}