#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x),left(nullptr),right(nullptr) {}
};
/*Approach Similar to that of Vertical Traversal
TC=O(N)
SC=O(N) O(NlogN) is better than O(N)
*/
vector<int> bottomView(Node *root)
{
    //Your code here
    map<int, int> mp; 
    queue<pair<Node*,int>> q;
    vector<int> ans;
    if (!root) return ans;
    q.push({root, 0});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        Node* node = temp.first;
        int x = temp.second;
        mp[x]=node->data;       
        if (node->left) q.push({node->left, x - 1});
        if (node->right) q.push({node->right, x + 1});
    }
    for(auto p:mp)
    {
        ans.push_back(p.second);
    }
    return ans;
}
int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    // Call the topView function
    vector<int> result = bottomView(root);

    // Print the top view elements
    cout << "Top View: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Clean up memory (optional)
    delete root->left->right->right->right;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
