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