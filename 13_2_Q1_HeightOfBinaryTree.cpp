#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*Level Order Traversal Approach=>
TC=O(N)
SC=O(N)
*/
int maxDepth(TreeNode* node) {
    ios_base::sync_with_stdio(false);
    if(node == NULL) return 0;
    queue<TreeNode*> q;
    q.push(node);
    int height = 0;
    while(!q.empty()) {
        int size = q.size();
        height++;
        while(size--) {
            TreeNode* temp = q.front();//TreeNode remNode = queue.removeFirst(); front+pop ka baap
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    }
    return height;
}

/*Recursive Approach=>
Time Complexity: O(N) 

SpaceComplexity: O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the 
binary tree.

-----------------------------------------EXPLAINATION----------------------------------------------------
When a recursive call is made for the left child root->left or the right child root->right, the current 
stack frame is suspended, and a new stack frame is created for the child node. This process continues 
until a leaf node is reached (i.e., a node with no children) where the recursion stops.

At any point during the traversal, the maximum number of active recursive calls on the call stack 
corresponds to the height of the tree. The space complexity of the recursive function is determined by 
the maximum depth of the call stack.

If the tree is well-balanced, with each level having approximately the same number of nodes, the height 
of the tree would be logarithmic in terms of the total number of nodes (N), and thus the space complexity
would be O(log N). However, in the worst-case scenario of an unbalanced tree (e.g., a skewed tree), the
height of the tree could be equal to the total number of nodes (N), resulting in a space complexity of 
O(N).
---------------------------------------------------------------------------------------------------------
*/
int maxDepth1(TreeNode* node) {
    ios_base::sync_with_stdio(false);
    if(node==NULL) return 0;
    int lh=maxDepth(node->left);
    int rh=maxDepth(node->right);
    return 1+max(lh,rh);        
}

int main() {
    // Create a binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Calculate the maximum depth of the tree
    int depth = maxDepth(root);

    // Output the result
    cout << "Maximum Depth of the Tree: " << depth << endl;

    return 0;
}
