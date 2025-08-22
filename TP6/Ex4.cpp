#include <iostream>
using namespace std;

struct Element {
    string title;
    string artist;
    int duration;
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

void add_beg(List *ls, string title, string artist, int duration){
    Element *newElement = new Element;
    newElement->title = title;
    newElement->artist = artist;
    newElement->duration = duration;
    newElement->next = ls->head;
    ls->head = newElement;
    if(ls->n == 0){
        ls->head = newElement;
    }
    ls->n++;
}

void bubbleSort(List *ls){
    if(ls->n < 2) return;
    Element *ptr;
    Element *lastptr = nullptr;
    bool swapped;
    do{
        ptr = ls->head;
        swapped = false;
        while(ptr->next != lastptr){
            if(ptr->duration > ptr->next->duration){
                int temp = ptr->duration;
                ptr->duration = ptr->next->duration;
                ptr->next->duration = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        lastptr = ptr;
    } while(swapped);
}

void display(List *ls){
    Element *temp = ls->head;
    while(temp != nullptr){
        cout << "Title: " << temp->title << endl;
        cout << "Artist: " << temp->artist << endl;
        cout << "Duration: " << temp->duration << "mn\n\n";
        temp = temp->next;
    }
    cout << endl;
}

int search(List *ls, string title){
    Element *e = ls->head;
    int position = 0;
    while(e != nullptr){
        if(e->title == title){
            cout << title << " is found at ";
            return position;
        }
        position++;
        e = e->next;
    }
    cout << title << " is not found!";
    return -1;
}

void reverseList(List *ls){
    Element *prev = nullptr;
    Element *current = ls->head;
    Element *next = nullptr;

    ls->tail = ls->head;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    ls->head = prev;
}

int main(){

    List *myList = createList();

    add_beg(myList, "C++", "Davin", 5);
    add_beg(myList, "Java", "Vath", 6);
    add_beg(myList, "HTML", "Vong", 3);
    add_beg(myList, "CSS", "Thyda", 7);
    add_beg(myList, "Ruby", "Layla", 2);

    bubbleSort(myList);

    display(myList);

    return 0;
}