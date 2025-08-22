#include <iostream> 
#include <fstream>
using namespace std;

void Merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int n = ub - lb + 1;
    int *b = new int[n];

    while(i <= mid && j <= ub) {
        if(a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while(i <= mid) {
        b[k++] = a[i++];
    }

    while(j <= ub) {
        b[k++] = a[j++];
    }

    for(k = 0; k < n; k++){
        a[lb + k] = b[k];
    }

    delete[] b;
}

void MergeSort(int a[], int lb, int ub) {
    if(lb < ub) {
        int mid = (lb + ub) / 2;
        MergeSort(a, lb, mid);
        MergeSort(a, mid + 1, ub);
        Merge(a, lb, mid, ub);
    }
}

int main() {

    ifstream read("unsorted.txt");
    ofstream write("sorted.txt");

    if(!read.is_open()) {
        cerr << "Error: Could not open unsorted.txt file!" << endl;
        return 1;
    }

    int temp, count = 0;
    while(read >> temp) {
        count++;
    }

    read.clear();
    read.seekg(0, ios::beg);

    int *a = new int[count];
    for(int i = 0; i < count; i++) {
        read >> a[i];
    }
    read.close();

    MergeSort(a, 0, count - 1);

    for(int i = 0; i < count; i++) {
        write << a[i] << endl;
    }
    write.close();

    cout << "Sorted Array: ";
    for(int i = 0; i < count; i++) {
        cout << a[i] << " ";
    }
    cout << "\nSorted data written to sorted.txt successfully!" << endl;

    delete[] a;
    return 0;
}