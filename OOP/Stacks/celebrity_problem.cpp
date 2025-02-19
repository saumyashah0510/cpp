// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &arr)
    {
        // code here
        stack<int> s;

        // push all ellements in stack
        for (int i = 0; i < arr.size(); i++)
        {
            s.push(i);
        }

        while (s.size() != 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (arr[a][b] == 1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        int potential_celebrity = s.top();

        bool coloumn_check = false;
        int count_c = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i][potential_celebrity] == 1)
            {
                count_c++;
            }
        }

        if (count_c == arr.size() - 1)
        {
            coloumn_check = true;
        }

        bool row_check = false;
        int count_r = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[potential_celebrity][i] == 0)
            {
                count_r++;
            }
        }
        if (count_r == arr.size())
        {
            row_check = true;
        }

        if (row_check == true && coloumn_check == true)
        {
            return potential_celebrity;
        }
        else
        {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
        cout << "~" << endl;
    }
}

// } Driver Cod