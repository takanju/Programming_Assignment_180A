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
void print(const mpf_t& pi);


/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits
    /***** Complete this program. *****/


    mpf_t  a0 ;mpf_t  y0;mpf_init(a0);mpf_init(y0);
	mpf_t two;mpf_init(two); mpf_t f1; mpf_init(f1);mpf_t f2; mpf_init(f2);
	mpf_ui_sub(two,2u,two);
	mpf_sqrt(f1,two);
	mpf_mul_ui(f1,f1,4);
	mpf_ui_sub(f1,6u,f1);

	mpf_sqrt(f2,two);
	mpf_sub_ui(f2,f2,1);
	mpf_set(a0,f1);
	mpf_set(y0,f2);
	mpf_t nr;mpf_t dr;mpf_t raisedTo4;mpf_t temp1;mpf_t holdYi;
	mpf_init(nr);mpf_init(dr);mpf_init(raisedTo4);mpf_init(temp1);mpf_init(holdYi);
	mpf_t oneMinueI;mpf_init(oneMinueI); 									//temp variable to store intermediate values
  	mpf_t ai;mpf_init(ai);
  	mpf_t ai_part1; mpf_t ai_part2;mpf_init(ai_part1);mpf_init(ai_part2);	//temp variable to store intermediate values


  	steady_clock::time_point start_time = steady_clock::now();

  	// Loop MAX_ITERATIONS times.
    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
	    	mpf_pow_ui(raisedTo4,y0,4u);
		    mpf_ui_sub(oneMinueI,1u,raisedTo4);
		    mpf_sqrt(temp1,oneMinueI);
		    mpf_sqrt(temp1,temp1);
		    mpf_ui_sub(nr,1u,temp1);
		    mpf_add_ui(dr,temp1,1u);
			//nr and dr calculated
		    mpf_div(y0,nr,dr); 								//calcualation of yi is completed.
		    //calcualtion of ai
			//part2
		    mpf_set(holdYi,y0);
		    mpf_pow_ui(ai_part2,y0,2u);
		    mpf_add(ai_part2,y0,ai_part2);
		    mpf_add_ui(ai_part2,ai_part2,1u);
		    mpf_mul(ai_part2,ai_part2,y0);
		    double two = (2*i)+1;
		    double twoP=pow(2,two);
		    mpf_mul_ui(ai_part2,ai_part2,twoP);         	// calcuation of part2 of ai completed
		    //calculate part1
		    mpf_add_ui(ai_part1,y0,1u);
		    mpf_pow_ui(ai_part1,ai_part1,4u);
		    mpf_mul(ai_part1,ai_part1,a0);					//calculateion of part1 of ai is completed
		    //calculate ai
		    mpf_sub(a0,ai_part1,ai_part2);
    }


    steady_clock::time_point end_time = steady_clock::now();
    long ns = duration_cast<nanoseconds>(end_time - start_time).count();


    mpf_t BigPi; mpf_init(BigPi);							// variable to hold 1/ai
	mpf_ui_div(BigPi,1u,a0);								//inverting the value of ai
    cout<<"API: pi to 1,000 places:"<<endl;
	print(BigPi);

	cout<<"Elapsed time: "<< ns/pow(10,9) <<"seconds";
}


void print(const mpf_t& pi)
{
	//mpf_out_str (stdout, 10,1001, pi);
	int group_count=0;
	char *ptr=NULL;
	char *newPtr;
	mp_exp_t exp;
	newPtr = mpf_get_str(ptr,&exp,BASE,PLACES+1,pi);
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


