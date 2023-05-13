#include<iostream>
#include<queue>
using namespace std;
queue<int> q1;
queue<int> q2;

/*Method 1=>
By Striver
Using 2 Queues*/
void push(int x)
{
    q2.push(x);
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1.swap(q2);

}
int pop()
{
    if(!q1.empty())
    {
        int x=q1.front();
        q1.pop();
        return x;
    }
    else
    {
        return -1;
    }
}
void display(queue<int> q1)
{
    queue<int> q3=q1;
    while(!q3.empty())
    {
        cout<<q3.front()<<endl;
        q3.pop();
    }
}
/*Method 2=>
Striver's
Using 1 Queue*/
void push1(int x)
{
    q1.push(x);
    for(int i=1;i<=q1.size()-1;i++)
    {
        q1.push(q1.front());
        q1.pop();
    }
}
int pop1()
{
    if(!q1.empty())
    {
        int x=q1.front();
        q1.pop();
        return x;
    }
    else
    {
        return -1;
    }
}
int main()
{
    /*
    push(78);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(93);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(28);
    push(60);
    cout<<pop()<<" ";
    push(41);
    push(73);
    push(12);
    push(68);
    cout<<pop()<<" ";
    push(31);
    push(24);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(23);
    push(70);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(12);
    push(30);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(38);
    push(25);
    cout<<pop()<<" ";
    push(14);
    push(92);
    push(57);
    cout<<pop()<<" ";
    push(71);
    push(82);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(28);
    push(6);
    push(30);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(96);
    push(46);
    push(68);
    push(65);
    cout<<pop()<<" ";
    push(88);
    push(77);
    push(89);
    push(4);
    cout<<pop()<<" ";
    push(100);
    push(61);
    push(69);
    cout<<pop()<<" ";
    push(27);
    push(95);
    
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    push(35);
    push(68);
    display(q1);
    cout<<pop()<<" "<<endl;
    cout<<"After";
    display(q1);
    cout<<"Back:"<<q1.back()<<endl;
    cout<<pop()<<" ";
    push(18);
    push(53);
    push(2);
    push(87);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    cout<<pop()<<" ";

    */
    push1(1);
    push1(2);
    push1(3);
    display(q1);
    cout<<"Popped element:"<<pop1()<<endl;
    display(q1);
}