#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main(){

    string str = "saumya";

    stack<char> s;

    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";

    while(s.empty() != 1)
    {
        char ch = s.top();
        ans.push_back(ch);

        s.pop();
    }

    cout << ans << endl;

    return 0;

}