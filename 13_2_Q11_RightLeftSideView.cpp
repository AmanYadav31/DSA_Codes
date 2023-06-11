#include<bits/stdc++.h>
using namespace std;
// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to create a new binary tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = new TreeNode(val);
    return newNode;
}

// Function to insert a node in the binary tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);
    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);
    return root;
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}
/*Optimal Approach=>(Right View)
Method 1=> Uses approach similar to level order traversal
TC=O(N)
SC=O(N)*/
vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*>q;
    vector<int>ans;
    if(!root)return ans;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        int tempsum=0;
        for(int i=0;i<n;i++){
            TreeNode* cur=q.front();
            q.pop();
            if(i==n-1)ans.push_back(cur->val);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
        }
        
    }
    return ans;
}
/*Optimal Approach=>(Right View)
Method 2=> Approach Similar to that of Vertcal traversal but in this we take levels
TC=O(N)
SC=O(N)
*/
vector<int> rightSideView1(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    map<int, int> mp; 
    queue<pair<TreeNode*,int>> q;
    vector<int> ans;
    if (!root) return ans;
    q.push({root, 0});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int x = temp.second;
        mp[x]=node->val;
        if (node->left) q.push({node->left, x + 1});
        if (node->right) q.push({node->right, x + 1});
    }
    for(auto p:mp)
    {
        ans.push_back(p.second);
    }
    return ans;
    
}
/*Left View
Similar to Method 2=>
TC=O(N)
SC=O(N)*/
vector<int> leftView(TreeNode *root)
{
   // Your code here
    map<int, int> mp; 
    queue<pair<TreeNode*,int>> q;
    vector<int> ans;
    if (!root) return ans;
    q.push({root, 0});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int x = temp.second;
        if(mp.find(x)==mp.end())
        {
            mp[x]=node->val;
        }
        if (node->left) q.push({node->left, x + 1});
        if (node->right) q.push({node->right, x + 1});
    }
    for(auto p:mp)
    {
        ans.push_back(p.second);
    }
    return ans;
}
int main() {
    // Create the binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->right = createNode(4);

    // Call the rightSideView function
    vector<int> result = rightSideView(root);

    // Print the right side view of the binary tree
    cout << "Right Side View: ";
    printVector(result);

    return 0;
}
