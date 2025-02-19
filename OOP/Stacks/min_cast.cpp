// refer image.png for question

#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int minCost(string str)
{
    //odd condition
    if(str.length()%2 != 0)
    {
        return -1;
    }

    stack<char> s;

    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];


        if(ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    //now stack conntains invalid expression
    int a=0,b=0;
    while(!s.empty())
    {
        if(s.top() == '{')
        {
            a++;;
        }
        else
        {
            b++;
        }
        s.pop();
    }

    // find pattern there will be 3 cases {{{{ , }}}} or }}}{{{
    int ans = (a+1)/2 + (b+1)/2;
    return ans;

}

int main(){

    string str = "{{{{";

    return 0;

}