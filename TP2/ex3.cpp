#include <iostream>
using namespace std;

int findMin(int a[], int n){
    if(n == 1) return a[0];
    int min = findMin(a, n-1);
    return (a[n - 1] < min) ? a[n - 1] : min;
}

int main(){

    int arr[5] = {1,4,6,-2,-9};

    cout << "Minimum value in the array is: " << findMin(arr, 5) << endl;

    return 0;
}