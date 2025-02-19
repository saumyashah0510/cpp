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

class German_Shepeherd: public dog
{
    public:
    void print()
    {
        cout << "German shepherd" << endl;
    }
};

int main(){

    German_Shepeherd bruno;
    bruno.print();

    return 0;

}