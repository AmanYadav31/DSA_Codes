#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> adj, vector<int>& vis, int node, stack<int>& s) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, vis, it, s);
            }
        }
        s.push(node);
    }
/*Optimal Approach=>
TC=O(V+E)
SC=O(V+V)*/
    vector<int> topoSort(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);
        vector<int> ans;
        stack<int> s;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, vis, i, s);
            }
        }
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices (V): ";
    cin >> V;
    cout << "Enter the number of edges (E): ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> result = obj.topoSort(V, adj);

    cout << "Topological order of vertices: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
