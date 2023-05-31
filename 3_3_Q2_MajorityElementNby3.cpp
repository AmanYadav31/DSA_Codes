#include <bits/stdc++.h>
using namespace std;

/*
An array can have at most 2 majority elements having more than n/3 elements.
*/
/*Better Approach=>
TC=O(N*logN)
SC=O(N)*/
vector<int> majorityElement(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    int n=nums.size();
    unordered_map<int ,int> m;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        m[nums[i]]++;
        if(m[nums[i]]==(n/3)+1) ans.push_back(nums[i]);
        if(ans.size()==2) break;
    }
    return ans;
}
/*Optimal Approach=>
TC=O(N)+O(N)
SC=O(1) //We are storing a max of 2 elements in the ans array, it could be considered as neglegible
*/
vector<int> majorityElement1(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    int n=nums.size();
    vector<int> ans;
    int cnt1=0;
    int cnt2=0;
    int ele1,ele2;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && nums[i]!=ele2)
        {
            cnt1=1;
            ele1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=ele1)
        {
            cnt2=1;
            ele2=nums[i];
        }
        else if(nums[i]==ele1) cnt1++;
        else if(nums[i]==ele2) cnt2++;
        else 
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==ele1) cnt1++;
        else if(nums[i]==ele2) cnt2++;
    }
    if(cnt1>=(n/3)) ans.push_back(ele1);
    if(cnt2>=(n/3)) ans.push_back(ele2);
    return ans;
}
int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}