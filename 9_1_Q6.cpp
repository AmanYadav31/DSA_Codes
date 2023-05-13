#include<iostream>
using namespace std;
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};


struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};
//Function to push an element into the queue.
void MyQueue:: push(int x)
{
    if(front==NULL && rear==NULL)
    {
        front=new QueueNode(-1);
        rear=new QueueNode(-1);
    }
    QueueNode* node=new QueueNode(x);
    if(front->next==NULL)
    {
        front->next=node;
    }
    rear->next=node;
    rear=node;
        // Your Code
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==rear)
    {
        return -1;
    }
    else
    {
        front=front->next;
        int x=front->data;
        front->data=-1;
        return x;
    }
        // Your Code       
}
#include <iostream>

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl; // expecting -1 since the queue is now empty

    return 0;
}
