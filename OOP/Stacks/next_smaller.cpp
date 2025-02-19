// find the next smaller element
// for ex in 2,3,1 ans should be 1,1,-1

// it can be done by loops by O(n2)
// stacks is more optimized O(N)

#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

vector<int> NextSmall(vector<int> &arr, int n)
{
    stack<int> s;

    // last elemennt will never have smaller
    s.push(-1);

    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 3, 1};

    return 0;
}