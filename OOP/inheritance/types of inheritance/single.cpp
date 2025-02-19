#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class animal
{
    public:
    int age;
};

class dog: public animal
{
    public:
    void speak()
    {
        cout << "Speaking" << endl;
    }
};

int main(){

    dog bruno;
    bruno.speak();

    return 0;

}