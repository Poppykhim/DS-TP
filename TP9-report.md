<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-9

Due Date: July 22, 2025 (11:59 AM)

</p>
<br/>

# Exercise 1

Write a C++ program to implement a queue data structure using an array to store integer numbers. Write functions for: enqueue(), dequeue(), front(), isEmpty(), isFull(), displayQueue(), getSize().

## Source Code

```C++
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
```

## Output

```C++
Queue Size: 5
Queue: 1 2 3 4 5
Front: 1
Rear: 5
Dequeued: 1
Dequeued: 2
Dequeued: 3
After dequeue:
Queue: 4 5
Dequeued: 4
Dequeued: 5
Cannot dequeue. Queue is empty
Queue is empty
```

# Exercise 2

Write a C++ program to implement a queue data structure using a singly linked list to store integer numbers with the following operations: enqueue(), dequeue(), front(), isEmpty(), isFull(), displayQueue(), getSize().

## Source Code

```C++
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
```

## Output:

```C++
Queue: 1 2 3 4 5
Queue Size: 5
Dequeue: 1
Dequeue: 2
Dequeue: 3
After Dequeued: 4 5
Current front: 4
Current rear: 5
Queue after deleted: [Empty]
```

# Exercise 3

Create a queue that can schedule a set of priority tasks. Each task is just to display a message on the screen. Table 1 shows about tasks and their descriptions (used for displaying message). Suppose that, the queue
contains Task4, Task1, Task3, and Task2 (Task 4 is the first task in the queue, Task 1 is the second task in the queue, so on and so forth). Write a program to ask user “Do you want to activate a task in your queue now?”. When the user say ‘yes’, activate the task by calling to dequeue function of the queue. Keep asking user until there is no task remained in the queue.

## Source Code:

```C++
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
```

## Output:

```C++
Do you want to activate a task in your queue now? (yes/no): yes
Doing task 4 ..... DONE!

Do you want to activate a task in your queue now? (yes/no): yes
Doing task 1 ..... DONE!

Do you want to activate a task in your queue now? (yes/no): yes
Doing task 3 ..... DONE!

Do you want to activate a task in your queue now? (yes/no): no
Task skipped. Queue still has pending tasks.

Do you want to activate a task in your queue now? (yes/no): yes
Doing task 2 ..... DONE!

All tasks have been completed.
```

# Exercise 4

At a restaurant, customers are waiting to be served. Create a queue as singly linked list that can store
customer. Each customer has name, sex and phone number.

The program provides a menu of choices that a user can use to do some operations on the queue. The
operations are:

    A. enqueue a customer (add a customer to queue),
    B. dequeue a customer (remove a customer from queue),
    C. display all customers’ info in the queue and
    D. exit the program.

Each time the function dequeue is called, display this message “Serving customer, [name]! ”. The program keeps running until the user choose choice number 4 to exit.

## Source Code:

```C++
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
```

## Output:

```C++
Welcome to the MK Restaurant!
Menu:
1. Add a customer to the queue
2. Remove a customer from the queue
3. Display queue
4. Exit the program
  Enter a choice: 1
Enter a student's name: rith
Enter a student's sex: M
Enter a student's phone number: 012613806

*******************************
Welcome to the MK Restaurant!
Menu:
1. Add a customer to the queue
2. Remove a customer from the queue
3. Display queue
4. Exit the program
  Enter a choice: 3
1 rith  M  012613806

*******************************
Welcome to the MK Restaurant!
Menu:
1. Add a customer to the queue
2. Remove a customer from the queue
3. Display queue
4. Exit the program
  Enter a choice: 2
Serving customer, rith!

*******************************
Welcome to the MK Restaurant!
Menu:
1. Add a customer to the queue
2. Remove a customer from the queue
3. Display queue
4. Exit the program
  Enter a choice: 3
No customers in queue.

*******************************
Welcome to the MK Restaurant!
Menu:
1. Add a customer to the queue
2. Remove a customer from the queue
3. Display queue
4. Exit the program
  Enter a choice: 4
Exiting program...
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3
