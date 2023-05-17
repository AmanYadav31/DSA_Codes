#include<bits/stdc++.h>
using namespace std;
/*Best approach=>
TC=O(N
SC=O(N)*/
vector <int> calculateSpan(vector<int> price, int n)
{
    stack<pair<int,int>> s;
    vector<int> span(n);
    for(int i=0;i<n;i++)
    {
        int count=1;
        while(!s.empty() && s.top().first<=price[i])
        {
            count+=s.top().second;
            s.pop();
        }
        s.push({price[i],count});
        span[i]=count;
    }
    return span;
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
    vector<int> a=calculateSpan(arr,n);
    cout<<"Final Output:"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}