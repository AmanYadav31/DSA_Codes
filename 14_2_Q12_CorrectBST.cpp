#include <iostream>
#include <climits>

using namespace std;
/*
Brute Force=>
Pahle inorder nikalo, phir usko sort kardo, phir agle inorder traversal mein compare karte jaao sorted
array se aur jo galat mile unko correct kardo
TC=O(NlogN+N+N) NlogN for sorting, N for finding inorder, N for comparing so i.e. traversal
SC=O(N) for storing inorder*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
    TreeNode* prev;

private:
    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
/*Optimal Approach=>
TC=O(N)
SC=O(height) auxilary space hai lekin morris traversal use karenge toh O(1) ho sakti hai 
Dry Run karke dekhlo nahi toh SS se dekhlena samjh mein aajayega.*/
    void recoverTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);

        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (first && last) {//yeh case tab ke liye jab adjacent nahi honge
            swap(first->val, last->val);
        } else if (first && middle) {//yeh case tab ke liye jab adjacent honge
            swap(first->val, middle->val);
        }
    }
};

int main() {
    // Create the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    // Create an instance of the Solution class
    Solution solution;

    // Recover the tree
    solution.recoverTree(root);

    // Print the corrected tree
    cout << root->val << " " << root->left->val << " " << root->left->right->val << endl;

    // Clean up the memory
    delete root->left->right;
    delete root->left;
    delete root;

    return 0;
}
