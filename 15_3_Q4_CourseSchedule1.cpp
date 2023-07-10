#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<int>& vis, vector<vector<int>>& adj, vector<int>& pathVisit) {
    vis[node] = 1;
    pathVisit[node] = 1;

    for (auto adjacentNode : adj[node]) {
        if (vis[adjacentNode] == -1) {
            if (dfs(adjacentNode, vis, adj, pathVisit))
                return true;
        } else if (pathVisit[adjacentNode] == 1) {
            return true;
        }
    }

    pathVisit[node] = 0;
    return false;
}

/*This was Using DFS -- Same as finding cycle in a directed graph--
TC=O(V+E)
SC=O(V+E)

We can also use Kahn's Algorithm to solve this. See the next question for that. In the next question we 
have to also result the order which can we solved only by using that approach and not this one.*/
bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(N);
    for (const auto& prereq : prerequisites) {
        adj[prereq.first].push_back(prereq.second);
    }

    vector<int> vis(P, -1);
    vector<int> pathVisit(P, 0);
    for (int i = 0; i < P; i++) {
        if (vis[i] == -1) {
            if (dfs(i, vis, adj, pathVisit))
                return false;
        }
    }
    return true;
}

/*GFG WAAla=>
bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
        for (const auto& prereq : prerequisites) {
            adj[(prereq.first)].push_back(prereq.second);
        }

        vector<int> vis(N, -1);
        vector<int> pathVisit(N, 0);
        for (int i = 0; i < N; i++) {
            if (vis[i] == -1) {
                if (dfs(i, vis, adj, pathVisit))
                    return false;
            }
        }
        return true;
	}*/
int main() {
    // Test case
    int N = 4; // Number of nodes
    int P = 3; // Number of prerequisites
    vector<pair<int, int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};

    bool isPossibleCourses = isPossible(N, P, prerequisites);

    if (isPossibleCourses) {
        cout << "All courses can be finished." << endl;
    } else {
        cout << "Cannot finish all courses." << endl;
    }

    return 0;
}
