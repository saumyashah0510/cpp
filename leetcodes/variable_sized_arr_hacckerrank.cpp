#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n_arr, n_quer;
    cin >> n_arr >> n_quer;

    vector<vector<int>> arr(n_arr);
    for (int i = 0; i < n_arr; i++)
    {
        int n_elements;
        cin >> n_elements;
        arr[i].resize(n_elements);

        for (int j = 0; j < n_elements; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<n_quer;i++)
    {
        int arr_index , element;
        cin >> arr_index >> element;
        cout << arr[arr_index][element] << endl;
    }

    return 0;
}