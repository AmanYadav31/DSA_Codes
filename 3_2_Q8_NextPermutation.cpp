#include <bits/stdc++.h>
using namespace std;
/*Optimal Approach 1=>
Its inside working is given below
TC=O(N)
SC=O(1)
Runtime=0ms
*/
vector<int> nextGreaterPermutation1(vector<int> &A) {
    next_permutation(A.begin(),A.end());
    return A;
}
/*Optimal Approach 2=>
This is the inside working of STL class of next_permutation()
TC=O(N)
SC=O(1)
Runtime=4ms
*/
vector<int> nextGreaterPermutation2(vector<int> &A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1) {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation2(A);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]\n";
    return 0;
}