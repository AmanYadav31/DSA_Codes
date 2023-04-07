#include<iostream>
#include<math.h>
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

Node* addOne(Node *head) 
{
    Node* dummy=NULL;
    while(head!=NULL)
    {
        Node* next=head->next;
        head->next=dummy;
        dummy=head;
        head=next;
    }
    head=dummy;
    Node* ptr=head;
    int flag=0;
    while(1)
    {
        ptr->data=ptr->data+1;
        if(ptr->data==10)
        {
            ptr->data=0;
            if(ptr->next==NULL)
            {
                flag=1;
                break;
            }
            ptr=ptr->next;
        }
        else
        {
            break;
        }
    }
    if(flag==1)
    {
        Node* node=(Node*)malloc(sizeof(Node));
        node->data=1;
        node->next=NULL;
        ptr->next=node;
    }
    dummy=NULL;
    while(head!=NULL)
    {
        Node* next=head->next;
        head->next=dummy;
        dummy=head;
        head=next;
    }
    return dummy;
}
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,4);   
    head=insertAtEnd(head,9);
    
    LLtraversal(head);

    head=addOne(head);
    LLtraversal(head);

    return 0;
}