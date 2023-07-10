#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, const int drow[], const int dcol[],vector<pair<int,int>> &temp,int base_row,int base_col) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    temp.push_back({row-base_row,col-base_col});
    for (int i = 0; i < 4; ++i) {
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m && !vis[new_row][new_col] && grid[new_row][new_col] == 1) {
            dfs(grid, vis, new_row, new_col, drow, dcol,temp,base_row,base_col);
        }
    }
}
/*Optimal Approach=>
TC=O(N*M+N*M*4+Log(N*M)(insertion into set))
SC=O(N*M)*/
int countDistinctIslands(vector<vector<int>>& grid) {
    // code here
    int n=grid.size();
    int m=grid[0].size();
    set<vector<pair<int,int>>> st;
    const int drow[] = {-1, 0, 1, 0};
    const int dcol[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                vector<pair<int,int>> temp;
                dfs(grid,vis,i,j,drow,dcol,temp,i,j);
                st.insert(temp);
            }
        }
    }
    return st.size();
}
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int distinctIslands = countDistinctIslands(grid);
    cout << "Number of distinct islands: " << distinctIslands << endl;

    return 0;
}
