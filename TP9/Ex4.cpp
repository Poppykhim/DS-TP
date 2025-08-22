#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    char sex;
    string phone;
    Customer* next;
};

struct Queue {
    Customer* front;
    Customer* rear;
};

Queue* createQueue() {
    Queue* q = new Queue;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
}

void enqueue(Queue* q, string name, char sex, string phone) {
    Customer* c = new Customer;
    c->name = name;
    c->sex = sex;
    c->phone = phone;
    c->next = nullptr;

    if (isEmpty(q)) {
        q->front = q->rear = c;
    } else {
        q->rear->next = c;
        q->rear = c;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        cout << "No customer to serve!\n";
        return;
    }

    Customer* temp = q->front;
    cout << "Serving customer, " << temp->name << "!" << endl;
    q->front = q->front->next;

    if (q->front == nullptr)
        q->rear = nullptr;

    delete temp;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        cout << "No customers in queue.\n";
        return;
    }

    Customer* temp = q->front;
    int i = 1;
    while (temp != nullptr) {
        cout << i++ << " " << temp->name << "  " << temp->sex << "  " << temp->phone << endl;
        temp = temp->next;
    }
}

void deleteQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    delete q;
}

int main() {
    Queue* q = createQueue();
    int choice;
    string name, phone;
    char sex;

    do {
        cout << "\n*******************************\n";
        cout << "Welcome to the MK Restaurant!\n";
        cout << "Menu:\n";
        cout << "1. Add a customer to the queue\n";
        cout << "2. Remove a customer from the queue\n";
        cout << "3. Display queue\n";
        cout << "4. Exit the program\n";
        cout << "  Enter a choice: ";
        cin >> choice;
        cin.ignore(); // To avoid input bug

        switch (choice) {
            case 1:
                cout << "Enter a student's name: ";
                getline(cin, name);
                cout << "Enter a student's sex: ";
                cin >> sex;
                cout << "Enter a student's phone number: ";
                cin >> phone;
                enqueue(q, name, sex, phone);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                displayQueue(q);
                break;

            case 4:
                cout << "Exiting program...\n";
                deleteQueue(q);
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
