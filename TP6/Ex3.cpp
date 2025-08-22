#include <iostream>
using namespace std;

struct Element {
    string desciption;
    int priority_level;
    Element *next;
};

struct List {
    int n;
    Element *head;
    Element *tail;
};

List *createList(){
    List *ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void add_end(List *ls, string desciption, int priority_level){
    Element *e = new Element;
    e->desciption = desciption;
    e->priority_level = priority_level;
    e->next = nullptr;
    if(ls->n == 0){
        ls->head = e;
    } else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}

void display(List *ls){
    Element *temp = ls->head;
    while(temp != nullptr){
        cout << "Desciption: " << temp->desciption << endl;
        cout << "Priority level: " << temp->priority_level << endl;
        temp = temp->next;
    }
    cout << endl;
}

void deleteBeg(List *ls){
    if(ls->n == 0) return;

    Element *temp = ls->head;
    ls->head = ls->head->next;
    delete temp;
    if(ls->n == 1){
        ls->tail = nullptr;
    }
    ls->n--;
}

int main(){

    List *myList = createList();

    add_end(myList, "Hello", 3);
    add_end(myList, "hi", 5);
    add_end(myList, "hey", 1);
    add_end(myList, "bye", 2);
    add_end(myList, "good", 4);

    cout << "List: " << endl;
    display(myList);

    deleteBeg(myList);

    cout << "List After Delete: " << endl;
    display(myList);

    return 0;
}