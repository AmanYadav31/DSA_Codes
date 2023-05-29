#include<bits/stdc++.h>
using namespace std;
/*See the document for intuition or you can understand from the code as well*/
/*Brute Force(Clockwise)=>
TC=O(N^2)
SC=O(N^2)
*/
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size();
    vector<vector<int>> ans(matrix);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[j][n-i-1]=ans[i][j];
        }
    }

}

/*----------------------------------------------------------------------------------------------------*/
/*Optimal Approach for reversing anticlockwise 90
TC=O(N^2)
SC=O(1)*/
void reverseColumns(vector<vector<int>>& matrix, int n)
{
    for (int j = 0; j < n; j++)
    {
        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            // Swap elements at start and end indices in the column
            int temp = matrix[start][j];
            matrix[start][j] = matrix[end][j];
            matrix[end][j] = temp;

            start++;
            end--;
        }
    }
}
void rotate1(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(false);
    int n=matrix.size();

//O(N/2 * N/2)
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(matrix[i][j],matrix[j][i]);
   //O(N* N/2)
    reverseColumns(matrix, n);
} 
/*Optimal Approach for reversing clockwise 90=>
TC=O(N^2)
SC=O(1)*/
void rotate2(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(false);
    int n=matrix.size();

//O(N/2 * N/2)
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            swap(matrix[i][j],matrix[j][i]);
   //O(N* N/2)
    for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());
} 
int main() {
  vector < vector < int >> arr;
  arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  rotate(arr);
  cout << "Rotated Image" << endl;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

}