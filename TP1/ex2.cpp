#include<iostream>
using namespace std;

void check(char c){
    if (int(c)==97 || int(c)==101 || int(c)==105 || int(c)==111 || int(c)==117){
        cout << "The character is a vowel!" << endl;
    }
    else if (int(c)==65 || int(c)==69 || int(c)==73 || int(c)==79 || int(c)==85){
        cout << "The character is a vowel!" << endl;
    }
    else if (int(c)>96 && int(c)<123){
        cout << "The character is a consonant!" << endl;
    }
    else if (int(c)>64 && int(c)<91){
        cout << "The character is a consonant!" << endl;
    }
    else{
        cout << "Please enter a valid character!" << endl;
    }
}

int main(){
    char c;
    cout << "Please give me a character:";
    cin >> c;
    cout << endl;
    check(c);
    return 0;
}
