#include<bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
TC=O(N^2)
SC=O(1)*/
 int reversePairs(vector < int > & arr) {
    int Pairs = 0;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = i + 1; j < arr.size(); j++) {
        if (arr[i] > 2 * arr[j]) Pairs++;
    }
    }
    return Pairs;
}
/*Optimal Approach is similar to the concept of optimal approach used in count inversion question*/
/*Optimal Approach=>
TC=O(NlogN)
SC=O(N)

Time Complexity : O( N log N ) + O (N) + O (N)   

Reason: O(N) – Merge operation, O(N) – counting operation ( at each iteration of i, j doesn’t start from 
0 . Both of them move linearly ) 

Space Complexity : O(N) 

Reason : O(N) – Temporary vector*/
int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
int reversePairs1(vector < int > & arr) {
  return MergeSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> arr{1,3,2,3,1};
  cout << "The Total Reverse Pairs are " << reversePairs1(arr);
}