#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int>& A, int& i, int bound);

/*Brute Force Approach=>
1 for loop that traverses through entire array and other loop which goes to all elements to check whether
to go left or right.
TC=O(N^2)
SC=O(1)*/

/*Better Approach=>
Uses the concept of BT creation from preorder and inorder.
We nee to find the inorder array by sorting.
TC=O(NlogN+N) for sorting the array too included
Sc=O(N) for inorder array*/

/*Optimal Approach=>
TC=O(3N)- - 3N kyonki 1 li baar jab create hua, 2 ri baar jab waapas aaye from left side, 3 ri baar jab
waapas aaye from right side. Karke dekh lena ya SS dekhlena for better understanding.
  =>O(N) 
SC=O(1)
See SS for further understanding or dry run.*/
TreeNode* bstFromPreorder(vector<int>& preorder) {
    ios_base::sync_with_stdio(false);
    int i = 0;
    return build(preorder, i, INT_MAX);//direct 0 nahi pass hota. Pahle int i=0; karo aur phir pass karo
}
/*
-------------------------------------------------------------------------------------------------------
                                    Reason
In the given code, the variable i is passed as a reference to the build function. Passing it directly as 
0 instead of assigning it to i before passing would not work as intended because it would create a new 
copy of i with the value 0 instead of modifying the original i variable.

By passing i as a reference (int& i), any modifications made to i within the build function will affect 
the original i variable in the bstFromPreorder function. This allows the build function to keep track of 
the current index while traversing the preorder vector.

So, to ensure that the changes made to i inside the build function are reflected outside, it is necessary
 to pass i as a reference by assigning it to the variable before passing it. This ensures that the same 
 variable is shared between the calling function and the called function.
------------------------------------------------------------------------------------------------------*/

TreeNode* build(vector<int>& A, int& i, int bound)/*&i pass zaroor karna kyonki maanlo 4 baar left
gaye aur i increment hota raha aur maanlo ki 5th waala jo aaya usko root ke right mein jaana hua
toh recursion se jab peeche jaayega toh jab root pe pahunchega to woh right function ko bulayega
toh uss samay agar &i na ho toh i=1 ke liye bulata jo ki already assigned ho chuka hai. &i karne se
woh i=4 ke liye bulayega joki hume chahiye tha.*/
{
    if (A.size() == i || A[i] > bound) return NULL;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A, i, root->val);
    root->right = build(A, i, bound);
    return root;
}

int main() {
    vector<int> preorder = { /* Insert your preorder sequence here */ };

    TreeNode* root = bstFromPreorder(preorder);

    // Print the resulting binary search tree
    // You can implement a function to print the tree, or perform other operations on it.
    
    return 0;
}
