// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        
        deque<int> q;
        vector<int> ans;
        
        // for first k elements
        
        for(int i=0;i<k;i++)
        {
            if(arr[i] < 0)
            {
                q.push_back(i);
            }
        }
        
        //store answer of first k sized window
        if(q.size()>0)
        {
            ans.push_back(arr[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        
        //remaining k elements
        for(int i=k;i<arr.size();i++)
        {
            //removal
            if(!q.empty() && i-q.front() >= k)
            {
                q.pop_front();
            }
            
            //addition
            if(arr[i] < 0)
            {
                q.push_back(i);
            }
            
            if(q.size()>0)
            {
                ans.push_back(arr[q.front()]);
            }
            else
            {
                ans.push_back(0);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends