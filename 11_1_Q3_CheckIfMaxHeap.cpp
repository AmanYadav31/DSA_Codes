#include<bits/stdc++.h>
using namespace std;
/*Made by ME=> Optimal Approach
TC=O(N/2)
SC=O(1)
*/
bool isMaxHeap(int a[], int n)
{
    /*int limit=static_cast<int>(log2(n));
    double base = 2.0;
    int result = static_cast<int>(pow(base, limit))-1;*/
    for(int i=0;i<=(n-1)/2;i++)
    {
        if((a[i]<a[((2*i)+1)] && ((2*i)+1)<n) || (a[i]<a[((2*i)+2)] && ((2*i)+2)<n))
        {
            return 0;
        }
    }
    return 1;
    // Your code goes here
}
int main()
{
    int arr[]={90, 15, 10, 7, 12, 2};
    cout<<boolalpha<<isMaxHeap(arr,6);
    return 0;
}