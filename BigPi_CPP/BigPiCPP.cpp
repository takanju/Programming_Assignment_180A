/*
 * BigPiCPP.cpp
 *
 *  Created on: Oct 28, 2020
 *      Author: swapnanjali
 */

#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctime>
#include <chrono>
#include <stdio.h>
#include <vector>
#include <mpirxx.h>

using namespace std;
using namespace std::chrono;

const int MAX_ITERATIONS = 5;				//number of iterations for 1 million digits of Pi
const int PLACES         = 1000;        // desired decimal places for extra credit
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Function declarations here. *****/
void print(const mpf_class& pi);


/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits


    mpf_class i(1), ii(2), iv(4), vi(6);
    mpf_class sqrtTwo = sqrt(ii);

    mpf_class y,a,y0,a0, y4, Four_root, aFirst, aSecond;

    y0 = sqrtTwo - i;
    a0 = vi - (iv*sqrtTwo);

    mpf_class powerTwo = 2;


  	steady_clock::time_point start_time = steady_clock::now();

  	// Loop MAX_ITERATIONS times.
    for (int j = 1; j <= MAX_ITERATIONS; j++)
    {

    	 y4 = y0*y0*y0*y0;
         Four_root = sqrt(sqrt(i-y4));

    	y = (i - Four_root) / (i + Four_root);


    	 aFirst = a0*((y + i) * (y + i) * (y + i) * (y + i));

    	powerTwo = iv*powerTwo;
    	 aSecond = powerTwo*y*(i + y + (y*y));

    	a = aFirst - aSecond;

         a0 = a;
         y0 = y;

    }


    steady_clock::time_point end_time = steady_clock::now();
    long ns = duration_cast<nanoseconds>(end_time - start_time).count();


    mpf_class BigPi = 1.0 / a;
    cout<<"API: pi to 1,000 places:"<<endl;
	print(BigPi);
	cout<<"Elapsed time: " <<ns/pow(10,9) <<"seconds";
}


void print(const mpf_class& pi)
{
	//mpf_out_str (stdout, 10,1001, pi);
	int group_count=0;
	char *ptr=NULL;
	char *newPtr;
	mp_exp_t exp;
	newPtr = mpf_get_str(ptr,&exp,BASE,PLACES+1,pi.get_mpf_t());
	cout<<newPtr[0]<<"."<<setw(1);
	for(int i =1;i<PLACES+1;i++)
	{
		cout<<newPtr[i];
		if(i%BLOCK_SIZE==0)
		{
			cout<<setw(2)<<" ";
			if(i%LINE_SIZE==0)
			{
				cout<<endl;
				cout<<" "<<setw(2);
				group_count++;
				if(group_count%GROUP_SIZE==0)
				{
					cout<<endl;
					cout<<" "<<setw(1);
				}
			}
		}

	}
}






