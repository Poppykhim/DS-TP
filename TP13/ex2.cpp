#include <iostream>
#include <fstream>  
#include <cstdlib>  
#include <ctime>     
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void inorderWriteCSV(Node* root, ofstream& write, bool& first) {
    if (root != nullptr) {
        inorderWriteCSV(root->left, write, first);
        if (!first) write << ",";
        write << root->data;
        first = false;
        inorderWriteCSV(root->right, write, first);
    }
}

int main() {
    Node* root = nullptr;

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 20; i++) {
        int data = 10 + (rand() % (1000 - 10 + 1)); 
        root = insert(root, data);
    }

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    ofstream fout("bst_inorder.csv");
    if (fout) {
        bool first = true;
        inorderWriteCSV(root, fout, first);
        fout << "\n";
        fout.close();
        cout << "Saved in-order data to: bst_inorder.csv\n";
    } else {
        cout << "Error: cannot open bst_inorder.csv for writing.\n";
    }

    return 0;
}
