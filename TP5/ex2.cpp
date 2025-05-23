#include <iostream>
#include <string>
using namespace std;

struct Element {
    string name;
    Element* next;
};

struct List {
    Element* head;
};

List* createList() {
    List* ls = new List;
    ls->head = nullptr;
    return ls;
}

void addPerson(List* ls, string name) {
    Element* e = new Element;
    e->name = name;
    e->next = ls->head;
    ls->head = e;
}

void display(List* ls) {
    Element* current = ls->head;
    int count = 1;
    while (current != nullptr) {
        cout << count <<". "<<current->name << endl;
        current = current->next;
        count++;
    }
}

int main() {
    List* myList = createList();

    string friends[10] = {"Preah Sovath", "Chhay Virak yuth", "Ouk SokunKanha", "Prom Samnang", "Chan Vathanaka","Jek Ma", "Pu Tin", "Pu Jork", "Vanda", "G-Devith"};

    for (int i = 0; i < 10; i++) {
        addPerson(myList, friends[i]);
    }

    cout << "Names in the list:" << endl;
    display(myList);

    return 0;
}
