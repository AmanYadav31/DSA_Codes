#include<bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
TC=O(N^2)
SC=O(1)
*/
int maxProductSubArray1(vector<int>& nums) {
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        int ans=nums[i];
        for(int j=i+1;j<nums.size();j++)
        {
            maxi=max(maxi,ans);
            ans=ans*nums[j];
        }
        maxi=max(maxi,ans);
    }
    return maxi;
}

/*Optimal Approach=>
TC=O(N)
SC=O(1)
See the document for further understanding and dry run an example.
*/
int maxProductSubArray2(vector<int>& nums) {
    int pre=1;
    int suf=1;
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        pre=pre*nums[i];
        suf=suf*nums[nums.size()-1-i];
        maxi=max(maxi,max(pre,suf));
        if(pre==0) pre=1;
        if(suf==0) suf=1;
    }
    return maxi;
}
int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray1(nums);
    return 0;
}