#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    char gender;
    string dob;
};

bool compare(const Student &a, const Student &b, int choice) {
    if(choice == 1) return a.id < b.id;
    if(choice == 2) return a.name < b.name;
    if(choice == 3) return a.gender < b.gender;
    return false;
}

int partition(Student a[], int low, int high, int choice) {
    Student pivot = a[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { i++; } while (compare(a[i], pivot, choice));     // a[i] < pivot
        do { j--; } while (compare(pivot, a[j], choice));     // pivot < a[j]
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}

void QuickSort(Student a[], int low, int high, int choice) {
    if (low < high) {
        int p = partition(a, low, high, choice);
        QuickSort(a, low, p, choice);
        QuickSort(a, p + 1, high, choice);
    }
}

void display(Student stu[], int n) {
    cout << "ID\tName\tGender\tDoB\n";
    for(int i = 0; i < n; i++) {
        cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].gender << "\t" << stu[i].dob << "\n";
    }
}

int main() {

    ifstream read("students.csv");
    if(!read) {
        cerr << "Error: can't open students.csv!" << endl;
        return 1;
    }

    Student students[100];
    int count = 0;
    string line;

    if (getline(read, line)) {
        if (line.find("ID") == string::npos) {
            stringstream ss(line);
            string idStr, name, genderStr, dob;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, genderStr, ',');
            getline(ss, dob);                 // read till end
            students[count++] = {stoi(idStr), name, genderStr[0], dob};
        }
    }

    while(getline(read, line) && count < 100) {
        stringstream ss(line);
        string idStr, name, genderStr, dob;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, genderStr, ',');
        getline(ss, dob, ',');

        students[count].id = stoi(idStr);
        students[count].name = name;
        students[count].gender = genderStr[0];
        students[count].dob = dob;
        count++;
    }
    read.close();

    int choice;
    cout << "Sort by:\n1. ID\n2. Name\n3. Gender\nEnter choice: ";
    cin >> choice;

    QuickSort(students, 0, count -1, choice);

    cout << "\nSorted Students:\n";
    display(students, count);

    return 0;
}