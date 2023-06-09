#include<bits/stdc++.h>
using namespace std;
struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}
/*Method 1=>
Made by me
TC=O(N)
SC=O(N)*/
void create_tree(node* root0, vector<int> &vec){
    int i=1;
    queue<node*> q;
    q.push(root0);
    while(i<vec.size())
    {
        node* curr=q.front();
        q.pop();
        curr->left=newNode(vec[i++]);
        q.push(curr->left);
        curr->right=newNode(vec[i++]);
        q.push(curr->right);
    }
}

int main() {
    // Create a vector of integers
    vector<int> vec = {1, 2, 3, 4, 5, 6};

    // Create the root node
    node* root = newNode(vec[0]);

    // Create the tree
    create_tree(root, vec);

    // Perform any further operations or print the tree if needed

    return 0;
}
