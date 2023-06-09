#include <bits/stdc++.h>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*Method 1=>
TC=O(N)
SC=O(N)*/
vector<vector<int>> levelOrder(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    vector<vector<int>> ans;
    queue<pair<TreeNode*,int>> q;
    if(root==NULL) return ans;
    q.push({root,0});
    while(!q.empty())
    {
        auto temp=q.front();
        q.pop();
        int level = temp.second;
        
        // Check if the current level exists in the ans vector
        if (level >= ans.size()) {
            ans.push_back(vector<int>());
        }
        
        ans[level].push_back(temp.first->val);
        if(temp.first->left!=nullptr)
        {
            q.push({temp.first->left,level+1});
        }
        if(temp.first->right!=nullptr)
        {
            q.push({temp.first->right,level+1});
        }
    }
    return ans;
}

/*Method 2=>
TC=O(N)
SC=O(N)*/
vector<vector<int>> levelOrder1(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root==NULL) return ans;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        vector<int> level;
        while(size--)
        {
            auto temp=q.front();
            q.pop();
            level.push_back(temp->val);
            if(temp->left!=nullptr)
            {
                q.push(temp->left);
            }
            if(temp->right!=nullptr)
            {
                q.push(temp->right);
            }
        }
        ans.push_back(level);
    }
    return ans;
}

/*For Printing in Spiral Order=>GFG Waala
TC=O(N)
TC=O(N/2+N/2+N)*/
vector<int> findSpiral(TreeNode *root)
{
    //Your code here
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    vector<int> ans;
    if(root==NULL) return ans;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            TreeNode* temp=s1.top();
            s1.pop();
            ans.push_back(temp->val);
            if(temp->right!=NULL)
            {
                s2.push(temp->right);
            }
            if(temp->left!=NULL)
            {
                s2.push(temp->left);
            }
        }
        while(!s2.empty())
        {
            TreeNode* temp=s2.top();
            s2.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL)
            {
                s1.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                s1.push(temp->right);
            }
        }
    }
    return ans;
}
int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Perform level order traversal
    vector<vector<int>> result = levelOrder1(root);

    // Print the result
    for (const vector<int>& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
