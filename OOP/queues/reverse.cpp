#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

void print(queue<int> q)
{

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
}

void reverse(queue<int> &q)
{
    if(q.empty())
    {
        return;
    }

    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);

}

int main()
{

    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    print(q);

    cout << "After reverse:" << endl;
    reverse(q);
    print(q);
    return 0;
}