#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
/*brute Force Approach uses O(N^2) time. See the code in screenshots.*/

int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if (lh == -1 || rh == -1)
        return -1;
    
    if (abs(lh - rh) > 1)
        return -1;
    
    return 1 + std::max(lh, rh);
}
/*Optimal Approach=>
Striver's
TC=O(N)
SC=O(height) auxilary space hai*/
bool isBalanced(TreeNode* root) {
    std::ios_base::sync_with_stdio(false);
    
    if (height(root) == -1) {
        return false;
    }
    
    return true;
}

int main() {
    // Create the tree nodes
    TreeNode* root = new TreeNode();
    root->val = 1;

    TreeNode* node1 = new TreeNode();
    node1->val = 2;

    TreeNode* node2 = new TreeNode();
    node2->val = 3;

    TreeNode* node3 = new TreeNode();
    node3->val = 4;

    TreeNode* node4 = new TreeNode();
    node4->val = 5;

    // Connect the tree nodes
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->right = node4;

    // Call the isBalanced function
    bool balanced = isBalanced(root);

    // Print the result
    if (balanced) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    // Clean up memory
    delete node4;
    delete node3;
    delete node2;
    delete node1;
    delete root;

    return 0;
}
