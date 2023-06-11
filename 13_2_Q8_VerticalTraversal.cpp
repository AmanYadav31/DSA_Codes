#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
Time Complexity: O(N*logN*logN*logN) N for forloop, logN for map,logN for another map,logN for multiset

Space Complexity: O(N)
In summary, the overall space complexity of the given code is O(N + M), where N is the number of nodes 
in the binary tree and M is the total number of unique (x, y) coordinate pairs encountered during the 
traversal.*/
vector<vector<int>> verticalTraversal(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    map<int, map<int, multiset<int>>> mp; // multiset because we might have duplicate values
    queue<pair<TreeNode*, pair<int, int>>> q;
    vector<vector<int>> ans;
    if (!root) return ans;
    q.push({root, {0, 0}});
    while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;
        mp[x][y].insert(node->val);
        if (node->left) q.push({node->left, {x - 1, y + 1}});
        if (node->right) q.push({node->right, {x + 1, y + 1}});
    }
    for (auto p : mp) {
        vector<int> temp;
        for (auto q : p.second) {
            temp.insert(temp.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    // Construct the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Call the verticalTraversal function and print the result
    vector<vector<int>> result = verticalTraversal(root);
    for (const auto& v : result) {
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Clean up memory (optional)
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
