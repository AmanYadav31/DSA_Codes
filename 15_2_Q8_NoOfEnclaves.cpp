#include <iostream>
#include <vector>
#include<queue>
using namespace std;
/*Good Approach=> Approach similar to ReplaceOwithX
Time Complexity: O(N) + O(M) + O(NxMx4) ~ O(N x M),
SC=O(N*M)*/
void dfs(std::vector<std::vector<int>> grid, std::vector<std::vector<int>>& visited, int drow[], int dcol[], int row, int col) {
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !visited[new_row][new_col] && grid[new_row][new_col] == 1) {
            dfs(grid, visited, drow, dcol, new_row, new_col);
        }
    }
}

int numEnclaves(std::vector<std::vector<int>>& grid) {
    std::ios_base::sync_with_stdio(false);
    int n = grid.size();
    int m = grid[0].size();
    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++) {
        if (!visited[i][0] && grid[i][0] == 1) {
            dfs(grid, visited, drow, dcol, i, 0);
        }
        if (!visited[i][m - 1] && grid[i][m - 1] == 1) {
            dfs(grid, visited, drow, dcol, i, m - 1);
        }
    }
    for (int i = 0; i < m; i++) {
        if (!visited[0][i] && grid[0][i] == 1) {
            dfs(grid, visited, drow, dcol, 0, i);
        }
        if (!visited[n - 1][i] && grid[n - 1][i] == 1) {
            dfs(grid, visited, drow, dcol, n - 1, i);
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}
/*Optimal Approach=> Approach Similar to Flood Fill.
Time Complexity: O(NxMx4) ~ O(N x M), For the worst case, assuming all the pieces as land, the BFS 
function will be called for (N x M) nodes and for every node, we are traversing for 4 neighbors, so it 
will take O(N x M x 4) time. 

Space Complexity ~ O(N x M), O(N x M) for the visited array, and queue space takes up N x M locations at 
max. 

DFS gives lesser Runtime*/
int numEnclaves1(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    queue<pair<int,int>> q; 
    int n = grid.size(); 
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    // traverse boundary elements
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            // first row, first col, last row, last col 
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                // if it is a land then store it in queue
                if(grid[i][j] == 1) {
                    q.push({i, j}); 
                    vis[i][j] = 1; 
                }
            }
        }
    }
    
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, +0, -1}; 
    
    while(!q.empty()) {
        int row = q.front().first; 
        int col = q.front().second; 
        q.pop(); 
        
        // traverses all 4 directions
        for(int i = 0;i<4;i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and for land cell
            if(nrow >=0 && nrow <n && ncol >=0 && ncol < m 
            && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1; 
            }
        }
        
    }
    
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            // check for unvisited land cell
            if(grid[i][j] == 1 & vis[i][j] == 0) 
                cnt++; 
        }
    }
    return cnt;        
}
int main() {
    // Example usage
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1}
    };

    int enclaveCount = numEnclaves(grid);
    std::cout << "Number of enclaves: " << enclaveCount << std::endl;

    return 0;
}
