#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*Optimal Approach using two stack=>
Similar to Spiral Level Order Traversal
TC=O(N)
SC=O(N+N)
Runtime=0ms*/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    vector<vector<int>> level;
    if(root==NULL) return level;
    s1.push(root);
    while(!s1.empty()||!s2.empty())
    {
        vector<int> ans;
        while(!s1.empty())
        {
            TreeNode* temp=s1.top();
            s1.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL) s2.push(temp->left);
            if(temp->right!=NULL) s2.push(temp->right);
        }
        if(ans.size()!=0) level.push_back(ans);
        ans.clear();
        while(!s2.empty())
        {
            TreeNode* temp=s2.top();
            s2.pop();
            ans.push_back(temp->val);
            if(temp->right!=NULL) s1.push(temp->right);
            if(temp->left!=NULL) s1.push(temp->left);
        }
        if(ans.size()!=0) level.push_back(ans);
    }
    return level; 
}
/*Optimal Approach using a queue=>
TC=O(N)
SC=O(N)
Runtime=0ms*/
vector < vector < int >> zigzagLevelOrder1(TreeNode * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < TreeNode * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      TreeNode * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value
      int index = (leftToRight) ? i : (size - 1 - i);

      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}
int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Call the zigzagLevelOrder function
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the result
    for (const auto& level : result) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    }

    // Clean up the binary tree
    // ...
    
    return 0;
}
