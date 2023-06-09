#include <bits/stdc++.h>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*Recursive=>
TC=O(N)
SC=O(N)
*/
void postOrderTrav(TreeNode * curr, vector < int > & postOrder) {
  if (curr == NULL)
    return;

  postOrderTrav(curr -> left, postOrder);
  postOrderTrav(curr -> right, postOrder);
  postOrder.push_back(curr -> val);
}

/*Method 1=>
Sriver's
TC=O(N)
SC=O(N)
Runtime=6ms*/
vector<int> postorderTraversal(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    stack<TreeNode*> s;
    vector<int> ans;
    if(root==NULL) return ans;
    
    while(root!=NULL || !s.empty())
    {
        if(root!=NULL)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            TreeNode* temp=s.top()->right;
            if(temp==NULL)
            {
                temp=s.top();
                s.pop();
                ans.push_back(temp->val);
                while(!s.empty()&& temp==s.top()->right)
                {
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                }
            }
            else
            {
                root=temp;
            }
        }
    }
    return ans;
}

/*Method 2=>
Leetcode's 0ms
TC=O(N)
SC=O(N)
Runtime=3ms*/
vector<int> postorderTraversal1(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    vector<int> ans;
    if (!root) return ans;
    stack<TreeNode*> s;
    TreeNode* prev = nullptr;

    while (!s.empty() || root) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            TreeNode* temp = s.top();

            // Check if the right subtree is already visited or not.
            if (temp->right && temp->right != prev) {
                root = temp->right;
            } else {
                ans.push_back(temp->val);
                prev = temp;
                s.pop();
            }
        }
    }
    return ans;
}
int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform postorder traversal
    vector<int> result = postorderTraversal(root);

    // Print the result
    cout << "Postorder Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Clean up the dynamically allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
