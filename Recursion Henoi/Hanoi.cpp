/*
 * Hanoi.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: swapnanjali
 */


#include <iostream>
using namespace std;

enum Pin { A = 'A', B = 'B', C = 'C' };

void solve(const int n, const Pin source, const Pin dest, const Pin temp);
void move(const Pin from, const Pin to);

int main()
{
    int n;
    cout << "Number of disks? ";
    cin >> n;

    cout << "Solve for " << n << " disks:" << endl << endl;
    solve(n, Pin::A, Pin::B, Pin::C);
}

void move(Pin from, Pin to)
{
    cout << "Move disk from " << static_cast<char>(from)
         << " to " << static_cast<char>(to) << endl;
}

void solve(const int n, const Pin source, const Pin dest, const Pin temp)
{
    if (n == 1) move(source, dest);      // Base case
    else
    {
        solve(n-1, source, temp, dest);  // Solve source ==> temp
        move(source, dest);              // Move 1 disk source ==> dest
        solve(n-1, temp, dest, source);  // Solve temp ==> dest
    }
}

