// greatest element at the top

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

void sorted_insert(stack<int> &s, int x)
{
    if (s.empty() || x > s.top())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    sorted_insert(s, x);
    s.push(num);
}

void sort(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int x = s.top();
    s.pop();

    sort(s);

    sorted_insert(s, x);
}

int main()
{

    stack<int> s;

    s.push(9);
    s.push(-3);
    s.push(4);
    s.push(2);

    cout << "Before sort:" << endl;
    print(s);

    sort(s);

    cout << "After sort:" << endl;
    print(s);

    return 0;
}