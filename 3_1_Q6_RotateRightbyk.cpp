#include<bits/stdc++.h>
using namespace std;
/*Brute Solution=>
TC=O(k)+O(N-k)+O(k)
  =>O(N+k)
SC=O(k)
-----------------Yeh left rotate hai------------------------------
*/
vector<int> rotate(vector<int> arr,int k)
{
    int n=arr.size();
    k=k%n;   //Very Important
    int temp[k];
    for(int i=0;i<k;i++)//O(k)
    {
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++)//O(N-k)
    {
        arr[i-k]=arr[i];
    }
    for(int i=n-k;i<n;i++)//O(k)
    {
        arr[i]=temp[i-(n-k)];
    }
    return arr;
}
/*Optimal solution=>
TC=O(k)+O(N-k)+O(N)
  =>O(2N)    //pichle method se zyada hai
SC=O(1)

-----------------------------------Important-------------------------------------------------------
Vector aur Array mein reverse mein kaise pass kiya hai woh dekho ek baar.

Uss cheez la explaination yeh raha:
The error occurs because the reverse function expects two iterators as arguments, 
but in line 5, you are passing a vector (nums) and an integer (nums + k) as arguments.

In the corrected code, nums.begin() returns an iterator pointing to the beginning of the vector, 
and nums.end() returns an iterator pointing to the end of the vector. By using the appropriate 
iterator ranges, you can perform the desired rotations.
---------------------------------------------------------------------------------------------------*/
/*----------------yeh left rotate hai---------------*/
void leftRotate(int arr[], int n, int d) {
    // code here
    reverse(arr,arr+d);//O(k)
    reverse(arr+d,arr+n);//O(N-k)
    reverse(arr,arr+n);//O(N)
}
/*----------------yeh right rotate hai---------------*/ 
vector<int> rotate1(vector<int>& nums, int k) {
    int n = nums.size();
    k=k%n;
    reverse(nums.begin(), nums.begin() + (n-k));
    reverse(nums.begin() + (n-k), nums.end());
    reverse(nums.begin(), nums.end()); 
    return nums;     
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
    vector<int> x=rotate1(vect,3);
    cout<<"Final array:"<<endl;
    for(int i=0;i<x.size();i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl;
    return 0;
}