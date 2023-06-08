#include <bits/stdc++.h>
using namespace std;
/*Made by me=>
TC=O(NlogN+k*N)
SC=O(N+N+k)
Exceeded Time limit in GFG*/
vector<int> topKFrequent(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    map<int,int> mp;
    for(int i:nums) mp[i]++;//O(NlogN)
    priority_queue<int> pq;
    for(auto i:mp) pq.push(i.second);//O(NlogN)
    vector<int> ans;
    while(k>0)//O(k*N)
    {
        int x;
        for(auto i:mp)//O(N) 
        {
            if(i.second==pq.top())
            {
                x=i.first;
            }
        }
        ans.push_back(x);
        mp.erase(x);
        pq.pop();
        k--;
    }
    return ans;
}
/*Optimal Approach=>
TC=>O(NlogN)
SC=O(N+N+k)*/
vector<int> topKFrequent1(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(false);
    unordered_map<int, int> mp;
    for (int i : nums) //O(N)
    {
        mp[i]++;//O(1)
    }
    priority_queue<pair<int, int>> pq;
    for (auto i : mp) //O(N)
    {
        pq.push({i.second, i.first});//O(logN)
    }
    vector<int> ans;
    while (k > 0) //O(k)
    {
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> result = topKFrequent(nums, k);
    
    cout << "Top " << k << " frequent elements: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
