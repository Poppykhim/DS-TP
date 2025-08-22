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
