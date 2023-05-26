#include<bits/stdc++.h>
using namespace std;
/*---------------------------VARIANT 1------------------------------------------------------------*/

/*Brute Force=>
TC=O(N+N/2)
SC=O(N/2+N/2)
  =>O(N)*/
vector<int> RearrangebySign1(vector<int>A, int n)
{
// Define 2 vectors, one for storing positive 
// and other for negative elements of the array.
vector<int> pos;
vector<int> neg;

// Segregate the array into positives and negatives.
for(int i=0;i<n;i++){
    
    if(A[i]>0) pos.push_back(A[i]);
    else neg.push_back(A[i]);
}
  
  // Positives on even indices, negatives on odd.
  for(int i=0;i<n/2;i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
  
  return A;
    
}

/*Optimal Approach=>
TC=O(N)
SC=O(N)*/
vector<int> rearrangeArray(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> a(nums.size(),0);     
    
    int pos=0;
    int neg=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>=0)
        {
            a[pos]=nums[i];
            pos=pos+2;
        }
        else
        {
            a[neg]=nums[i];
            neg=neg+2;
        }
    }
    return a;
    
}

/*-------------------------------------VARIANT 2 (GFG)-------------------------------------------------*/
/*Only approach
Similar to brute force solution of above approach
TC=O(2N)
SC=O(N/2+N/2)
  =>O(N)
  */
vector<int> RearrangebySign2(vector<int>A, int n){
    
  // Define 2 vectors, one for storing positive 
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;
  
  // Segregate the array into positives and negatives.
  for(int i=0;i<n;i++){
      
      if(A[i]>=0) pos.push_back(A[i]);
      else neg.push_back(A[i]);
  }
  
  // If positives are lesser than the negatives.
  if(pos.size() < neg.size()){
      
    // First, fill array alternatively till the point 
    // where positives and negatives ar equal in number.
    for(int i=0;i<pos.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
    }
    
    // Fill the remaining negatives at the end of the array.
    int index = pos.size()*2;
    for(int i = pos.size();i<neg.size();i++){
        
        A[index] = neg[i];
        index++;
    }
  }
  
  // If negatives are lesser than the positives.
  else{
      
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<neg.size();i++){
      
      A[2*i] = pos[i];
      A[2*i+1] = neg[i];
  }
    
    // Fill the remaining positives at the end of the array.
    int index = neg.size()*2;
    for(int i = neg.size();i<pos.size();i++){
        
        A[index] = pos[i];
        index++;
    }
  }
  return A;
    
}
int main() {
    
  // Array Initialisation.
  int n = 9;
  vector<int> A {9 ,4, -2, -1, 5, 0, -5, -3, 2};

  vector<int> ans = RearrangebySign2(A,n);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}