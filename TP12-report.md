<p>
  <img src="ITC.gif" alt="Alt text" style="float: left; width: 220px; margin-right: 20px;">
Name: Virak Rith

Student ID: P20230033

Course: Data Structures and Algorithms

Instructor: SEAK Leng

Assignment: TP-12

Due Date: July 22, 2025 (11:59 AM)

</p>
<br/>

# Exercise 1

(No collision) Consider a hash table data structure that has a simple hash function as “key mod 20”. We would like to insert these numbers 50, 700, 76, 85, 92, 73, 101, respectively into this hash table. Draw the hash table to see how your data is stored.

`````

## Source Code

````C++
#include <iostream>
using namespace std;

const int SIZE = 20;
int ht[SIZE];

void initialize() {
    for(int i = 0; i < SIZE; i++) {
        ht[i] = 0;
    }
}

int hashFunction (int value) {
    return value % SIZE;
}

void insertData (int value) {
    int index = hashFunction(value);
    ht[index] = value;
}

void displayHT() {
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t-->";
        cout << ht[i] << endl;
    }
}

int main () {

    initialize();

    insertData(50);
    insertData(700);
    insertData(76);
    insertData(85);
    insertData(92);
    insertData(73);
    insertData(101);

    displayHT();

    return 0;
}
`````

## Output

```C++
0       -->700
1       -->101
2       -->0
3       -->0
4       -->0
5       -->85
6       -->0
7       -->0
8       -->0
9       -->0
10      -->50
11      -->0
12      -->92
13      -->73
14      -->0
15      -->0
16      -->76
17      -->0
18      -->0
19      -->0
```

# Exercise 2

2. (No collision) Create a hash table to store 4 integer numbers. This hash table uses a hash function to compute the index using the operation data % size of array, assume that the size of array is 7. Write 4 functions to
   ▪ Insert a number to the hash table.
   ▪ Display all data in hash table. Each data should be displayed with its index
   ▪ Search whether a number is contained in the hash table. If the number is contained in the hash table,
   then display a message “It is contained in position
   positionNumber” and return true. Otherwise,
   display “Not found” and return false.
   ▪ Remove a number from the hash table. If the number is contained in the hash table, then remove it by
   setting a default value (e.g: for array of integer, the default value for each element can be 0). Finally,
   display a message “removed success. Otherwise (if not contained), display “failed to delete as it does
   not exist”.
   In main program, add the numbers of 2, 4, 7, 10. Search for the number 7 by calling the search function. Then remove the number 10 using the remove function. Finally, display all data in the hash table.

## Source Code

```C++
#include <iostream>
using namespace std;

const int SIZE = 7;
int ht[SIZE];

int hashFunction(int value) { return value % SIZE; }

void initialize() {
    for (int i = 0; i < SIZE; ++i) ht[i] = 0;
}

void insertData (int value) {
    int index = hashFunction(value);
    ht[index] = value;
}

void displayHT() {
    for (int i = 0; i < SIZE; ++i) {
        cout << "Index: " << i << ", Data: " << ht[i] << '\n';
    }
}

bool searchData(int value) {
    int index = hashFunction(value);
    if (ht[index] == value) {
        cout << value << " is contained in position " << index << endl;
        return true;
    }
    cout << "It is not found" << endl;
    return false;
}

void deleteData(int value) {
    int index = hashFunction(value);
    if (ht[index] == value) {
        ht[index] = 0;
        cout << value << " is removed successfully\n";
    } else {
        cout << "Failed to delete since " << value << " does not exist\n";
    }
}

int main() {
    initialize();

    insertData(2);
    insertData(4);
    insertData(7);
    insertData(10);
    displayHT();
    cout << "\n";

    searchData(7);

    deleteData(10);

    displayHT();

    return 0;
}
```

## Output

```C++
Index: 0, Data: 7
Index: 1, Data: 0
Index: 2, Data: 2
Index: 3, Data: 10
Index: 4, Data: 4
Index: 5, Data: 0
Index: 6, Data: 0

7 is contained in position 0
10 is removed successfully
Index: 0, Data: 7
Index: 1, Data: 0
Index: 2, Data: 2
Index: 3, Data: 0
Index: 4, Data: 4
Index: 5, Data: 0
Index: 6, Data: 0
```

