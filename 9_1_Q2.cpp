#include <iostream>
using namespace std;
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    arr[++rear]=x;
        // Your Code
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front==rear)
    {
        return -1;
    }
    else
    {
        return arr[++front];
    }
    
        // Your Code       
}

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.pop() << endl; // Output: 10
    cout << q.pop() << endl; // Output: 20

    q.push(40);

    cout << q.pop() << endl; // Output: 30
    cout << q.pop() << endl; // Output: 40

    cout << q.pop() << endl; // Output: -1 (queue is empty)

    return 0;
}
