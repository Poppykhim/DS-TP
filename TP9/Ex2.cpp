#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct Queue {
    int size;
    Element *front;
    Element *rear;
};

bool isEmpty(const Queue *q) {
    return q->size == 0;
}

Queue *createEmptyQueue() {
    Queue *q = new Queue;
    q->size = 0;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}

void enqueue(Queue *q, int data) {
    Element *e = new Element;
    e->data = data;
    e->next = nullptr;

    if (q->size == 0) {
        q->front = e;
        q->rear = e;
    } else {
        q->rear->next = e;
        q->rear = e;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty.\n";
        return -1;
    }
    int value = q->front->data;
    Element *e = q->front;
    q->front = e->next;
    if(q->front == nullptr) {
        q->rear = nullptr;
    }
    delete e;
    q->size--;

    return value;
}

int front(const Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q->front->data;
}

int rear(const Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue is empty\n";
        return -1;
    }
    return q->rear->data;
}

int getSize(const Queue *q) {
    return q->size;
}

void displayQueue(const Queue *q) {
    if(q == nullptr || q->size == 0) {
        cout << "[Empty]" << endl;
        return;
    }
    
    Element* temp = q->front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteQueue(Queue *q) {
    while(!isEmpty(q)) {
        dequeue(q);
    }
    delete q;
}

int main() {
    Queue *q = createEmptyQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    cout << "Queue: ";
    displayQueue(q);
    cout << "Queue Size: " << getSize(q) << endl;

    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;
    cout << "Dequeue: " << dequeue(q) << endl;

    cout << "After Dequeued: ";
    displayQueue(q);

    cout << "Current front: " << front(q) << endl;
    cout << "Current rear: " << rear(q) << endl;

    deleteQueue(q);
    cout << "Queue after deleted: ";
    displayQueue(q);

    return 0;
}
