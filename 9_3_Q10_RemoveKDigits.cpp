#include<bits/stdc++.h>
using namespace std;
/*Good approach
Works for all the test cases except for 1*/
string removeKdigits(string S, int K) {
    stack<char> s;
    for(int i=0;i<S.size();i++)
    {
        while(!s.empty() && K>0 && s.top()>S[i])
        {
            s.pop();
            K--;
        }
        if (!s.empty() || S[i] != '0'){
            s.push(S[i]);
        }
    }
    while(K>0)
    {
        s.pop();
        K--;
    }
    string rs="";
    while (!s.empty())
    {
        rs= s.top()+rs;
        s.pop();
    }
    return rs;
}
string removeKdigits1(string num, int k)
{
    int n = num.size();
    stack<char> mystack;
    // Store the final string in stack
    for (char c : num) {
        while (!mystack.empty() && k > 0
               && mystack.top() > c) {
            mystack.pop();
            k -= 1;
        }
 
        if (!mystack.empty() || c != '0'){
            mystack.push(c);
        }
    }
 
    // Now remove the largest values from the top of the
    // stack
    while (!mystack.empty() && k--)
        mystack.pop();
    if (mystack.empty())
        return "0";
 
    // Now retrieve the number from stack into a string
    // (reusing num)
    while (!mystack.empty()) {
        num[n - 1] = mystack.top();
        mystack.pop();
        n -= 1;
    }
    return num.substr(n);
}
/*Better approach without stack*/
string removeKdigits(string S, int K) {
        string result;
    int n = S.size();

    // Special case: If K is equal to or greater than the size of S, return "0"
    if (K >= n)
        return "0";

    for (char c : S) {
        while (!result.empty() && K > 0 && result.back() > c) {
            result.pop_back();
            K--;
        }
        result.push_back(c);
    }

    // Remove the remaining largest digits from the end
    while (K > 0 && !result.empty()) {
        result.pop_back();
        K--;
    }

    // Remove leading zeros
    int leadingZeros = 0;
    while (leadingZeros < result.size() && result[leadingZeros] == '0')
        leadingZeros++;

    result = result.substr(leadingZeros);

    if (result.empty())
        return "0";
    return result;
}
int main()
{
    string s;
    cout<<"Enter String:"<<endl;
    cin>>s;
    int k;
    cout<<"enter value of k:"<<endl;
    cin>>k;
    cout<<"Final String:"<<removeKdigits1(s,k);
    return 0;
}