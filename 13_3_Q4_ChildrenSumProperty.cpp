#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
/*Recursive Approach
TC=O(N)
SC=O(height) O(N) for worst*/
int isSumProperty(Node* root)
{
    // Add your code here
    if (root == nullptr)
        return 1;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int sum = 0;

    if (root->left != nullptr)
        sum += root->left->data;

    if (root->right != nullptr)
        sum += root->right->data;

    return (root->data == sum && isSumProperty(root->left) && isSumProperty(root->right));
}
/*Made by me
Uses Level Order traversal
TC=O(N)
SC=O(N)*/
int isSumProperty1(Node *root)
{
    // Add your code here
    if (root == NULL) return 0;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* temp = q.front();
            q.pop();
            int sum=0;
            if (temp->left){ q.push(temp->left);sum+=temp->left->data;}
            if (temp->right){ q.push(temp->right);sum+=temp->right->data;}
            if(temp->left||temp->right)
            {
                if(sum!=temp->data) return 0;
            }
        }
    }

    return 1;
}

/*Children Sum property=> Tree conversion
TC=O(N)
SC=O(height)
The intution is to start from top and if the sum is less then increase one of its value to be equal to 
root such that there is no shortage ever.Go down then to repeat the same strategy using recursio,
see the video again if intuition not properly clear.Run a few test cases on copy if needed.
*/
void reorder(Node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
int main()
{
    // Create the tree and test the isSumProperty function
    Node* root = new Node();
    root->data = 10;

    root->left = new Node();
    root->left->data = 4;

    root->right = new Node();
    root->right->data = 6;

    root->left->left = new Node();
    root->left->left->data = 3;

    root->left->right = new Node();
    root->left->right->data = 1;

    root->right->left = new Node();
    root->right->left->data = 2;

    root->right->right = new Node();
    root->right->right->data = 4;

    if (isSumProperty1(root))
        std::cout << "The tree satisfies the sum property." << std::endl;
    else
        std::cout << "The tree does not satisfy the sum property." << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
