#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};
/*
TC=O(logN)
SC=O(1)*/
int findCeil(Node* root, int val) {
    if (root == NULL) return -1;

    // Your code here
    int ceil=-1;
    while(root)
    {
        if(val==root->data)
        {
            ceil=root->data;
            return ceil;
        }
        else if(val>root->data)
        {
            root=root->right;
        }
        else
        {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
main() {
    // Create the binary search tree
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    // Call the findCeil function
    int val = 9;
    int ceil = findCeil(root, val);

    // Print the result
    if (ceil == -1)
        cout << "Ceiling not found for " << val << endl;
    else
        cout << "Ceiling of " << val << " is " << ceil << endl;

    

    return 0;
}
