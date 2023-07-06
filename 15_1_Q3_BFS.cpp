#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Optimal Approach=>
TC=O(N+2E) har node ke liye liye N aur saare edges ke liye 2N
SC=O(3N)  1 for queue, 1 for visted,1 for bfs array
  =>(N)*/
vector<int> bfsOfGraph(int V, vector<vector<int>> adj) {
    queue<int> q;
    q.push(0);
    vector<int> visited(V, 0);
    visited[0] = 1;
    vector<int> bfs;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        bfs.push_back(x);
        for (auto it : adj[x]) {
            if (!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V; // Number of vertices in the graph
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V); // Adjacency list representation of the graph

    // Input the graph
    for (int i = 0; i < V; i++) {
        int numEdges;
        cout << "Enter the number of edges for vertex " << i << ": ";
        cin >> numEdges;
        cout << "Enter the connected vertices for vertex " << i << ": ";
        for (int j = 0; j < numEdges; j++) {
            int vertex;
            cin >> vertex;
            adj[i].push_back(vertex);
        }
    }

    vector<int> bfs = bfsOfGraph(V, adj);

    cout << "BFS traversal of the graph starting from vertex 0: ";
    for (int i = 0; i < bfs.size(); i++) {
        cout << bfs[i] << " ";
    }
    cout << endl;

    return 0;
}
