#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to merge k sorted arrays.
/*Using Min Heap=>
TC=O(K^2*Log(K^2))
SC=O(K^2)*/
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> finalArray;
        for (int i = 0; i < k; i++)//K^2
        {
            for (int j = 0; j < k; j++)
            {
                pq.push(arr[i][j]);//logK^2
            }
        }
        while (!pq.empty())
        {
            finalArray.push_back(pq.top());
            pq.pop();
        }
        return finalArray;
    }
};

int main()
{
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    vector<vector<int>> arr(k, vector<int>(k));
    cout << "Enter the elements of the arrays: " << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }

    Solution obj;
    vector<int> mergedArray = obj.mergeKArrays(arr, k);

    cout << "Merged Array: ";
    for (int i = 0; i < mergedArray.size(); i++)
    {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    return 0;
}
