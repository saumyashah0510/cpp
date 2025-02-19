#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

// printing top to bottom
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

void delete_mid(stack<int> &s, int count, int size)
{

    if (count == size / 2)
    {
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();

    delete_mid(s, count + 1, size);

    s.push(x);
}

int main()
{

    int count = 0;

    stack<int> s;
    

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    // s.push(5);

    int size = s.size();

    cout << "Before removal:" << endl;
    print(s);

    delete_mid(s, count, size);
    cout << "After removal:" << endl;
    print(s);

    return 0;
}