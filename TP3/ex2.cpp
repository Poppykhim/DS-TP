#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;

    int *p = &n;

    cout << *p << " + 7 = " << *p + 7;

    return 0;
}