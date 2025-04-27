#include <iostream>
using namespace std;

int main() {
    int minutes;
    cout << "Enter the number of minutes: ";
    cin >> minutes;

    int hours = minutes / 60;
    int remainingMinutes = minutes % 60;
    int seconds = remainingMinutes * 60;

    cout << "Time format (h:m:s) -> ";
    cout << hours << ":" << remainingMinutes << ":" << seconds << endl;

    return 0;
}
