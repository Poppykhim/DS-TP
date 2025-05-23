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
