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