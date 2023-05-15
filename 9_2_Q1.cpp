#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        int precedence(char c)
        {
            if(c=='('||c=='['||c=='{')
            {
                return 5;
            }
            else if(c=='^')
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
            else if(c==')'||c=='}'||c==']')
            {
                return -2;
            }
            return -1;
        }
        string infixtoPostfix(string s)
        {
            string s1;
            stack<char> a;
            for(int i=0;i<s.length();i++)
            {
                if(isalpha(s[i]))
                {
                    s1=s1+s[i];
                }
                else
                {
                    if(precedence(s[i])==-1)
                    { 
                        continue;
                    }
                    if(a.empty())
                    {
                        a.push(s[i]);
                        
                    }
                    else{
                        if(precedence(s[i])>precedence(a.top()))
                        {
                            a.push(s[i]);
                            
                        }
                        else
                        {
                            while(!a.empty())
                            {
                                if(precedence(a.top())>=precedence(s[i])&& precedence(a.top())!=5)
                                {
                                    s1=s1+a.top();
                                   
                                    a.pop();
                                    
                                }
                                else
                                {
                                    break;
                                }                        
                            }
                            if(precedence(s[i])==-2)
                            {
                                a.pop();
                                
                            }
                            else
                            {
                                a.push(s[i]);
                                
                            }
                        }
                    }
                }
            }
            while(!a.empty())
            {
                s1=s1+a.top();
                a.pop();
                
            }
            return s1;
        }
};

/*Another similar approach
By GFG*/
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
  
// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{
  
    stack<char> st;
    string result;
  
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
  
        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
  
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');
  
        // If the scanned character is an ‘)’,
        // pop and add to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
  
        // If an operator is scanned
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
  
    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
  
    cout << result << endl;
}
int main() {
    Solution sol;
    string infix_expression = "a*{b/(c+d)}";
    string postfix_expression = sol.infixtoPostfix(infix_expression);
    cout << "Infix expression: " << infix_expression << endl;
    cout << "Postfix expression: " << postfix_expression << endl;
    return 0;
}
/*
int main()
{
    string s;
    cout<<"Enter String:"<<endl;
    getline(cin, s);
    cout<<"Final String:"<<infixtoPostfix(s)<<endl;
    return 0;
}*/