#include<iostream>
#include<vector>
using namespace std;
/*Optimal Approach=> 
Striver's
TC=O(N)
SC=O(1)*/
int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
}
int main()
{
    int n;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    vector<int> vect;
    cout<<"Enter the values:"<<endl;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        vect.push_back(val);
    }
    for(int p:vect)
    {
        cout<<p<<endl;
    }
    cout<<"Value :"<<removeDuplicates(vect)<<endl;
}