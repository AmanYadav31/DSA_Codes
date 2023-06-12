#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

/*GFG Waala--For finding the max nodes in a particular level of a binary tree. Uses level order traversal
Technique
TC=O(N)
SC=O(N)*/
int getMaxWidth(Node* root) {
    if (root == NULL) return 0;
    
    queue<Node*> q;
    q.push(root);
    
    int maxi = INT_MIN;
    
    while (!q.empty()) {
        int size = q.size();
        maxi = max(maxi, size);
        
        while (size--) {
            Node* temp = q.front();
            q.pop();
            
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    
    return maxi;
}

/*This is for finding the max width of a binary tree=>
Leetcode waala, Striver's
TC=O(N)
SC=O(N)*/
int getMaxWidth1(Node* root) {
    queue<pair<Node*,int>> q;
        int ans=0;
        if(root==NULL) return ans;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int mmsize=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front().first;
                int curr_id=q.front().second-mmsize;
                if(i==0) first=curr_id;
                if(i==size-1) last=curr_id;
                q.pop();
                if(temp->left) q.push({temp->left,2*curr_id+1});
                if(temp->right) q.push({temp->right,2*curr_id+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
}
// Driver code
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
    
    root->right->left = new Node();
    root->right->left->data = 6;
    
    int maxWidth = getMaxWidth1(root);
    cout << "Maximum width of the binary tree is: " << maxWidth << endl;
    
    return 0;
}
