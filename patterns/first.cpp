// 1 1 1
// 2 2 2
// 3 3 3

#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    int temp = 1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << temp << " ";
        }
        cout << endl;
        temp++;
    }

    return 0;

}