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
/*Method 1(Intersection of two linked lists not Y)=>
Made by me-----is rubbish----takes a lot of time
L1=M
L2=N
TC=O(MN)
SC=O(M) such that M>N*/
Node* findIntersection(Node* head1, Node* head2)
{
    Node* ptr1=head1;
    Node* ptr=NULL;
    Node* finall=NULL;
    while(ptr1!=NULL)
    {
        Node* ptr2=head2;
        while(ptr2!=NULL)
        {
            if(ptr1->data==ptr2->data)
            {
                Node* node=(Node*)malloc(sizeof(Node));
                node->data=ptr1->data;
                node->next=NULL;
                if(ptr==NULL)
                {
                    ptr=node;
                    finall=ptr;
                }
                else
                {
                    while(ptr->next!=NULL)
                    {
                        ptr=ptr->next;
                    }
                    ptr->next=node;
                }
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
    return finall;
}
/*Method 2=> (Leetcode question Y)
Brute Force approch
traverse both in O(MN) then return the point where node1==node2
*/

/*Method 3=>
Entering in hash table:
Enter the elements in hash table of the two linked list, check at each insertion if that alraedy exists,
if it does, then that point is the intersection point
TC=O(M+N)
SC=O(M+N)*/

/*Method 4=.
Part1 =>
L1=M
L2=N
M>N(Length)
TC=O(M)(Calculating lenght simultaneously)+ O(M-N)(traversing tillremainder length equivalent to both)
+O(N)(traversing the two LL, length will equal to that of shorter LL )
TC=>O(2M)
SC=O(1)*/
Node* findIntersection(Node* head1,Node* head2)
{
    int count1=0;
    int count2=0;
    Node* ptr1=head1;
    Node* ptr2=head2;
    Node* ptr3=head1;
    Node* ptr4=head2;
    while(ptr1!=NULL)
    {
        count1++;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        count2++;
        ptr2=ptr2->next;
    }
    if(count1>count2)
    {
        int x=count1-count2;
        for(int i=1;i<=x;i++)
        {
            ptr3=ptr3->next;
        }
    }
    else
    {
        int x=count2-count1;
        for(int i=1;i<=x;i++)
        {
            ptr4=ptr4->next;
        }
    }
    while(ptr4!=NULL && ptr3!=NULL)
    {
        if(ptr4==ptr3)
        {
            return ptr3;
        }
        ptr3=ptr3->next;
        ptr4=ptr4->next;
    }
    return NULL;
}

/*Method 4=.
Part2 =>
L1=M
L2=N
M>N(Length)
TC=>O(2M)
SC=O(1)
Is considered to be better than the part1 approach beacuse it is less lengthy and the code is more precious
and crisp*/
Node* findIntersection(Node* head1,Node* head2)
{
    Node* dummy1=head1;
    Node* dummy2=head2;
    while(dummy1!=NULL || dummy2!=NULL)
    {
        if(dummy1==NULL)
        {
            dummy1=head2;
        }
        if(dummy2==NULL)
        {
            dummy2=head1;
        }
        if(dummy1==dummy2)
        {
            return dummy1;
        }
        dummy1=dummy1->next;
        dummy2=dummy2->next;
    }
    return NULL;
}
int main()
{
    cout<<"First List:"<<endl;
    Node* head1=NULL;
    head1=insertAtEnd(head1,9);
    head1=insertAtEnd(head1,6);
    head1=insertAtEnd(head1,4);
    head1=insertAtEnd(head1,2);
    head1=insertAtEnd(head1,3);
    head1=insertAtEnd(head1,8);
    LLtraversal(head1);

    cout<<"Second List:"<<endl;
    Node* head2=NULL;
    head2=insertAtEnd(head2,1);
    head2=insertAtEnd(head2,2);
    head2=insertAtEnd(head2,8);
    head2=insertAtEnd(head2,6);
    LLtraversal(head2);
     
    Node* head3=NULL;
    head3=findIntersection(head1,head2);
    LLtraversal(head3);

    return 0;
}