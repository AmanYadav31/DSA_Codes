#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

/*
TC=O(logN)
SC=O(1)*/
int minValue(Node* root) {
    if (!root) return -1;
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int main() {
    // Test the minValue function
    Node* root = new Node();
    root->data = 5;
    root->left = new Node();
    root->left->data = 3;
    root->left->left = new Node();
    root->left->left->data = 2;
    root->left->right = new Node();
    root->left->right->data = 4;
    root->right = new Node();
    root->right->data = 7;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 8;

    std::cout << "Minimum value: " << minValue(root) << std::endl;

    // Clean up the dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
