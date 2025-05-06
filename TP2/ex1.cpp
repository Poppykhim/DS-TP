#include <iostream>
#include <cmath>
using namespace std;

int summationOfOdd(int n){
    if(n <= 1) 
        return n;
    else if(n % 2 == 1)
        return n + summationOfOdd(n-2);
    else
        return summationOfOdd(n-1);
} 

int power(int m, int n){
    if(n == 0) return 1;
    return m * power(m, n-1);
}

int sumSquare(int n){
    if(n <= 1) return n;
    else return pow(n, 2) + sumSquare(n - 1);
}

int sumDigit(int n){
    if(n / 10 == 0){
        return n;
    } else {
        int remaining = n%10;
        return remaining + sumDigit(n/10);
    }
}

int main(){

    int number, m, n, number_of_sum_square, digit_number;

    cout << "==============================\n";
    cout << "  Recursive Calculation Menu\n";
    cout << "==============================\n\n";

    cout << "--- Sum of All Odd Numbers ---\n";
    cout << "Enter a positive number: ";
    cin >> number;
    cout << "Sum of all odd numbers from 1 to " << number << " is: " << summationOfOdd(number) << "\n\n";

    cout << "-------- Power Number --------\n";
    cout << "Enter base number: ";
    cin >> m;
    cout << "Enter exponent: ";
    cin >> n;
    cout << m << "^" << n << " = " << power(m, n) << "\n\n";

    cout << "--- Sum of All Square Numbers ---\n";
    cout << "Enter a positive number: ";
    cin >> number_of_sum_square;
    cout << "Sum of squares from 1 to " << number_of_sum_square << " is: " << sumSquare(number_of_sum_square) << "\n\n";

    cout << "---------- Sum of Digits ----------\n";
    cout << "Enter a positive number: ";
    cin >> digit_number;
    cout << "Sum of digits in " << digit_number << " is: " << sumDigit(digit_number) << "\n\n";

    cout << "======== Program Finished ========\n";

    return 0;
}