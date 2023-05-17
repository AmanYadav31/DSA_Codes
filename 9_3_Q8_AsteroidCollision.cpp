#include<bits/stdc++.h>
using namespace std;
/*Optimal approach=>
TC=O(N)
SC=O(N)*/
vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
    stack<int> s;
    for(int i=0;i<N;i++)
    {
        int flag=0;
        while(!s.empty() && asteroids[i]<0 && s.top()>0)
        {
            if(s.top()<abs(asteroids[i]))
            {
                s.pop();
                continue;
            }
            else if(s.top()==abs(asteroids[i]))
            { 
                s.pop();
            }
            flag=1;
            break;
        }
        if(flag==1)
        {
            continue;
        }
        s.push(asteroids[i]);
    }
    vector<int> col(s.size());
    while(!s.empty())
    {
        col[s.size()-1]=s.top();
        s.pop();
    }
    return col;
}
    int main()
{
    
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> a=asteroidCollision(n,arr);
    cout<<"Final Output:"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}