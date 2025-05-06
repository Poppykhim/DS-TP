#include <iostream> 
using namespace std;

int summation(){
    int number;
    cout << "Please Enter number: ";
    cin >> number;
    if(number == -1) return -1;
    return number + summation();
}

int main(){

    int total = summation();

    cout << "Total = " << total;

    return 0;
}