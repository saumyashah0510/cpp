#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    char temp = 'A'; 

    for (int i = 0; i < n; i++)
    {
        for (int j = n - i - 1; j < n; j++)
        {
            cout << temp << " ";
            temp++;
        }
        cout << endl;
    }

    return 0;
}