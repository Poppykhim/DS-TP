#include <iostream>
using namespace std;

int main(){
    float numbers[7],sum=0.0,multiplication=1.0;
    int n=0;
    float *ptr = numbers;
    cout << "Enter 7 float number: "<<endl;
    while(n<7){
        cout << n+1 << " : ";
        cin >> *(ptr+n);
        n++;
    }
    cout << "All numbers in the array:";

    for (int i = 0; i < 7;i++){
        cout << *(ptr + i) << ", ";
        sum+= *(ptr + i);
        multiplication*= *(ptr + i);
    }

    cout << "\nSum of all numbers: " << sum << endl;
    cout << "Multiplication of all numbers: " << multiplication << endl;
        return 0;
}