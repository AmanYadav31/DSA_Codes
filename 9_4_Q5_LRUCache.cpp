#include<bits/stdc++.h>
using namespace std;
/*Optimal approach=>
TC=O(1)
SC=O(1)
Striver's*/
class LRUCache
{
    public:
    class Node
    {
        public:
        int key;
        int value;
        Node* next;
        Node *prev;
        Node(int key1,int value1)
        {
            key=key1;
            value=value1;
        }
    };
    
    
    
    Node* head= new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node *> m;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        // code here
    }
    
    void addNode(Node* node)
    {
        Node* temp=head->next;
        node->next=temp;
        temp->prev=node;
        head->next=node;
        node->prev=head;
    }
    
    void deleteNode(Node* node)
    {
        Node* nodeprev=node->prev;
        Node* nodenext=node->next;
        nodeprev->next=nodenext;
        nodenext->prev=nodeprev;
    }
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(m.find(key)!=m.end())
        {
            Node* resnode=m[key];
            int res=resnode->value;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key]=head->next;
            return res;
        }
        return -1;
        // your code here
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(m.find(key)!=m.end())
        {
            Node* ptr=m[key];
            deleteNode(ptr);
            m.erase(key);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key]=head->next;
        // your code here   
    }
};
int main() {
    // Creating an LRUCache object with capacity 5
    LRUCache cache(5);

    // Performing cache operations
    cache.SET(1, 10);
    cache.SET(2, 20);
    cache.SET(3, 30);

    int value = cache.GET(2);
    cout << "Value for key 2: " << value << endl;

    cache.SET(4, 40);
    cache.SET(5, 50);
    cache.SET(6, 60);

    value = cache.GET(1);
    cout << "Value for key 1: " << value << endl;

    value = cache.GET(6);
    cout << "Value for key 6: " << value << endl;

    return 0;
}
