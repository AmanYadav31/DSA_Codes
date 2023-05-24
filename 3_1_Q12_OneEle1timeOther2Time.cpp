#include <bits/stdc++.h>
using namespace std;


/*For the leetcode question in which we have to solve this in O(N) and array is unsorted, See the 
documentation provided in striver's sheet*/


/*Optimal Approach:
TC=O(logN)
SC=O(1)
This is the GFG medium question
This method only works for sorted arrays

Logic:
Now check if the mid index value falls in the left half or the right half. If it falls in the 
left half then we change the low value to mid+1 and if it falls in the right half, then we change
 the high index to mid-1. To check it , we used a logic (if(arr[mid]==arr[mid^1]). If mid is an even
  number then mid^1 will be the next odd index , and if the condition gets satisfied, then we can say 
  that we are in the left index, else we can say we are in the right half. But if mid is an odd index,
   then mid^1 takes us to mid-1 which is the previous even index , which is gets equal means we are in
    the right half else left half.
*/
int search(int arr[], int n){
    //code
    int low = 0, high = n - 2;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == arr[mid ^ 1])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[low];
}


int main()
{
    int arr[] = {4, 1, 3, 1, 2,2,5,9,5,3,9};
    int ans = search(arr,11);
    cout << "The single element is: " << ans << endl;
    return 0;
}