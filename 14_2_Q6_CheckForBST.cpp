#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*Brute Force Approach=>
You can find the inorder traversal using morris inorder and check for the order.
TC=O(N)
SC=O(1)
But this method shows an error attached in the notes of the A2Z sheet. Kisi se poochna.
*/
bool isValidBST1(TreeNode* root) {
    bool check=true;
    long past=LONG_MIN;
    while(root!=NULL && check)
    {
        if(root->left==NULL)
        {
            if(root->val<=past)
            {
                check=false;
            }
            past=root->val;
            root=root->right;
        }
        else
        {
            TreeNode* prev=root->left;
            while(prev->right&&prev->right!=root)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=root;
                root=root->left;
            }
            else
            {
                prev->right=NULL;
                if(root->val<=past)
                {
                    check=false;
                }
                past=root->val;
                root=root->right;
            }
        }
    }
    return check;
}


bool isValid(TreeNode* root, long minVal, long maxVal);

/*Optimal Approach=>
TC=O(N)
SC=O(height)
Can see the SS if proper understanding needed, dry run an example case if needed.*/
bool isValidBST(TreeNode* root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}

bool isValid(TreeNode* root, long minVal, long maxVal) {
    std::ios_base::sync_with_stdio(false);
    if (root == nullptr) {
        return true;
    }
    if (root->val >= maxVal || root->val <= minVal) {
        return false;
    }
    return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
}

int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Check if the binary search tree is valid
    bool isValid = isValidBST(root);
    std::cout << "Is the binary search tree valid? " << (isValid ? "Yes" : "No") << std::endl;

    // Clean up the memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
