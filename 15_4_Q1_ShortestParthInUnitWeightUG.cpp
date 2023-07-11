#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
/*
Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) 
{ for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array}
~ O(N+2M). 

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) 
{for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
*/
vector<int> shortestPath(vector<vector<int>>& edge, int N, int M, int src) {
    vector<vector<int>> adj(N);
    
    // Build adjacency list
    for (int i = 0; i < M; i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;
    
    queue<pair<int, int>> q;
    q.push({src, 0});
    
    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();
        
        for (int it : adj[node]) {
            if (distance + 1 < dist[it]) {
                dist[it] = distance + 1;
                q.push({it, dist[it]});
            }
        }
    }
    
    for (int& d : dist) {
        if (d == INT_MAX) {
            d = -1;
        }
    }
    
    return dist;
}

int main() {
    // Example usage
    int N = 5;  // Number of nodes
    int M = 7;  // Number of edges
    
    // Edge list
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 3}};
    
    int source = 0;  // Source node
    
    vector<int> shortestDistances = shortestPath(edges, N, M, source);
    
    // Print the shortest distances from the source node
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }
    
    return 0;
}
