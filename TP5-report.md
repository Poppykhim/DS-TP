<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-5

Due Date: July 22, 2025 (11:59 AM)

</p>
<br/>

# Exercise 1

1. Create two linked list that are able to store list of English alphabets, one list for the small letters and
   another list for the capital letters. Hint: Create 2 structures such as element structure and list
   structure. Then create 3 functions: createList, addPerson(add to the end of the list), display all data
   in the list.

## Source Code

```C++
#include<iostream>
using namespace std;

struct CapitalElement {
    char data;
    CapitalElement *next;
};

struct LowerElement {
    char data;
    LowerElement *next;
};

struct List {
    int n;
    CapitalElement *capitalHead;
    CapitalElement *capitalTail;
    LowerElement *lowerHead;
    LowerElement *lowerTail;
};

List *createEmptyList() {
    List *ls = new List;
    ls->n = 0;
    ls->capitalHead = nullptr;
    ls->capitalTail = nullptr;
    ls->lowerHead = nullptr;
    ls->lowerTail = nullptr;
    return ls;
}

void addPerson(List *ls, char data) {
    if (isupper(data)) {
        CapitalElement *e = new CapitalElement;
        e->data = data;
        e->next = nullptr;

        if (ls->capitalHead == nullptr) {
            ls->capitalHead = e;
        } else {
            ls->capitalTail->next = e;
        }
        ls->capitalTail = e;
    } else {
        LowerElement *e = new LowerElement;
        e->data = data;
        e->next = nullptr;

        if (ls->lowerHead == nullptr) {
            ls->lowerHead = e;
        } else {
            ls->lowerTail->next = e;
        }
        ls->lowerTail = e;
    }
    ls->n++;
}

void display(List *ls) {
    CapitalElement *capitalPtr = ls->capitalHead;
    LowerElement *lowerPtr = ls->lowerHead;

    cout << "Capital letters: ";
    while (capitalPtr != nullptr) {
        cout << capitalPtr->data << " ";
        capitalPtr = capitalPtr->next;
    }
    cout << endl;

    cout << "Lowercase letters: ";
    while (lowerPtr != nullptr) {
        cout << lowerPtr->data << " ";
        lowerPtr = lowerPtr->next;
    }
    cout << endl;
}

int main(){
    cout << "\t*** A program to store letters: ***\n";
    List *myList = createEmptyList();
    for (char c = 'A'; c <= 'Z'; c++) {
        addPerson(myList, c);
    }
    for (char c = 'a'; c <= 'z'; c++) {
        addPerson(myList, c);
    }
    display(myList);
    return 0;
}
```

## Output

```C++
          *** A program to store letters: ***
Capital letters: A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
Lowercase letters: a b c d e f g h i j k l m n o p q r s t u v w x y z
```

# Exercise 2

2. Store names of 50 person in a linked list. Make sure we can add person more as many as possible.
   Hint: Create 2 structures such as element structure and list structure. Then create 3 functions:
   createList (make the list empty), addPerson(add new person name to the begin of the list), display
   all data in the list. Finally, test your program in main and add 10 of your friends’ names.

## Source Code

```C++
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
```

## Output:

```C++
Names in the list:
1. G-Devith
2. Vanda
3. Pu Jork
4. Pu Tin
5. Jek Ma
6. Chan Vathanaka
7. Prom Samnang
8. Ouk SokunKanha
9. Chhay Virak yuth
10. Preah Sovath
```

# Exercise 3,4

3. Design a program that is able to manage product information. Define a linked list that is able to store a list of products. Each product has some , such as productid, Name, price. Create data structures for this program. Create some functions below:

   a. create an empty list,  
   b. add product to begin of the list (when the price is less than 50 dollars),  
   c. add product to end of the list (when the price is at least 50 dollars), and  
   d. display product for the implementation of linked list.  
   Finally, test your program in main.

With the extension to the exercise #3, we also create two search functions and one update function.  
The update function is to update data based on the input of productid. The first search function is
able to search and display detail product information by name, while the second search function
should be able to show all products based on a given price (p). It shows product into two sections
such as:

1. Section1: All products that have price lower than p, and
2. Section2: All products that have price more than p. Test your program in main.

## Source Code:

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct  Product{
    string name,id;
    double price;
    Product* next;
};

struct ListProduct {
    int n;
    Product* head;
    Product* tail;
};

ListProduct* createList() {
    ListProduct* ls = new ListProduct;
    ls->head = nullptr;
    ls->tail = nullptr;
    ls->n = 0;
    return ls;
}

