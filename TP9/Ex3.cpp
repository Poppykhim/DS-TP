#include <iostream>
#include <string>
using namespace std;

struct Task {
    string description;
    Task* next;
};

struct Queue {
    Task* front;
    Task* rear;
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

void enqueue(Queue* q, string message) {
    Task* t = new Task;
    t->description = message;
    t->next = nullptr;
    
    if (isEmpty(q)) {
        q->front = q->rear = t;
    } else {
        q->rear->next = t;
        q->rear = t;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        cout << "No tasks remaining in the queue." << endl;
        return;
    }

    Task* temp = q->front;
    cout << temp->description << endl;
    q->front = q->front->next;

    delete temp;

    if (q->front == nullptr)
        q->rear = nullptr;
}

void deleteQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    delete q;
}

int main() {
    Queue* q = createQueue();

    enqueue(q, "Doing task 4 ..... DONE!");
    enqueue(q, "Doing task 1 ..... DONE!");
    enqueue(q, "Doing task 3 ..... DONE!");
    enqueue(q, "Doing task 2 ..... DONE!");

    string userInput;
    while (!isEmpty(q)) {
        cout << "\nDo you want to activate a task in your queue now? (yes/no): ";
        cin >> userInput;
        
        if (userInput == "yes") {
            dequeue(q);
        } else {
            cout << "Task skipped. Queue still has pending tasks." << endl;
        }
    }

    cout << "\nAll tasks have been completed." << endl;
    deleteQueue(q);
    return 0;
}
