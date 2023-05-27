#include<bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
TC=O(N^2)
SC=O(N)*/
vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

/*Better Approach=>
By me
We can use the concept similar to that of NGE
we check finalli in the array of nge, once that contain -1 will be entered in to the final answer array
TC=O(2N)
SC=O(3N) One for ans array, one for nge array, one for the stack
*/


/*Optimal Approach=>
TC=O(2N)
SC=O(N)*/
vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> ans;
    int max=INT_MIN;
    for(int i=n-1;i>=0;i--)//O(N)
    {
        if(a[i]>=max)
        {
            ans.push_back(a[i]);
            max=a[i];
        }
    }
    reverse(ans.begin(),ans.end());//O(N)
    return ans;
    
}
int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = leaders(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}