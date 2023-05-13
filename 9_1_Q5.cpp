#include<iostream>
#include<list>
using namespace std;

list<int> l1;

void push(int x)
{
    l1.push_back(x);
}
int pop()
{
    if(!l1.empty())
    {
        int x=l1.back();
        l1.pop_back();
        return x;
    }
    else
    {
        return -1;
    }
}
int main()
{
    push(43);
    cout<<" "<<pop();
    push(29);
    cout<<" "<<pop();
    cout<<" "<<pop();
    push(69);
    push(23);
    cout<<" "<<pop();
    /*cout<<"Popped Element:"<<pop()<<endl;
    cout<<"Popped Element:"<<pop()<<endl;*/
    return 0;
}