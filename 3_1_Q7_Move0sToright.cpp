#include<bits/stdc++.h>
using namespace std;
/*Method 1=>
Brute Force approach==
TC=O(2N)
SC=O(N)(Worst Case)*/
void pushZerosToEnd(int arr[], int n) {
    int temp[n];
    int k=0;
    for(int i=0;i<n;i++)//O(N)
    {
        if(arr[i]!=0)
        {
            temp[k++]=arr[i];
        }
    }
    for(int i=0;i<k;i++)//O(k)
    {
        arr[i]=temp[i];
    }
    for(int i=k;i<n;i++)//O(N-k)
    {
        arr[i]=0;
    }
}

/*Method 2=>
Made by me
Better approach=>
TC=O(N+x)
SC=O(1)
Runtime 29ms*/
void pushZerosToEnd1(int arr[], int n) {
	    // code here
    if(n==0)
    {
        return;
    }
    int i=0;
    for(int j=0;j<n;j++)//O{N}
    {
        if(arr[j]!=0)
        {
            arr[i++]=arr[j];
        }
    }
    while(i!=n)//O(x) where x is the number of 0's
    {
        arr[i++]=0;
    }
}
/*Method 3=>
Optimal Approach
TC=O(N)
SC=O(1)
Striver's
Runtime 20ms
*/
void pushZerosToEnd2(int arr[], int n) {
    int j=-1;
    for(int i=0;i<n;i++)//O(x) where x is the number of 0's
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)
    {
        return;
    }
    for(int i=j+1;i<n;i++)//O(N-x)
    {
        if(arr[i]!=0)
        {
            swap(arr[j],arr[i]);
            j++;
        }
    }
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
    pushZerosToEnd2(vect,n);
    cout<<"Final array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<endl;
    return 0;
}