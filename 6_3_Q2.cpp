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

//Method 1 =>
/*T/his method id divised by me and takes a lot of time.*/
Node* reverseList1(Node *head)
{
    Node* p=head;
    Node* q=head->next;
    while(q!=NULL)
    {
        p->next=q->next;
        q->next=head;
        head=q;
        q=p->next;
    }
    p->next=NULL;
    return head;
}

//Method 2 =>
/*TC=O(N)*/
Node* reverseList2(Node* head)
{
    Node* dummy=NULL;
    while(head!=NULL)
    {
        Node* next=head->next;
        head->next=dummy;
        dummy=head;
        head=next;
    }
    return dummy;
}

//Method 3=>
/*Recursive technique
Striver*/
Node* reverseList3(Node* head)
{

    if (head == NULL||head->next==NULL)
        return head;

    Node* nnode = reverseList3(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
}

//Method 4 =>
/*Made by me*/
Node* reverseList4(Node* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    Node* y=reverseList4(head->next);
    Node* temp=y;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return y;    
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

    head=reverseList4(head);
    LLtraversal(head);
   


    return 0;
}