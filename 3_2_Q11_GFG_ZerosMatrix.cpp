#include<bits/stdc++.h>
using namespace std;
/*Approach Using BFS.
Made by me
TC=O(N*M)
SC=O(N*M)
Both are multiplied by some constant*/
void MakeZeros(vector<vector<int> >& matrix) 
{
    // Code here
    int n=matrix.size();
    int m=matrix[0].size();
    queue<pair<int,int>> q;
    vector<vector<int> > score(n, vector<int>(m,0));
    int drow[]={-1,0,1,0};
    int dcol[]={0,1,0,-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                score[i][j]=-5;
                q.push({i,j});
                for(int k=0;k<4;k++)
                {
                    int newrow=i+drow[k];
                    int newcol=j+dcol[k];
                    if(newrow>=0&&newrow<n && newcol>=0&& newcol<m)
                    {
                        score[newrow][newcol]++;
                    }
                }
                
            }
        }
    }
    
    while(!q.empty())
    {
        int sum=0;
        int rowi=q.front().first;
        int coli=q.front().second;
        for(int i=0;i<4;i++)
        {
            int newrow=rowi+drow[i];
            int newcol=coli+dcol[i];
            if(newrow>=0&&newrow<n && newcol>=0&& newcol<m)
            {
                
                if(score[newrow][newcol]>1)
                {
                    sum+=matrix[newrow][newcol];
                    score[newrow][newcol]--;
                }
                else if(score[newrow][newcol]<0)
                {
                    sum+=0;
                    matrix[newrow][newcol]=0;
                }
                else
                {
                    sum+=matrix[newrow][newcol];
                    matrix[newrow][newcol]=0;
                }
            }
        }
        matrix[rowi][coli]=sum;
        q.pop();
    }
    
    
}

/*Approach similar to mine but using less space and without bfs. Concept is same.
*/void MakeZeros1(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> v(matrix);
        for(int i=0; i<n; i++){
           for(int j=0; j<m; j++){
             if(v[i][j]==0){
                  int sum=0;
                  if(i-1>=0 ){
                     sum = sum + v[i-1][j];
                     matrix[i-1][j] = 0;
                  }
                  if(j-1>=0 ){
                     sum = sum + v[i][j-1];
                     matrix[i][j-1] = 0;
                  } 
                  if(i+1<n){
                     sum = sum + v[i+1][j];
                     matrix[i+1][j] = 0;
                  }
                  if(j+1<m ){
                     sum = sum + v[i][j+1];
                     matrix[i][j+1] = 0;
                  } 
                  matrix[i][j] = sum;
        }
        }
    }
    }  
int main() {
    int n, m;
    cin >> n >> m;  // Assuming the input for matrix dimensions

    vector<vector<int>> matrix(n, vector<int>(m));

    // Input matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    MakeZeros(matrix);

    // Output modified matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
 