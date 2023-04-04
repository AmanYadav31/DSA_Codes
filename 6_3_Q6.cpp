#include<iostream>
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
int countNodesinLoop(struct Node *head)
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
            int count=1;
            Node* p=entry->next;
            while(p!=entry)
            {
                count++;
                p=p->next;
            }
            return count;
        }
    }
    return 0;
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

    cout<<"Length of self loop is: "<<countNodesinLoop(head)<<endl;

    return 0;
}