void addProductToBegin(ListProduct* ls, string name, string id, double price) {
    Product* p = new Product;
    p->name = name;
    p->id = id;
    p->price = price;
    p->next = ls->head;
    ls->head = p;
    if (ls->tail == 0) {
        ls->tail = p;
    }
    ls->n++;
}



void addProductToEnd(ListProduct* ls, string name, string id, double price) {
    Product* p = new Product;
    p->name = name;
    p->id = id;
    p->price = price;
    p->next = nullptr;
    if (ls->tail == 0) {
        ls->head = p;
    } else {
        ls->tail->next = p;

    }
    ls->tail = p;
    ls->n++;
}

void addProduct(ListProduct* ls,string name, string id, double price) {

    if (price<50){
        addProductToBegin(ls, name, id, price);
    }
    else{
        addProductToEnd(ls, name, id, price);
    }
}

void display(ListProduct* ls) {
    Product* current = ls->head;
    int count = 1;
    printf("|%-4s|%-5s|%-15s|%-10s|\n", "No.", "ID", "Name", "Price");
    cout << "======================================\n";
    while (current != nullptr) {
        printf("|%-4d|%-5s|%-15s|%-10f|\n",
            count,
            current->id.c_str(),
            current->name.c_str(),
            current->price);
        current = current->next;
        count++;
    }
}

//exercise 4

void updateProduct(ListProduct* ls, string id, string name, double price) {
    Product* current = ls->head;
    while (current != nullptr) {
        if (current->id == id) {
            current->name = name;
            current->price = price;
            return;
        }
        current = current->next;
    }
}

void searchbyName(ListProduct* ls, string name){
    Product *current = ls->head;
    while(current!=nullptr){
        if(current->name==name){
            cout << "Product found: " << current->name << ", ID: " << current->id << ", Price: " << current->price << endl;
            return;
        }
        current = current->next;
    }
}
vector<Product*> lower,higher;


void searchByPrice(ListProduct* ls, double price){
    Product *current = ls->head;
    while(current!=nullptr){
        if(current->price<price){
            lower.push_back(current);
        }
        else if(current->price>price){
            higher.push_back(current);
        }
        current = current->next;
    }
    cout << "Products with price lower than " << price << ":" << endl;
    for (Product* p : lower) {
        cout << "Product found: " << p->name << ", ID: " << p->id << ", Price: " << p->price << endl;
    }
    cout << "======================================\n";
    cout << "Products with price higher than " << price << ":" << endl;
    for (Product* p : higher) {
        cout << "Product found: " << p->name << ", ID: " << p->id << ", Price: " << p->price << endl;
    }
}

int main(){
    ListProduct* myList = createList();
    string name, id;
    double price;
    Product inputs[] = {
        {"Product1", "P001", 30.0},
        {"Product2", "P002", 60.0},
        {"Product3", "P003", 20.0},
        {"Product4", "P004", 80.0},
        {"Product5", "P005", 15.0},
        {"Product6", "P006", 55.0},
        {"Product7", "P007", 45.0},
        {"Product8", "P008", 70.0},
        {"Product9", "P009", 25.0},
        {"Product10", "P010", 90.0}
    };

    int totalProducts = sizeof(inputs) / sizeof(inputs[0]);

    for (int i = 0; i < totalProducts; i++) {
        addProduct(myList, inputs[i].name, inputs[i].id, inputs[i].price);
    }


    cout << "Products in the list:" << endl;
    cout << "======================================\n";
    display(myList);

    cout << "======================================\n";
    searchByPrice(myList,50);

    return 0;
}
```

## Output:

```C++
Products in the list:
======================================
|No. |ID   |Name           |Price     |
======================================
|1   |P009 |Product9       |25.000000 |
|2   |P007 |Product7       |45.000000 |
|3   |P005 |Product5       |15.000000 |
|4   |P003 |Product3       |20.000000 |
|5   |P001 |Product1       |30.000000 |
|6   |P002 |Product2       |60.000000 |
|7   |P004 |Product4       |80.000000 |
|8   |P006 |Product6       |55.000000 |
|9   |P008 |Product8       |70.000000 |
|10  |P010 |Product10      |90.000000 |
======================================
Products with price lower than 50:
Product found: Product9, ID: P009, Price: 25
Product found: Product7, ID: P007, Price: 45
Product found: Product5, ID: P005, Price: 15
Product found: Product3, ID: P003, Price: 20
Product found: Product1, ID: P001, Price: 30
======================================
Products with price higher than 50:
Product found: Product2, ID: P002, Price: 60
Product found: Product4, ID: P004, Price: 80
Product found: Product6, ID: P006, Price: 55
Product found: Product8, ID: P008, Price: 70
Product found: Product10, ID: P010, Price: 90
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3
