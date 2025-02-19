// 1
// 2 3
// 3 4 5
// 4 5 6 7
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp = i + 1;
        for (int j = n - i - 1; j < n; j++)
        {
            cout << temp << " ";
            temp++;
        }
        cout << endl;
    }

    return 0;
}