#include<bits/stdc++.h>
using namespace std;

/*Brute Force=>
TC=O(N^2)
SC=O(N)

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
	for (int i = 0; i < n; i++) {
		set<int>s;
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[i]) {
				s.insert(arr[j]);
			}
		}
		cout << s.size() + 1 << " ";
	}

}
*/
/*Optimal approach=>
TC=O(NlogN + N)
SC=O(N+N) waise answer ko return karne waale ko lene ki zaroorat nahi thi*/
vector<int> replaceWithRank(vector<int> &arr, int N){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    vector<int> ans(N);
    for(int i=0;i<N;i++)
    {
        pq.push({arr[i],i});
    }
    int rank=1;
    while(!pq.empty())
    {
        ans[pq.top().second]=rank;
        int x=pq.top().first;
        pq.pop();
        if(!pq.empty() && x!=pq.top().first) rank++;
    }
    return ans;
}
/*Optimal Approach=>
TC=O(N+NlogN+N+N)
  =>NlogN
SC=O(N+N)*/
vector<int> replaceWithRank1(vector<int> &arr, int N){
    map<int,int> p;
    vector<int> temp(N);
    for(int i=0;i<N;i++)
    {
        temp[i]=arr[i];
    }
    sort(temp.begin(),temp.end());
    int rank=1;
    for(int i=0;i<N;i++)
    {
        if(p[temp[i]]==0)
        {
            p[temp[i]]=rank;
            rank++;
        }
    }
    temp.clear();
    for(int i=0;i<N;i++)
    {
        temp[i]=p[arr[i]];
    }
    return temp;
}
int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;
    
    vector<int> arr(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    vector<int> rankedArr = replaceWithRank1(arr, N);
    
    cout << "Ranked array: ";
    for (int i = 0; i < N; i++) {
        cout << rankedArr[i] << " ";
    }
    
    return 0;
}
