#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include<bits/stdc++.h>
using namespace std;
/*Method 1=> Using approach similar to previous question

/*
Time Complexity: O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) 
{ for the BFS Algorithm} + O(N) { for adding the final values of the shortest path in the resultant array}
~ O(N+2M). 

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) 
{for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
*/
vector<int> shortestPath(int N, int M, vector<vector<int>>& edge) {
    vector<vector<pair<int,int>>> adj(N);

    // Build adjacency list
    for (int i = 0; i < M; i++) {
        adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
    }

    vector<int> dist(N, INT_MAX);
    dist[0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;
        q.pop();

        for (auto it : adj[node]) {
            if (distance + it.second < dist[it.first]) {
                dist[it.first] = distance + it.second;
                q.push({it.first, dist[it.first]});
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


/*Method 2=> Using topological sorting and then applying approach similar to above

We use Topolical Sorting because it minimizes the number of searches. We search on basis of reachability.
Example if we have the sort 542136 we know that we cannot reach 4 from 3 and can reach 4 only from 
5 so we have calculated for that before hand. In this way we don't have to make unnecessary searches.

Read the document or see video again if wnat to understand the intuition properly.

Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and
 its adjacent nodes get traversed} ~ O(N+M).

Where N= number of vertices and M= number of edges.

Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest 
distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

Where N= number of vertices and M= number of edges.
*/
    void topoSort(int node, vector < vector<pair < int, int >>> adj,
      vector<int> &vis, stack < int > & st) {
      //This is the function to implement Topological sort. 
      vis[node] = 1;
      for (auto it: adj[node]) {
        int v = it.first;
        if (!vis[v]) {
          topoSort(v, adj, vis, st);
        }
      }
      st.push(node);
    }
    vector < int > shortestPath1(int N, int M, vector < vector < int >> & edges) {

      //We create a graph first in the form of an adjacency list.
      vector < vector<pair < int, int >>> adj(N);
      for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt}); 
      }
      // A visited array is created with initially 
      // all the nodes marked as unvisited (0).
      vector<int> vis(N,0);
      //Now, we perform topo sort using DFS technique 
      //and store the result in the stack st.
      stack < int > st;
      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          topoSort(i, adj, vis, st);
        }
      }
      //Further, we declare a vector ‘dist’ in which we update the value of the nodes’
      //distance from the source vertex after relaxation of a particular node.

      vector < int > dist(N);
      for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
      }

      dist[0] = 0;
      while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it: adj[node]) {
          int v = it.first;
          int wt = it.second;

          if (dist[node] + wt < dist[v]) {
            dist[v] = wt + dist[node];
          }
        }
      }

      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
int main() {
    int N, M;
    cout << "Enter the number of nodes (N): ";
    cin >> N;
    cout << "Enter the number of edges (M): ";
    cin >> M;

    vector<vector<int>> edges(M, vector<int>(3));
    cout << "Enter the edges in the format (source destination weight):" << endl;
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> shortestDistances = shortestPath(N, M, edges);

    cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
