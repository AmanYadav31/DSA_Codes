#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
/*Iterative Approach=>
TC=O(N)
SC=O(N)*/
vector<int> inOrder(Node* root) {
    // Implementation of inOrder traversal
    vector<int> ans;
    stack<Node*> s;
    while (true) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        } else {
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}

/*Recursive Approach=>
TC=O(N)
SC=O(N)*/
void inOrderTrav(Node * curr, vector < int > & inOrder) {
  if (curr == NULL)
    return;

  inOrderTrav(curr -> left, inOrder);
  inOrder.push_back(curr -> data);
  inOrderTrav(curr -> right, inOrder);
}

int main() {
    // Create a binary tree
    Node* root = new Node();
    root->data = 1;

    Node* leftChild = new Node();
    leftChild->data = 2;
    root->left = leftChild;

    Node* rightChild = new Node();
    rightChild->data = 3;
    root->right = rightChild;

    Node* leftGrandchild = new Node();
    leftGrandchild->data = 4;
    leftChild->left = leftGrandchild;

    // Perform in-order traversal
    vector<int> result = inOrder(root);

    // Print the result
    cout << "In-order traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    // Clean up memory
    delete leftGrandchild;
    delete rightChild;
    delete leftChild;
    delete root;

    return 0;
}
