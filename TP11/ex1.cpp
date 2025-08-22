#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct List {
    int size;
    Element *head;
    Element *tail;
};

List *createList(){
    List *ls = new List;
    ls->size = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void addEnd(List *ls, int data) {
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;
    if(ls->size == 0) {
        ls->head = e;
    } else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->size++;
}

void display(List *ls) {
    Element *temp = ls->head;
    cout << "Merge Sort: ";
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Element *getNodeAt(List *ls, int index) {
    Element *current = ls->head;
    int i = 0;
    while(current != nullptr && i < index) {
        current = current->next;
        i++;
    }
    return current;
}

void Merge(List *ls, int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int n = ub - lb + 1;
    int *b = new int[n];

    Element *left = getNodeAt(ls, i);
    Element *right = getNodeAt(ls, j);

    while(i <= mid && j <= ub) {
        if(left->data < right->data) {
            b[k++] = left->data;
            left = left->next;
            i++;
        } else {
            b[k++] = right->data;
            right = right->next;
            j++;
        }
    }

    while(i <= mid) {
        b[k++] = left->data;
        left = left->next;
        i++;
    }

    while(j <= ub) {
        b[k++] = right->data;
        right = right->next;
        j++;
    }

    Element *current = getNodeAt(ls, lb);
    for(k = 0; k < n; k++) {
        current->data = b[k];
        current = current->next;
    }

    delete[] b;
}

void MergeSort(List *ls, int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        MergeSort(ls, lb, mid);
        MergeSort(ls, mid + 1, ub);
        Merge(ls, lb, mid, ub);
    }
}

void mergeSort(List *ls) {
    if(ls->size > 1) {
        MergeSort(ls, 0, ls->size - 1);
    }
}

int main(){

    List *ls = createList();
    int number;

    for(int i = 0; i < 5; i++) {
        cout << "Input number #" << (i + 1) << ": ";
        cin >> number;
        addEnd(ls, number);
    }
    cout << endl;

    mergeSort(ls);

    display(ls);
    
    return 0;
}