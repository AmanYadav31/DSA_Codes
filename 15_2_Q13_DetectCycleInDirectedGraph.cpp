#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, vector<int> &pathVisit) {
    vis[node] = 1;
    pathVisit[node] = 1;
    // visit adjacent nodes
    for (auto adjacentNode : adj[node]) {
        // unvisited adjacent node
        if (!vis[adjacentNode]) {
            if (dfs(adjacentNode, vis, adj, pathVisit) == true)
                return true;
        } else {
            if (pathVisit[adjacentNode] == 1)
                return true;
        }
    }
    pathVisit[node] = 0;
    return false;
}
/*
Time Complexity: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V 
components. So, another O(V) time complexity.

Space Complexity: O(2N) + O(N) ~ O(2N): O(2N) for two visited arrays and O(N) for recursive stack space.

Hum ek aur array lenge pathVsit karke jo treck rakhega ki hume yeh pata chalega ki koi ek cycle tab hi
form kar sakta agar woh visited bhi ho aur same path pe lie karta ho. SEE the SS for better understanding.*/
bool isCyclic(int V, vector<vector<int>> &adj) {
    vector<int> vis(V, 0);
    vector<int> pathVisit(V, 0);
    // for graph with connected components
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, vis, adj, pathVisit) == true)
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges (source and destination): " << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (isCyclic(V, adj))
        cout << "The graph contains a cycle." << endl;
    else
        cout << "The graph doesn't contain a cycle." << endl;

    return 0;
}
