#include<iostream>
using namespace std;
double Tax;

void display(){
    cout << "Tax required to paid is "<< Tax << endl;
}

void maleTax(double salary){
    if (salary > 1000){
        Tax = salary * (9.5/100);
    } else if (salary <= 1000 && salary > 500){
        Tax = salary * (7.0/100);
    } else if(salary <= 500 && salary > 300){
        Tax = salary * (5.0/100);
    }else if(salary <= 300 && salary > 0){
        Tax = 0;
    }
    else{
        cout << "Please enter a valid salary!" << endl;
    }
    display();
}
void femaleTax(double salary){
    if (salary > 1000){
        Tax = salary * (8.0/100);
    } else if (salary <= 1000 && salary > 500){
        Tax = salary * (6.5/100);
    } else if(salary <= 500 && salary > 300){
        Tax = salary * (3.5/100);
    }else if(salary <= 300 && salary > 0){
        Tax = 0;
    }
    else{
        cout << "Please enter a valid salary!" << endl;
    }
    display();
}

int main(){
    string name; 
    char gender;
    double salary;
    cout << "Please give me: name, gender, salary" << endl;
    cout << "(Example: Rith M 1000)" << endl;
    cin >> name >> gender >> salary;
    if (gender == 'M'){
        maleTax(salary);
    } else if (gender == 'F'){
        femaleTax(salary);
    } else {
        cout << "Please enter a valid";
    }
    return 0;
}