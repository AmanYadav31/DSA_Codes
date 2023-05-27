#include<bits/stdc++.h>
using namespace std;
/*Brute Force
TC=O(N*logN)
SC=O(1) As we are not using any additional space but are altering the original array so might be O(N)
Runtime=79ms
Much better than the below method*/
int findLongestConseqSubseq(vector<int> arr)
{
    ios_base::sync_with_stdio(false);
    int N=arr.size();
    if(N==0) return 0;
    sort(arr.begin(),arr.begin()+N);
    int length=1;
    int maxi=1;
    for(int i=0;i<N-1;i++)
    {
        if(arr[i+1]==(arr[i]+1))
        {
            length++;
        }
        else if(arr[i+1]==(arr[i]))
        {
            continue;
        }
        else
        {
            length=1;
        }
        maxi=max(maxi,length);
    }
    return maxi;
    //Your code here
}
/*Optimal Approach=>
TC=O(N) Assuming hashset takes O(1) to search
SC=O(N) We store a hash set

-------------Runtime=2370ms------------------------------------------
Not that good. Use above approach.
*/
int longestConsecutive(vector < int > & nums) {
  ios_base::sync_with_stdio(false);
  set<int> hashset;
  int longestStreak=0;
  for(int a:nums)
  {
    hashset.insert(a);
  }
  for(int a:nums)
  {
    if(!hashset.count(a-1))
    {
        int curr=a;
        int length=1;
        while(hashset.count(curr+1))
        {
            curr=curr+1;
            length++;
        }
        longestStreak=max(longestStreak,length);
    }
  }
  return longestStreak;
}
int main() {
  vector<int> arr{100,200,1,2,3,4};
  int lon = longestConsecutive(arr);
  cout << "The longest consecutive sequence is " << lon << endl;

}
