#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node* insertAtBeginning(Node* head,int x)
{
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=x;
    if(head==NULL)
    {
        p->next=NULL;
        head=p;
    }
    else
    {
        p->next=head;
        head=p;
    }
    return head;
}

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
            cout<<ptr->data<<"->NULL";
            ptr=ptr->next;
        }
    }
}

int main()
{
    //cout<<"Enter the linked list: "<<endl;
    Node* head=NULL;
    head=insertAtBeginning(head,1);
    head=insertAtBeginning(head,2);

    head=insertAtBeginning(head,3);

    head=insertAtBeginning(head,4);

    LLtraversal(head);

    return 0;
}