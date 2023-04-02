#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node* prev;

};

Node* insertAtEnd(Node* head, int x)
{
    Node* p=(Node*)malloc(sizeof(Node*));
    Node* ptr=head;
    p->data=x;
    p->next=NULL;
    p->prev=NULL;
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
        p->prev=ptr;
    }
    return head;  
}
Node* add(Node* head,int pos,int data)
{
    Node* p=head;
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->data=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    int i=0;
    while(i!=pos)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->prev=p;
    return head;
}

void LLtraversal(struct Node *ptr)
{
    cout<<"NULL<->";
    while(ptr!=NULL)
    {
        if(ptr->next!=NULL)
        {
            cout<<ptr->data<<"<->";
            ptr=ptr->next;
        }
        else
        {
            cout<<ptr->data<<"<->NULL";
            ptr=ptr->next;
        }
    }
}
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    head=insertAtEnd(head,4);
    head=insertAtEnd(head,5);
    LLtraversal(head);

    head=add(head,2,8);
    LLtraversal(head);
    return 0;
}