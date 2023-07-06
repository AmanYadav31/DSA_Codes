#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < adj[u].size(); j++) {
            if (adj[u][j] == 1) {
                if (!visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

/*
TC=O(V+E)
SC=O(V)

The time complexity of the numProvinces function, which calls the BFS function, is O(V + E), where V is 
the number of vertices and E is the number of edges in the graph represented by the adjacency matrix.

The numProvinces function performs a loop over all the vertices (V iterations), and for each unvisited 
vertex, it calls the BFS function. The BFS function then visits all the vertices connected to the 
current vertex, which takes O(E) time. Therefore, the overall time complexity is O(V + E).

The space complexity is O(V), as it requires additional space to store the visited vector, which keeps 
track of visited vertices. The size of the visited vector is equal to the number of vertices (V), and no 
additional space is used in a significant manner.*/

int numProvinces(vector<vector<int>>& adj, int V) {
    vector<bool> visited(V, false);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            BFS(adj, i, visited);
            count++;
        }
    }
    return count;
}

int main() {
    // Example usage
    vector<vector<int>> adjacencyMatrix = {
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };
    int numVertices = 4;
    int result = numProvinces(adjacencyMatrix, numVertices);
    cout << "Number of provinces: " << result << endl;
    
    return 0;
}
