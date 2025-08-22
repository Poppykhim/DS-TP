#include <iostream>
#include <fstream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int numbers[], int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(numbers[j] < numbers[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(numbers[i], numbers[minIndex]);
        }
    }
}

int main(){

    const int MAX_SIZE = 9; 
    int numbers[MAX_SIZE];
    int count = 0;

    ifstream read("input.txt");
    ofstream write("selection.txt");

    if(!read) {
        cerr << "Error: Cannot open input.txt" << endl;
        return 1;
    }

    while(read >> numbers[count]) {
        count++;
        if(count >= MAX_SIZE) break;
    }

    read.close();

    selectionSort(numbers, count);

    for(int i = 0; i < count; i++){
        write << numbers[i] << endl;
    }

    write.close();

    cout << "Sorted numbers written to selection.txt" << endl;

    return 0;
}