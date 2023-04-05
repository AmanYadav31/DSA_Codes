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

Node* divide(int N, Node* head)
{
    Node* dummy=NULL;
    if(head->data%2==0)
    {
        dummy=head;
    }
    int count=0;
    Node* ptr=head;
    Node* p=head;
    Node* next=head->next;
    while(next!=NULL)
    {
        if(next->data%2==0)
        {
            if(dummy==NULL||dummy->next!=next)
            {
                Node* p1=next->next;
                p->next=next->next;
                if(dummy==NULL)
                {
                    next->next=head;
                    head=next;
                    dummy=next;
                }
                else
                {
                    next->next=dummy->next;
                    dummy->next=next;
                    dummy=dummy->next;
                }
                next=p1;
                count++;
            }
            else
            {
                p=p->next;
                next=next->next;
                dummy=dummy->next;
                count++;
            }
        }
        else
        {
            p=p->next;
            next=next->next;
            count++;
        }
    }
    return head;
}

int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,17);
    head=insertAtEnd(head,15);
    head=insertAtEnd(head,8);
    head=insertAtEnd(head,9);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,4);
    head=insertAtEnd(head,6);
    LLtraversal(head);

    head=divide(7,head);
    LLtraversal(head);

    return 0;
}