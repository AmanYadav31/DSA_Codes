#include<bits/stdc++.h>
using namespace std;
/*Method 1=>
Striver's approach
TC=O(N)
SC=O(1)
See other approacher i.e brute force,better,optimal(This one) in the screenshots taken*/
int trapping(vector<int> arr, int n)
{
    int left=0,right=n-1,leftmax=0,rightmax=0,trap=0;
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            if(arr[left]>=leftmax)
            {
                leftmax=arr[left];
            }
            else
            {
                trap+=leftmax-arr[left];
            }
            left++;
        }
        else
        {
            if(arr[right]>=rightmax)
            {
                rightmax=arr[right];
            }
            else
            {
                trap+=rightmax-arr[right];
            }
            right--;
        }
    }
    return trap;
}
/*Another approach=>
Give runtime was 0 ms but when I ran showed 25ms*/
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int> maxAfter(n);
        maxAfter[n-1] = 0;

        for (int i = n-2; i >= 0; i--) {
            maxAfter[i] = max(height[i+1], maxAfter[i+1]);
        }

        int edge = 0;
        int water = 0;

        for (int i = 0; i < n; i++) {
            if (height[i] >= edge) {
                edge = min(height[i], maxAfter[i]);
            }
            else {
                water += (edge - height[i]);
            }
        }

        return water;
    }

int main()
{
    
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Trapped Water:"<<trap(arr)<<endl;
    return 0;
}