#include<iostream>
using namespace std;
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
void MyStack :: push(int x)
{
    arr[++top]=x;
    // Your Code
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top!=-1)
    {
        return arr[top--];
    }
    else
    {
        return -1;
    }
    // Your Code       
}

int main() {
    MyStack stack;

    // push elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // pop elements from the stack
    cout << stack.pop() << endl; // outputs 3
    cout << stack.pop() << endl; // outputs 2
    cout << stack.pop() << endl; // outputs 1

    return 0;
}