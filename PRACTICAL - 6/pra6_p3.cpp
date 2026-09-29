#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
  
    if(ch == '*' || ch == '/' || ch == '%')
        return 2;

    if(ch == '^')
        return 3;

    return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";

    for(char ch : s)
    {
        if((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') ||  (ch >= '0' && ch <= '9'))
        {
            ans += ch;
        }
        else if(ch == '(')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            if(!st.empty())
                st.pop();
        }
        else
        {
            while(!st.empty() &&  precedence(st.top()) >= precedence(ch))
            {
                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s;
    cout<<"enter number of string : ";
    cin >> s;

    cout << infixToPostfix(s);

    return 0;
}