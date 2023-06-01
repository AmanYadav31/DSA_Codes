#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
/*Variant 1=>
TC=O(r) where r is the given column number
SC=O(1)*/
int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

/*Variant 2=> Approach 1=>
TC=O(n*r)
SC=O(1)*/
void pascalTriangle1(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}
/*Variant 2=> Approach 2=>
TC=O(n)
SC=O(1)*/
void pascalTriangle2(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}
/*Variant 3=>
TC=O(N^2)
SC=O(1) ans aur temp ko nahi lete kyonki woh toh answer nikalne ke liye istemaal kiye na*/
vector<int> generatelist(int rownum)
{
    vector<int> temp;
    temp.push_back(1);
    int ans=1;
    for(int i=1;i<rownum;i++)
    {
        ans=ans*(rownum-i);
        ans=ans/i;;
        temp.push_back(ans);
    }
    return temp;
}
vector<vector<int>> pascalTriangle3(int n) {
    vector<vector<int>> ans;
    for(int c=1;c<=n;c++)
    {
        ans.push_back(generatelist(c));
    }
    return ans;

}
/*Approach made by me=>
TC=O(N^2)
SC=O(N^2)*/
vector<vector<int>> generate(int n) {
    ios_base::sync_with_stdio(false);
    const int MOD = 1e9 + 7;
    vector<vector<int>> tri(n,vector<int>());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 || j==i)
            {
                tri[i].push_back(1);
            }
            else
            {
                tri[i].push_back((tri[i-1][j-1]+tri[i-1][j])%MOD);
            }
        }
        ans.push_back(tri[i]);
    }
    return ans;
}
int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    vector<vector<int>> ans = pascalTriangle3(r);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
        