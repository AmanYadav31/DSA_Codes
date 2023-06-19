#include <iostream>
#include <climits>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

/*Brute Force Approach=>
Uses Validate BST Approach=>
Call the Validate Bst function for each node and count for the same
TC=O(N^2) 1N for validate and other for visting each node, onw within another
SC=O(height)*/
class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(Node* root) {
        // An empty tree is a BST of size 0.
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);
        
        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->data && root->data < right.minNode) {
            // It is a BST.
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), 
                            left.maxSize + right.maxSize + 1);
        }
        
        // Otherwise, return [-inf, inf] so that parent can't be a valid BST.
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
public:
/*Optimal Approach=>
Striver's
TC=O(N)
SC=O(height)
See SS and dry run to understand properly.*/
    int largestBst(Node* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main() {
    // Create the tree nodes
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call the largestBst function and print the result
    int largestBstSize = solution.largestBst(root);
    cout << "Size of the largest BST: " << largestBstSize << endl;
    
    // Clean up the dynamically allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
