#include <iostream>
using namespace std;

const int SIZE = 10;

struct Queue {
    int front;
    int rear;
    int Q[SIZE];
};

void createEmptyQueue(Queue &q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue &q) {
    return (q.front == -1 || q.front > q.rear);
}

bool isFull(Queue &q) {
    return (q.rear == SIZE - 1);
}

void enqueue(Queue &q, int data) {
    if(isFull(q)) {
        cout << "Cannot add data. Queue is full\n";
        return;
    }

    if(isEmpty(q)) {
        q.front = 0;
        q.rear = 0;
    } else {
        q.rear++;
    }
    q.Q[q.rear] = data;
}

int dequeue(Queue &q) {
    if(isEmpty(q)) {
        cout << "Cannot dequeue. Queue is empty\n";
        return -1;
    }

    cout << "Dequeued: " << q.Q[q.front] << endl;
    int value = q.Q[q.front];
    q.Q[q.front] = 0;
    if(q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }

    return value;
}

int front(Queue &q) {
    if(isEmpty(q)) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q.Q[q.front];
}

int rear(Queue &q) {
    if(isEmpty(q)) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q.Q[q.rear];
}

void displayQueue(Queue &q) {
    if(isEmpty(q)) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";
    for(int i = q.front; i <= q.rear; i++) {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int size(Queue &q) {
    if(isEmpty(q)) {
        return 0;
    }
    return (q.rear - q.front + 1);
}

int main(){

    Queue q;
    createEmptyQueue(q);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    cout << "Queue Size: " << size(q) << endl;
    displayQueue(q);

    cout << "Front: " << front(q) << endl;
    cout << "Rear: " << rear(q) << endl;

    dequeue(q);
    dequeue(q);
    dequeue(q);

    cout << "After dequeue: \n";
    displayQueue(q);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    displayQueue(q);

    return 0;
}