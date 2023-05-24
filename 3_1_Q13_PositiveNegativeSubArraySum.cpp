#include <bits/stdc++.h>
using namespace std;
/*Brute Force approach=>
TC=O(N^2)
SC=O(1)*/
int getLongestSubarray(vector<int>& a, int k) {
    int n = a.size(); // size of the array.

    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        int s = 0;
        for (int j = i; j < n; j++) { // ending index
            // add the current element to
            // the subarray a[i...j-1]:
            s += a[j];

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}
/*Better approach for positive and 0's.
Optimal Approach for those arrays containg negative numers as well
TC=O(N*logN)
SC=O(N)*/
int lenOfLongSubarr(int A[],  int n, int k) 
{ 
    map<long long,int> m;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==k)
        {
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-k;
        if(m.find(rem)!=m.end())
        {
            int len=i-m[rem];
            maxlen=max(maxlen,len);
        }
        if(m.find(sum)==m.end())//this condition is neccessary if 0 exists in the array
        {
            m[sum]=i;
        }
    }
    return maxlen;
}
/*Optimal approach for postive and 0's
TC=O(2N)
SC=O(1)*/
int lenOfLongSubarr1(int A[],  int n, int k) 
{
    int left=0;
    int right=0;
    long long sum=A[0];
    int maxlen=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=A[left];
            left++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum+=A[right];
        } 
    }
    return maxlen;
}
int main()
{
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    int ans = lenOfLongSubarr1(arr,10,3);
    cout << "The length is: " << ans << endl;
    return 0;
}