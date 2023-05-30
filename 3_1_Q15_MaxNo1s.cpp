#include<bits/stdc++.h>
using namespace std;

/*Optimal Approach=>
Similar approach to search in 2D array
TC=O(M+N)
SC=O(1)*/
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    ios_base::sync_with_stdio(false);
    int i=0;
    int j=m-1;
    int max=0;
    int maxr=-1;
    while(i<n && j>=0)
    {
        if(arr[i][j]==1)
        {
            j--;
            maxr=i;
        }
        else
        {
            i++;
        }
    }
    return maxr;
}

/*Leetcode Waala=>*/
vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {
    ios_base::sync_with_stdio(false);
    int n=arr.size();
    int m=arr[0].size();
    int i=0;
    int j=m-1;
    int max=0;
    int maxr=0;
    for(int k=0;k<n;k++)
    {
        sort(arr[k].begin(),arr[k].begin()+m);
    }
    while(i<n && j>=0)
    {
        if(arr[i][j]==1)
        {
            j--;
            maxr=i;
        }
        else
        {
            i++;
        }
    }
    return {maxr,(m-1)-j};
    
}

int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   {{0,0,1,1},
                             {0,0,1,1},
	                         {0,1,1,1},
		                     {0,0,0,1},
                             {0,0,0,0}};
		                     
  cout<<rowWithMax1s(mat,5,4)<<endl;
  
  return 0;
}
