#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& adj, int V) {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int it : adj[i]) {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for (int it : adj[x]) {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
    
public:
/*Optimal Approach=>
Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length 
up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.

Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue 
data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency 
list used in the algorithm.*/
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        for (int i = 0; i < N - 1; i++) {
            int mini = min(dict[i].size(), dict[i + 1].size());
            for (int j = 0; j < mini; j++) {
                if (dict[i][j] != dict[i + 1][j]) {
                    adj[dict[i][j] - 'a'].push_back(dict[i + 1][j] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(adj, K);
        string s = "";
        for (int i = 0; i < topo.size(); i++) {
            s = s + char(topo[i] + 'a');
        }
        return s;
    }
};

int main() {
    Solution solution;
    
    string dict[] = {"caa", "aaa", "aab"};
    int N = 3;
    int K = 3;
    
    string result = solution.findOrder(dict, N, K);
    
    cout << "Order: " << result << endl;
    
    return 0;
}
