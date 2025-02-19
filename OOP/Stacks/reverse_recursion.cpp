#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

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

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int x = s.top();
    s.pop();

    reverse(s);

    insert_at_bottom(s, x);
}

int main()
{

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Before reverse:" << endl;
    print(s);

    reverse(s);

    cout << "After reverse:" << endl;
    print(s);

    return 0;
}