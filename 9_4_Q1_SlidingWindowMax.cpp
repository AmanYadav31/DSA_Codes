#include<bits/stdc++.h>
using namespace std;
/*Optimal Approach
TC=O(N)+O(N)
   =>O(N)
SC=O(k)
*/
vector <int> max_of_subarrays(int *arr, int n, int k)
{
    deque<int> d;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        while(!d.empty() && d.front()==i-k)//for removing out of bounds
        {
            d.pop_front();
        }
        while(!d.empty() && arr[d.back()]<arr[i])
        {
            d.pop_back();
        }
        d.push_back(i);
        if(i>=k-1)
        {
            ans.push_back(arr[d.front()]);
        }
    }
    return ans;
    // your code here
}
int main()
{
    cout<<"Enter size of the array:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of k:"<<endl;
    int k;
    cin>>k;
    vector<int> a=max_of_subarrays(arr,n,k);
    cout<<"The solution:"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}