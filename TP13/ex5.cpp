#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    string id;
    string first;
    string last;
    string position;
    string gender;
    string phone;
};

struct Node {
    Employee e;
    Node* left;
    Node* right;
};

Node* insert(Node* root, const Employee& emp) {
    if (root == nullptr) {
        root = new Node;
        root->e = emp;
        root->left = nullptr;
        root->right = nullptr;
    } else if (emp.id < root->e.id) {
        root->left = insert(root->left, emp);
    } else if (emp.id > root->e.id) {
        root->right = insert(root->right, emp);
    } else {
        root->e = emp; 
    }
    return root;
}

Node* search(Node* root, const string& id) {
    if (root == nullptr) return nullptr;
    if (id == root->e.id) return root;
    if (id < root->e.id) return search(root->left, id);
    return search(root->right, id);
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->e.id << " | "
             << root->e.first << " " << root->e.last << " | "
             << root->e.position << " | "
             << root->e.gender << " | "
             << root->e.phone << "\n";
        inorder(root->right);
    }
}

bool splitCSVLine(const string& line, Employee& emp) {
    string fields[6];
    int fieldIndex = 0;
    string current = "";

    for (size_t i = 0; i < line.size(); i++) { // size_t: unsigned integer
        char c = line[i];
        if (c == ',') {
            if (fieldIndex < 6) {
                fields[fieldIndex++] = current;
                current = "";
            }
        } else {
            current += c;
        }
    }
    if (fieldIndex < 6) {
        fields[fieldIndex++] = current;
    }

    if (fieldIndex != 6) return false;

    emp.id       = fields[0];
    emp.first    = fields[1];
    emp.last     = fields[2];
    emp.position = fields[3];
    emp.gender   = fields[4];
    emp.phone    = fields[5];
    return true;
}

bool loadFromCSV(const string& filename, Node*& root) {
    ifstream read(filename.c_str());
    if (!read) return false;

    string line;
    while (getline(read, line)) {
        if (line.size() == 0) continue; 
        Employee emp;
        if (splitCSVLine(line, emp)) {
            root = insert(root, emp);
        }
    }
    read.close();
    return true;
}

int main() {
    Node* root = nullptr;

    string filename = "employees.csv";
    if (!loadFromCSV(filename, root)) {
        cout << "Error: cannot open '" << filename << "'.\n";
        return 1;
    }

    cout << "=== Employees (read-order by ID) ===\n";
    inorder(root);

    string q;
    cout << "\nEnter employee ID to search (e.g., emp007): ";
    getline(cin >> ws, q);

    Node* found = search(root, q);
    if (found) {
        cout << "Found:\n";
        cout << "  ID      : " << found->e.id << "\n";
        cout << "  Name    : " << found->e.first << " " << found->e.last << "\n";
        cout << "  Position: " << found->e.position << "\n";
        cout << "  Gender  : " << found->e.gender << "\n";
        cout << "  Phone   : " << found->e.phone << "\n";
    } else {
        cout << "Employee ID '" << q << "' not found.\n";
    }

    return 0;
}
