#include <iostream>
using namespace std;

int findsum(int a[], int n){
    if(n <= 1) return n;
    return a[n - 1] + findsum(a, n-1);
}

int main(){

    int arr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20};
   
    cout << "The sum of all elements in an array is: " << findsum(arr, 20);

    return 0;
}