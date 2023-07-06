#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Try to look for new ways so TC=O(V+E)   -- After the graph is finished*/
/*
The time complexity of the printGraph function is O(V + E*log(E)), where V is the number of vertices and 
E is the total number of edges in the graph.

The outer loop iterates over all the vertices, so it has a time complexity of O(V). Within the outer 
loop, the inner loop iterates over the adjacent nodes of each vertex, which has a time complexity of 
O(E), where E is the total number of edges in the graph.

Sorting the adjacent nodes using sort takes O(E*log(E)) time complexity because the number of adjacent 
nodes can be at most E.

Therefore, the overall time complexity of the function is O(V + E*log(E)).

SC=O(V+E)*/


vector<vector<int>> printGraph(int V, vector<vector<int>> adj) {
    vector<vector<int>> newAdj(V);

    for (int i = 0; i < V; i++) {
        newAdj[i].push_back(i);  // Add the vertex itself at the first position

        for (int j = 0; j < adj[i].size(); j++) {
            int adjacentNode = adj[i][j];
            newAdj[i].push_back(adjacentNode);  // Add adjacent nodes
        }

        sort(newAdj[i].begin() + 1, newAdj[i].end());  // Sort the adjacent nodes
    }

    return newAdj;
}

int main() {
    int V;  // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);;  // Array of vectors to represent adjacency list

    cout << "Enter the adjacency list:\n";
    for (int i = 0; i < V; i++) {
        int numAdjacentNodes;
        cout << "Enter the number of adjacent nodes for vertex " << i << ": ";
        cin >> numAdjacentNodes;

        cout << "Enter the adjacent nodes for vertex " << i << ": ";
        for (int j = 0; j < numAdjacentNodes; j++) {
            int adjacentNode;
            cin >> adjacentNode;
            adj[i].push_back(adjacentNode);
        }
    }

    vector<vector<int>> result = printGraph(V, adj);

    cout << "Graph representation:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
