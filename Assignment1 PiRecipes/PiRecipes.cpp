


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int    MAX_ITERATIONS = 20;
const double TOLERANCE      = 1.0e-17;

/**
 * Compute the factorial of an integer value.
 * @param n the value.
 * @return n! as a double.
 */
double factorial(int n);

/**
 * Compute the arctangent of a double value.
 * @param x the value.
 * @return an estimate of arctan(x).
 */
double arctangent(double x);

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_0();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_1();

/**
 * Compute an estimate of pi using a formula by Ramanujan.
 * @return an estimate of pi.
 */
void Ramanujan_2();

/**
 * Compute an estimate of pi using a formula by the Chudnovsky brothers.
 * @return an estimate of pi.
 */
void Chudnovsky();

/**
 * Compute an estimate of pi using an arctangent formula by Machin.
 * @return an estimate of pi.
 */
void Machin();

int main()
{
    cout << fixed << setprecision(16);

    cout << endl;
    cout << "Ramanujan pi recipe #0:" << endl << endl;
    Ramanujan_0();

    cout << endl;
    cout << "Ramanujan pi recipe #1:" << endl << endl;
    Ramanujan_1();

    cout << endl;
    cout << "Ramanujan pi recipe #2:" << endl << endl;
    Ramanujan_2();

    cout << endl;
    cout << "Chudnovsky pi recipe:" << endl << endl;
    cout << "  Iteration  Estimate" << endl;
    Chudnovsky();

    cout << endl;
    cout << "Machin pi recipe:";
    Machin();

    return 0;
}

double factorial(int n)
{
    double nf = 1;
    for (int i = 2; i <= n; i++) nf *= i;
    return nf;
}

void Ramanujan_0()
{
    double  log_value = 0.0,  pi = 0.0;
    const double K = 12.00/sqrt((double)190);

    //to compute value from the given formula
    log_value = log((2*sqrt((double)2) + sqrt((double)10)) * (3 + sqrt((double)10)));
    pi = K*log_value;

    //to use library function setw() to set width field
    cout << setw(11) << "Estimate:" <<  " " << pi << endl;

}

void Ramanujan_1()
{
    cout << "  Iteration  Estimate" << endl;

    double one_over_pi;
    double factor0 = sqrt((double) 8)/(99*99);
    double sum  = 0.0;
    double prev = 0.0;
    double diff = 0.0;

    int n = 0;

    do
    {
        double factor1 = factorial(4*n)/pow((pow(4.0, n)*factorial(n)), 4);
        double factor2 = ((double) 1103 + 26390*n)/pow((double) 99, 4*n);

        sum += factor1*factor2;

        one_over_pi = factor0*sum;
        cout << setw(11) << n+1 << "  " << 1.0/one_over_pi << endl;

        diff = abs(prev - one_over_pi);
        prev = one_over_pi;
        n++;
    } while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

void Ramanujan_2()
{
    cout << "  Iteration  Estimate" << endl;
    const double   K = 1.00/882;
    double  numerator_n1 = 0.0, denominator_d1 = 0.0, numerator_n2 = 0.0;
    double denominator_d2 =0.0, factor1 = 0.0, factor2 = 0.0, summation = 0.0;
    double prev = 0.0, diff = 0.0;
    int n=0;

    do
   {
        numerator_n1 = (pow((signed)-1,n)) * (factorial(4*n));
        denominator_d1 = pow((pow(4,n)) * (factorial(n)), 4);

        numerator_n2 = ((double)1123 + (21460 * n));
        denominator_d2 = pow((double)882, (2*n));

        factor1 = numerator_n1/denominator_d1;
        factor2 = numerator_n2/denominator_d2;

        summation += (K*factor1*factor2);


        cout << setw(11) << n+1 << "  "  << 4.0/summation<<endl;

        //to calculate absolute value as difference can be positive or negative
        diff = abs(prev - summation);
        //to assign summation in prev to use in next iteration
        prev = summation;
        n++;

      }
      //to put the same conditions as mentioned in Ramanujan 1 formula
      while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

void Chudnovsky()
{
    const int K = 12;
    double  numerator_n1 = 0.0, denominator_d1 = 0.0, numerator_n2 = 0.0;
    double denominator_d2 =0.0, factor1 = 0.0, factor2 = 0.0, total = 0.0, one_over_pi = 0;
    double prev = 0.0, diff = 0.0;
    int n=0;

  do
  {
        //to calculate numerator and denominator of factor 1
        numerator_n1 = pow((signed)-1, n)* factorial(6*n);
        denominator_d1 = factorial(3*n)*pow(factorial(n),3);

        //to calculate numerator and denominator of factor 1
        numerator_n2 = 13591409 + (545140134*n);
        denominator_d2 = pow(pow(640320,3),(n+ 0.5));

        factor1 = numerator_n1/denominator_d1;
        factor2 = numerator_n2/denominator_d2;

        total += (K*(factor1*factor2));
        one_over_pi = K*total;

        cout << setw(11) << n+1 << "  " << 1.0/total <<endl;
        diff = abs(prev - one_over_pi);
        prev = one_over_pi;
        n++;

       }while ((diff > TOLERANCE) && (n <= MAX_ITERATIONS));
}

double arctangent(double x)
{
    double arctan = x;
    cout <<  endl;

    double factor_1 = 0.0, factor_2 = 0.0, diff = 0.0, prev = 0.0;
    int n =1;
    do
    {
        //first convert series in to sigma notation
        //then compute value of arctan x
        factor_1 = pow((signed)-1, n);
        factor_2 = pow((double)x, (2*n)+1)/(double)(2*n+1);

        arctan+=factor_1*factor_2;
        diff = abs(prev - arctan);
        prev = arctan;
        n++;

     //to put condition as mentioned in given formula
   }while (diff < TOLERANCE);
    return arctan;
}

void Machin()
{
    double pi_over_4 = 4*arctangent(0.2) - arctangent(1.0/239.0);
    cout << " Estimate:  " << 4*pi_over_4 << endl;
}
