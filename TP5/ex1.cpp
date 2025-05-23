#include<iostream>
using namespace std;

struct CapitalElement {
    char data;
    CapitalElement *next;
};

struct LowerElement {
    char data;
    LowerElement *next;
};

struct List {
    int n;
    CapitalElement *capitalHead;
    CapitalElement *capitalTail;
    LowerElement *lowerHead;
    LowerElement *lowerTail;
};

List *createEmptyList() {
    List *ls = new List;
    ls->n = 0;
    ls->capitalHead = nullptr;
    ls->capitalTail = nullptr;
    ls->lowerHead = nullptr;
    ls->lowerTail = nullptr;
    return ls;
}

void addPerson(List *ls, char data) {
    if (isupper(data)) {
        CapitalElement *e = new CapitalElement;
        e->data = data;
        e->next = nullptr;

        if (ls->capitalHead == nullptr) {
            ls->capitalHead = e;
        } else {
            ls->capitalTail->next = e;
        }
        ls->capitalTail = e;
    } else {
        LowerElement *e = new LowerElement;
        e->data = data;
        e->next = nullptr;

        if (ls->lowerHead == nullptr) {
            ls->lowerHead = e;
        } else {
            ls->lowerTail->next = e;
        }
        ls->lowerTail = e;
    }
    ls->n++;
}

void display(List *ls) {
    CapitalElement *capitalPtr = ls->capitalHead;
    LowerElement *lowerPtr = ls->lowerHead;

    cout << "Capital letters: ";
    while (capitalPtr != nullptr) {
        cout << capitalPtr->data << " ";
        capitalPtr = capitalPtr->next;
    }
    cout << endl;

    cout << "Lowercase letters: ";
    while (lowerPtr != nullptr) {
        cout << lowerPtr->data << " ";
        lowerPtr = lowerPtr->next;
    }
    cout << endl;
}

int main(){
    cout << "\t*** A program to store letters: ***\n";
    List *myList = createEmptyList();
    for (char c = 'A'; c <= 'Z'; c++) {
        addPerson(myList, c);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        addPerson(myList, c);
    }
    display(myList);
    return 0;
}