<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-3

Due Date: May 11, 2025 (11:59 AM)

</p>
<br/>

# Exercise 1

Write a C++ program to create three integer numbers n1, n2 and n3. Assign values of 7, 3, 15 to n1,n2 and n3, respectively. Next create three pointer variables p1, p2 and p3, where p1 points to n1, p2 points to n2 and p3 points to n3.

a. Display the address and value of n1, n2, and n3 using the pointer variables p1, p2 and p3.  
b. Update the value of n3 using p3. The value of n3 now should be the sum of n1 and n2.

## Source Code

```C++
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
```

## Output

```C++
Address of n1: 0x80b59ffb24 Value of n1: 7
Address of n2: 0x80b59ffb20 Value of n1: 3
Address of n3: 0x80b59ffb1c Value of n1: 15
Sum of n1 and n2: 10
```

# Exercise 2

Write a Write a C++ program to get a number, say n, from a user. Then modify the value of n to n+7
using a pointer variable.  
Remark: You are not allowed to use n=n+7. Use pointer operation instead.

## Source Code

```C++
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
```

## Output:

```C++
Enter a number: 20
20 + 7 = 27
```

# Exercise 3

Write a function in C++ program to exchange two numbers. These two variables are passed through
parameters of the function using pointer.  
void exchange(float *a, float *b)

## Source Code:

```C++
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
```

## Output:

```C++
a = 200, b = 100
```

# Exercise 4

Write a function to solve this quadratic equation ax2 + bx + c = 0, where a is not equal to 0. Store
values of x1, x2 and delta using the parameters given to the function. The prototype of this function
is defined by:  
void solveEquation(int a, int b, int c, float *x1, float *x2, float \*delta)

## Source Code:

```C++
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
```

## Output:

```C++
Delta = 49
Result of the x1 = 2
Result of the x2 = -5
```

# Exercise 5

Write a C++ program to ask a user for 7 integer numbers and store in an array. Then write a function
that can find min and max values from this array. You are recommended to use pointer. Pass your
max and min variable as reference via function parameter.  
The prototype of this function is defined by:  
void findMaxMin(int* arr, int *max, int \*min)

## Source Code:

```C++
#include <iostream>
using namespace std;

void FindMaxMin(int *arr, int *max, int *min){
    *max = arr[0];
    *min = arr[0];
    for(int i=1; i<7; i++){
        if(arr[i] > *max){
            *max = arr[i];
        }
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
}

int main(){
    int numbers[7],n=0;
    int *ptr = numbers;
    cout << "Enter 7 number: "<<endl;
    while(n<7){
        cout << n+1 << " : ";
        cin >> *(ptr+n);
        n++;
    }
    int max, min;
    FindMaxMin(numbers, &max, &min);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;

}
```

## Output:

```C++
Enter 7 number:
1 : 2
2 : 3
3 : 5
4 : 2
5 : -4
6 : 9
7 : -7
Max: 9
Min: -7
```

# Exercise 6

Write a C++ program to ask a user for 7 float numbers and store in an array. Create a pointer variable
and let it reference to the array.

a. Display all numbers stored in array by using another pointer variable. Let’s loop through array.

b. Compute the summation and multiplication of all numbers in this array using pointer operation.

REMARK: You are not allowed to access element in array using the bracket [ ]. You are required to
use pointer operation.

## Source Code

```C++
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
```

## Output:

```C++
Enter 7 float number:
1 : 2.2
2 : 3.5
3 : 9.4
4 : 10.3
5 : 2.4
6 : 6.3
7 : 5.9
All numbers in the array:2.2, 3.5, 9.4, 10.3, 2.4, 6.3, 5.9,
Sum of all numbers: 40
Multiplication of all numbers: 66505.8
```

# Exercise 7

Write a C++ program which calculates the sum of 1/12 + 1/22 + 1/32 + ... + 1/n2, where n is a
positive integer. The program calls to a function that can calculate the sum above. The prototype of
this function is as followed:

## Example code

```C++
#include<iostream>
using namespace std;

void sum1(double *sum, int n){
    //your codes
}
int main(){
    double result;
    sum1(&result, 5);
    cout<<result<<endl;
}
```

## Source Code

```C++
#include<iostream>
using namespace std;

void sum1(double *sum, int n){
    double num = 0;
    for(int i=1; i<=n; i++){
        num += (1.0/(i*10+2));
    }
    *sum = num;
}
int main(){
    double result;
    sum1(&result, 5);
    cout<<result<<endl;
}
```

## Output:

```C++
0.203078
```
