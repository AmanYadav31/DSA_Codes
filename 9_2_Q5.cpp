#include<bits/stdc++.h>
using namespace std;
/*Cannot solve for brackets*/
int precedence(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='/'||c=='*')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    return -1;
}

void display(stack<char> s1)
{
    stack<char> s=s1;
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
}
string PostfixtoInfix(string s)
{
    stack<char> s1;
    stack<char> s2;
    for(int i=0;i<s.length();i++)
    {
        if(isalpha(s[i])||isdigit(s[i]))
        {
            s1.push(s[i]);
        
        }
        else if(precedence(s[i])!=-1)
        {
            s2.push(s[i]);
        }
    }
    string a;
    int flag=0;
    a= a+s1.top();
    s1.pop();
    while(!s1.empty() && !s2.empty())
    {
        char c;
        stack<char> s3;
        c=s2.top();
        s2.pop();
        display(s2);
        while((!s2.empty()) && !(precedence(c)<=precedence(s2.top())))
        {
            s3.push(c);
            char c1=s2.top();
            s2.pop();
            c=c1;
            flag=1;
        }
        while(!s3.empty())
        {
            s2.push(s3.top());
            s3.pop();
        }
        
        char d =s1.top();
        string h= string(1,d)+c;
        if(flag!=0)
        {
            a.insert(1,")");
            flag=0;
            a= "(" +h+a;
        }
        else
        {
            a=h+a;
        }
        s1.pop();
        
        
    }
    return a;
}
/*GFG approach=>*/
 
bool isOperand(char x)
{
   return (x >= 'a' && x <= 'z') ||
          (x >= 'A' && x <= 'Z');
}
 
// Get Infix for a given postfix
// expression
string getInfix(string exp)
{
    stack<string> s;
 
    for (int i=0; exp[i]!='\0'; i++)
    {
        // Push operands
        if (isOperand(exp[i]))
        {
           string op(1, exp[i]);
           s.push(op);
        }
 
        // We assume that input is
        // a valid postfix and expect
        // an operator.
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] +
                   op1 + ")");
        }
    }
 
    // There must be a single element
    // in stack now which is the required
    // infix.
    return s.top();
}
int main()
{
    string ss;
    cout<<"Enter String:"<<endl;
    getline(cin, ss);
    cout<<"Final String:"<<getInfix(ss)<<endl;
    return 0;
}