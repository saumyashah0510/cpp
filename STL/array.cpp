#include <iostream>
#include <bits/stdc++.h>//contains all libraries like vector ,array , string
using namespace std;

int main(){

    int basic[]={1,2,3,4};//normal array

    array<int,4>a = {1,2,3,4}; //STL static array

    int size = a.size();

    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout << "Element at second index is " << a.at(2) << endl;
    cout << "Emppty or not " << a.empty() << endl;
    cout << "First elemnt " << a.front() << endl;
    cout << "Last element " << a.back() << endl;

    return 0;

}