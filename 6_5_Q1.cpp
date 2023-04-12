#include<iostream>
#include<math.h>
using namespace std;
/*Layering of stucture*/
struct Node
{
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node* insert(Node* head,int x)
{
    Node* ptr=new Node(x);
    Node* dummy=head;
    while(dummy->next!=nullptr)
    {
        dummy=dummy->next;
    }
    dummy->next=ptr;
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
/*GFG Method(Last bacche hue bhi reverse larne hai)*/
Node* reverseKGroup(Node* head, int k)
{
    Node* ptr=head;
    Node* p=head;
    Node* x=nullptr;
    int count=0;
    int d=0;
    while(ptr!=nullptr)
    {
        count++;
        ptr=ptr->next;
    }
    int pointer=0;
    Node* dummy=nullptr;
    while(p!=NULL)
    {
        if(d==1)
        {
            head=dummy;
        }
        if(x!=nullptr)
        {
            x->next=dummy;
        }
        if(dummy!=nullptr)
        {
            while(dummy->next!=nullptr)
            {
                dummy=dummy->next;
            }
            dummy->next=p;
            x=dummy;
        }
        dummy=nullptr;
        for(int i=1;i<=k;i++)
        {
            pointer++;
            Node* next=p->next;
            p->next=dummy;
            dummy=p;
            p=next;
            if(p==nullptr)
            {
                break;
            }
        }
        d++;
    }
    if(d==1)
    {
        head=dummy;
    }
    if(x!=nullptr)
    {
        x->next=dummy;
    }
    if(dummy!=nullptr)
    {
        while(dummy->next!=nullptr)
        {
            dummy=dummy->next;
        }
        dummy->next=p;
        x=dummy;
    }
    return head;
}

/*Leetcode waala=>
Method 1=>
Made by me
Works correctly but is lenghty*/
Node* reverseKGroup1(Node* head, int k)
{
    Node* ptr=head;
    Node* p=head;
    Node* x=nullptr;
    int count=0;
    int d=0;
    while(ptr!=nullptr)
    {
        count++;
        ptr=ptr->next;
    }
    int pointer=0;
    Node* dummy=nullptr;
    while((count-pointer)>=k)
    {
        if(d==1)
        {
            head=dummy;
        }
        if(x!=nullptr)
        {
            x->next=dummy;
        }
        if(dummy!=nullptr)
        {
            while(dummy->next!=nullptr)
            {
                dummy=dummy->next;
            }
            dummy->next=p;
            x=dummy;
        }
        dummy=nullptr;
        for(int i=1;i<=k;i++)
        {
            pointer++;
            Node* next=p->next;
            p->next=dummy;
            dummy=p;
            p=next;
        }
        d++;
    }
    if(d==1)
    {
        head=dummy;
    }
    if(x!=nullptr)
    {
        x->next=dummy;
    }
    if(dummy!=nullptr)
    {
        while(dummy->next!=nullptr)
        {
            dummy=dummy->next;
        }
        dummy->next=p;
        x=dummy;
    }
    return head;
}

/*Method 2=>
Striver's method
TC=O(N/K)(For groups)+O(K)(For traversing ecah group)
TC=>O(N)
SC=O(1)*/
Node* reverseKGroup2(Node* head, int k)
{
    if(head==NULL ||k==1)
    {
        return head;
    }
    Node* dummy=new Node(0);
    dummy->next=head;
    Node *curr=dummy, *pre=dummy, *next=dummy;
    int count=0;
    while(curr->next!=NULL)
    {
        count++;
        curr=curr->next;
    }
    while(count>=k)
    {
        curr=pre->next;
        next=curr->next;
        for(int i=1;i<k;i++)
        {
            curr->next=next->next;
            next->next=pre->next;
            pre->next=next;
            next=curr->next;
        }
        pre=curr;
        count-=k;
    }
    return dummy->next;
}

int main()
{
    Node* head=new Node();
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,3);
    head=insert(head,4);
    head=insert(head,5);
    LLtraversal(head->next);

    head->next=reverseKGroup2(head->next,2);
    LLtraversal(head->next);

    return 0;
}