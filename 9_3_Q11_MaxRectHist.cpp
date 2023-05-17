#include<bits/stdc++.h>
using namespace std;
/*Method 1=>
Uses 2 pass --1 for each array i.e. leftsmall and rightsmall
Same as striver's
--Not the optimal approach--
TC=[O(N)+O(N)]leftsmall+[O(N)+O(N)]rightsmall
  =>O(N)
SC=O(3N)
Same as NGE approach*/
int getMaxArea(vector<int> arr, int n)
{
    int max=INT_MIN;
    vector<int> leftsmall(n);
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while(!s.empty() && arr[s.top()]>=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            leftsmall[i]=0;
        }
        else
        {
            leftsmall[i]=s.top()+1;
        }
        s.push(i);
    }
    vector<int> rightsmall(n);
    stack<int> s1;
    for(int i=n-1;i>=0;i--)
    {
        while(!s1.empty() && arr[s1.top()]>=arr[i])
        {
            s1.pop();
        }
        if(s1.empty())
        {
            rightsmall[i]=n-1;
        }
        else
        {
            rightsmall[i]=s1.top()-1;
        }
        s1.push(i);
        int a=((rightsmall[i]-leftsmall[i])+1)*arr[i];
        if(a>max)
        {
            max=a;
        }
    }
    return max;
}

/*Method 2=>
Uses 1 pass
See video again if not understood properly
Optimal approach
TC=O(N)+O(N)
SC=O(N)
Only explain this if the interviewer asks you to explain it as it requires a certain level of skill to
explain*/
int getMaxArea1(vector<int> arr, int n)
{
    stack<int> s;
    int maxArea=0;
    for(int i=0;i<=n;i++)
    {
        while(!s.empty() && (i==n || arr[s.top()]>=arr[i]))
        {
            int height=arr[s.top()];
            s.pop();
            int width;
            if(s.empty())
            {
                width=i;
            }
            else
            {
                width=i-s.top()-1;
            }
            maxArea=max(maxArea,(width*height));
        }
        s.push(i);
    }
    return maxArea;
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
    cout<<"arr:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Largest Area:"<<getMaxArea(arr,n);
    return 0;
}