#include <iostream>
using namespace std;

struct Node {
    string id;
    Node* left;
    Node* right;
};

Node* insert(Node* root, string id) {
    if(root == nullptr) {
        root = new Node;
        root->id = id;
        root->left = nullptr;
        root->right = nullptr;
    } else if (id < root->id) {
        root->left = insert(root->left, id);
    } else if (id > root->id) {
        root->right = insert(root->right, id);
    }
    return root;
}

void preorder(Node* root) {
    if(root != nullptr) {
        cout << root->id << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if(root != nullptr) {
        inorder(root->left);
        cout << root->id << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if(root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->id << " ";
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, "p20230018");

    insert(root, "p20230011");
    insert(root, "p20230012");
    insert(root, "p20230013");
    insert(root, "p20230014");

    cout << "Pre-Order: ";
    preorder(root);
    cout << endl;

    cout << "In-Order: ";
    inorder(root);
    cout << endl;

    cout << "Post-Order: ";
    postorder(root);
    return 0;
}