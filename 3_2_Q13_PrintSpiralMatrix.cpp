#include <bits/stdc++.h>
using namespace std;
/*Optimal Solution=>
Made by me=>
TC=O(N^2)
SC=O(1) //if don't include ans array 
-----Yaad rakho ki jisse return karne ko bola hi hai toh usse SC mein nahi ginte--------------------
Runtime =0ms
*/
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    ios_base::sync_with_stdio(false);
    int m=matrix.size();
    int n=matrix[0].size();
    int i=0;
    int j=0;
    
    int count=0;
    int c=0;
    vector<int> ans(m*n);
    while(count!=(m*n))
    {
        ans[count++]=matrix[i][j];
        if(i==c+1 && j==c && j!=n-1-c) c++;
        if( j!=n-1-c && i==c)
        {
            j++;
        }
        else if( j==n-1-c && i!=m-1-c)
        {
            i++;
        }
        else if(j!=c && i==m-1-c)
        {
            j--;
        }
        else 
        {
            i--;
        }
    }
    return ans;
}
int main() {
    
  //Matrix initialization.
  vector<vector<int>> mat   {{2},
                             {5},
	                         {8},
		                     {11},
                             {14}};
		                     
  vector<int> ans = spiralOrder(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}