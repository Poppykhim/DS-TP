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