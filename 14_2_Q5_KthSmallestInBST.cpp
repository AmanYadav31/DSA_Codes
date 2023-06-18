#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
Brute Force=>
Store all the elements in a vector, sort it and return kth element of that vector.=>
TC=O(N+NlogN+K)
SC=O(N)*/

/*Efficient Approach=>
Use recursive or iterative inorder traversal.
TC=O(N)
SC=O(N)*/
TreeNode* kthsmallest(TreeNode* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	TreeNode* left=kthsmallest(root->left,k);
	if(left!=NULL)
	return left;
	k--;
	if(k==0)
	return root;
	
	return kthsmallest(root->right,k);
}

/*Optimal Approach=>
Uses Morris Order Traversal
TC=O(N)
SC=O(1)*/
int kthSmallest(TreeNode* root, int k) {
    std::ios_base::sync_with_stdio(false);
    int c = 0;
    int kvalue = INT_MIN;
    
    while (root != nullptr) {
        if (root->left == nullptr) {
            c++;
            if (c == k) kvalue = root->val;
            root = root->right;
        } else {
            TreeNode* prev = root->left;
            
            while (prev->right != nullptr && prev->right != root) {
                prev = prev->right;
            }
            
            if (prev->right == nullptr) {
                prev->right = root;
                root = root->left;
            } else {
                prev->right = nullptr;
                c++;
                if (c == k) kvalue = root->val;
                root = root->right;
            }
        }
    }
    
    return kvalue;
}

int main() {
    // Example usage:
    // Creating a sample binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int k = 3;
    int result = kthSmallest(root, k);
    std::cout << "The kth smallest element is: " << result << std::endl;
    
    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
