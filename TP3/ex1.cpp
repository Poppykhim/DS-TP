#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n1 = 7, n2 = 3, n3 = 15;
    int *p1 = &n1;
    int *p2 = &n2;
    int *p3 = &n3;

    cout << "Address of n1: " << p1  << " Value of n1: " << *p1 << endl;
    cout << "Address of n2: " << p2  << " Value of n1: " << *p2 << endl;
    cout << "Address of n3: " << p3  << " Value of n1: " << *p3 << endl;

    *p3 = n1 + n2;

    cout << "Sum of n1 and n2: " << *p3;

    return 0;
}