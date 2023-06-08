#include <bits/stdc++.h>
using namespace std;
/*
Try to understand the intuition. As to why for loop is running k time and why we are expanding the
 element at the top and how can we know if its index expansion can be the next max sum and not any 
 other index that has not been expanded till now.

*/

/*Brute Force Approach=>
TC=O(N^2*logN)
SC=O(N+N)*/
vector<int> maxCombinations(int N, int k, vector<int> &A, vector<int> &B) {
    priority_queue<int> pq;
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            pq.push(A[i] + B[j]);
        }
    }
    vector<int> ans;
    for(int i = 0; i < k; i++) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

/*Optimal Approach=>
TC=O(NlogN)
SC=O(k+N^2+N^2) worst case*/
vector<int> maxCombinations1(int n, int k, vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});//set mein insert hota hai
    vector<int> ans;
    for(int p=0;p<k;p++)
    {
        pair<int, pair<int, int> > temp=pq.top();
        ans.push_back(temp.first);
        int i=temp.second.first;
        int j=temp.second.second;
        pq.pop(); 
        int sum=A[i-1]+B[j];
        if(s.find({i-1,j})==s.end())
        {
            pq.push({sum,{i-1,j}});
            s.insert({i-1,j});
        }
        sum=A[i]+B[j-1];
        if(s.find({i,j-1})==s.end())
        {
            pq.push({sum,{i,j-1}});
            s.insert({i,j-1});
        }  
    }
    return ans;
}
int main() {
    // Example usage
    int N = 3;
    int k = 3;
    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5, 7};
    
    vector<int> result = maxCombinations(N, k, A, B);
    
    cout << "Max Combinations: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
