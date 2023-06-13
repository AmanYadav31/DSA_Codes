#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* ifNodeExists(Node* node, int key) //O(N)
{
    if (node == NULL)
        return NULL;

    if (node->data == key) {
        return node;
    }

    Node* res1 = ifNodeExists(node->left, key);
    if (res1)
        return res1;

    Node* res2 = ifNodeExists(node->right, key);

    return res2;
}
/*Optimal Approach=>
Same as the approach for the previous code. (Nodes at given distance)
TC=O(3N)
SC=O(4N+height(N))*/
int minTime(Node* root, int target) {
    int ans = 0;
    if (root == NULL)
        return ans;
    unordered_map<Node*, Node*> parent;
    queue<Node*> q;
    q.push(root);
    parent[root] = NULL;
    while (!q.empty()) {//O(N)
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
                parent[temp->left] = temp;
            }
            if (temp->right) {
                q.push(temp->right);
                parent[temp->right] = temp;
            }
        }
    }
    int distance = 0;
    Node* tg = ifNodeExists(root, target);
    q.push(tg);
    unordered_set<Node*> visited;
    visited.insert(tg);
    while (!q.empty()) {//O(N)
        ans++;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left && visited.find(temp->left) == visited.end()) {
                q.push(temp->left);
                visited.insert(temp->left);
            }
            if (temp->right && visited.find(temp->right) == visited.end()) {
                q.push(temp->right);
                visited.insert(temp->right);
            }
            if (parent[temp] && visited.find(parent[temp]) == visited.end()) {
                q.push(parent[temp]);
                visited.insert(parent[temp]);
            }
        }
    }
    return ans - 1;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;

    int target = 4;

    int result = minTime(root, target);

    cout << "Minimum time to burn the entire tree: " << result << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
