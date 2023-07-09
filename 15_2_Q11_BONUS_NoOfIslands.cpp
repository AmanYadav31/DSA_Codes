#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>> grid, vector<vector<int>> &vis, int row, int col)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int new_row = row + i;
            int new_col = col + j;
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && grid[new_row][new_col] == '1')
            {
                dfs(grid, vis, new_row, new_col);
            }
        }
    }
}
/*GFG WAALA=>
TC=O(N*M+N*M*9)
SC=O(N*M)*/
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                count++;
                dfs(grid, vis, i, j);
            }
        }
    }
    return count;
}

void dfs1(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col, const int drow[], const int dcol[]) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    for (int i = 0; i < 4; ++i) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && grid[new_row][new_col] == '1') {
            dfs1(grid, vis, new_row, new_col, drow, dcol);
        }
    }
}
/*Leetcode Waala=>
TC=O(N*M+N*M*4)
SC=O(N*M)*/
int numIslands1(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    const int drow[] = {-1, 0, 1, 0};
    const int dcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j] && grid[i][j] == '1') {
                ++count;
                dfs1(grid, vis, i, j, drow, dcol);
            }
        }
    }
    return count;
}
int main()
{
    // Test case
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
