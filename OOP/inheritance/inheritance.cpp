#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class human
{

private:
    int weight;

public:
    int age;
    int height;

    int get_weight()
    {
        return weight;
    }

    void set_weight(int w)
    {
        this->weight = w;
    }

    human(int age, int height)
    {
        this->age = age;
        this->height = height;
    }
};

// inherited class
class male : public human
{
public:
    string color;

    // constructor inheritance
    male(int age, int height, string color) : human(age, height)
    {
        this->color = color;
    }

    void sleep()
    {
        cout << "Men sleep" << endl;
    }
};

int main()
{

    male saumya(18, 6, "brown");
    saumya.set_weight(74);
    cout << "Age: " << saumya.age << ", Height: " << saumya.height << ", Color: " << saumya.color << ", Weight: " << saumya.get_weight() << endl;

    saumya.sleep();

    return 0;
}