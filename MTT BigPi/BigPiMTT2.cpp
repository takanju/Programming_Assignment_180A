#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <queue>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <pthread.h>

#define NUM_THREADS 4;

using namespace std;
using namespace std::chrono;


const int max_iterations =2;
int iter=0;
deque<int>  buffer;
std::mutex mu;





long double borwein();

int main()
{
       cout << fixed << setprecision(19);


	    cout << endl;
	    cout << "Value of pi" << endl << endl;

	    cout << "C++ API: pi to " << " 1 million places:" << endl;

	       pthread_t  threads[NUM_THREADS];
	        int rc;
	        long t;
	        void* status;
	        float tot_in =0;
	        for( t=0;t<NUM_THREADS;t++){
	              rc = pthread_create(&threads[t], NULL,borwein , (void *)t);
	              if (rc){
	            cout<< "ERROR; return code from pthread_create()"<< rc ;
	            exit(-1);
	             }
	        }
	        //join the threads
	        for( t=0;t<NUM_THREADS;t++)
	        {
	        pthread_join(threads[t], &status);

	        tot_in+=*(float*)status; //keep track of the total in count
	        }

	        /* Last thing that main() should do */
	        pthread_exit(NULL);

	    long double pi;


	    steady_clock::time_point start_time = steady_clock::now();
	    borwein();

	    steady_clock::time_point end_time = steady_clock::now();

	    long ns = duration_cast<nanoseconds>(end_time - start_time).count();

	           cout<<" Total elapsed time: "<< ns/(1000000000) <<" seconds"<<endl;


	    return 0;


}


long double borwein(){

double six(6.0), four(4.0), two(2.0), one(1.0);


 double a0 = six - four * sqrt(two);
 double y0 = sqrt(two) - one;

 long double yi, ai_first, ai_second, ai;
 long double two_power = two;;

for(int i=1; i<max_iterations;i++){

	long double four_root = sqrt(sqrt(one - (y0*y0*y0*y0)));

	yi = (one - four_root) / (one + four_root);

	ai_first = a0*(one + yi)*(one + yi)*(one + yi)*(one + yi);

	two_power = two*two_power;

	ai_second = two_power * yi * (one + yi + (yi*yi));

	ai = ai_first - ai_second;

	y0 = yi;
	a0 = ai;
}

	return ai;

}

