#include<bits/stdc++.h>
using namespace std;
int H[100];
int s=-1;
/*
Time Complexity: The time complexity of all the operation is O(log N) except for GetMax() which has 
time complexity of O(1). 

Auxiliary Space: O(N)*/
int parent(int index)
{
    return (index-1)/2;
}

int leftchild(int index)
{
    return ((2*index)+1);
}

int rightchild(int index)
{
    return ((2*index)+2);
}

void shiftup(int index)
{
    while(index>0 && H[index]>H[parent(index)])
    {
        swap(H[parent(index)],H[index]);
        index=parent(index);
    }
}

void shiftdown(int index)
{
    int maxIndex=index;
    int left=leftchild(index);
    if(left<=s && H[left]>H[index])
    {
        maxIndex=left;
    }
    int right=rightchild(index);
    if(right<=s && H[right]>H[maxIndex])
    {
        maxIndex=right;
    }
    if(maxIndex!=index)
    {
        swap(H[maxIndex],H[index]);
        shiftdown(maxIndex);
    }
}
void insert(int x)
{
    s=s+1;
    H[s]=x;
    shiftup(s);
}

int extractMax()
{
    int x=H[0];
    H[0]=H[s--];
    shiftdown(0);
    return x;
}

void changePriority(int index, int p)
{
    int oldPriority=H[index];
    H[index]=p;
    if(p>oldPriority)
    {
        shiftup(index);
    }
    else
    {
        shiftdown(index);
    }
}

int getMax()
{
    return H[0];
}

void remove(int index)
{
    H[index]=getMax()+1;
    shiftup(index);
    extractMax();
}
int main()
{
    insert(5);
    insert(8);
    insert(9);
    insert(1);
    insert(6);
    insert(12);
    insert(2);
    cout<<"Priority Queue:"<<endl;
    for(int i=0;i<=s;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
    cout<<"Max Element:"<<extractMax()<<endl;
    cout<<"Priority Queue after extraction of max:"<<endl;
    for(int i=0;i<=s;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
    changePriority(5,16);
    cout<<"Priority Queue after Change of priority of index 5 to 16:"<<endl;
    for(int i=0;i<=s;i++)
    {
        cout<<H[i]<<" ";
    }
    cout<<endl;
    remove(2);
    cout<<"Priority Queue after removal of index 2:"<<endl;
    for(int i=0;i<=s;i++)
    {
        cout<<H[i]<<" ";
    }
    return 0;
}