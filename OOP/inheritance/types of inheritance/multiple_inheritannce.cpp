#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class animal
{
public:
    int age;

    void bark()
    {
        cout << "Barking" << endl;
    }
};

class human
{
public:
    string name;

    void speak()
    {
        cout << "Speaking" << endl;
    }
};

// multiple inheritance
class hybrid : public human, public animal
{
};

int main()
{
    
    hybrid pranshu;
    pranshu.bark();
    pranshu.speak();

    return 0;
}