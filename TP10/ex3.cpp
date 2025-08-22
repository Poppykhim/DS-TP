#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    char gender;
    string dob;
};

void insertionSort(Student arr[], int size, int choice){
    for(int i = 1; i < size; i++){
        Student key = arr[i];
        int j = i - 1;

        if(choice == 1){
            while(j >= 0 && key.id < arr[j].id) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else if(choice == 2) {
            while(j >= 0 && key.name < arr[j].name) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else if(choice == 3) {
            while(j >= 0 && key.gender < arr[j].gender) {
                arr[j + 1] = arr[j];
                j--;
            }
        }

        arr[j + 1] = key;
    }
}

void display(Student arr[], int size) {
    cout << "ID\tName\tGender\tDOB\n";
    for(int i = 0; i < size; i++){
        cout << arr[i].id << "\t" << arr[i].name << "\t" << arr[i].gender << "\t" << arr[i].dob << endl;
    }
}

int main(){

    const int MAX_SIZE = 100;
    Student students[MAX_SIZE];
    int count = 0;

    ifstream read("students.csv");
    if(!read){
        cerr << "Error: Cannot open students.csv\n";
        return 1;
    }

    string line;
    while(getline(read, line) && count < MAX_SIZE) {
        stringstream ss(line);
        string idStr, name, genderStr, dob;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, genderStr, ',');
        getline(ss, dob, ',');

        students[count].id = stoi(idStr);
        students[count].name = name;
        students[count].gender = genderStr[0];;
        students[count].dob = dob;
        count++;
    }
    read.close();

    int choice;
    cout << "Choose sorting option:\n";
    cout << "1. Sort by ID\n";
    cout << "2. Sort by Name\n";
    cout << "3. Sort by Gender\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if(choice < 1 || choice > 3){
        cout << "Invalid choice.\n";
        return 1;
    }

    insertionSort(students, count, choice);

    cout << "\nSorted Student List:\n";
    display(students, count);

    return 0;
}