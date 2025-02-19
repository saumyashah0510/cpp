// https://leetcode.com/problems/largest-rectangle-in-histogram/

// given a graph find rect of max area
// can be done using loops but stacks optimized

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{

    vector<int> next_smaller(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prev_smaller(vector<int> &arr, int n)
    {
        stack<int> s;
        s.push(-1);

        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        next = next_smaller(heights, n);

        vector<int> prev(n);
        prev = prev_smaller(heights, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;

            int new_area = l * b;
            area = max(area, new_area);
        }
        return area;
    }
};