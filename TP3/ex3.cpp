#include <iostream>
using namespace std;

void exchange(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    float a = 100,b = 200;
    exchange(&a, &b);
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}