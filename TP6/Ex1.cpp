#include <iostream>
using namespace std;

struct Element {
    int id;
    string name;
    double score;
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

void add_end(List *ls, int id, string name, double score){
    Element *newElement = new Element;
    newElement->id = id;
    newElement->name = name;
    newElement->score = score;
    newElement->next = nullptr;
    if(ls->n == 0){
        ls->head = newElement;
    } else {
        ls->tail->next = newElement;
    }
    ls->tail = newElement;
    ls->n++;
}

void deleteEnd(List *ls){
    if(ls->n == 0) return;
    if(ls->n == 1) {
        delete ls->tail;
        ls->head = ls->tail = nullptr;
    } else {
        Element *newElement = ls->head;
        while(newElement->next != ls->tail){
            newElement = newElement->next;
        }
        newElement->next = nullptr;
        delete ls->tail;
        ls->tail = newElement;
    }
    ls->n--;
}

void display(List *ls){
    Element *temp = ls->head;
    cout << "\nStudent List: \n";
    while(temp != nullptr){
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Score: " << temp->score << "\n\n";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    List *myList = createList();

    add_end(myList, 111, "Davin", 90.99);
    add_end(myList, 222, "Naraka", 80);
    add_end(myList, 333, "Scar", 87.99);
    add_end(myList, 444, "Alucard", 85.99);

    cout << "Before Delete: ";
    display(myList);
    cout << "After Delete: ";
    deleteEnd(myList);
    display(myList);

    return 0;
}