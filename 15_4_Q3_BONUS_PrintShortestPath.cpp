#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.

Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
*/
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<int> dis(n+1);
    vector<int> parent(n+1);
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e9;
        parent[i]=i;
    }
    set<pair<int,int>> s;
    s.insert({0,1});
    dis[1]=0;
    while(!s.empty())
    {
        auto it=*(s.begin());
        int weight=it.first;
        int node=it.second;
        s.erase(it);
        for(auto it:adj[node])
        {
            if(weight+it.second<dis[it.first])
            {
                if(dis[it.first]!=1e9) s.erase({dis[it.first],it.first});
                dis[it.first]=weight+it.second;
                s.insert({dis[it.first],it.first});
                parent[it.first]=node;
            }
        }
    }
    vector<int> ans;
    if(dis[n]==1e9)
    {
        ans.push_back(-1);
        return ans;
    }
    int node=n;
    while(parent[node]!=node)
    {
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>edges[i][j];
        }
    }
    vector<int> ans=shortestPath(n,m,edges);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}