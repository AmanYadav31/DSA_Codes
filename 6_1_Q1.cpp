#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *constructLL(int A[],int length)
{
    //int length=sizeof(A)/sizeof(A[0]);
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=A[0];
    struct Node *p1=ptr;
    for(int i=1;i<length;i++)
    {
        //cout<<i<<"p1: "<<p1->data<<"ptr: "<<ptr->data<<endl;
        struct Node *p=(struct Node *)malloc(sizeof(struct Node));
        p->data=A[i];
        p->next=NULL;
        ptr->next=p;
        ptr=ptr->next;
    }
    return p1;
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
            cout<<ptr->data<<"->NULL";
            ptr=ptr->next;
        }
    }
}


int main()
{
    cout<<"Enter size of the array: "<<endl;
    int n;
    cin>>n;
    int Array[n];
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>Array[i];
    }

    struct Node *head=constructLL(Array,n);
    LLtraversal(head);
    /*cout<<"The Elements of the array are: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<Array[i]<<" ";
    }*/

    return 0;
}