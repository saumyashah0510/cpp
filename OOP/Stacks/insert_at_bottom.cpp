#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }

    int x = s.top();
    s.pop();

    insert_at_bottom(s, element);

    s.push(x);
}

void print(stack<int> s)
{
    if (s.empty())
    {
        return;
    }

    int x = s.top();
    s.pop();

    cout << x << endl;

    print(s);

    s.push(x);
}

int main()
{

    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Before insertion:" << endl;
    print(s);

    insert_at_bottom(s, 1);

    cout << "After insertion:" << endl;
    print(s);

    return 0;
}