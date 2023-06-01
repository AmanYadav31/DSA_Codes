#include <bits/stdc++.h>
using namespace std;
/*GFG Waala Brute Force=>
Time Complexity: O(n+m) + O(n+m), where n and m are the sizes of the given arrays.
Reason: O(n+m) is for copying the elements from arr1[] and arr2[] to arr3[]. And another O(n+m) is for 
filling back the two given arrays from arr3[].

Space Complexity: O(n+m) as we use an extra array of size n+m.*/
void merge0(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

/*gfg Waala=>
Optimal Approach 1
Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), where n and m are the sizes of the given arrays.
Reason: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the 
two arrays.

Space Complexity: O(1) as we are not using any extra space.*/
void merge(long long arr1[], long long arr2[], int n, int m) {
    int i=n-1;
    int j=0;
    while(i>=0 && j<m)
    {
        if(arr1[i]>arr2[j])
        {
            swap(arr1[i],arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

/*GFG Waala=>
Optimal Approach 2
TC=O((M+N)log(M+N))
SC=O(1)*/
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge1(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}
/*Leetcode Waala Optimal Approach using optimal of previous type=>
TC=O((M+N)log(M+N)+M)
SC=O(1)
Runtime=3ms*/
void merge2(vector<int>& nums1, int n, vector<int>& nums2, int m) {
    ios_base::sync_with_stdio(false);
    int length=(m+n);
    int gap=(length/2)+(length%2);
    while(gap>0)
    {
        int left=0;
        int right=left+gap;
        while(right<length)
        {
            if(left<n && right>=n)
            {
                if(nums1[left]>nums2[right-n]) swap(nums1[left],nums2[right-n]);
            }
            else if(left>=n)
            {
                if(nums2[left-n]>nums2[right-n]) swap(nums2[left-n],nums2[right-n]);
            }
            else
            {
                if(nums1[left]>nums1[right]) swap(nums1[left],nums1[right]);
            }
            right++;
            left++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
    for(int i=n;i<(m+n);i++)
    {
        nums1[i]=nums2[i-n];
    }
}
/*Leetcode Waala=>
Optimal Approach=>
TC=O(M+N)
SC=O(1)
Runtime=0ms --Mere mrin 3ms mein chala*/
void merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = n + m - 1, p1 = m - 1, p2 = n - 1;
    while(p >= 0 && p1 >= 0 && p2 >= 0) {
        if(nums1[p1] > nums2[p2]) {
            nums1[p--] = nums1[p1--];
        } else {
            nums1[p--] = nums2[p2--];
        }
    }
    while(p2 >= 0) {
        nums1[p--] = nums2[p2--];
    }
}
int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}