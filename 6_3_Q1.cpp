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
/*This is the normal method with 
TC=O(N)+O(N/2)
Sc=O(1)
*/
int getMiddle1(Node *head)
{
    int count=0;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    Node* p=head;
    if(count%2==0)
    {
        for(int j=1;j<(count/2)+1;j++)
        {
            p=p->next;
        }
        return p->data;
    }
    else
    {

        for(int j=1;j<=(count/2);j++)
        {
            p=p->next;
        }
        return p->data;
    }
}

//Method 2 =>
/*This is know as Tortoise Hare Method
TC=O(N/2) --taking only that of slow pointer--
SC=O(1)
If we want that when it is even we want the first middle element instead of the second then we have two
approaches:
a)go to second last
b)take one more pointer which is one step slower than the slow pointer
*/
int getMiddle2(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
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

    cout<<"Middle ELement is: "<<getMiddle2(head)<<endl;

    return 0;
}