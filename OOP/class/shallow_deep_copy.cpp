// already present coopy constructor created a shallow copy

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
        name = new char[100];
        subject = new char[100];
    };

    // paramertized constructor
    student(int number, char division)
    {
        this->number = number;
        this->division = division;
    }

    void print()
    {
        cout << "Student Name: " << this->name << endl;
        cout << "Student Number: " << number << endl;
        cout << "Division: " << division << endl;
        cout << "Student Subject: " << subject << endl;
    }

    // createe own copy constructor
    // no need to create always as already present
    student(student &temp) // pass by reference
    {

        char *ch = new char[strlen(temp.subject) + 1];
        strcpy(ch, temp.subject);
        this->subject = ch;

        this->name = temp.name;

        this->division = temp.division;
        
        cout << endl
             << endl
             << "Copy constructor called" << endl
             << endl
             << endl;
    }

    void setsubject(char subject[])
    {
        strcpy(this->subject, subject);
    }
};

int main()
{

    student saumya;
    saumya.division = 'B';
    saumya.number = 1;
    char name[] = "Saumya";
    strcpy(saumya.name, name);
    char subject[] = "Maths";
    saumya.setsubject(subject);
    saumya.print();

    student *pranshu = new student;
    char namep[] = "Pranshu";
    pranshu->number = 3;
    pranshu->division = 'A';
    pranshu->setsubject(subject);
    strcpy(pranshu->name, namep);
    cout << endl
         << endl;
    pranshu->print();

    student KJ(saumya);
    KJ.number = 2;
    cout << endl
         << "Before copy assignment operator:" << endl;
    KJ.print();

    // assignment copy operator
    KJ = saumya;
    cout << endl
         << "After copy assignment operator:" << endl;
    KJ.print();

    return 0;
}