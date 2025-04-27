#include <iostream>
#include <string>
using namespace std;

struct Book {
    string isbn, title, author;
    int id;
    double price;
};

void displayAllBook(Book Books[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Book " << i + 1 << endl;
        cout << "Book Id: " << Books[i].id << endl;
        cout << "ISBN: " << Books[i].isbn << endl;
        cout << "Title: " << Books[i].title << endl;
        cout << "Author: " << Books[i].author << endl;
        cout << "Price: $" << Books[i].price << endl;
        cout << endl;
    }
}

void displayBasedOnIsbn(Book Books[], int size, string isbn) {
    for (int i = 0; i < size; i++) {
        if (Books[i].isbn == isbn) {
            cout << "Book found!" << endl;
            cout << "Book Id: " << Books[i].id << endl;
            cout << "ISBN: " << Books[i].isbn << endl;
            cout << "Title: " << Books[i].title << endl;
            cout << "Author: " << Books[i].author << endl;
            cout << "Price: $" << Books[i].price << endl;
            return;
        }
    }
    cout << "Book with ISBN " << isbn << " not found." << endl;
}

int main() {
    Book Books[5];
    for (int i = 0; i < 5; i++) {
        Books[i].id = i + 1;
        cout << "Enter ISBN of book " << i + 1 << ": ";
        getline(cin, Books[i].isbn);
        
        cout << "Enter the title: ";
        getline(cin, Books[i].title);

        cout << "Enter the author's name: ";
        getline(cin, Books[i].author);

        cout << "Enter the price: ";
        cin >> Books[i].price;
        cin.ignore();
    }
    displayAllBook(Books, 5);
    displayBasedOnIsbn(Books, 5, "1234567890");

    return 0;
}
