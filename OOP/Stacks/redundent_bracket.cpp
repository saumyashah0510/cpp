// redundant bracket is useless bracket
// for ex : ((a+b))  Here outside bracket is redundent
// only lowercasse alphabets , () and operators allowed

#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<char> s;

    bool isRed;
    string str = "((a+b))";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            // either lowercase or ) left
            if (ch == ')')
            {
                isRed = true;
                while (s.top() != '(')
                {
                    char top = s.top();
                    {
                        if (top == '+' || top == '-' || top == '*' || top == '/')
                        {
                            isRed = false;
                        }
                    }
                    s.pop();
                }
            }
        }
    }

    if (isRed)
    {
        cout << "Redundent brackets present" << endl;
    }
    else
    {
        cout << "Redundent brackets not present" << endl;
    }

    return 0;
}