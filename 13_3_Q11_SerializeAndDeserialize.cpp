#include <iostream>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
TC=O(N)
SC=O(N)*/
string serialize(TreeNode* root) {
    ios_base::sync_with_stdio(false);
    if (!root) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp == NULL) {
                s.append("#,");
            }
            else {
                s.append(to_string(temp->val) + ',');
            }
            if (temp != NULL) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }

    return s;
}
/*
TC=O(N)
SC=O(N)*/
TreeNode* deserialize(string data) {
    ios_base::sync_with_stdio(false);
    if (data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#") {
            temp->left = NULL;
        }
        else {
            TreeNode* ne = new TreeNode(stoi(str));
            temp->left = ne;
            q.push(ne);
        }
        getline(s, str, ',');
        if (str == "#") {
            temp->right = NULL;
        }
        else {
            TreeNode* ne = new TreeNode(stoi(str));
            temp->right = ne;
            q.push(ne);
        }
    }
    return root;
}

// Helper function to print the binary tree (in-order traversal)
void printTree(TreeNode* node) {
    if (node) {
        printTree(node->left);
        cout << node->val << " ";
        printTree(node->right);
    }
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the binary tree
    string serialized = serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the binary tree
    TreeNode* deserialized = deserialize(serialized);
    cout << "Deserialized tree: ";
    printTree(deserialized);
    cout << endl;

    return 0;
}
