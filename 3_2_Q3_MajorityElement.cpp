#include<bits/stdc++.h>
using namespace std;
/*Better Approach=>
TC=O(NlogN)+O(N)
SC=O(N)
Keys in maps are inserted in sorted order(for ordered maps only)*/
int majorityElement(vector<int>& a) {
    map<int,int> m;
    for(int i=0;i<a.size();i++)
    {
        m[a[i]]++;
    }
    for(auto &it:m)
    {
        if(it.second>(a.size()/2))
        {
            return it.first;
        }
    }
    return -1;
}
/*Optimal approach=>
improve space and time complexity
TC=O(N)
SC=O(1)
See the document again and understand the intuition perfectly.
*/
int majorityElement1(vector<int>& a) {
    int cnt=0;
    int ele;
    for(int i=0;i<a.size();i++)
    {
        if(cnt==0)
        {
            cnt=1;
            ele=a[i];
        }
        else if(ele==a[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<a.size();i++)
    {
        if(ele==a[i]) cnt1++;
    }
    if(cnt1>(a.size()/2))
    {
        return ele;
    }
    return -1;
}


int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement1(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}