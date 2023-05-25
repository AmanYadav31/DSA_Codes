#include<bits/stdc++.h>
using namespace std;
/*Brute force approach
TC=O(N^2)
SC=O(1)*/
vector<int> twoSum2(int n, vector<int> &arr, int target) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}
/*Optimal approach using map=>
TC=O(NlogN)
SC=O(N)*/
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    map<int,int> s;
    for(int i=0;i<nums.size();i++)
    {
        int rem=target-nums[i];
        if(s.find(rem)!=s.end())
        {
            ans.push_back(i);
            ans.push_back(s[rem]);
            break;
        }
        s.insert({nums[i],i});
    }
    return ans;
    
}
/*Optimal approach when map cannot be used
TC=O(N)+O(NlogN)
SC=O(1)*/
string twoSum1(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum( arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}