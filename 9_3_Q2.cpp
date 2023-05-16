#include<bits/stdc++.h>
using namespace std;
/*Striver's approach=>
TC=O(2N+2N) -- pahla N is for the for loo
             doosra N is for the while as it sometimes runs for 1 time, sometimes 0, sometimes 3
             the total number of times it will run is N.
  =>O(N)
SC=O(N) --N sirf stack waala lete hain kyonki jo humne answer pass karne ke liye store karna hota hai usse
          generally nahi lete hain SC mein
Runtime=>39ms*/
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> nge(n);
    stack<long long> s;
    for(int i= 2*n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i%n])
        {
            s.pop();
        }
        if(i<n)
        {
            if(s.empty())
            {
                nge[i]=-1;
            }
            else
            {
                nge[i]=s.top();
            }
        }
        s.push(arr[i%n]);
    }
    return nge;
}
/*Same approach=>
Runtime=>19ms
Maine chalaya to =42ms
Toh upar waala hi better hai!!!!!!*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=n-1; i>=0 ; i--)
        {   int t=nums[i];
            s.push(t);
        }
        for(int i=n-1; i>=0 ; i--)
        { int ch=nums[i];
            while(!s.empty() && (s.top()<=ch))
            {
           s.pop();
            }
            if(s.empty())
            {
                ans[i]=-1;
                s.push(ch);
            }
            else
            {
            ans[i]=s.top();
            s.push(ch);
            }
        }
        return ans;
    }
};
/*Mine similar to above fastre approach=>
runtime:32ms
int x=arr[i]; likhne is 35ms se 32ms aagaya
Aur for loop lagane se 39ms se 35ms aagaya*/
vector<int> nextGreaterElements(vector<int>& arr) {
    int n=arr.size();
    vector<int> nge(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        int x=arr[i];
        s.push(x);
    }
    for(int i=n-1;i>=0;i--)
    {
        int x=arr[i];
        while(!s.empty() && s.top()<=x)
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
        s.push(x);
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
    /*
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }*/
    vector<long long> nge(n);
    nge=nextLargerElement(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<nge[i]<<" ";
    }
    return 0;
}