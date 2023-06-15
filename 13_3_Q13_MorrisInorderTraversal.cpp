#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x), left(nullptr), right(nullptr) {}
};

/*Morris Traversal=>
TC=O(N) 
SC=O(1)  Yoh improvement hai iss method mein
Intuition video aur screen shots se seekh lo. Dry run karke dekh lena, acchese samjh mein aajayega*/
vector<int> InorderTreversal(Node* root)
{
    vector<int> ans;
    while(root!=NULL)
    {
        if(root->left==NULL)
        {
            ans.push_back(root->data);
            root=root->right;
        }
        else
        {
            Node* prev=root->left;
            while(prev->right&&prev->right!=root)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=root;
                root=root->left;
            }
            else
            {
                prev->right=NULL;
                ans.push_back(root->data);
                root=root->right;
            }
        }
    }
    return ans;
}
int main() {
    // Create a binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform Morris Traversal (Preorder)
    vector<int> result = InorderTreversal(root);

    // Print the result
    cout << "Inorder Traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    // Clean up memory
    // ...
    
    return 0;
}
