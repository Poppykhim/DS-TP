#include <iostream>
#include <cmath>
using namespace std;

void solveEquation(int a, int b, int c, float* x1, float* x2, float* delta) {

    *delta = pow(b, 2) - 4 * a * c;

    if (*delta >= 0) {
        *x1 = (-b + sqrt(*delta)) / (2 * a);
        *x2 = (-b - sqrt(*delta)) / (2 * a);
    } else {
        cout << "The equation has complex roots." << endl;
        *x1 = *x2 = 0;
    }
}


int main() {
    int a = 1, b = 3, c = -10;

    float x1, x2, delta;
   
    solveEquation(a, b, c, &x1, &x2, &delta); 

    cout << "Delta = " << delta << endl;
    if (delta >= 0) {
        cout << "Result of the x1 = " << x1 << endl;
        cout << "Result of the x2 = " << x2 << endl;
    }

    return 0;
}