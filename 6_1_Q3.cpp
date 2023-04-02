#include<iostream>
using namespace std;
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
Node* deleteNode(Node* head,int x)
{
    Node* ptr=head;
    if(x==1)
    {
        head=head->next;
        free(ptr);
    }
    else
    {
        int i=1;
        while(i!=x-1)
        {
            ptr=ptr->next;
            i++;
        }
        Node* ptr1=ptr->next;
        ptr->next=ptr1->next;
        free(ptr1);
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
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    head=insertAtEnd(head,4);
    head=insertAtEnd(head,5);
    LLtraversal(head);
    
    head=deleteNode(head,5);
    LLtraversal(head);


}
