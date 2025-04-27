#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void convertTemperatureToFahrenheit(){
    cout << "\t\t***Convert temperature Celsius to Fahrenheit***\n";
    double fahrenheit, celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;
    fahrenheit = (celsius * 9/5) + 32;
    cout << "Convert temperature from " << celsius << " C to Fahrenheit is " << fahrenheit << " F" << endl;
}

void convertTemperatureToCelsius(){
    cout << "\t\t***Convert temperature Fahrenheit to Celsius***\n";
    double fahrenheit, celsius;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fahrenheit;
    celsius = (fahrenheit - 32) * 5/9;
    cout << "Convert temperature from " << fahrenheit << " F to Celsius is " << celsius << " C" << endl;
}

void calculateQuadraticEquation(){
    cout << "\t\t***Quadratic Equation ax2+bx+c=0***\n";
    double a, b, c;
    double x, x1, x2;
    cout << "Please enter a: ";
    cin >> a;
    cout << "Please enter b: ";
    cin >> b;
    cout << "Please enter c: ";
    cin >> c;

    double delta = pow(b, 2) - 4 * a * c;

    if(delta == 0){
        x = -b / (2 * a);
        cout << "Result: \n";
        cout << "\tX1 = X2 = " << x << endl;
    } else if(delta > 0){
        x1 = (-b - sqrt(delta)) / (2 * a);
        x2 = (-b + sqrt(delta)) / (2 * a);
    
        cout << "Result: \n";
        cout << "\tX1 = " << x1 << endl;
        cout << "\tX2 = " << x2 << endl;
    } else {
        cout << "Result: \n";
        cout << "Quadratic equation has no root!" << endl;
    }
}

void computeBMI(){
    cout << "\t\t***Compute BMI***\n";

    double weight, height, bmi;

    cout << "Please Enter your Weight in (Kilogram): ";
    cin >> weight;
    cout << "Please Enter your Height in meters(m): ";
    cin >> height;

    bmi = weight / pow(height, 2);

    if (bmi < 18.5) {
        cout << "Your BMI is " << fixed << setprecision(2) << bmi << ", which mean you are underweight." << endl;
    } else if (bmi < 25) {
        cout << "Your BMI is " << fixed << setprecision(2) << bmi << ", which mean you have a normal weight." << endl;
    } else if (bmi < 30) {
        cout << "Your BMI is " << fixed << setprecision(2) << bmi << ", which mean you are overweight." << endl;
    } else {
        cout << "Your BMI is " << fixed << setprecision(2) << bmi << ", which mean you are obese." << endl;
    }
}

void summation(int n){
    int sum;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0){
            continue;
        } else {
            sum += i;
        }
    }
    cout << "Sum from 1 to " << n << " except those that are divisible by 3 is " << sum << endl;
}

int main(){

    int choice;
    do{
        cout << "==========================================" << endl;
        cout << "|              MAIN MENU                 |" << endl;
        cout << "==========================================" << endl;
        cout << "| 1. Convert Temperature to Fahrenheit   |" << endl;
        cout << "| 2. Convert Temperature to Celsius      |" << endl;
        cout << "| 3. Calculate Quadratic Equation        |" << endl;
        cout << "| 4. Compute BMI                         |" << endl;
        cout << "| 5. Sum (1 to N)                        |" << endl;
        cout << "| 0. Exit                                |" << endl;
        cout << "==========================================" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch(choice){
            case 1: 
                convertTemperatureToFahrenheit();
                system("Pause");
                system("cls");
                break;
            case 2:
                convertTemperatureToCelsius();
                system("Pause");
                system("cls");
                break;
            case 3:
                calculateQuadraticEquation();
                system("Pause");
                system("cls");
                break;
            case 4:
                computeBMI();
                system("Pause");
                system("cls");
                break;
            case 5:
                cout << "\t\t***Sum numbers from 1 to n except those numbers that are divisible by 3***\n";
                int n;
                cout << "Please Enter n: ";
                cin >> n;
                summation(n);
                system("Pause");
                system("cls");
                break;
            case 0:
                cout << "Exiting Program...\n";
                system("Pause");
                break;
        }

    }while(choice != 0);

    return 0;
}