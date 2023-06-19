#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*Brute Force=>
TC=O(N+N) 1N for the inorder other N for 2Sum
SC=O(N) N for inorder
First find the inorder array and then apply the 2Sum approach on that array.*/


class BSTIterator {
public:
    stack<TreeNode*> s;
    bool reverse; // true means next and false means before

    BSTIterator(TreeNode* root, bool rev) {
        reverse = rev;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = s.top();
        s.pop();
        if (reverse) {
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }

    bool hasNext() {
        return !s.empty();
    }

private:
    void pushAll(TreeNode* root) {
        while (root) {
            s.push(root);
            if (reverse) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
};

class Solution {
public:
/*Optimal Approach=> Approach is similar to 2Sum problem in as that in Array
TC=O(N)
SC=O(2*height)*/
    bool findTarget(TreeNode* root, int k) {
        ios_base::sync_with_stdio(false);
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        int i = l.next();
        int j = r.next();
        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

int main() {
    // Test the function

    // Create the binary search tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    Solution solution;
    int target = 9;
    bool result = solution.findTarget(root, target);

    cout << "Target " << target << (result ? " found" : " not found") << endl;

    // Clean up the memory
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
