#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
/*Method 1=.
By me 
SC=O(2N)
TC=O(1)*/
class Solution{
    int minEle=INT_MAX;
    stack<int> s;
    stack<int> s1;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(!s1.empty())
           {
               return s1.top();
           }
           return -1;
           //Write your code here
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(!s.empty())
           {
               int x=s.top();
               s.pop();
               if(s1.top()==x)
               {
                   s1.pop();
                   if(!s1.empty())
                   {
                    minEle=s1.top();
                   }
                   else
                   {
                    minEle=INT_MAX;
                   }
               }
               return x;
           }
           return -1;
           //Write your code here
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(x<=minEle)
           {
               minEle=x;
               s1.push(x);
           }
           s.push(x);
           //Write your code here
       }
};
/*Method 2=>
By Striver
TC=O(1)
SC=O(N)*/
class MinStack {
    stack<long long> s;
    long long min;
public:
/*We are using long long because in between we are doing *2 so 
there is a possiblity that it might overflow therefore we don't us eint*/
    MinStack() {
        stack<long long> s;
        long long min=INT_MAX;
    }
    
    void push(int val) {
        long long x= val;
        if(s.empty())
        {
            min=x;
            s.push(x);
        }
        else
        {
            if(x<min)
            {
                s.push(2*x*1LL - min);
                min=x;
            }
            else
            {
                s.push(x);
            }
        }
    }
    
    void pop() {
        if(s.empty())
        {
            return;
        }
        long long x=s.top();
        s.pop();
        if(x<min)
        {
            min=2*min-x;
        }
    }
    
    int top() {
        if(s.empty())
        {
            return -1;
        }
        long long x=s.top();
        if(x<min)
        {
            return min;
        }
        return x;
    }
    
    int getMin() {
        return min;
    }
};
/*Leetcode waala=>
Runtime=0ms*/
class MinStack {
private:
        stack<int> s;
        stack<int> ss;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty()||(!ss.empty()&&val<=ss.top()))
        {
            ss.push(val);
        }
    }
    
    void pop() {
        int val= s.top();
        s.pop();
        if(val==ss.top())
        ss.pop();
    }
    
    int top() {
       return  s.top();
    }
    
    int getMin() {

        return ss.top();

    }
};
int main() {
    Solution stackObj;

    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    stackObj.push(45);
    stackObj.push(12);
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    stackObj.push(6);
    stackObj.push(50);
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.pop()<<" ";
    stackObj.push(27);
    cout<<stackObj.pop()<<" ";
    cout<<stackObj.pop()<<" ";
    cout<<stackObj.getMin()<<" ";
    cout<<stackObj.getMin()<<" ";

    /*cout << "Current Minimum Element: " << stackObj.getMin() << endl; // Output: Current Minimum Element: 10

    cout << "Popped Element: " << stackObj.pop() << endl; // Output: Popped Element: 30
    cout << "Popped Element: " << stackObj.pop() << endl; // Output: Popped Element: 20

    cout << "Current Minimum Element: " << stackObj.getMin() << endl; // Output: Current Minimum Element: 10

    stackObj.push(5);
    cout << "Current Minimum Element: " << stackObj.getMin() << endl; // Output: Current Minimum Element: 5

    cout << "Popped Element: " << stackObj.pop() << endl; // Output: Popped Element: 5
    cout << "Popped Element: " << stackObj.pop() << endl; // Output: Popped Element: 10

    cout << "Current Minimum Element: " << stackObj.getMin() << endl; // Output: Current Minimum Element: -1 (stack is empty)
    */
    return 0;
}
