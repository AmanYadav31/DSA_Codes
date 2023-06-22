#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x): key(x),left(nullptr),right(nullptr) {}
};
/*Optimal Approach=>
Striver's
TC=O(2*height) Uses two loops
SC=O(1)*/
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Your code goes here
    suc=new Node(-1);
    Node* cur=root;
    while(cur!=NULL)
    {
        if(cur->key>key)
        {
            suc=cur;
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
    pre=new Node(-1);
    while(root!=NULL)
    {
        if(root->key<key)
        {
            pre=root;
            root=root->right;
        }
        else
        {
            root=root->left;
        }
    }
    
}


/*Optimal Approach=>
Slightly different than above, uses a single loop
TC=O(height)
SC=O(1)*/
void findPreSuc1(Node* root, Node*& pre, Node*& suc, int key) {
    pre = NULL;
    suc = NULL;
    if (root == NULL)
        return;

    while (root) {
        if (root->key == key) {
            if (root->left) {
                pre = root->left;
                while (pre->right)
                    pre = pre->right;
            }

            if (root->right) {
                suc = root->right;
                while (suc->left)
                    suc = suc->left;
            }
            return;
        } else if (root->key > key) {
            suc = root;
            root = root->left;
        } else {
            pre = root;
            root = root->right;
        }
    }
}

int main() {
    // Test the findPreSuc function

    // Create the tree nodes
    Node* root = new Node(50);
    Node* node1 = new Node(30);
    Node* node2 = new Node(70);
    Node* node3 = new Node(20);
    Node* node4 = new Node(40);
    Node* node5 = new Node(60);
    Node* node6 = new Node(80);

    // Connect the tree nodes
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;

    // Find the predecessor and successor of key=40
    Node* pre = NULL;
    Node* suc = NULL;
    int key = 40;
    findPreSuc(root, pre, suc, key);

    // Print the results
    if (pre)
        std::cout << "Predecessor: " << pre->key << std::endl;
    else
        std::cout << "Predecessor: NULL" << std::endl;

    if (suc)
        std::cout << "Successor: " << suc->key << std::endl;
    else
        std::cout << "Successor: NULL" << std::endl;

    // Clean up the memory
    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}
