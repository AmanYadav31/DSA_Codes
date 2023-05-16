#include<bits/stdc++.h>
using namespace std;
/*TC=O(N)
Sc=O(N)
Optimal
See the last ans conversion to int_64 bit part vv imp
Uske bina submit nahi ho raha tha*/
int sumSubarrayMins(int N, vector<int> &arr) 
{
    int m=1000000007;
    int N=arr.size();
    stack<pair<int,int>> s1;
    stack<pair<int,int>> s2;
    vector<int> left(N); //remember to always initialize the size at the time of declaration
    vector<int> right(N);
    for(int i=0;i<N;i++)
    {
        int count=1;
        while(!s1.empty() && s1.top().first>arr[i])
        {
            count+=s1.top().second;
            s1.pop();
        }
        left[i]=count;
        s1.push({arr[i],count});
    }
    for(int i=N-1;i>=0;i--)
    {
        int count=1;
        while(!s2.empty() && s2.top().first>=arr[i])
        {
            count+=s2.top().second;
            s2.pop();
        }
        right[i]=count;
        s2.push({arr[i],count});
    }/*Yeh part bohot important hai --tab hi submit hua hai*/
    int64_t ans = 0;  // Use int64_t for larger range
    for (int i = 0; i < N; i++) {
        ans = (ans + static_cast<int64_t>(left[i]) * right[i] * arr[i]) % m;
    }
    
    return static_cast<int>(ans); 
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
    cout<<"Output:"<<sumSubarrayMins(n,arr)<<endl;
    return 0;
}