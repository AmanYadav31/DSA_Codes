#include<bits/stdc++.h>
using namespace std;
/*Read the document provide on striver's sheet regarding this. Very well explained.*/
/*Inmein se kissi bhi case ne 0 number ko include nahi kiya hai*/
/*Method 1=>
Brute Force Approach
TC=O(N^2)
SC=O(1)
*/
int missingNumber(vector<int>&a, int N) {
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return i;
    }
    return -1;
}

/*Method 2=>
Better approach
Uses Hash table
TC=O(N)
SC=O(N)*/
int missingNumber1(vector<int>&a, int N) {
    int hash[N+1]={0};
    for (int i = 0; i < N-1; i++)
    {
        hash[a[i]]++;
    }
    for(int i=1;i<=N;i++)
    {
        if(hash[i]==0)
        {
            return i;
        }
    }    
    return -1;
}

/*Method 3=>
Optimal Approach
TC=O(N)
SC=O(1)
Two appraches:
i)Summation
ii)Using XOR Operator
*/
/*Using Summation

Approach:
The steps are as follows:
1)We will first calculate the summation of first N natural numbers(i.e. 1 to N) using the 
  specified formula.
2)Then we will add all the array elements using a loop.
3)Finally, we will consider the difference between the summation of the first N natural 
  numbers and the sum of the array elements.*/
int missingNumber3(vector<int>&a, int N) {

    //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}
/*Using XOR Operator:
----------------------------------------------------------------------------------------------------
Intuition:
Intuition: Two important properties of XOR are the following:

XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a.  ←Property 2

Now, let’s XOR all the numbers between 1 to N.
xor1 = 1^2^…….^N

Let’s XOR all the numbers in the given array.
xor2 = 1^2^……^N (contains all the numbers except the missing one).

Now, if we again perform XOR between xor1 and xor2, we will get:
xor1 ^ xor2 = (1^1)^(2^2)^……..^(missing Number)^…..^(N^N)

Here all the numbers except the missing number will form a pair and each pair will result in 0 
according to the XOR property. 
The result will be = 0 ^ (missing number) = missing number (according to property 2).

--------------------------------------------------------------------------------------------------
Approach:

The steps are as follows:

1)We will first run a loop(say i) from 0 to N-2(as the length of the array = N-1).
2)Inside the loop, xor2 variable will calculate the XOR of array elements
  i.e. xor2 = xor2 ^ a[i].
  And the xor1 variable will calculate the XOR of 1 to N-1 i.e. xor1 = xor1 ^ (i+1).
3)After the loop ends we will XOR xor1 and N to get the total XOR of 1 to N.
4)Finally, the answer will be the XOR of xor1 and xor2.

*/
int missingNumber4(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

/*0 included in the following algo:*/
int missingNumber(vector<int> a) {
        int N=a.size();
    
       //Summation of first N numbers:
    int sum = (N * (N + 1)) / 2;

    //Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N; i++) {
        s2 += a[i];
    }

    int missingNum = sum - s2;
    return missingNum;
        
    }
int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber1(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}