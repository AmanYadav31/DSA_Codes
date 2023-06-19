#include <iostream>
#include <stack>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*Optimal Approach=>
Striver's
TC=O(1) Try to under stand why see striver video last part or ask some as to why average time is O(1)
SC=O(H) 
*/
class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() {
        return !s.empty();
    }

private:
    void pushAll(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};

int main() {
    // Create a sample binary search tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    // Create an instance of BSTIterator
    BSTIterator iterator(root);

    // Print all elements using BSTIterator
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}
