// if memoery dynamically allocated then u have to call destructor manually

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    char *subject;

public:
    char division;
    char *name;
    int number;

    // simple constructor
    student()
    {
        
    };

    // simple destructor
    ~student()
    {
        cout << "Destructor called" << endl;
    }

    
};

int main(){

    student a;

    student* b = new student;
    //manual destructor call
    delete b; //now two times destructor called

    return 0;

}