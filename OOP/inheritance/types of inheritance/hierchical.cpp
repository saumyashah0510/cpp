#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class A
{
    public:
    void func1()
    {
        cout << "Inside function 1" << endl;
    }
};

class B: public A
{
    public:
    void func2()
    {
        cout << "Inside fucntion 2" << endl;
    }
};

class C: public A
{
    public:
    void func3()
    {
        cout << "Inmside function 3" << endl;
    }
};

int main(){

    

    return 0;

}