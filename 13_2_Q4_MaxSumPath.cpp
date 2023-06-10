#include <iostream>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sum(TreeNode* root, int& maxi) {
    if (root == nullptr)
        return 0;
    
    int ls = max(0, sum(root->left, maxi));/*Because considering negative path sum will never give me
    maximum sum so we take it as 0 because doing so will lead to finding maximum sum
    Try to take a tree where all values are negative then you will be able to understand it better*/ 
    int rs = max(0, sum(root->right, maxi));
    maxi = max(maxi, root->val + ls + rs);
    
    return root->val + max(ls, rs);
}
/*Optimal approach=>
TC=O(N)
SC=O(height) auxilary space*/
int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    sum(root, maxi);
    return maxi;
}

int main() {
    // Create your binary tree or modify the code to accept input for the tree
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    // Call the maxPathSum function
    int result = maxPathSum(root);
    
    // Print the result
    cout << "Maximum path sum: " << result << endl;
    
    return 0;
}
