#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    //doubly ended queue is represented by deque
    deque<int> d;

    d.push_back(12);
    d.push_front(14);

    cout << d.front() << " " << d.back() << endl;

    return 0;

}