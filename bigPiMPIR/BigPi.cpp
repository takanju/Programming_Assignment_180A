/*
 * BigPi.cpp
 *
 *  Created on: Oct 25, 2020
 *      Author: swapnanjali
 */

#include <iostream>
#include <mpirxx.h>
#include <mpir.h>
#include <stdio.h>
#include <cmath>

using namespace std;


void calculatePi();


int main(){
	calculatePi();
//mpz_class a =1;
//cout << a;



}


void calculatePi(){
	//double a=0, y=0;
	mpz_class a =0, y=0;

for(mpz_class i =1; i=0; i<250; i++){
if(i==0){

	a = mpz_sub (mpz t rop, mpz t 6, mpz t (mpz_mul (4,mpz_sqrt (mpz t rop, mpz t 2))))
	//a= 6 - 4*sqrt(2);

			y= sqrt(2) -1;
}

else

    y = 1 -  pow((1-pow(y,4)), 1.0/4) / 1 + pow((1-pow(y,4)), 1.0/4);

     a = a * pow((1+y), 4) - y * (1+y+ pow(y, 2));



}

cout<< 1.0/a;

}


