#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
/*Optimal Approach=>
Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N+N)*/
vector<int> postOrder(Node* root) {
    stack<Node*> s1;
    stack<Node*> s2;
    vector<int> ans;
    
    if (root == nullptr) return ans;
    
    s1.push(root);
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
        Node* temp = s2.top();
        if (temp->left != nullptr) s1.push(temp->left);
        if (temp->right != nullptr) s1.push(temp->right);
    }
    
    while (!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    
    return ans;
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    // Get the post-order traversal of the binary tree
    vector<int> result = postOrder(root);
    
    // Print the result
    cout << "Post-order traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    // Clean up the memory (optional)
    // ...
    
    return 0;
}
