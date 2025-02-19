#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    while(n>1)
    {

        int prime = 1;

        for(int i=2;(i*i)<=n;i++)
        {
            if(n%i==0)
            {
                prime=0;
                continue;
            }
        }

        if(prime==1)
        {
            cout << n << " ";
        }
        
        n--;

    }

    return 0;

}