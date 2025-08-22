#include <iostream>
#include <fstream>
#include <cctype>    
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

void preorder(Node* root) {          
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {           
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {         
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;

    ifstream read("bst_file.txt");

    if (!read) {
        cerr << "Error: cannot open file.\n";
        return 1;
    }

    int line;

    while(read >> line) {
        root = insert(root, line);
    }

    cout << "Pre-order : ";
    preorder(root);
    cout << "\nIn-order  : ";
    inorder(root);
    cout << "\nPost-order: ";
    postorder(root);
    cout << "\n";

    return 0;
}
