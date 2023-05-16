#include<bits/stdc++.h>
using namespace std;
/*Striver's approach=>
TC=O(N+N) -- pahla N is for the for loo
             doosra N is for the while as it sometimes runs for 1 time, sometimes 0, sometimes 3
             the total number of times it will run is N.
  =>O(N)
SC=O(N) --N sirf stack waala lete hain kyonki jo humne answer pass karne ke liye store karna hota hai usse
          generally nahi lete hain SC mein
*/
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> nge(n);
    stack<long long> s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            nge[i]=-1;
        }
        else
        {
            nge[i]=s.top();
        }
        s.push(arr[i]);
    }
    return nge;
}
int main()
{
    
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    vector<long long> arr(n);
    cout<<"Enter array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"arr:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    vector<long long> nge(n);
    nge=nextLargerElement(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<nge[i]<<" ";
    }
    return 0;
}