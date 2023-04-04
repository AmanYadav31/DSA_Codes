#include<iostream>
#include <unordered_map>
using namespace std;
/*Layering of stucture*/
struct Node
{
    int data;
    Node *next;
};

Node* insertAtEnd(Node* head, int x)
{
    Node* p=(Node*)malloc(sizeof(Node*));
    Node* ptr=head;
    p->data=x;
    p->next=NULL;
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p;
    }
    return head;  
}

void LLtraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        if(ptr->next!=NULL)
        {
            cout<<ptr->data<<"->";
            ptr=ptr->next;
        }
        else
        {
            cout<<ptr->data<<"->NULL"<<endl;
            ptr=ptr->next;
        }
    }
}
/*Method 1=>
TC:O(N)
SC:O(1)
Best approach hai
See the intutition proof from striver video*/
Node* detectCycle1(Node *head) 
{
    Node* slow=head;
    Node* fast=head;
    Node* entry=head;
    while(fast!=NULL && fast->next!=NULL)/*can also write while(fast->next!=NULL && fast->next->next!=NULL) 
    This method wasn't excepted by Leetcode but is correct and was given in 0 ms solution*/
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            while(slow!=entry)
            {
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return NULL;
}
/*Method 2=>
Brute force approach.
USing hash table
TC:O(N)
SC:O(N)
Learn how the unordered map can be used as a hash table*/
Node *detectCycle2(Node *head) {
      if(head==nullptr){
        return nullptr;
      }
        int count=1;
        unordered_map<Node* ,int>mp;
        for(Node *temp=head;temp!=nullptr;temp=temp->next){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp[temp]=count;
            count++;
        }
        return nullptr;
    }

int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    head=insertAtEnd(head,4);
    head=insertAtEnd(head,5);
    head=insertAtEnd(head,6);
    LLtraversal(head);

    cout<<detectCycle2(head)<<endl;

    return 0;
}