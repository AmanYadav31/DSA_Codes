#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
TC=O(V+E) because it is a directed graph
SC=O(V+V) one for indegree, 1 for queue

Intuition=> Jinka indegree 0 hai unko pahle daal denge queue mein phir queue mein se unko uthaayenge aur 
woh jinpe arrow maar rahe unka indegree kam kardenge, agar isme kissi ka 0 hogaya indegree toh usko queue
mein daaldenge aur phir iss process ko repeat karte rahenge.*/
vector<int> topoSort(int V, vector<vector<int>> adj) {
    vector<int> indegree(V);
    for (int i = 0; i < V; i++) {
        for (int it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return ans;
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V); // Adjacency list

    int E; // Number of edges
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges in the format (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> result = topoSort(V, adj);

    cout << "Topological Sort Order: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
