#include<bits/stdc++.h>
using namespace std;
/*Method 1=>
by me
Runtime=20ms
Similar to subarraymins approach*/
long long subarrayRanges(int N, vector<int> &arr) 
{
    stack<pair<int,int>> s1;
    stack<pair<int,int>> s2;
    vector<int> left(N); //remember to always initialize the size at the time of declaration
    vector<int> right(N);
    for(int i=0;i<N;i++)
    {
        int count=1;
        while(!s1.empty() && s1.top().first>arr[i])
        {
            count+=s1.top().second;
            s1.pop();
        }
        left[i]=count;
        s1.push({arr[i],count});
    }
    for(int i=N-1;i>=0;i--)
    {
        int count=1;
        while(!s2.empty() && s2.top().first>=arr[i])
        {
            count+=s2.top().second;
            s2.pop();
        }
        right[i]=count;
        s2.push({arr[i],count});
    }
    stack<pair<int,int>> s3;
    stack<pair<int,int>> s4;
    vector<int> Xleft(N); //remember to always initialize the size at the time of declaration
    vector<int> Xright(N);
    for(int i=0;i<N;i++)
    {
        int count=1;
        while(!s3.empty() && s3.top().first<=arr[i])
        {
            count+=s3.top().second;
            s3.pop();
        }
        Xleft[i]=count;
        s3.push({arr[i],count});
    }

    for(int i=N-1;i>=0;i--)
    {
        int count=1;
        while(!s4.empty() && s4.top().first<arr[i])
        {
            count+=s4.top().second;
            s4.pop();
        }
        Xright[i]=count;
        s4.push({arr[i],count});
    }
    long long sum=0;
    for(int i=0;i<N;i++)
    {
        long long a=Xright[i]*Xleft[i];
        long long b=right[i]*left[i];
        sum=sum+ (arr[i]*(a-b));
    }
    return sum;
}
/*another approach=>
Runtime=11ms
Leetcode ka hai 0ms waala*/
long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        long long ans=0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || nums[st.top()] >= nums[i])){
                int mid=st.top();
                st.pop();
                int left = (st.empty())?-1:st.top();
                ans -= (long long)nums[mid]*(i-mid)*(mid-left);
            }
            st.push(i);
        }
        st.pop();
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || nums[st.top()] <= nums[i])){
                int mid=st.top();
                st.pop();
                int left = (st.empty())?-1:st.top();
                ans += (long long)nums[mid]*(i-mid)*(mid-left);
            }
            st.push(i);
        }
        return ans;
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
    long long x=subarrayRanges(n,arr);
    cout<<"Output:"<<x<<endl;
    return 0;
}