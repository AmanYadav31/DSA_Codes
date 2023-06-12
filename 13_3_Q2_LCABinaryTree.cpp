#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool getPath(TreeNode* root, std::vector<TreeNode*>& arr, TreeNode* x) {
    if (!root)
        return false;
    arr.push_back(root);
    if (root == x)
        return true;
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;
    arr.pop_back();
    return false;
}
/*Brute Force Approach=>
TC=O(N+N)
SC=O(N+N)
--------------------Runtime=11ms-----------------------------------------------
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    std::ios_base::sync_with_stdio(false);
    std::vector<TreeNode*> path1;
    std::vector<TreeNode*> path2;
    getPath(root, path1, p);
    getPath(root, path2, q);
    int mini = std::min(path1.size(), path2.size());
    for (int i = mini - 1; i >= 0; i--) {
        if (path1[i] == path2[i])
            return path1[i];
    }
    return nullptr;
}

/*Optimal Approach=> See the video again for understanding the intution better also do a dry run.
TC=O(N)
SC=O(N)
--------------------Runtime=14ms-----------------------------------------------
*/
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL||root==p||root==q)
    {
        return root;
    }
    TreeNode* lh=lowestCommonAncestor1(root->left,p,q);
    TreeNode* rh=lowestCommonAncestor1(root->right,p,q);
    if(lh==NULL)
    {
        return rh;
    }
    else if(rh==NULL)
    {
        return lh;
    }
    else return root;

}
int main() {
    // Create a sample tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;  // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    TreeNode* lca = lowestCommonAncestor1(root, p, q);
    if (lca)
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    else
        std::cout << "No Lowest Common Ancestor found." << std::endl;

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
