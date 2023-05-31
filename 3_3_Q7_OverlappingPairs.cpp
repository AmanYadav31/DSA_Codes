#include <bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
TC=O(NlogN+2N)//2N because we are traversing each pair only two times as we are uding the statements
such as break and continue. it may look like N^2 but is 2N. See the video for better understanding.
SC=O(N)*/

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) 
{
    int n=arr.size();
    sort(arr.begin(),arr.end());//NlogN
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty()&& arr[i][0]<ans.back()[1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(arr[j][0]<=end)
            {
                end=max(end,arr[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
/*Optimal Approach=>
TC=O(NlogN+N)
SC=O(N)*/
vector<vector<int>> mergeOverlappingIntervals1(vector<vector<int>> &arr) 
{
    int n=arr.size();
    sort(arr.begin(),arr.end());//NlogN
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || arr[i][0]>ans.back()[1])//O(N)
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;
}
/*Optimal Approach Made by me=>*/
vector<vector<int>> merge(vector<vector<int>>& arr) {
    ios_base::sync_with_stdio(false);
    sort(arr.begin(), arr.end());
        int n=arr.size();
        int i=0;
        vector<vector<int>> ans;
        vector<int> curr=arr[i++];
        while(i<n)
        {
            if (curr[1] >= arr[i][0]) {
            curr[1] = max(arr[i][1],curr[1]);
            i++;
            }
            else
            {
                ans.push_back(curr);
                curr=arr[i];
                i++;
            }
        }
        ans.push_back(curr);
        return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}