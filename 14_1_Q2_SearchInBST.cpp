#include <iostream>
#include <ios>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*Iterative Method=>
TC=O(logN)
SC=O(1)
Runtime=39ms*/
TreeNode* searchBST(TreeNode* root, int val) {
    std::ios_base::sync_with_stdio(false);
    while (root != nullptr && val != root->val) {
        root = (val < root->val) ? root->left : root->right;
    }
    return root;
}

/*Recursive Method=>
TC=O(logN)
SC=O(height)
Runtime=35ms*/
TreeNode* searchBST1(TreeNode* root, int val) {
    ios_base::sync_with_stdio(false);
    if(!root) return NULL;
    if(val==root->val) return root;
    else return (val<root->val)?searchBST(root->left,val):searchBST(root->right,val);
}
int main() {
    // Create a binary search tree for testing
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Search for a value in the binary search tree
    int target = 3;
    TreeNode* result = searchBST(root, target);

    if (result != nullptr) {
        std::cout << "Found the value " << target << " in the binary search tree." << std::endl;
    } else {
        std::cout << "The value " << target << " does not exist in the binary search tree." << std::endl;
    }

    // Clean up memory
    // ...

    return 0;
}
