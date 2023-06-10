#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
TC=O(N)
SC=O(height) worst=O(N) if skewed*/
bool isSameTree(TreeNode* r1, TreeNode* r2) {
    if (r1 == NULL && r2 == NULL)
        return true;
    else if (r1 == NULL || r2 == NULL)
        return false;
    return (r1->val == r2->val) && isSameTree(r1->left, r2->left) && isSameTree(r1->right, r2->right);
}

int main() {
    // Example usage
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    bool result = isSameTree(root1, root2);

    if (result)
        std::cout << "The trees are the same." << std::endl;
    else
        std::cout << "The trees are different." << std::endl;

    // Clean up memory
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}
