// dynamic constructor
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    int number;

public:
    char division;

    // simple constructor
    student() {

    };

    // paramertized constructor
    student(int number, char division)
    {
        this->number = number;
        this->division = division;
    }

    void print()
    {
        cout << "Student Number: " << number << endl;
        cout << "Division: " << division << endl;
    }

    void set_number(int n)
    {
        number = n;
    }

    int get_number()
    {
        return number;
    }

    void set_division(char d)
    {
        division = d;
    }

    char get_division()
    {
        return division;
    }

    // createe own copy constructor
    // no need to create always as already present
    student(student &temp) // pass by reference
    {
        cout << "Copy constructor called" << endl;
        this->division = temp.division;
        this->number = temp.number;
    }
};

int main()
{
    // dynamic allocation
    student *saumya = new student(1, 'B');
    saumya->print();

    // this can be used if parametrized constructor is not usde and getter setter ddefined

    // student pranshu;
    // pranshu.set_division('B');
    // pranshu.set_number(2);

    // used when parametrizec constructor defined
    student pranshu(2, 'B');
    pranshu.print();

    // copy constructor
    student KJ(pranshu); // this sets all data values of pranshu into KJs
    KJ.print();

    return 0;
}