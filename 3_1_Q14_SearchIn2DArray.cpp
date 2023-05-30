#include<bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
TC=O(N*M)
SC=O(1)*/
bool searchMatrix(vector<vector<int>>& mat, int X) 
{
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==X)
            {
                return true;
            }
        }
    }
    return false;
}    

/*Slightly Better Approach=>
1)Traverse each row and perform binary search on each row
TC=O(N*logM)
SC=O(1)*/

/*Better Approach(For LeetCode) & Optimal Approach(For GFG)=>
TC=O(M+N)
SC=O(1)
*/
bool searchMatrix1(vector<vector<int>>& mat, int X) 
{
    int n=mat.size();
    int m=mat[0].size();
    int i=0,j=m-1;
    while(i<n && j>=0)
    {
        if(mat[i][j]==X)
        {
            return true;
        }
        else if(mat[i][j]>X)
        {
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

/*Optimal Approach(For Leetcode)=>
TC=O(N*M)
SC=O(1)
Runtime= 10ms*/
bool searchMatrix2(vector<vector<int>>& mat, int X) 
{
    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=(n*m)-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mat[mid/m][mid%m]==X)
        {
            return true;
        }
        else if(mat[mid/m][mid%m]>X)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return false;
}
/*
--------------------------------------------------------------------------------------------------------
                     REASON FOR USING MID=LOW+(HIGH-LOW)/2 INSTEAD OF MID =(LOW+HIGH)/2
The expression mid = (low + high) / 2 performs the addition of low and high first, and then divides 
the sum by 2. If low and high are large numbers, there is a potential risk of integer overflow, 
especially if the language you are using has limited integer sizes. This could lead to incorrect results
or unexpected behavior.

On the other hand, the expression mid = low + (high - low) / 2 calculates the difference between high 
and low first and then divides it by 2. This approach avoids the issue of integer overflow because it
performs subtraction before division. By subtracting low from high, we ensure that the difference 
between them remains within a manageable range.    
--------------------------------------------------------------------------------------------------------            
*/

/*Optimal Approach =>
Made by me for Leet code
TC=O(N+M)
SC=O(1)*/
bool searchMatrix(vector<vector<int>>& mat, int X) {
    ios_base::sync_with_stdio(false);
    int N=mat.size();
    int M=mat[0].size();
    int col=-1;
    for(int j=0;j<N;j++)
    {
        if(X>=mat[j][0])
        {
            col=j;
        }
        else
        {
            break;
        }
    }
    if(col==-1) return 0;
    for(int i=0;i<M;i++)
    {
        if(X==mat[col][i]) return 1;
    }
    return 0;
}
int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   {{1,2,3,4},
                             {5,6,7,8},
	                         {9,10,11,12},
		                     {13,14,15,16},
                             {17,18,19,20}};
		                     
  cout<<boolalpha<<searchMatrix2(mat,11)<<endl;
  
  return 0;
}
