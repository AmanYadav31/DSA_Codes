#include<bits/stdc++.h>
using namespace std;

void nextLargerElement(vector<int> arr, int n)
{
    int i;
    for(i=0;i<n-1;i++)
    {
        if(arr[i+1]<arr[i])
        {
            arr[i]=arr[i+1];
        }
        else
        {
            arr[i]=-1;
        }
    }
    arr[i]=-1;
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
    cout<<"arr:"<<endl;
    nextLargerElement(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}