// https://www.geeksforgeeks.org/problems/max-rectangle/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
  
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
    // Function to calculate the maximum area of a rectangle
    // in the given matrix.
    int maxArea(vector<vector<int>> &mat) {
        // Your code here
        
        int n = mat.size();
        
        vector<int> ans(mat[0].size());
        
        for(int i=0;i<mat[0].size();i++)
        {
            ans[i] = mat[0][i];
        }
        
        int area = largestRectangleArea(ans);

        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j] != 0)
                {
                    ans[j] = ans[j] + mat[i][j];
                }
                else
                {
                    ans[j] = 0;
                }
                
            }
            int new_area = largestRectangleArea(ans);

            if(new_area > area)
            {
                area = new_area;
            }
        }

        return area;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(mat) << endl;

        cout << "~"
             << "\n";
    }
}
