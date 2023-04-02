#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

};

Node* insertAtEnd(Node* head, int x)
{
    Node* p=(Node*)malloc(sizeof(Node*));
    Node* ptr=head;
    p->data=x;
    p->next=NULL;
    p->prev=NULL;
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
        p->prev=ptr;
        cout<<p->data<<endl;
    }
    return head;  
}
void LLtraversal(struct Node *ptr)
{
    cout<<"NULL<->";
    while(ptr!=NULL)
    {
        if(ptr->next!=NULL)
        {
            cout<<ptr->data<<"<->";
            ptr=ptr->next;
        }
        else
        {
            cout<<ptr->data<<"<->NULL";
            ptr=ptr->next;
        }
    }
}

Node* deleteNode(Node* head,int x)
{
    Node* p=head;
    if(x==1)
    {
        head=head->next;
        head->prev=NULL;
        free(p);
    }
    else
    {
        int i=1;
        while(i!=x-1)
        {
            i++;
            p=p->next;
        }
        Node* q=p->next;
        Node* r=q->next;
        if(r!=NULL)
        {
            p->next=q->next;
            r->prev=p;
            q->prev=NULL;
            free(q);
        }
        else
        {
             p->next=q->next;
            q->prev=NULL;
            free(q);
        }
    }
    return head;
}
int main()
{
    Node* head=NULL;
    head=insertAtEnd(head,1);
    cout<<"Process 1 done"<<endl;
    head=insertAtEnd(head,2);
    cout<<"Process 2 done"<<endl;
    head=insertAtEnd(head,3);
    cout<<"Process 3 done"<<endl;
    head=insertAtEnd(head,4);
    cout<<"Process 4 done"<<endl;
    head=insertAtEnd(head,5);
    cout<<"Process 5 done"<<endl;

    LLtraversal(head);

    head=deleteNode(head,3);
        LLtraversal(head);



    return 0;
}