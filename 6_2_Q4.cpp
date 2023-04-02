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
            cout<<ptr->data<<"<->NULL"<<endl;
            ptr=ptr->next;
        }
    }
}
Node* reverseDLL(Node * head)
{
    Node* p=head;
    while(p->next!=NULL)
    {
        head=head->next;
        Node* q=p->prev;
        p->prev=p->next;
        p->next=q;
        p=head;
    }
    Node* r=p->prev;
    p->prev=p->next;
    p->next=r;
    return head;
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

    head=reverseDLL(head);
    LLtraversal(head);
    return 0;
}