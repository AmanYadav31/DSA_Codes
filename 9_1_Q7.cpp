#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*Best approach
Runtime=0ms*/
bool check(string s)
{
    stack<int> s1;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='{' ||ch=='['||ch=='(')
        {
            s1.push(ch);
        }
        else
        {
            if(s1.empty())
            {
                return false;
            }
            char c=s1.top();
            s1.pop();
            if((ch=='}'&& c!='{')||(ch==']'&& c!='[')||(ch==')'&& c!='('))
            {
                return false;
            }
        }
    
    }
    return s1.empty();
            // Your code here
}

    

int main()
{
    string s;
    cout<<"Enter String:"<<endl;
    cin>>s;
    cout<<boolalpha<<check(s)<<endl;


}