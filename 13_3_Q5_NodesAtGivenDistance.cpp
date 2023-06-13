#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
/*Writing a function is better as it increases readability and is a good practice and is better for 
longer inputs.
*/
void parentTrack(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left) {
            mp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right) {
            mp[temp->right] = temp;
            q.push(temp->right);
        }
    }
}
/*Optimal Approach=>
TC=O(N+N) first N for parentTrack another N for the while loop in main
SC=O(4N)
Runtime=15ms*/
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {/*Agar target Node ki jagah sirf data value
di ho toh koi bhi traversal use karke usko find karlena. See the GFG waala given below for the same.*/
    ios_base::sync_with_stdio(false);
    unordered_map<TreeNode*, TreeNode*> mp;
    vector<int> ans;
    if (!root) return ans;
    parentTrack(root, mp);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int c = 0;
    while (!q.empty()) {
        if (c++ == k) break;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (mp[curr] && !visited[mp[curr]]) {
                q.push(mp[curr]);
                visited[mp[curr]] = true;
            }
        }
    }
    while (!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}

/*Same approach=>
2 Differences:
i) Instead of writing another function like parentCheck, writes it's code in the main.
ii) Instead of using unordered_map for visited, uses unordered_set.

Runtime=0ms*/
vector<int> distanceK1(TreeNode* root, TreeNode* target, int k) {
    ios_base::sync_with_stdio(false);
    vector<int> ans;
    if (root == NULL)
        return ans;
    unordered_map<TreeNode *, TreeNode *> parent;
    queue<TreeNode *> q;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
                parent[temp->left] = temp;
            }
            if (temp->right)
            {
                q.push(temp->right);
                parent[temp->right] = temp;
            }
        }
    }
    int distance = 0;
    q.push(target);
    unordered_set<TreeNode *> visited;
    visited.insert(target);
    while (distance != k)
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left && visited.find(temp->left) == visited.end())
            {
                q.push(temp->left);
                visited.insert(temp->left);
            }
            if (temp->right && visited.find(temp->right) == visited.end())
            {
                q.push(temp->right);
                visited.insert(temp->right);
            }
            if (parent[temp] && visited.find(parent[temp]) == visited.end())
            {
                q.push(parent[temp]);
                visited.insert(parent[temp]);
            }
        }
        distance++;
    }
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;     
}
/*
---------------------------------REASON---------------------------------------------------------------
See the screenshots for the difference in using unordered_Set instead of map for this case, as we 
don't have to maintain anything that it assiciates to. Just knowing it's presence can tell us if present
or not.
*/

/*GFG Waala=>
if target value is given instead of target node.*/
TreeNode* ifNodeExists(struct TreeNode* node, int key)
{
    if (node == NULL)
        return NULL;
    
    if (node->val == key)
    {
        return node;
    }
        
    
    /* then recur on left subtree */
    TreeNode* res1 = ifNodeExists(node->left, key);
    // node found, no need to look further
    if(res1) return res1;
    
    /* node is not found in left,
    so recur on right subtree */
    TreeNode* res2 = ifNodeExists(node->right, key);
    
    return res2;
}
vector <int> KDistanceNodes(TreeNode* root, int target , int k)
{
    // return the sorted vector of all nodes at k dist
    vector<int> ans;
if (root == NULL)
    return ans;
unordered_map<TreeNode *, TreeNode *> parent;
queue<TreeNode *> q;
q.push(root);
parent[root] = NULL;
while (!q.empty())
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left)
        {
            q.push(temp->left);
            parent[temp->left] = temp;
        }
        if (temp->right)
        {
            q.push(temp->right);
            parent[temp->right] = temp;
        }
    }
}
int distance = 0;
TreeNode* tg=ifNodeExists(root,target);
q.push(tg);
unordered_set<TreeNode *> visited;
visited.insert(tg);
while (distance != k)
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left && visited.find(temp->left) == visited.end())
        {
            q.push(temp->left);
            visited.insert(temp->left);
        }
        if (temp->right && visited.find(temp->right) == visited.end())
        {
            q.push(temp->right);
            visited.insert(temp->right);
        }
        if (parent[temp] && visited.find(parent[temp]) == visited.end())
        {
            q.push(parent[temp]);
            visited.insert(parent[temp]);
        }
    }
    distance++;
}
while (!q.empty())
{
    ans.push_back(q.front()->val);
    q.pop();
}
sort(ans.begin(),ans.end());
return ans;   
}
int main() {
    // Create the tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Set the target node and distance
    TreeNode* target = root->left;
    int k = 2;

    // Call the distanceK function
    vector<int> result = distanceK(root, target, k);

    // Print the result
    cout << "Nodes at distance " << k << " from target node " << target->val << ":" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Clean up the memory
    // Implement code to delete the tree nodes and free memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
