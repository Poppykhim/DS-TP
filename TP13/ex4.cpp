#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    string name;
    int age;
    Node* left;
    Node* right;
};

Node* insert(Node* root, const string& name, int age) {
    if (root == nullptr) {
        root = new Node;
        root->name = name;
        root->age = age;
        root->left = nullptr;
        root->right = nullptr;
    } else if (name < root->name) {
        root->left = insert(root->left, name, age);
    } else if (name > root->name) {
        root->right = insert(root->right, name, age);
    } else {
        root->age = age;
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->name << " (" << root->age << ")\n";
        inorder(root->right);
    }
}

void inorderWriteCSV(Node* root, ofstream& write) {
    if (root != nullptr) {
        inorderWriteCSV(root->left, write);
        write << root->name << "," << root->age << "\n";
        inorderWriteCSV(root->right, write);
    }
}

void findYoungest(Node* root, Node*& best) {
    if (root == nullptr) return;
    if (best == nullptr || root->age < best->age) best = root;
    findYoungest(root->left, best);
    findYoungest(root->right, best);
}

void findOldest(Node* root, Node*& best) {
    if (root == nullptr) return;
    if (best == nullptr || root->age > best->age) best = root;
    findOldest(root->left, best);
    findOldest(root->right, best);
}

int main() {
    Node* root = nullptr;

    int n;
    cout << "Enter number of students: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid n.\n";
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        string name;
        int age;

        cout << "Student #" << i << " name: ";
        getline(cin >> ws, name);    
        cout << "Student #" << i << " age : ";
        cin >> age;

        root = insert(root, name, age);
    }

    cout << "\n=== In-order (by name) ===\n";
    inorder(root);

    ofstream write("students_inorder.csv");
    if (write) {
        write << "Name,Age\n";
        inorderWriteCSV(root, write);
        write.close();
        cout << "Saved to students_inorder.csv\n";
    } else {
        cout << "Error: cannot write students_inorder.csv\n";
    }

    Node* youngest = nullptr;
    findYoungest(root, youngest);
    if (youngest) {
        cout << "\nThe Youngest: " << youngest->name << " (" << youngest->age << ")\n";
    }

    Node* oldest = nullptr;
    findOldest(root, oldest);
    if (oldest) {
        cout << "The Oldest  : " << oldest->name << " (" << oldest->age << ")\n";
    }

    return 0;
}
