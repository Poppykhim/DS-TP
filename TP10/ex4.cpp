#include<iostream>
using namespace std;

struct Element {
    int num;
    Element* next;
};

struct List {
    Element* head;
    Element* tail;
    int n;
};

List* createList() {
    List* ls = new List;
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n = 0;
    return ls;
}
void add(List *ls, int num){
    Element *e = new Element;
    e->num = num;
    e->next = ls->head;
    ls->head = e;
    if (ls->tail == nullptr) {
        ls->tail = e;
    }
    ls->n++;
}

void Swap(int *a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(List* ls){
    if(ls->n <2) return;
    bool swapped;
    Element *end = nullptr;
    do {
        swapped = false;
        Element* current = ls->head;
        while (current->next != end){
            if (current->num > current->next->num) {
                swap(current->num, current->next->num);
                swapped = true;
            }
            current = current->next;
        }
        end = current;
    } while (swapped);
}

void display(List* ls) {
    Element* current = ls->head;
    while (current != nullptr) {
        cout << current->num << " ";
        current = current->next;
    }
    cout << endl;
}



int main(){
    List* myList = createList();
    add(myList, 5);
    add(myList, 3);
    add(myList, 8);
    add(myList, 1);
    add(myList, 4);
    cout << "Before sorting:" << endl;
    display(myList);
    bubbleSort(myList);
    cout << "After sorting:" << endl;
    display(myList);

    return 0;
}