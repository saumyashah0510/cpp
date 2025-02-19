#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool valid(string s)
{
    stack<char> st;

    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];

        if(ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty())
            {
                char top = st.top();
                if( (ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') )
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if(st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main(){

    string s = "({[]})";

    bool check = valid(s);

    if(check == true)
    {
        cout << "Valid Paranthesis" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;

}