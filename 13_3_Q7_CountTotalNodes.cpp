#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

/*Brute Force Approach=>
TC=O(N)
SC=O(height)*/
void inOrderTrav(node * curr, int& count) {
  if (curr == NULL)
    return;

  count++;
  inOrderTrav(curr -> left, count);
  inOrderTrav(curr -> right, count);
}
 
/*
Brute Force Approach 2=>
TC=O(N)
SC=O(height)*/
int countNodes1(node* root) {
    // Write your code here
    if(!root) return 0;
    int x=countNodes1(root->left);
    int y=countNodes1(root->right);
    return x+y+1;
    /*
    Aise likha karo abse. Upar waala ki 46ms hai aur iss waale ki 33ms
        ios_base::sync_with_stdio(false);
        if(root==NULL)return 0;
        return (1+countNodes(root->left)+countNodes(root->right)); */
}
int findHeightLeft(node* cur) //O(logN)
{
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->left; 
    }
    return hght; 
}
int findHeightRight(node* cur) //O(logN)
{
    int hght = 0; 
    while(cur) {
        hght++; 
        cur = cur->right; 
    }
    return hght; 
}
/*
Time Complexity: O(log^2 N).

Reason: To find the leftHeight and right Height we need only logN time and in the worst case we will 
encounter the second case(leftHeight!=rightHeight) for at max logN times, so total time complexity will 
be O(log N * logN)

Space Complexity: O(logN)

Reason: Space is needed for the recursion stack when calculating height. As it is a complete tree, the 
height will always be logN.*/
int countNodes(node* root) {
    if(root == NULL) return 0; 
    
    int lh = findHeightLeft(root); 
    int rh = findHeightRight(root); 
    
    if(lh == rh) return (1<<lh) - 1; 
    
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    
    return 1 + leftNodes + rightNodes; 
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);
  root -> left -> left -> left = newNode(8);
  root -> left -> left -> right = newNode(9);
  root -> left -> right -> left = newNode(10);
  root -> left -> right -> right = newNode(11);


  cout << "The total number of nodes in the given complete binary tree are: "
  <<countNodes(root);
  return 0;
}
