#include <iostream>
#include <climits>
using namespace std;

/*Brute Force is similar to previous question brute force*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int& maxi) {
    if (root == NULL) return 0;
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);
    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
/*Optimal Approach=>
TC=O(N)
SC=O(height) auxilary (stack)
)*/
int diameterOfBinaryTree(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    int maxi = INT_MIN;
    height(root, maxi);
    return maxi;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Calculate the diameter of the binary tree
    int diameter = diameterOfBinaryTree(root);

    // Print the result
    cout << "Diameter of the binary tree: " << diameter << endl;

    // Clean up the memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
