#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* constructTrees(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd, map<int,int>& mp) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int ind = mp[root->val];
    int pE = ind - inStart;
    root->left = constructTrees(preorder, inorder, inStart, ind - 1, preStart + 1, preStart + pE, mp);
    root->right = constructTrees(preorder, inorder, ind + 1, inEnd, preStart + 1 + pE, preEnd, mp);

    return root;
}
/*Optimal Approach=>
TC=O(NlogN+N)
SC=O(N+height)
understand intuiton ans practice by yourself*/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    ios_base::sync_with_stdio(false);
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;
    map<int,int> mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }
    return constructTrees(preorder, inorder, inStart, inEnd, preStart, preEnd, mp);
}

void printInorder(TreeNode* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
