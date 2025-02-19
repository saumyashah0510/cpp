#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class hero{

    //properties:

    public:
    int health;
    char level;

    private:
    int attack;

    public:
    int getattack()
    {
        return attack;
    }

    void setattack(int a)
    {
        attack = a;
    }

};

int main(){

    //static allocation
    hero V;

    V.health = 70;
    V.level = 'S';

    cout << "Health is "<< V.health << endl;
    cout << "Level is "<< V.level << endl;

    //use setter
    V.setattack(100);

    //use getter
    cout << "Attack is "<< V.getattack() << endl;

    cout << endl << endl << endl;


    //dynamic allocation
    hero *a = new hero;

    a->health = 100;
    a->level = 'A';

    a->setattack(20) ;

    cout << "a : " << a->health << a->level << a->getattack() << endl;

    return 0;

}