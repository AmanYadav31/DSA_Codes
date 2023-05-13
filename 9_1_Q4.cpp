#include<iostream>
using namespace std;
#include<stack>
stack<int> s1;
stack<int> s2;
/*Method 1=>
TC=O(N)
SC=O(N)
Runtime = 5ms*/
void enqueue(int x)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(x);
    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int dequeue()
{
    if(!s1.empty())
    {
        int x=s1.top();
        s1.pop();
        return x;
    }
    else{
        return -1;
    }
}

/*Method 2=>
TC=O(1) (Amortised ___ Meaning=O(N) hoti jab transfer karenge lekin majority of
                                    time sirf access hi kar rahe toh O(1))
SC=O(N)*/
void enqueue1(int x)
{
    s1.push(x);
}
int dequeue1()
{
    if(s2.empty())
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x=s2.top();
    s2.pop();
    return x;
}
void display(stack<int> s1)
{
    stack<int> s=s1;
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
int main()
{
    enqueue1(1);
    enqueue1(2);
    enqueue1(3);
    display(s1);
    cout<<"Popped Element:"<<dequeue1()<<endl;
    display(s1);
    cout<<"Popped Element:"<<dequeue1()<<endl;
    return 0;
}