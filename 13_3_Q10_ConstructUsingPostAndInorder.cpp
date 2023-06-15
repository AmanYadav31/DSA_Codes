#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructTrees(vector<int>& postorder, vector<int>& inorder, int inStart, int inEnd, int postStart, int postEnd, map<int,int>& mp) {
    if (postStart > postEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int ind = mp[root->val];
    int pE = ind - inStart;
    root->left = constructTrees(postorder, inorder, inStart, ind - 1, postStart, postStart + pE - 1, mp);
    root->right = constructTrees(postorder, inorder, ind + 1, inEnd, postStart + pE, postEnd - 1, mp);

    return root;
}
/*Optimal Approach=> Similar to previous approach
TC=O(NlogN+N)
SC=O(N+height)
understand intuiton ans practice by yourself*/
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int postStart = 0, postEnd = postorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;
    map<int,int> mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }
    return constructTrees(postorder, inorder, inStart, inEnd, postStart, postEnd, mp);
}

void printInorder(TreeNode* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(inorder,postorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
