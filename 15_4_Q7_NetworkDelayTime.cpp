#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

/*Djikstra Algorithm=>
TC=O(ElogV)
SC=O( |E| + |V| )
*/
int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
    ios_base::sync_with_stdio(false);
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }
    vector<int> dis(n + 1, 1e9);
    set<pair<int, int>> s;
    s.insert({0, k});
    dis[k] = 0;
    int maxi = INT_MIN;
    while (!s.empty()) {
        auto it = *(s.begin());
        int weight = it.first;
        int node = it.second;
        s.erase(it);
        for (auto it : adj[node]) {
            if (weight + it.second < dis[it.first]) {
                if (dis[it.first] != 1e9) s.erase({dis[it.first], it.first});
                dis[it.first] = weight + it.second;
                s.insert({dis[it.first], it.first});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 1e9) return -1;
        maxi = max(maxi, dis[i]);
    }
    return maxi;
}

int main() {
    // Example usage of the function
    vector<vector<int>> edges = {{1, 2, 1}, {2, 3, 2}, {1, 3, 4}};
    int n = 3;
    int k = 1;
    int result = networkDelayTime(edges, n, k);
    cout << "Max network delay time: " << result << endl;

    return 0;
}
