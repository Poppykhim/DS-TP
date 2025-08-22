<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-4

Due Date: July 22, 2025 (11:59 AM)

</p>
<br/>

# Exercise 1

1.  Create a singly linked list to manage student records.  
    a. Define a linked list to store student information such as id, name, score.  
    b. Implement the following functions and test the program:

        i. add the student info to the end of the list
        ii. display all student info from the list
        iii. remove the last student from the list

## Source Code

```C++
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
```

## Output

```C++
Before Delete:
Student List:
ID: 111
Name: Davin
Score: 90.99

ID: 222
Name: Naraka
Score: 80

ID: 333
Name: Scar
Score: 87.99

ID: 444
Name: Alucard
Score: 85.99


After Delete:
Student List:
ID: 111
Name: Davin
Score: 90.99

ID: 222
Name: Naraka
Score: 80

ID: 333
Name: Scar
Score: 87.99
```

# Exercise 2

2.  Create a singly linked list to manage the lists of books.

    a. Define a singly linked list for books (title, isbn, price)
    b. Implement:

         i. add the book info to the beginning of the list1 when price is higher than 50
         ii. add the book info to the end of the list2 when price is lower than 50
         iii. display all book info in the list
         iv. combine two lists into one list list1

## Source Code

```C++
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
```

## Output:

```C++
Add Beg:
Title: JavaScript
ISBN: 333
Price: 19.99

Title: Java
ISBN: 222
Price: 39.99

Title: C++
ISBN: 111
Price: 19.99


Add End:
Title: C#
ISBN: 444
Price: 88.99

Title: Ruby
ISBN: 555
Price: 49.99

Title: HTML
ISBN: 666
Price: 10.99


After Combination:
Title: JavaScript
ISBN: 333
Price: 19.99

Title: Java
ISBN: 222
Price: 39.99

Title: C++
ISBN: 111
Price: 19.99

Title: C#
ISBN: 444
Price: 88.99

Title: Ruby
ISBN: 555
Price: 49.99

Title: HTML
ISBN: 666
Price: 10.99
```

# Exercise 3

3.  Create a singly linked list to manage tasks.

    a. Define a singly linked list to stores a task (description, priority level: 1-5)
    b. Implement:

         i. add tasks to the end of the list
         ii. display all tasks info in the list
         iii. delete the oldest task in the list (the beginning of the list)

## Source Code:

```C++
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
```

## Output:

```C++
List:
Desciption: Hello
Priority level: 3
Desciption: hi
Priority level: 5
Desciption: hey
Priority level: 1
Desciption: bye
Priority level: 2
Desciption: good
Priority level: 4

List After Delete:
Desciption: hi
Priority level: 5
Desciption: hey
Priority level: 1
Desciption: bye
Priority level: 2
Desciption: good
Priority level: 4
```

# Exercise 4

4.  Create a singly linked list to manage the playlist

    a. Define a singly linked list for songs (title, artist, duration)
    b. Implement:

         i. add a song to the beginning of the list
         ii. display all book info in the list
         iii. search a song based on title from the list
         iv. reverse the order of songs in the list
         v. sort the songs based on duration using bubble sort algorithm. (swap data, not
         nodes)

## Source Code:

```C++
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
```

## Output:

```C++
Title: Ruby
Artist: Layla
Duration: 2mn

Title: CSS
Artist: Thyda
Duration: 3mn

Title: HTML
Artist: Vong
Duration: 5mn

Title: Java
Artist: Vath
Duration: 6mn

Title: C++
Artist: Davin
Duration: 7mn
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3
