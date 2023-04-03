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
This is better than the bruteforce method.
For this method:
TC-O(N)
SC-O(1)

*/
bool detectLoop(Node* head)
{
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        if(slow==fast)
        {
            return true;
        }
        slow=slow->next;
        fast=fast->next->next;
    }
    return false;
}

/*Method 2=>
Same as above but better running time*/
bool detectLoop2(Node* head)
{
    Node* slow= head;
    Node* fast= head;

        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
            if(fast==slow){
                return true;
            }
        }
        return false;
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

    cout<<boolalpha<<detectLoop2(head)<<endl;


    return 0;
}