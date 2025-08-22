#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while(start < end) {
        while(a[start] >= pivot && start <= ub) {
            start++;
        }
        while(a[end] < pivot && end >= lb) {
            end--;
        }
        if(start < end) {
            swap(a[start], a[end]);
        }
    }

    swap(a[lb], a[end]);
    return end;
}

void QuickSort(int a[], int lb, int ub) {
    if(lb < ub) {
        int pos = Partition(a, lb, ub);
        QuickSort(a, lb, pos - 1);
        QuickSort(a, pos + 1, ub);
    }
}

int main() {
    
    int number[5];

    int size = sizeof(number) / sizeof(number[0]);

    for(int i = 0; i < size; i++) {
        cout << "Input number #" << (i + 1) << ": ";
        cin >> number[i];
    }

    QuickSort(number, 0, size - 1);

    cout << endl;
    cout << "Quick Sort: ";
    for(int i = 0; i < size; i++) {
        cout << number[i] << " ";
    }
    
    return 0;
}