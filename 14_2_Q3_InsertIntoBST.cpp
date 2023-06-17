#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*Recursive approach=>
TC=O(logN)
SC=O(height)*/
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) {
        TreeNode* temp = new TreeNode(val);
        root = temp;
        return root;
    }
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

/*Iterative Approach=>
TC=O(logN)
SC=O(1)*/
TreeNode* insertIntoBST1(TreeNode* root, int val) {
    if(root==NULL) return new TreeNode(val);
    TreeNode* cur=root;//copy because hume aakhir mein root return karna hoga na
    while(true)
    {
        if(val>cur->val)
        {
            if(cur->right) cur=cur->right;
            else{
                cur->right= new TreeNode(val);
                break;
            }
        }
        else if(val<cur->val)//yeh condition bhi likhi kyonki agar equal waala aaya toh dono meinse kuch nahi hoga
        {
            if(cur->left) cur=cur->left;
            else{
                cur->left= new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left);  // Recursively traverse the left subtree
    
    std::cout << root->val << " ";  // Print the current node value
    
    inorderTraversal(root->right);  // Recursively traverse the right subtree
}
int main() {
    TreeNode* root = nullptr;
    root = insertIntoBST1(root, 5);
    root = insertIntoBST1(root, 3);
    root = insertIntoBST1(root, 7);
    root = insertIntoBST1(root, 2);
    root = insertIntoBST1(root, 4);

    inorderTraversal(root);
    // Perform any necessary operations on the binary search tree

    return 0;
}
