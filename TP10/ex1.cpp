#include<iostream>
using namespace std;

void bubbleSort(int num[],int n){

    for (int i = 0; i < n - 1;i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1 - i;j++){
            if ( num[j]>num[j+1]){
                swap(num[j], num[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
void display(int num[],int n){
    for (int i = 0; i < n;i++){
        cout << num[i] << " ";
    }
    cout << endl;
}


int main(){

    int num[] = {3, 5, 2, 5, 7, 9, 3};
    int n = sizeof(num) / sizeof(num[0]);
    display(num,n);
    bubbleSort(num, n);
    display(num,n);
    return 0;
}