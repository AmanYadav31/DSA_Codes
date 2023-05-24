#include<bits/stdc++.h>
using namespace std;
/*Method 1=>
Made by me
TC=O((M+N)log(M+N))
SC=O(M+N)
inserion takes logN time

We can also use unordered set but it would be the same thing as insertion would take O(1) time but
sorting it would take O((M+N)log(M+N))

We can also use map for the same.
The code for the same is attached below.
*/
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr1[i]);
    }
    for(int i=0;i<m;i++)
    {
        s.insert(arr2[i]);
    }
    vector<int> v;
    for(auto & it:s)
    {
        v.push_back(it);
    }
    return v;
    //Your code here
    //return vector with correct order of elements
}
/*
------------------------For Map----------------------------------
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}
-------------------------------------------------------------------
*/
/*Method 2=>
Optimal Approach
Using 2 pointer approach
TC=O(M+N)
SC=O(M+N)
SC ko hum log O(1) bhi kah sakte kyonki isme humlog answer jisme stor karte usko nahi lete. Agar kuch 
extra istemaal kiya hai toh usko lete hain.
*/
vector<int> findUnion1(vector<int> arr1, vector<int> arr2, int n, int m)
{
    vector<int> uni;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            if(uni.size()==0 || uni.back()!=arr1[i])
            {
                uni.push_back(arr1[i]);
            }          
            i++;
        }
        else
        {
            if(uni.size()==0 || uni.back()!=arr2[j])
            {
                uni.push_back(arr2[j]);
            } 
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (uni.back() != arr1[i])
        uni.push_back(arr1[i]);
        i++;
    }
    while (j < m) // IF any element left in arr2
    {
        if (uni.back() != arr2[j])
        uni.push_back(arr2[j]);
        j++;
    }
    return uni;

}
vector<int> findintersectin(vector<int> arr1, vector<int> arr2, int n, int m)
{
    vector<int> inter;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<=arr2[j])
        {
            if(arr1[i]==arr2[j] && (inter.size()==0 || inter.back()!=arr1[i]))
            {
                inter.push_back(arr1[i]);
            }          
            i++;
        }
        else
        {
            j++;
        }
    }
    return inter;
}
int main()
{
    int n;
    cout<<"Enter size of the array 1:"<<endl;
    cin>>n;
    vector<int> arr1;
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        arr1.push_back(val);
    }
    int m;
    cout<<"Enter size of the array 2:"<<endl;
    cin>>m;
    vector<int> arr2;//agar bracket mein kuch likhte ho toh utte 0 lag jaate hai aur phir agar
    //uske baad push_back karoge toh unn 0 ke baad add hoga naya element
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<m;i++)
    {
        int val;
        cin>>val;
        arr2.push_back(val);
    }
     
    vector<int> v=findintersectin(arr1,arr2,n,m);
    cout<<"Final array:"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}