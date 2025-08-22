<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-7

Due Date: July 22, 2025 (11:59 AM)

</p>
<br/>

# Exercise 1,2,3,4

1.  Create an element structure and a list structure that can store a list of integer numbers. Create 4
    functions to

        i) Create an empty list
        ii) Add a number to begin of list
        iii) Add a number to end of list
        iv) Add a number to specific position in the list
        v) display list.

2.Using the doubly linked list from problem above. Get a number n from a user. Generate n random
numbers and store in the list. Display the list. Compute summation and average of all numbers in
the list then display the result on screen.

3.Using the doubly linked list from problem above. Create functions to delete the element from the
list: (1) delete one element from beginning, (2) delete one element from the end of the list, (3) delete
one element at the position. Display all data in the list.

4.Using the doubly linked list from problem above.

    a. Give the minimum number in the list,
    b. Give the maximum number in the list.

## Source Code

```C++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Element {
    int data;
    Element *next;
    Element *prev;
};

struct List {
    int n;
    Element *head;
    Element *tail;
};

List *createList() {
    List *ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void addBeg(List *ls, int data) {
    Element *e = new Element;
    e->data = data;
    e->next = ls->head;
    e->prev = nullptr;
    if (ls->n == 0) {
        ls->tail = e;
    } else {
        ls->head->prev = e;
    }
    ls->head = e;
    ls->n++;
}

void addEnd(List *ls, int data) {
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;
    e->prev = ls->tail;
    if (ls->n == 0) {
        ls->head = e;
    } else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}

void addPos(List *ls, int data, int pos) {
    if (pos < 0 || pos > ls->n) {
        cout << "Invalid position!\n";
        return;
    }

    if (pos == 0) {
        addBeg(ls, data);
        return;
    }
    if (pos == ls->n) {
        addEnd(ls, data);
        return;
    }

    Element *current = ls->head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    Element *e = new Element;
    e->data = data;
    e->prev = current;
    e->next = current->next;

    current->next->prev = e;
    current->next = e;
    ls->n++;
}

void displayBeg(List *ls) {
    Element *e = ls->head;
    while (e != nullptr) {
        cout << e->data << " ";
        e = e->next;
    }
    cout << endl;
}

void generateRandom(List *ls, int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int randNum = rand() % 100 + 1; // 0-100
        addEnd(ls, randNum);
    }
}

void sumAndAverage(List *ls) {
    if (ls->n == 0) {
        cout << "List is empty.\n";
        return;
    }

    int sum = 0;
    Element *e = ls->head;
    while (e != nullptr) {
        sum += e->data;
        e = e->next;
    }
    double avg = static_cast<double>(sum) / ls->n; // It's like (double) sum
    cout << "Sum: " << sum << ", Average: " << avg << endl;
}

void deleteBeg(List *ls) {
    if (ls->n == 0) return;
    Element *temp = ls->head;
    ls->head = ls->head->next;
    if (ls->head != nullptr)
        ls->head->prev = nullptr;
    else
        ls->tail = nullptr;
    delete temp;
    ls->n--;
}

void deleteEnd(List *ls) {
    if (ls->n == 0) return;
    Element *temp = ls->tail;
    ls->tail = temp->prev;
    if (ls->tail != nullptr)
        ls->tail->next = nullptr;
    else
        ls->head = nullptr;
    delete temp;
    ls->n--;
}

void deletePos(List *ls, int pos) {
    if (pos < 0 || pos >= ls->n-1) {
        cout << "Invalid position to delete!\n";
        return;
    }

    if (pos == 0) {
        deleteBeg(ls);
        return;
    }
    if (pos == ls->n - 1) {
        deleteEnd(ls);
        return;
    }

    Element *current = ls->head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    Element *temp = current->next;
    current->next = temp->next;

    if(temp->next != nullptr){
        temp->next->prev = current;
    }
    delete temp;
    ls->n--;
}

int findMin(List *ls) {
    if (ls->n == 0) return -1;
    int min = ls->head->data;
    Element *e = ls->head->next;
    while (e != nullptr) {
        if (e->data < min){
            min = e->data;
        }
        e = e->next;
    }
    return min;
}

int findMax(List *ls) {
    if (ls->n == 0) return -1;
    int max = ls->head->data;
    Element *e = ls->head->next;
    while (e != nullptr) {
        if (e->data > max){
            max = e->data;
        }
        e = e->next;
    }
    return max;
}

int main() {
    List *myList = createList();

    addBeg(myList, 2);
    addBeg(myList, 1);
    addEnd(myList, 3);
    addEnd(myList, 4);
    cout << "List after adding at beginning and end:\n";
    displayBeg(myList);

    addPos(myList, 99, 2);
    cout << "List after adding 99 at position 2:\n";
    displayBeg(myList);

    int n;
    cout << "Enter number of random elements to generate: ";
    cin >> n;
    generateRandom(myList, n);
    cout << "List after adding random numbers:\n";
    displayBeg(myList);

    sumAndAverage(myList);

    deleteBeg(myList);
    deleteEnd(myList);
    deletePos(myList, 2);
    cout << "List after deletions:\n";
    displayBeg(myList);

    cout << "Minimum number: " << findMin(myList) << endl;
    cout << "Maximum number: " << findMax(myList) << endl;

    return 0;
}
```

## Output

```C++
List after adding at beginning and end:
1 2 3 4
List after adding 99 at position 2:
1 2 99 3 4
Enter number of random elements to generate:  3
List after adding random numbers:
1 2 99 3 4 57 79 83
Sum: 328, Average: 41
List after deletions:
2 99 4 57 79
Minimum number: 2
Maximum number: 99
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3
