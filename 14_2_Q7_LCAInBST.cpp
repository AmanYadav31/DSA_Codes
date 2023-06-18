#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*Optimal Approach=>
Recursive==
TC=O(height)
SC=O(height) auxilary space of stack
Can see the video for proper understanding or dry run a few examples
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    int cur = root->val;
    if (cur < p->val && cur < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else if (cur > p->val && cur > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

/*Optimal Approach=>
Iterative==
TC=O(height)
SC=O(1)
Can see the video for proper understanding or dry run a few examples
*/
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
    ios_base::sync_with_stdio(false);
    if(!root) return NULL;
    while(root!=NULL)
    {
        int cur=root->val;
        if(cur>p->val&&cur>q->val)
        {
            root=root->left;
        }
        else if(cur<p->val&&cur<q->val)
        {
            root=root->right;
        }
        else
        {
            break;
        }
    }
    return root;
}
int main() {
    // Example usage
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;

    TreeNode* result = lowestCommonAncestor(root, p, q);

    std::cout << "Lowest Common Ancestor: " << result->val << std::endl;

    // Clean up allocated memory
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
