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
Node* sort(Node* head)
{
    int count=0;
    Node* ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    int x=0;
    while(x<count-1)
    {
        Node* dummy=new Node(); 
        dummy->next=head;       
        Node* first=head;        
        Node* second=head->next;        
        while(second!=NULL)
        {            
            if(first->data>second->data)
            {                
                Node* x=first;                
                first->next=second->next;                
                second->next=x;
                dummy->next=second;                
                if(head==first)
                {                    
                    head=second;
                }
                Node* t=first;
                first=second;
                second=t;                
            }
            first=first->next;
            second=second->next;
            dummy=dummy->next;
        }
        x++;
    }
    return head;

}
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,2);
    head=insertAtEnd(head,1);
    head=insertAtEnd(head,3);
    head=insertAtEnd(head,4);
    head=insertAtEnd(head,5);
    head=insertAtEnd(head,6);
    head=insertAtEnd(head,7);
    head=insertAtEnd(head,8);
    head=insertAtEnd(head,9);
    LLtraversal(head);

    head=sort(head);
    LLtraversal(head);

    return 0;
}