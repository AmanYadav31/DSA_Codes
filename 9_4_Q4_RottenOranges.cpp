#include<bits/stdc++.h>
using namespace std;
/*Optimal Approach=>
striver's
TC=O(N*M)
SC=O(N*M)*/
int orangesRotting(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>> s;
    vector<vector<int>> visited(n, vector<int>(m));
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                s.push({{i,j},0});
                visited[i][j]=2;
            }
            else
            {
                visited[i][j]=0;
            }
            if(grid[i][j]==1)
            {
                count++;
            }
        }
    }
    int cnt=0;
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    int tmax=0;
    while(!s.empty())
    {
        int ni=s.front().first.first;
        int mi=s.front().first.second;
        int ti=s.front().second;
        s.pop();
        tmax=max(tmax,ti);
        for(int i=0;i<4;i++)
        {
            int nrow=ni+drow[i];
            int ncol=mi+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1)
            {
                s.push({{nrow,ncol},ti+1});
                visited[nrow][ncol]=2;
                cnt++;
            }
        }
    }
    if(count!=cnt)
    {
        return -1;
    }
    /*One way to is this also:*/
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==0 && grid[i][j]==1)
            {
                return -1;
            }
        }
    }*/
    return tmax;
}
int main()
{
    cout<<"Enter size of the array:"<<endl;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int a= orangesRotting(arr);
    cout<<"The solution:"<<a<<endl;
    return 0;
}