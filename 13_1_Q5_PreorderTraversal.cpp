#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
/*Iterative approach=>
TC=O(N)
SC=O(N+N)*/
vector<int> preorder(Node* root)
{
    vector<int> ans;
    if (root == NULL) return ans;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* temp = s.top();
        s.pop();
        ans.push_back(temp->data);
        if (temp->right != NULL) {
            s.push(temp->right);
        }
        if (temp->left != NULL) {
            s.push(temp->left);
        }
    }
    return ans;
}

/*Recursive approach=>
Time Complexity: O(N).

Reason: We are traversing N nodes and every node is visited exactly once.

Space Complexity: O(N)

Reason: Space is needed for the recursion stack. In the worst case (skewed tree), space complexity 
can be O(N).*/

void preOrderTrav(Node * curr, vector < int > & preOrder) {
  if (curr == NULL)
    return;

  preOrder.push_back(curr -> data);
  preOrderTrav(curr -> left, preOrder);
  preOrderTrav(curr -> right, preOrder);
}
int main()
{
    // Create nodes
    Node* root = new Node();
    root->data = 1;
    
    Node* left = new Node();
    left->data = 2;
    
    Node* right = new Node();
    right->data = 3;
    
    Node* leftleft = new Node();
    leftleft->data = 4;
    
    Node* leftright = new Node();
    leftright->data = 5;
    
    // Build the tree
    root->left = left;
    root->right = right;
    left->left = leftleft;
    left->right = leftright;
    
    // Get the preorder traversal
    vector<int> result = preorder(root);
    
    // Print the result
    cout << "Preorder traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    // Clean up memory
    delete root;
    delete left;
    delete right;
    delete leftleft;
    delete leftright;
    
    return 0;
}
