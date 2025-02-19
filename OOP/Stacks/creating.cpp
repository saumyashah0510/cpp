#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout << s.top() << endl;

    if (s.empty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "size of stack is: " << s.size() << endl;

    return 0;
}