# Exercise 3

3. (No collision) Create a hash table with the size of 10 to store names of people. This hash table uses a hash function which returns the index in which the name should be inserted into. The hash function computes the total summation of ASCII value in the string (sum each character’s ASCII value together) and modulo with 10. Write 3 functions to:
   ▪ Insert a string to the hash table
   ▪ Search whether a string is contained in the hash table. If the string is contained in the hash table, then display a
   message “It is contained in position/index
   positionNumber”. Otherwise, display “Not found”.
   ▪ Remove the string from the hash table. If the string is contained in the hash table, then remove it by setting to
   a default value (e.g: for array of string, the default value can be an empty string). Finally display a message
   “removed success”. Otherwise (if not contained), display “failed to delete as it does not exist”.
   In main program, add a string “Bob” to the hash table. Then ask a user for 3 other names and add to the hash table. Search for the string “Bob” by calling search function. Then remove string “Bob” using the remove function. Finally, display all data in the hash table.

````

## Source Code

```C++
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;
string ht[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) ht[i] = "";
}

int hashFunction(const string& s) {
    int sum = 0;
    for (char c : s) sum += static_cast<unsigned char>(c);
    return sum % SIZE;
}

void insertData (const string& name) {
    int index = hashFunction(name);
    ht[index] = name;
}

bool searchData(const string& name) {
    int index = hashFunction(name);
    if (ht[index] == name) {
         cout << name << " is contained in position " << index << endl;
        return true;
    }
    cout << "It is not found" << endl;
    return false;
}

void deleteData(const string& name) {
    int index = hashFunction(name);
    if (ht[index] == name) {
        ht[index] = "";
        cout << name << " is removed successfully\n";
    } else {
        cout << "Failed to delete since " << name << " does not exist\n";
    }
}

void displayHT() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index: " << i << ", String: ";
        if (ht[i].empty()) {
            cout << "-\n";
        } else {
            cout << ht[i] << '\n';
        }
    }
}

int main() {

    initialize();

    insertData("Bob");

    for (int i = 1; i <= 3; i++) {
        cout << "Enter name #" << i << ": ";
        string name;
        getline(cin >> ws, name);
        insertData(name);
    }

    cout << endl;
    displayHT();

    cout << endl;
    searchData("Bob");

    cout << endl;
    deleteData("Bob");

    cout << endl;
    displayHT();

    return 0;
}
````

## Output

```cpp
Enter name #1: Bob
Enter name #2: Davin
Enter name #3: Rith

Index: 0, String: -
Index: 1, String: -
Index: 2, String: -
Index: 3, String: -
Index: 4, String: -
Index: 5, String: Bob
Index: 6, String: -
Index: 7, String: Rith
Index: 8, String: Davin
Index: 9, String: -

Bob is contained in position 5

Bob is removed successfully

