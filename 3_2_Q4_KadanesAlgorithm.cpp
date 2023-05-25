#include<bits/stdc++.h>
using namespace std;
/*Optimal approach=>
Kadane's Approach
TC=O(N)
SC=O(1)*/
int maxSubArray(vector<int>& nums) {
    int sum=0;
    int maxi=INT_MIN;
    int substart=-1;
    int subend=-1;
    int start=0;
    for(int i=0;i<nums.size();i++)
    { 
        if(sum==0) start=i;
        sum+=nums[i];
        if(maxi<sum)
        {
            maxi=sum;
            substart=start;
            subend=i;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    cout << "The subarray is: [";
    for (int i = substart; i <= subend; i++) {
        cout << nums[i] << " ";
    }
    cout << "]\n";
    return maxi;
}
int main()
{
    vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    long long maxSum = maxSubArray(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}