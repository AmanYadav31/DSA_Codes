#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*Optimal Approach=>
TC=O(NlogK)
SC=O(K)

Leetcode waaala*/
class KthLargest {
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq; // Min-Heap

public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        ios_base::sync_with_stdio(false);
        if (pq.size() < K) {
            pq.push(val);
        } else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/*GFG WAALA=>
*/
vector<int> kthLargest1(int k, int arr[], int n) {
    // code here
    vector<int> ans(n);

    // Creating a min-heap using priority queue
    priority_queue<int, vector<int>, greater<int> > pq;
    
    // Iterating through each element
    for (int i = 0; i < n; i++) {
        // If size of priority
        // queue is less than k
        if (pq.size() < k)
            pq.push(arr[i]);
        else {
            if (arr[i] > pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
    
        // If size is less than k
        if (pq.size() < k)
            ans[i] = -1;
        else
            ans[i] = pq.top();
    }
    
    return ans;
}
int main() {
    int k = 3;
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(k, nums);
    
    cout << "Enter a value to add (or -1 to exit): ";
    int val;
    while (cin >> val && val != -1) {
        int result = kthLargest.add(val);
        cout << "Kth largest element: " << result << endl;
        cout << "Enter a value to add (or -1 to exit): ";
    }
    
    return 0;
}
