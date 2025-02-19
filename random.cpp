#include <iostream>
#include <bits/stdc++.h>

class Newo{
    public:
    int quantity;
    std::string name;
};

int main()
{
    Newo Fruits;
    std::cout << "Enter the quantity of the fruit: ";
    std::cin >> Fruits.quantity;

    std::cout << "Enter the name of the fruit: ";
    getline(std::cin >> std::ws, Fruits.name);

    std::cout << "Name of the Fruit: " << Fruits.name << std::endl;
    std::cout << "Quantity: " << Fruits.quantity << std::endl;

}