Index: 0, String: -
Index: 1, String: -
Index: 2, String: -
Index: 3, String: -
Index: 4, String: -
Index: 5, String: -
Index: 6, String: -
Index: 7, String: Rith
Index: 8, String: Davin
Index: 9, String: -
```

# Exercise 4

4.  Create a hash table to store key-value data for 15 students.
    A student has ID, name, sex, phone and major.

        • A student’s ID will be taken as a key which is used as a parameter for the hash function. The value to be inserted to an array slot at the position defined by the hash function is a student info of that ID.
        • To avoid collision, you have to apply collision resolution technique called chaining (implement hash table as an array of linked list).
        • The hash function of this hash table is to generate the student ID into an index of the array. Let assume that the student ID is the same format as ITC’ engineer student ID (e.g: e20110015)

To test this program, enter information of 3 students (your friends) then

    a. Insert their information to the hash table.
    b. Finally, display all data in hash table.
    c. Study the case that has duplicate data in order to verify that your program is still working well since we apply collision resolution technique.

## Source Code

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string sex;
    string phone;
    string major;
};

struct Element {
    Student data;
    Element* next;
    Element(const Student& s) : data{s}, next(nullptr) {}
};

const int TABLE_SIZE = 15;
Element* table[TABLE_SIZE];

void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

int hashFunction(const string& id) {
    unsigned long h = 0;
    for (unsigned char c : id) {
        h = (h * 31u + c) % TABLE_SIZE;
    }
    return static_cast<int>(h);
}

void insertStudent(const Student& s) {
    int index = hashFunction(s.id);

    for (Element* current = table[index]; current != nullptr; current = current->next) {
        if (current->data.id == s.id) {
            current->data = s;
            cout << "[Update] ID " << s.id << " at bucket " << index << '\n';
            return;
        }
    }

    Element* node = new Element(s);
    node->next = table[index];
    table[index] = node;
    cout << "[Insert] ID " << s.id << " into bucket " << index << '\n';
}

bool searchStudent(const string& id, Student& out) {
    int index = hashFunction(id);
    for (Element* current = table[index]; current != nullptr; current = current->next) {
        if (current->data.id == id) {
            out = current->data;
            return true;
        }
    }
    return false;
}

void displayHT() {
    cout << "\n=== Hash Table Buckets ===\n";
    for (int i = 0; i < TABLE_SIZE; ++i) {
        cout << "Bucket " << i << ": ";
        Element* current = table[i];
        if (!current) {
            cout << "(empty)\n";
            continue;
        }
        cout << '\n';
        while (current) {
            const Student& s = current->data;
            cout << "  - ID: " << s.id
                 << " | Name: " << s.name
                 << " | Sex: " << s.sex
                 << " | Phone: " << s.phone
                 << " | Major: " << s.major << '\n';
            current = current->next;
        }
    }
}

bool deleteStudent(const string& id) {
    int index = hashFunction(id);
    Element* current = table[index];
    Element* prev = nullptr;
    while (current) {
        if (current->data.id == id) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
            cout << "[Remove] ID " << id << " from bucket " << index << '\n';
            return true;
        }
        prev = current;
        current = current->next;
    }
    cout << "[Remove] ID " << id << " not found\n";
    return false;
}

void destroy() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Element* current = table[i];
        while (current) {
            Element* nxt = current->next;
            delete current;
            current = nxt;
        }
        table[i] = nullptr;
    }
}

int main() {
    initialize();

    Student s1;
    s1.id = "e20110015";
    s1.name = "Bob";
    s1.sex = "M";
    s1.phone = "012345678";
    s1.major = "CS";
    insertStudent(s1);

    for (int i = 2; i <= 3; ++i) {
        Student s;
        cout << "\nEnter student #" << i << " info\n";
        cout << "  ID: ";    getline(cin >> ws, s.id); // skips leftover newline, reads actual input
        cout << "  Name: ";  getline(cin, s.name);
        cout << "  Sex: ";   getline(cin, s.sex);
        cout << "  Phone: "; getline(cin, s.phone);
        cout << "  Major: "; getline(cin, s.major);
        insertStudent(s);
    }

    cout << "\n-- Duplicate test: updating ID e20110015 --\n";
    Student dup = s1;
    dup.name = "Bob Updated";
    insertStudent(dup);

    displayHT();

    destroy();
    return 0;
}
```

## Output

```cpp
[Insert] ID e20110015 into bucket 0

Enter student #2 info
  ID: p20230018
  Name: Do Davin
  Sex: M
  Phone: 000111
  Major: SE
[Insert] ID p20230018 into bucket 2

Enter student #3 info
  ID: p20230024
  Name: Rith
  Sex: M
  Phone: 111000
  Major: SE
[Insert] ID p20230024 into bucket 14

-- Duplicate test: updating ID e20110015 --
[Update] ID e20110015 at bucket 0

=== Hash Table Buckets ===
Bucket 0:
  - ID: e20110015 | Name: Bob Updated | Sex: M | Phone: 012345678 | Major: CS
Bucket 1: (empty)
Bucket 2:
  - ID: p20230018 | Name: Do Davin | Sex: M | Phone: 000111 | Major: SE
Bucket 3: (empty)
Bucket 4: (empty)
Bucket 5: (empty)
Bucket 6: (empty)
Bucket 7: (empty)
Bucket 8: (empty)
Bucket 9: (empty)
Bucket 10: (empty)
Bucket 11: (empty)
Bucket 12: (empty)
Bucket 13: (empty)
Bucket 14:
  - ID: p20230024 | Name: Rith | Sex: M | Phone: 111000 | Major: SE
```

## Link to GitHub Account : [Click Here](https://github.com/Poppykhim/DS-TP.git) <3
