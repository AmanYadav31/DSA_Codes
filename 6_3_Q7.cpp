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
Made by me
Is good but not perfect*/
bool isPalindrome(Node* head)
{
    int x=0;
    int count1 = 0;
    Node* t=head;
    while(t!=NULL)
    {
        count1++;
        t=t->next;
    }
    Node* ptr=head;
    while(x<(count1-x-1))
    {
        Node* pass=head;
        for(int i=1;i<count1-x;i++)
        {
            pass=pass->next;
        }
        if(pass->data==ptr->data)
        {
            ptr=ptr->next;
            x++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
/*Method 2=>
Striver Method
TC=O(N/2)(Finding middle element)+O(N/2)(reversing the linked list from the element to the next 
of middle element)+O(N/2)(Comparing the two livked List)
SC=O(1)*/
bool isPalindrome1(Node* head)
{
    Node* ptr=head;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* point=slow->next;
    Node* dummy=NULL;
    while(point!=NULL)
    {
        Node* next=point->next;
        point->next=dummy;
        dummy=point;
        point=next;
    }
    slow->next=dummy;
    slow=slow->next;
    while(slow!=NULL)
    {
        if(ptr->data==slow->data)
        {
            ptr=ptr->next;
            slow=slow->next;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,3);
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,1);
    LLtraversal(head);
    bool d=isPalindrome1(head);
    if(d==0)
    {
        cout<<"Not Palindrome"<<endl;
    }
    else
    {
        cout<<"Palindrome"<<endl;
    }
    return 0;
}