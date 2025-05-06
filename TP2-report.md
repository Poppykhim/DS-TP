# Exercise 1

## Source Code

```C++
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
```

## Output

```C++
==============================
  Recursive Calculation Menu
==============================

--- Sum of All Odd Numbers ---
Enter a positive number: 20
Sum of all odd numbers from 1 to 20 is: 100

-------- Power Number --------
Enter base number: 2
Enter exponent: 1
2^1 = 2

--- Sum of All Square Numbers ---
Enter a positive number: 4
Sum of squares from 1 to 4 is: 30

---------- Sum of Digits ----------
Enter a positive number: 123
Sum of digits in 123 is: 6

======== Program Finished ========
```

# Exercise 2

## Source Code

```C++
#include <iostream>
using namespace std;

void displayStar(int n){
    if (n < 1) return;
    cout << "* ";
    displayStar(n - 1);
}

void displayNumbers(int n){
    if (n < 1) return;
    cout << n << " ";
    displayNumbers(n - 1);
}

int main(){

    int choice;
    int star;
    int number;

    do{
        cout << "\n==============================\n";
        cout << "      Recursive Menu Program\n";
        cout << "==============================\n";
        cout << "1. Display n stars\n";
        cout << "2. Display numbers from n to 1\n";
        cout << "3. Exit\n";
        cout << "Choose an option (1-3): ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Please enter number of the star: ";
                cin >> star;
                displayStar(star);
                break;
            case 2:
                cout << "Please enter number: ";
                cin >> number;
                displayNumbers(number);
                break;
            case 3:
                cout << "Exiting Program..." << endl;
                return 0;
            default:
                cout << "Invalid Choie!" << endl;
        }
    } while (true);

    return 0;
}
```

## Output:

```C++
==============================
      Recursive Menu Program
==============================
1. Display n stars
2. Display numbers from n to 1
3. Exit
Choose an option (1-3): 1
Please enter number of the star: 10
* * * * * * * * * *
==============================
      Recursive Menu Program
==============================
1. Display n stars
2. Display numbers from n to 1
3. Exit
Choose an option (1-3): 2
Please enter number: 20
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
==============================
      Recursive Menu Program
==============================
1. Display n stars
2. Display numbers from n to 1
3. Exit
Choose an option (1-3): 3
Exiting Program...
```

# Exercise 3

## Source Code:

```C++
#include <iostream>
using namespace std;

int findMin(int a[], int n){
    if(n == 1) return a[0];
    int min = findMin(a, n-1);
    return (a[n - 1] < min) ? a[n - 1] : min;
}

int main(){

    int arr[5] = {3, 7, 1, 0, -4};

    cout << "Minimum value in the array is: " << findMin(arr, 5) << endl;

    return 0;
}
```

## Output:

```C++
Minimum value in the array is: -9
```

# Exercise 4

## Source Code:

```C++
#include <iostream>
using namespace std;

int findsum(int a[], int n){
    if(n <= 1) return n;
    return a[n - 1] + findsum(a, n-1);
}

int main(){

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "The sum of all elements in an array is: " << findsum(arr, 10);

    return 0;
}
```

## Output:

```C++
The sum of all elements in an array is: 210
```

# Exercise 5

## Source Code:

```C++
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
```

## Output:

```C++
Please Enter number: 20
Please Enter number: 20
Please Enter number: 30
Please Enter number: 40
Please Enter number: -2
Please Enter number: -1
Total = 107
```
