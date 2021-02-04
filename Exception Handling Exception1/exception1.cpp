/*
 * exception1.cpp
 *
 *  Created on: Oct 20, 2020
 *      Author: swapnanjali
 */


#include <iostream>
using namespace std;

int main()
{
    int value;
    cout << "Enter positive integers, 0 to quit." << endl;

    do
    {
        cout << "Value? ";
        try
        {
            cin >> value;
            if (value < 0) throw value;

            if (value > 0) cout << "You entered " << value << endl;
        }
        catch (int v)
        {
            cout << "*** Error: You entered the negative value " << v << endl;
        }

    } while (value != 0);

    cout << "Done!" << endl;
    return 0;
}

