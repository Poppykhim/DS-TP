#include <iostream>
using namespace std;

void displayStar(int n){
    if (n < 1) return;
    cout << "* ";
    displayStar(n - 1);
}

void displayNumbers(int n){
    if (n < 1) return;
    cout << n << " ";
    displayNumbers(n - 1);
}

int main(){

    int choice;
    int star;
    int number;

    do{
        cout << "\n==============================\n";
        cout << "      Recursive Menu Program\n";
        cout << "==============================\n";
        cout << "1. Display n stars\n";
        cout << "2. Display numbers from n to 1\n";
        cout << "3. Exit\n";
        cout << "Choose an option (1-3): ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Please enter number of the star: ";
                cin >> star;
                displayStar(star);
                break;
            case 2:
                cout << "Please enter number: ";
                cin >> number;
                displayNumbers(number);
                break;
            case 3:
                cout << "Exiting Program..." << endl;
                return 0;
            default:
                cout << "Invalid Choie!" << endl;
        }
    } while (true);

    return 0;
}