#include<bits/stdc++.h>
using namespace std;
/*Optimal Method=>
Striver's
TC=O(N)
SC=O(1)
-----------------------------------Important-------------------------------------------------------
Interviewer ko hamesha bata dena ki extra space kuch nahi li isliye SC=O(1) likha hai lekin
waise algorithm mein toh total SC=O(N) hai. Isse usko pata chalta hai ki tumhare concepts sahi hain
---------------------------------------------------------------------------------------------------
*/
vector<int> rotate(vector<int> arr)
{
    int n=arr.size();
    if(n==0)
    {
        return arr;
    }
    int temp=arr[0];
    for(int i=1;i<n;i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}
int main()
{
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    vector<int> vect;
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        vect.push_back(val);
    }
    vector<int> x=rotate(vect);
    cout<<"Final array:"<<endl;
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
    return 0;
}