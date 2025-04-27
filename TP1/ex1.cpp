#include<iostream>
using namespace std;
int main(){
    string name, major;
    char gender;
    int age;
    cout << "Please give me name, gender,major and age:" << endl;
    cout << "(Example: Rith M SE 18)" << endl;
    cin >> name >> gender >> major >> age;
    if (gender == 'M'){
        if (age < 18 && age >0){
            cout << "Hi, Mr. " << name << "! your age is " << age <<  "year old and you learn "<<major<<"!." << "You can not vote" <<endl;
        } else if (age >= 18 && age < 100){
            cout << "Hi, Mr. " << name << "! your age is " << age <<  "year old and you learn "<<major<<"!." << "You can vote" <<endl;
        }
        else {
            cout << "Please enter a valid age!" << endl;
        }
    }
    else if(gender == 'F'){
        if (age < 18 && age >0){
            cout << "Hi, Ms. " << name << "! your age is " << age <<  "year old and you learn "<<major<<"!." << "You can not vote" <<endl;
        } else if (age >= 18 && age < 100){
            cout << "Hi, Ms. " << name << "! your age is " << age <<  "year old and you learn "<<major<<"!." << "You can vote" <<endl;
        }
        else {
            cout << "Please enter a valid age!" << endl;
        }
    }
    else{
        cout << "Please enter a valid gender (M/F)!" << endl;
    }
        return 0;
}
