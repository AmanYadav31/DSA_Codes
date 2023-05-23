#include<bits/stdc++.h>
using namespace std;
/*TC=O(logN)
SC=O(1)*/
int searchInSorted(int arr[], int N, int k) 
{ 

    // Your code here
    int l=0;
    int h=N-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(k==arr[mid])
        {
            return 1;
        }
        else if(k>arr[mid])
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    return -1;
    
}
int main()
{
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    int vect[n];
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        vect[i]=(val);
    }
    cout<<"Output:"<<searchInSorted(vect,n,5)<<endl;
    return 0;
}