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
/*Made by me
It is the optimal solution but it is length
See the striver's solution given below*/
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    Node* p1=first;
    Node* p2=second;
    Node* dummy=NULL;
    Node* temp=dummy;
    int carry=0;
    while(p1!=NULL || p2!=NULL)
    {
        int sum=0;
        if(p1==NULL)
        {
            sum=sum+p2->data+carry;
        }
        else if(p2==NULL)
        {
            sum=sum+p1->data+carry;
        }
        else
        {
            sum=sum+p1->data+p2->data+carry;
        }
        carry=sum/10;
        sum=sum%10;
        Node* node=(Node*)malloc(sizeof(Node));
        node->data=sum;
        node->next=NULL;
        if(dummy==NULL)
        {
            dummy=node;
            temp=dummy;
        }
        else
        {
            while(dummy->next!=NULL)
            {
                dummy=dummy->next;
            }
            dummy->next=node;
        }
        p1=p1->next;
        p2=p2->next;
    }
    if(carry!=0)
    {
        Node* node=(Node*)malloc(sizeof(Node));
        node->data=carry;
        node->next=NULL;
        while(dummy->next!=NULL)
        {
            dummy=dummy->next;
        }
        dummy->next=node;
    }
    return temp;
}

/*Striver's Solution*/
Node* addTwoLists1(Node* first, Node* second)
{
    Node* dummy=new Node();
    Node* temp=dummy;
    int carry=0;
    while(first!=NULL || second!= NULL || carry!=0)
    {
        int sum=0;
        if(first!=NULL)
        {
            sum+=first->data;
            first=first->next;
        }
        if(second!=NULL)
        {
            sum+=second->data;
            second=second->next;
        }
        sum+=carry;
        Node* node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
        carry=sum/10;
    }
    return dummy->next;
}

/*Solution to GFG Problem*/
Node* addTwoLists3(Node* first, Node* second)
    {
        Node* dummy1=NULL;
        while(first!=NULL)
        {
            Node* next=first->next;
            first->next=dummy1;
            dummy1=first;
            first=next;
        }
        first=dummy1;
        Node* dummy2=NULL;
        while(second!=NULL)
        {
            Node* next=second->next;
            second->next=dummy2;
            dummy2=second;
            second=next;
        }
        second=dummy2;
        Node* dummy=(Node*)malloc(sizeof(Node));
        Node* temp=dummy;
        int carry=0;
        while(first!=NULL || second!= NULL || carry!=0)
        {
            int sum=0;
            if(first!=NULL)
            {
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL)
            {
                sum+=second->data;
                second=second->next;
            }
            sum+=carry;
            Node* node=new Node(sum%10);
            temp->next=node;
            temp=temp->next;
            carry=sum/10;
        }
        Node* dummy3=NULL;
        Node* temp1=dummy->next;
        while(temp1!=NULL)
        {
            Node* next=temp1->next;
            temp1->next=dummy3;
            dummy3=temp1;
            temp1=next;
        }
        return dummy3;
    }
int main()
{
    Node* head=NULL;
      
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,9);
    head=insertAtEnd(head,0);
    LLtraversal(head);

    Node* head1=NULL;
       
    head1=insertAtEnd(head1,2);
    head1=insertAtEnd(head1,5);
    LLtraversal(head1);
    
    Node* head3=NULL;
    head3=addTwoLists3(head,head1);
    LLtraversal(head3);

    return 0;
}