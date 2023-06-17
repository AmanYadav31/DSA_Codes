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
int findFloor(Node* root, int val) {

    // Your code here
    int floor=-1;
    while(root)
    {
        if(val==root->data)
        {
            floor=root->data;
            return floor;
        }
        else if(val>root->data)
        {
            floor=root->data;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    return floor;
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
    int floor = findFloor(root, val);

    // Print the result
    if (floor == -1)
        cout << "Floor not found for " << val << endl;
    else
        cout << "Floor of " << val << " is " << floor << endl;

    

    return 0;
}
