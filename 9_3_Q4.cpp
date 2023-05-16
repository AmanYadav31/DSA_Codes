#include<bits/stdc++.h>
using namespace std;
vector<int> count_NGE(int n, vector<int> arr, int queries, vector<int> indices){
    //write your code here
    vector<int> count(queries);
    for(int i=0;i<queries;i++)
    {
        int j=indices[i];
        int c=0;
        for(int k=j+1;k<n;k++)
        {
            if(arr[k]>arr[j])
            {
                c++;
            }
        }
        count[i]=c;
    }
    return count;
}
int main()
{
    int n=8;
    vector<int> arr{3, 4, 2, 7, 5, 8, 10, 6};
    int queries=2;
    vector<int> indices{0,5};
    vector<int> a=count_NGE(n,arr,queries,indices);
    cout<<"Final Output:"<<endl;
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;

}