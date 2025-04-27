#include<iostream>
using namespace std;

void check(int n){
    int sum;
    for ( int i =1; i<=n;i++){
        sum+= i;
    }
    sum-=40;
    cout << "The sum of the number 1 to  " << n << " is: " << sum << endl;
}

int main (){
    int n;
    while (true){
        cout << "Please give me a number greater than 50:" << endl;
        cin >> n;
        if (n >= 50){
            check(n);
            return false;
        }
    }
    return 0;
}