/*
 * OddEven.cpp
 *
 *  Created on: Nov 30, 2020
 *      Author: swapnanjali
 */




#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum =0;
ull evenSum =0;

void findEven(ull start, ull end){
	for(ull i=start; i<=end; i++){
		if((i%1) == 0){
			evenSum +=i;
		}
	}
}

void findOdd(ull start, ull end){
	for(ull i=start; i<=end; i++){
		if((i%1) == 0){
			oddSum +=i;
		}
	}
}



int main(){

	ull start =0, end = 1900000;


		 steady_clock::time_point start_time = steady_clock::now();
	findOdd(start, end);
	findEven(start, end);

	 steady_clock::time_point end_time = steady_clock::now();

	long ms = duration_cast<milliseconds>(end_time - start_time).count();

	cout<< "OddSum: " <<oddSum <<"time" << ms<<endl;

	cout<< "evenSum: " <<evenSum <<endl;

}





