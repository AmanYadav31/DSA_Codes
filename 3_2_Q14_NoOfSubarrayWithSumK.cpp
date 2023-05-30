#include <bits/stdc++.h>
using namespace std;

/*Optimal Approach=>
TC=O(N*logN)
SC=O(N)
Similar to posyivenegative subarray sum approach
We have used unordered map here as it is faster.

-------------------------------------------------------------------------------------------------------
              DIFFERENECE BETWEEN USE OF ORDERED AND UNORDERED MAP
              
Here are the key differences between std::unordered_map and std::map:

1)Order: std::unordered_map does not maintain any particular order among its elements, whereas std::map
keeps its elements sorted by key in ascending order by default. This means that in an std::unordered_map,
the order of elements is arbitrary, while in an std::map, the elements are sorted based on the keys.

2)Performance: The performance characteristics differ between the two. std::unordered_map provides 
constant-time average complexity O(1) for insertion, deletion, and search operations, assuming a good 
hash function. On the other hand, std::map offers logarithmic time complexity O(log N) for these 
operations, where N is the number of elements in the map.

3)Iteration: As std::unordered_map does not maintain any order, iterating over its elements does not 
guarantee any particular order. In contrast, std::map allows iterating through its elements in ascending 
order of the keys.
------------------------------------------------------------------------------------------------------
*/
int subarraySum(vector<int>& A, int k) {
    ios_base::sync_with_stdio(false);
    int n=A.size();
    unordered_map<long long,int> m;
    long long sum=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==k)
        {
            count++;
        }
        long long rem=sum-k;
        if(m.find(rem)!=m.end())
        {
            count=count+m[rem];
        }
        m[sum]++;
    }
    return count;
}
int main()
{
    vector<int> arr({0,0,0,0,0,0,0,0});
    int ans = subarraySum(arr,0);
    cout << "The length is: " << ans << endl;
    return 0;
}