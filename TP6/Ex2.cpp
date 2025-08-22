#include <iostream>
using namespace std;

struct Element {
    string title;
    int isbn;
    double price;
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

void add_beg(List *ls, string title, int isbn, double price){
    Element *newElement = new Element;
    newElement->title = title;
    newElement->isbn = isbn;
    newElement->price = price;
    newElement->next = ls->head;
    ls->head = newElement;
    if(ls->n == 0){
        ls->tail = newElement;
    }
    ls->n++;
}

void add_end(List *ls, string title, int isbn, double price){
    Element *newElement = new Element;
    newElement->title = title;
    newElement->isbn = isbn;
    newElement->price = price;
    newElement->next = nullptr;
    if(ls->n == 0){
        ls->head = newElement;
    } else {
        ls->tail->next = newElement;
    }
    ls->tail = newElement;
    ls->n++;
}

void combine(List* list1, List *list2){
    if(list2->n == 0){
        return;
    }
    if(list1->n == 0){
        list1->head = list2->head;
        list1->tail = list2->tail;
        list1->n = list2->n;
    } else {
        list1->tail->next = list2->head;
        list1->tail = list2->tail;
        list1->n += list2->n;
    }
}

void display(List *ls){
    Element *temp = ls->head;
    while(temp != nullptr){
        cout << "Title: " << temp->title << endl;
        cout << "ISBN: " << temp->isbn << endl;
        cout << "Price: " << temp->price << "\n\n";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    List *list1 = createList();
    List *list2 = createList();

    add_beg(list1, "C++", 111, 19.99);
    add_beg(list1, "Java", 222, 39.99);
    add_beg(list1, "JavaScript", 333, 19.99);

    cout << "Add Beg:\n";
    display(list1);

    add_end(list2, "C#", 444, 88.99);
    add_end(list2, "Ruby", 555, 49.99);
    add_end(list2, "HTML", 666, 10.99);

    cout << "Add End:\n";
    display(list2);

    combine(list1, list2);
    cout << "After Combination:\n";
    display(list1);

    return 0;
}