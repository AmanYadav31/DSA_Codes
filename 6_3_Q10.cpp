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
/*Method 1=>
TC=O(N)+O(N)
SC=O(1)
Time Complexity is not good*/
int getNthFromLast(Node *head, int n)
{
    int count=0;
    Node* p=head;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    if(n>count)
    {
        return -1;
    }
    Node* ptr=head;
    for(int i=1;i<=count-n;i++)
    {
        ptr=ptr->next;
    }
    return ptr->data;
}
/*Method 2=>
Striver's Method
TC=O(N)
SC=O(1)*/
Node* getNthFromLast1(Node *head, int n)
{
    Node* start=new Node();
    start->next=head;
    Node* slow=start;
    Node* fast=start;
    for(int i=1;i<=n;i++)
    {
        fast=fast->next;
    }
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return start->next;
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
    head=insertAtEnd(head,7);
    head=insertAtEnd(head,8);
    head=insertAtEnd(head,9);
    LLtraversal(head);

    Node* x=getNthFromLast1(head,2);
    LLtraversal(x);
    cout<<"Element is "<<x->data<<endl;

    return 0;
}