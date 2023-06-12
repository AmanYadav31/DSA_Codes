#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    //Node(int x): data(x),left(nullptr),right(nullptr) {}
};

bool isLeaf(Node *root)
{
    return !root->left && !root->right;
}
// Define the Paths function here
/*
Post OrderTraversal applied to find the leaf nodes
----We can also use preorder and inorder. Try to figure out using them during revision-----------------
TC=O(N)
SC=O(N)*/
vector<vector<int>> Paths(Node* root)
{
    // Code here
    stack<Node*> s;
    vector<int> ans;
    vector<vector<int>> finalans;
    if(root==NULL) return finalans;
    
    while(root!=NULL || !s.empty())
    {
        if(root!=NULL)
        {
            s.push(root);
            ans.push_back(root->data);
            root=root->left;
        }
        else
        {
            Node* temp=s.top()->right;
            if(temp==NULL)
            {
                temp=s.top();
                if(isLeaf(temp))
                {
                    finalans.push_back(ans);
                }
                s.pop();
                ans.pop_back();
                while(!s.empty()&& temp==s.top()->right)
                {
                    temp=s.top();
                    s.pop();
                    ans.pop_back();
                }
            }
            else
            {
                root=temp;
            }
        }
    }
    return finalans;
}
/*
REcursive approach=>
TC=O(N)
SC=O(height) auxilary*/
void helper(Node* root,vector<vector<int>> &ans,vector<int> temp)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
    temp.push_back(root->data);
    ans.push_back(temp);
    temp.pop_back();
    return;
    }
    temp.push_back(root->data);
    helper(root->left,ans,temp);
    helper(root->right,ans,temp);
    temp.pop_back();
}

/*Function to find the path upto a node with sime specific value=>
TC=O(N)
SC=O(N)*/
bool getPath(Node * root, vector < int > & arr, int x) {
  // if root is NULL
  // there is no path
  if (!root)
    return false;

  // push the node's value in 'arr'
  arr.push_back(root -> data);

  // if it is the required node
  // return true
  if (root -> data == x)
    return true;

  // else check whether the required node lies
  // in the left subtree or right subtree of
  // the current node
  if (getPath(root -> left, arr, x) ||
    getPath(root -> right, arr, x))
    return true;

  // required node does not lie either in the
  // left or right subtree of the current node
  // Thus, remove current node's value from
  // 'arr'and then return false   
  arr.pop_back();
  return false;
}
int main() {
    // Create a sample binary tree
    Node* root = new Node();
    root->data = 1;
    
    Node* leftNode = new Node();
    leftNode->data = 2;
    root->left = leftNode;
    
    Node* rightNode = new Node();
    rightNode->data = 3;
    root->right = rightNode;
    
    Node* leftLeftNode = new Node();
    leftLeftNode->data = 4;
    leftNode->left = leftLeftNode;
    
    Node* leftRightNode = new Node();
    leftRightNode->data = 5;
    leftNode->right = leftRightNode;
    
    // Call the Paths function
    vector<vector<int>> paths = Paths(root);
    
    // Print the paths
    cout << "Paths in the binary tree:" << endl;
    for (const vector<int>& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
