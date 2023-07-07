#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*Using BFS=>
TC=O(n*m+n*m*4) worst case mein sabko ek baar toh visit karna hoga aur sabke 4 neighnours bhi
SC=O(2*n*m) 1 for visited, 1 for queue*/
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    ios_base::sync_with_stdio(false);
    int n=image.size();
    int m=image[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,0));
    q.push({sr,sc});
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int new_row=row+drow[i];
            int new_col=col+dcol[i];
            if(new_row>=0&&new_row<n&&new_col>=0&&new_col<m&&visited[new_row][new_col]!=1&&image[new_row][new_col]==image[row][col])
            {
                q.push({new_row,new_col});
            }
        }
        if(image[row][col]!=newColor) image[row][col]=newColor;
        visited[row][col]=1;
    }
    return image;
}

/*Using DFS
Time Complexity: O(NxM + NxMx4) ~ O(N x M)

For the worst case, all of the pixels will have the same colour, so DFS function will be called for 
(N x M) nodes and for every node we are traversing for 4 neighbours, so it will take O(N x M x 4) time.

Space Complexity: O(N x M) + O(N x M)

O(N x M) for copied input array and recursive stack space takes up N x M locations at max. 

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor) {
        // color with new color
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
        return ans; 
    }
};*/
int main() {
    // Example usage of the floodFill function
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1;
    int sc = 1;
    int newColor = 2;
    
    vector<vector<int>> result = floodFill(image, sr, sc, newColor);
    
    // Print the resulting image
    for (const auto& row : result) {
        for (int color : row) {
            cout << color << " ";
        }
        cout << endl;
    }
    
    return 0;
}
