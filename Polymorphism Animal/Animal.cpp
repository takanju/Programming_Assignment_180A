/*
 * Animal.cpp
 *
 *  Created on: Oct 27, 2020
 *      Author: swapnanjali
 */


#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual string speak() { return "Shhh!"; }
};

class Mammal : public Animal
{
public:
    string speak() { return "Grrr!" ; }
};

class Cat : public Animal
{
public:
    string speak() { return "Roar!"; }
};

class Kitty : public Animal
{
public:
    string speak() { return "Meow!"; }
};

string make_sound(Animal& anim) { return anim.speak(); }

int main()
{
    Animal a;
    cout << make_sound(a) << endl;

    Mammal m;
    cout << make_sound(m) << endl;

    Kitty k;
    cout << make_sound(k) << endl;

}

