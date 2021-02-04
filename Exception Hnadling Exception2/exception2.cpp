/*
 * exception2.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */

#include <iostream>
using namespace std;

class SomeNumber
{
public:
    SomeNumber(int n) : value(n) {}
    int get_value() const { return value; }
private:
    int value;
};

class NegativeNumber : public SomeNumber
{
public:
    NegativeNumber(int n) : SomeNumber(n) {};
};

class NumberTooBig : public SomeNumber
{
public:
    NumberTooBig(int n) : SomeNumber(n) {};
};

int main()
{
    int value;
    cout << "Enter positive integers < 10, 0 to quit." << endl;

    do
    {
        cout << "Value? ";
        try
        {
            cin >> value;
            if (value < 0)   throw NegativeNumber(value);
            if (value >= 10) throw NumberTooBig(value);

            if (value > 0) cout << "You entered " << value << endl;
        }
        catch (NegativeNumber& v)
        {
            cout << "*** Error: Negative value: " << v.get_value() << endl;
        }
        catch (NumberTooBig& v)
        {
            cout << "*** Error: Value too big: " << v.get_value() << endl;
        }

    } while (value != 0);

    cout << "Done!" << endl;
    return 0;
}


