#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct hero
{
    int attack;
    int level;

    hero(int a,int l)
    {
        attack = a;
        level = l;
    }
};

ostream& operator<< (ostream& COUT, hero temp)
{
    COUT << temp.attack << " " << temp.level << endl;
    return COUT;
}

int main(){

    hero hero1 = hero(34,100);    
    hero hero2 = hero(50,50);

    cout << hero1 << hero2;

    return 0;

}