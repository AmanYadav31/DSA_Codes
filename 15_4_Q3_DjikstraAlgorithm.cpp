#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include<bits/stdc++.h>
using namespace std;
/*Method 1=> Using Priority Queue=>
Time Complexity: O( E log(V) ), SEE THE DERIVATION IN SS(**VERY IMPORTANT**)
Where E = Number of edges and V = Number of Nodes.

Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.

In this method we have to check for a few un-necessary conditions like in the priority queue if we have
4,2 and 6,2 then obviously we will pick the 4,2 first at it is smaller but we will have to check for 6,2
even though we won't have to change any values in the distance array or insert any new pair in the 
queue because of it as we already have checked for the smaller first but still we will have to spend
some time on this. In the case of set, we erase the earlier pair so we reduce a few "Possible" iterations
but the erase function used there takes log(N) TC so we cannot say which method is better as it will
vary from question to question. 

If we use queue instead of priority queue, we will still get the correct answer but we will have to make
a lot of unnecessary explorations which could have been avoided. For example, like above the min-heap
sorts 4,2 and 6,2 so we pick the minimum first. But queue won't sort it so we would have explored 6,2
if it would have been first, make changes in array and queue which would be of no use as when we get 4,2
we would have replace them in the array and insert the pairs we would actually need in the future so
a lot of unnecessary exploartions are made while using only queue.


*/
vector<int> dijkstra1(int V, vector<vector<int>> adj[], int S)
{

    // Create a priority queue for storing the nodes as a pair {dist,node}
    // where dist is the distance from source to the node. 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initialising distTo list with a large number to
    // indicate the nodes are unvisited initially.
    // This list contains distance from source to the nodes.
    vector<int> distTo(V, INT_MAX);

    // Source initialised with dist=0.
    distTo[S] = 0;
    pq.push({0, S});

    // Now, pop the minimum distance node first from the min-heap
    // and traverse for all its adjacent nodes.
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        // Check for all adjacent nodes of the popped out
        // element whether the prev dist is larger than current or not.
        for (auto it : adj[node])
        {
            int v = it[0];
            int w = it[1];
            if (dis + w < distTo[v])
            {
                distTo[v] = dis + w;

                // If current distance is smaller,
                // push it into the queue.
                pq.push({dis + w, v});
            }
        }
    }
    // Return the list containing shortest distances
    // from source to all the nodes.
    return distTo;
}

/*Method 2=> Using Set
TC=. Same as above but takes and extra logN for erasing*/
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    set<pair<int, int>> s;
    vector<int> dis(V, 1e9);
    dis[S] = 0;
    s.insert({0, S});

    while (!s.empty()) {
        auto it = *(s.begin());
        int w = it.first;
        int node = it.second;
        s.erase(it);

        for (auto p : adj[node]) {
            if (w + p.second < dis[p.first]) {
                if (dis[p.first] != 1e9) {
                    s.erase({ dis[p.first], p.first });
                }
                dis[p.first] = w + p.second;
                s.insert({ dis[p.first], p.first });
            }
        }
    }

    return dis;
}

int main() {
    // Example usage
    int V = 5; // Number of vertices
    int S = 0; // Source vertex

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> adj(V);
    adj[0].push_back({1, 2}); // Edge from vertex 0 to vertex 1 with weight 2
    adj[0].push_back({2, 4}); // Edge from vertex 0 to vertex 2 with weight 4
    adj[1].push_back({2, 1}); // Edge from vertex 1 to vertex 2 with weight 1
    adj[1].push_back({3, 7}); // Edge from vertex 1 to vertex 3 with weight 7
    adj[2].push_back({3, 3}); // Edge from vertex 2 to vertex 3 with weight 3
    adj[3].push_back({4, 5}); // Edge from vertex 3 to vertex 4 with weight 5

    vector<int> distances = dijkstra(V, adj, S);

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << S << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
