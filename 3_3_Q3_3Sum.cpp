#include<bits/stdc++.h>
/*Brute Force Approach=>
TC=O(N^3 * logM) LogM for insertion into set which check uniqueness also sort them before inserting into
set, so you can add another 3Mlog3 for that, where M is the number of triplets
SC=O(3*k) where k is the number of triplets, k for final ans vector and 3 for temp as each time it is
storing only 3 numbers
*/
using namespace std;
vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}
/*Better Approach=> 
Using Map:
TC=O(N^2*logM) whre logM is for inserting in hash map, set se pehle insert karne ke liye sorting ki 
complexity ko bhi alag se include karenge
SC=O(M)+O(N) where M is the number of distnct triplets(in ans vector) and N is for the map*/
vector<vector<int>> threeSum2(vector<int>& nums) {
    int n = nums.size();
    map<int, int> m;
    vector<vector<int>> ans;
    set<vector<int>> uniqueTriplets;  // New set to track unique triplets
    
    for (int i = 0; i < n; i++) {
        m[nums[i]] = i;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            vector<int> temp;
            int rem = 0 - (nums[i] + nums[j]);
            
            if (m.find(rem) != m.end() && m[rem] > j) {
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(rem);
                sort(temp.begin(), temp.end());  // Sort the triplet
                
                if (uniqueTriplets.find(temp) == uniqueTriplets.end()) {
                    ans.push_back(temp);
                    uniqueTriplets.insert(temp);  // Add the triplet to the set
                }
            }
        }
    }
    return ans;
}

/*Optimal Approach=>
TC=O(N*N)
SC=O(1)
Concept similar to that of 2 sum. There we have to find sum=k, here a+b+c=0 can be written as
b+c=-a so now we have to find pairs that result in sum -a.
*/
vector<vector<int>> threeSum3(vector<int>& nums) 
{
    int n=nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-2;i++)
    {
        if(i==0 || (i>0 && nums[i]!=nums[i-1]))
        {
            int low=i+1;
            int high=n-1;
            int sum=0-nums[i];
            while(low<high)
            {
                if(nums[low]+nums[high]==sum)
                {
                    ans.push_back({nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1]) low++;//to avoid dupilcates
                    while(low<high && nums[high]==nums[high-1]) high--;//to avoid duplicates
                    low++;
                    high--;
                    //dry run an example to understand the working more thoroughly
                }
                else if(nums[low]+nums[high]<sum)
                {
                    low++;
                }
                else high--;
            }
        }
    }
    return ans;
}    
/*GFG Question=>
3Sum Closest
TC=O(N^2)
SC=O(1)*/
int closest3Sum(int arr[], int n, int x)
{
    // code here
    // Sort the array
sort(arr, arr+n);

// To store the closest sum
//not using INT_MAX to avoid overflowing condition
int closestSum = 1000000000;

// Fix the smallest number among
// the three integers
for (int i = 0; i < n - 2; i++) {

    // Two pointers initially pointing at
    // the last and the element
    // next to the fixed element
    int ptr1 = i + 1, ptr2 = n - 1;

    // While there could be more pairs to check
    while (ptr1 < ptr2) {

        // Calculate the sum of the current triplet
        int sum = arr[i] + arr[ptr1] + arr[ptr2];
            
            // if sum is equal to x, return sum as
            if (sum == x)
            return sum;
        // If the sum is more closer than
        // the current closest sum
        if (abs(x - sum) < abs(x - closestSum)) {
            closestSum = sum;
        }

        // If sum is greater than x then decrement
        // the second pointer to get a smaller sum
        if (sum > x) {
            ptr2--;
        }

        // Else increment the first pointer
        // to get a larger sum
        else {
            ptr1++;
        }
    }
}

// Return the closest sum found
return closestSum;
}
int main() {
  vector < int > arr { -1, 0, 1, 2, -1, -4};
  vector < vector < int >> ans;
  ans = threeSum3(arr);
  cout << "The triplets are as follows: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}