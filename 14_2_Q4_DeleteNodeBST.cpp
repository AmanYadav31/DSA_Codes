#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*Recursive Approach=>
TC=O(logN)
SC=O(height)
Runtime=42ms*/
TreeNode* deleteNode(TreeNode* root, int val) {
    if (!root) return root;

    if (val < root->val) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val);
    } else {
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        } else {
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
    }

    return root;
}


/*Iterative Approach=>
TC=O(logN)
SC=O(1)
Runtime=31ms*/
TreeNode* moveRight(TreeNode* root){/*move right aur helper ko deleteNode1 mein use karne se pahle uske
upar declare karna*/
    if(!root->right) return root;
    return moveRight(root->right);
}
TreeNode* helper(TreeNode * root){
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* rightMost = moveRight(root->left);
    rightMost->right = rightChild;
    return root->left;
}
TreeNode* deleteNode1(TreeNode* root, int key) {
    ios_base::sync_with_stdio(false);
    if(!root) return nullptr;
    if(root->val == key){
        return helper(root);
    }
    TreeNode* ptr = root;
    while(root!=nullptr){
        if(root->val>key){
            if(root->left!=nullptr && root->left->val==key){
                root->left = helper(root->left);
                break;
            }else{
                root = root->left;
            }
        }else{
            if(root->right!=nullptr && root->right->val == key){
                root->right = helper(root->right);
                break;
            }else{
                root = root->right;
            }
        }
    }
    return ptr;
}
// Function to print the values of a binary tree (inorder traversal)
void printTree(TreeNode* root) {
    if (root) {
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
}

int main() {
    // Constructing the binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int key = 3;

    // Deleting the node with the specified key
    root = deleteNode1(root, key);

    // Printing the resulting tree
    printTree(root);
    std::cout << std::endl;

    // Clean up the memory (optional, but recommended)
    // TODO: Implement a function to delete the tree nodes and call it here

    return 0;
}
