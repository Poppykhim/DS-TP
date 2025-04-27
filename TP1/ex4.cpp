#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

string getComputerChoice() {
    int choice = rand() % 3;
    if (choice == 0) return "rock";
    else if (choice == 1) return "paper";
    else return "scissors";
}

string getResult(string user, string computer) {
    if (user == computer) {
        return "It's a tie!";
    } else if ((user == "rock" && computer == "scissors") ||
               (user == "paper" && computer == "rock") ||
               (user == "scissors" && computer == "paper")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

int main() {
    srand(time(0));

    string userChoice;
    cout << "Welcome to Rock-Paper-Scissors Game!\n";
    cout << "Enter your choice (rock, paper, scissors): ";
    cin >> userChoice;

    for (auto &c : userChoice) c = tolower(c);

    if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
        cout << "Invalid choice. Please run the program again.\n";
        return 1;
    }
    

    string computerChoice = getComputerChoice();
    cout << "Computer chose: " << computerChoice << endl;

    cout << getResult(userChoice, computerChoice) << endl;

    return 0;
}
