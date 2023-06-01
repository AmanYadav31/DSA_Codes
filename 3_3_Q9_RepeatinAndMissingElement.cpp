#include<bits/stdc++.h>
using namespace std;
/*Brute Force Approach=>
TC=O(N^2)
SC=O(1)*/
vector<int> findTwoElement(vector<int> arr, int n) {
    int repeating=-1;
    int missing=-1;
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==i) count++;
        }
        if(count==2) repeating=i;
        else if(count==0) missing=i;

        if(repeating!=-1 && missing!=-1)
        {
            break;
        }
    }
    return {repeating,missing};
}
/*Better Approach=>
TC=O(2N)
SC=O(N)*/
vector<int> findTwoElement1(vector<int> arr, int n) {
    int hashtable[n+1]={0};
    int repeating=-1;
    int missing=-1;
    for(int i=0;i<n;i++)
    {
        hashtable[arr[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(hashtable[i]==2) repeating=i;
        else if(hashtable[i]==0) missing=i;
        if(repeating !=-1 && missing!=-1)
        {
            break;
        }

    }
    return {repeating,missing};
    
}
/*Optimal Approach 1=>
Using maths
TC=O(N)
SC=O(1)*/
vector<int> findTwoElement2(vector<int> arr, int n) {
    long long sum=0;
    long long sumsquare=0;
    long long sum1=0;
    long long sumsquare1=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        sum1=sum1+(i+1);
        sumsquare=sumsquare+((long long)arr[i]*arr[i]);
        sumsquare1=sumsquare1+((long long)(i+1)*(i+1));
    }
    long long x=sum1-sum;
    long long y=sumsquare1-sumsquare;
    long long z=y/x;
    long long missing=(x+z)/2;
    long long repeating=z-missing;
    return {(int)repeating,(int)missing};
}
/*Optimal Approach 2=>
USing Xor
TC=O(N)
SC=O(1)*/
vector<int> findTwoElement3(vector<int> a, int n) {
    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}
int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findTwoElement3(a,8);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}