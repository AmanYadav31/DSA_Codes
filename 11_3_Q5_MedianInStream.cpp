#include <bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
Exceeds Time limit
Every time we call find median, it sorts every time.
*/
class MedianFinder {
public:
    std::vector<int> ans;

    MedianFinder() {

    }

    void addNum(int num) {//O(1)
        ans.push_back(num);
    }

    double findMedian() {
        std::sort(ans.begin(), ans.end());//O(NlogN)
        if (ans.size() % 2 == 0) {
            return static_cast<double>(ans[ans.size() / 2] + ans[(ans.size() / 2) - 1]) / 2;
        }
        else {
            return ans[ans.size() / 2];
        }
    }
};
/*Optimal Approach=>
Uses Two Heaps:
TC=O(logN)
SC=O(N/2+N/2)*/
class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!maxi.empty() && num < maxi.top()) {
            maxi.push(num);
        } else {
            mini.push(num);
        }
        
        int total = maxi.size() + mini.size();
        
        if (maxi.size() > total / 2) {
            mini.push(maxi.top());
            maxi.pop();
        } else if (mini.size() > total / 2 && maxi.size() < total / 2 && mini.size() != 1) {
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        int total = maxi.size() + mini.size();
        
        if (total % 2 == 0) {
            return (double)(mini.top() + maxi.top()) / 2;
        } else {
            return mini.top();
        }
    }
};
int main() {
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(2);
    mf.addNum(8);
    double median = mf.findMedian();
    std::cout << "Median: " << median << std::endl;
    return 0;
}
