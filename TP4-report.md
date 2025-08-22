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

Given a list below. Describe what does it store. Let’s create structures that can hold all of those data.

Remark: Do not write the full implementation of linked list. You are just asked to define two structures
such as the element structure and the list structure.

## Source Code

```C++
#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct List {
    int n;
    Element *head;
    Element *tail;
};

int main(){
    return 0;
}
```

## Output

```C++
....
```

# Exercise 2,3,4

2.Define a data structure that can store unlimited data of ITC students. Each student has ID, name,
year and program degree. Let’s create an element for student then a list that contains head, tail and
pointer.

3.In addition to Exercise #1, create 2 functions such as: create an empty list, and add student to list.
After that, in the main program, call to these functions and add 5 students of your classmate that
you like the most.

4.Create a function to display all data in the list that implemented in the exercises 2 and 3 above. Test
your program in main. Finally, add 2 more students to the list. Display all data.

## Source Code

```C++
#include <iostream>
#include <cstdio>
using namespace std;

// Exercise 2
struct StudentElement {
    string id;
    string name;
    int year;
    string degree;
    StudentElement *next;
};

struct ListStudent {
    int n;
    StudentElement *head;
    StudentElement *tail;
};

// Exercise 3
ListStudent *createEmptyList(){
    ListStudent *ls;
    ls = new ListStudent;
    ls->n;
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}

void addStudent(ListStudent *ls, string id, string name, int year, string degree){
    StudentElement *e = new StudentElement;
        e->id = id;
        e->name = name;
        e->year = year;
        e->degree = degree;
        e->next = nullptr;

    if(ls->n == 0){
        ls->head =e;
    } else {
        ls->tail->next =e;
    }
    ls->tail =e;
    ls->n++;
}

// Exercise 4
void displayStudents(ListStudent *ls){
    StudentElement *ptr = ls->head;
    for(int i = 0; i < 68; i++){
        cout << "=";
    }
    printf("\n| %-10s | %-20s | %-5s | %-20s |\n", "ID", "Name", "Year", "Degree");
    for(int i = 0; i < 68; i++){
        cout << "=";
    }
    cout << endl;
    while(ptr != nullptr){
        printf("| %-10s | %-20s | %-5d | %-20s |\n", ptr->id.c_str(), ptr->name.c_str(), ptr->year, ptr->degree.c_str());
        ptr = ptr->next;
    }
    for(int i = 0; i < 68; i++){
        cout << "=";
    }
}

int main(){

    ListStudent *stuList = createEmptyList();

    addStudent(stuList, "p20230018", "Do Davin", 2, "Software Engineering");
    addStudent(stuList, "p20230033", "Virak Rith", 2, "Software Engineering");
    addStudent(stuList, "p20230021", "Tat Chansereyvong", 2, "Software Engineering");
    addStudent(stuList, "p20230035", "Thy Sethasarakvath", 2, "Software Engineering");
    addStudent(stuList, "p20230029", "Sokha Ordom", 2, "AIECS");

    // Add 2 more students to the list
    addStudent(stuList, "p20230039", "Huoth Sitha", 2, "Software Engineering");
    addStudent(stuList, "p20230031", "Sam Sokleap", 2, "Software Engineering");

    displayStudents(stuList);

    return 0;
}
```

## Output:

```C++
====================================================================
| ID         | Name                 | Year  | Degree               |
====================================================================
| p20230018  | Do Davin             | 2     | Software Engineering |
| p20230033  | Virak Rith           | 2     | Software Engineering |
| p20230021  | Tat Chansereyvong    | 2     | Software Engineering |
| p20230035  | Thy Sethasarakvath   | 2     | Software Engineering |
| p20230029  | Sokha Ordom          | 2     | AIECS                |
| p20230039  | Huoth Sitha          | 2     | Software Engineering |
| p20230031  | Sam Sokleap          | 2     | Software Engineering |
====================================================================
```

# Exercise 5

Write a program that can store numbers as many as possible using linked list data structure. The
program ask user for a number at a time then add to the list. Keep asking the user for another
number and add to the list if the input number is not 0.  
a. When the user inputs 0 twice, display all data in the list and stop the program.  
b. Finally, compute the summation of all data in the list and show the result.

## Source Code:

```C++
#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct List {
    int n;
    Element *head;
    Element *tail;
};

List *createEmptyList() {
    List *ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}

void add_end(List *ls, int data) {
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;

    if (ls->n == 0) {
        ls->head = e;
    } else {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}

void display(List *ls) {
    Element *tmp = ls->head;
    cout << "All data in the list are: ";
    while (tmp != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int sum(List *ls) {
    int total = 0;
    Element *e = ls->head;
    while (e != nullptr) {
        total += e->data;
        e = e->next;
    }
    return total;
}

int main() {
    cout << "\t*** A program to store number as many as possible: ***\n";

    List *myList = createEmptyList();
    int input;
    int zeroCount = 0;

    while (true) {
        cout << "Enter a number: ";
        cin >> input;
        if (input == 0) {
            zeroCount++;
            if (zeroCount == 1) {
                cout << "\tYou have entered the number 0 once. Only 1 more left. We will quit the program.\n";
            } else if (zeroCount == 2) {
                cout << "\tYou have entered the number 0 twice so far. The program is going to stop now.\n";
                break;
            }
        } else {
            add_end(myList, input);
        }
    }
    display(myList);
    cout << "Summation of all numbers is: " << sum(myList) << endl;

    return 0;
}
```

## Output:

```C++
        *** A program to store number as many as possible: ***
Enter a number: 5
Enter a number: 2
Enter a number: 4
Enter a number: 6
Enter a number: 2
Enter a number: 3
Enter a number: 4
Enter a number: 0
        You have entered the number 0 once. Only 1 more left. We will quit the program.
Enter a number: 5
Enter a number: 1
Enter a number: 0
        You have entered the number 0 twice so far. The program is going to stop now.
All data in the list are: 5 2 4 6 2 3 4 5 1
Summation of all numbers is: 32
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3
