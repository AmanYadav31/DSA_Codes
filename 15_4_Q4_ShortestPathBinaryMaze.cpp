#include <bits/stdc++.h>
using namespace std;

class Solution
{
/*ApproachSimilar To dijikstra algorithm=>
Time Complexity: O( 4*N*M ) { N*M are the total cells, for each of which we also check 4 adjacent nodes 
for the shortest path length}, Where N = No. of rows of the binary maze and M = No. of columns of the 
binary maze.

Space Complexity: O( N*M ), Where N = No. of rows of the binary maze and M = No. of columns of the
 binary maze.*/
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] 
                == 1 && dis + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first &&
                        newc == destination.second)
                        return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};


/*Leetcode Waala=>
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<pair<int,pair<int,int>>> s;
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        if(grid[0][0]!=0) return -1;
        dis[0][0]=1;
        s.insert({1,{0,0}});
        if(0==n-1&& 0==m-1) return 1;
        while(!s.empty())
        {
            auto it=*(s.begin());
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            s.erase(it);
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int new_row=r+i;
                    int new_col=c+j;
                    if(new_row>=0&&new_row<n&&new_col>=0&&new_col<m&&grid[new_row][new_col]==0&&d+1<dis[new_row][new_col])
                    {
                        if(dis[new_row][new_col]!=1e9) s.erase({dis[new_row][new_col],{new_row,new_col}});
                        dis[new_row][new_col]=1+d;
                        s.insert({dis[new_row][new_col],{new_row,new_col}});
                        if(new_row==n-1&&new_col==m-1) return 1+d;
                    }
                }
            }
        }
        return -1;
    }
};*/
int main()
{
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}