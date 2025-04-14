// This program experiments with harmonic sums

// A. Anda;

#include <iostream>
#include <iomanip>
#include <float.h>
#include <math.h>
#include <time.h>
using namespace std;

// Global Declarations
const long double Eulers = 0.57721566490153286060651209008240243L;

//Function to test function call overhead
double  prodfun(int i)
{
    return (FLT_EPSILON * i);
}

//Function to test function parameter truncation and call overhead
double  divfun(int i)
{
    return (1.0 / i);
}

int main()
{
    // Local Declarations

int i;
int terms = 0;
float ffsum = 0;
float fbsum;
float oldsum = 0;
float newsum = 0;
double dfsum;
double dbsum;
long double ldfsum;
long double ldbsum;
long double formula;
long double err;

    

// Statements

        clock_t time_ffsum_start = clock(); // begin timing ffsum loop
    // Compute forward sum using float 
    //    and maintaining a loop counter, terms
    do
        {
         oldsum = newsum;
         newsum = oldsum + 1.0f / ++terms;
        } while (oldsum != newsum);
    ffsum = newsum;

    // decrementing the loop counter, terms

    terms--;
        clock_t time_ffsum_end = clock(); // end timing ffsum loop


        clock_t time_dfsum_start = clock(); // begin timing dfsum loop
    // Computing forward sum using double for terms iterations
    for (dfsum = 0, i = 1; i <= terms; i++)
    {
        dfsum  += 1.0 / i;
    }
        clock_t time_dfsum_end = clock(); // end timing dfsum loop

	double fdfsum;
        clock_t time_fdfsum_start = clock(); // begin timing fdfsum loop
    // Computing forward sum using double for terms iterations
    for (fdfsum = 0, i = 1; i <= terms; i++)
    {
        fdfsum  += divfun(i);
    }
        clock_t time_fdfsum_end = clock(); // end timing fdfsum loop


        clock_t time_fbsum_start = clock(); // begin timing fbsum loop
    // Computing backward sum using float for terms iterations
    for (fbsum  = 0, i = terms; i >= 1; i--)
        {
         fbsum  += 1.0f / i;
        } // for
        clock_t time_fbsum_end = clock(); // end timing fbsum loop

        clock_t time_dbsum_start = clock(); // begin timing dbsum loop
    // Computing backward sum using double for terms iterations
    for (dbsum  = 0, i = terms; i >= 1; i--)
        {
         dbsum  += 1.0 / i;
        } // for
        clock_t time_dbsum_end = clock(); // end timing dbsum loop

        clock_t time_ldbsum_start = clock(); // begin timing ldbsum loop
    // Computing backward sum using long double for terms iterations
    for (ldbsum = 0, i = terms; i >= 1; i--)
        {
         ldbsum += 1.0L / i;
        } // for
        clock_t time_ldbsum_end = clock(); // end timing ldbsum loop

        clock_t time_ldfsum_start = clock(); // begin timing ldfsum loop
    // Computing backward sum using long double for terms iterations
    for (ldfsum = 0, i = terms; i >= 1; i--)
        {
         ldfsum += 1.0L / i;
        } // for
        clock_t time_ldfsum_end = clock(); // end timing ldfsum loop


	float sfmsum;
        clock_t time_sfmsum_start = clock(); // begin timing sfmsum loop
    // Computing forward sum no division using single for terms iterations
    for ( sfmsum = 0, i = 1; i <= terms; i++)
    {
        sfmsum += FLT_EPSILON * i;
    }
        clock_t time_sfmsum_end = clock(); // end timing sfmsum loop

	double fdfmsum;
        clock_t time_fdfmsum_start = clock(); // begin timing fdfmsum loop
    // Computing forward sum no division using double function for terms iterations
    for ( fdfmsum = 0, i = 1; i <= terms; i++)
    {
        fdfmsum += prodfun(i);
    }
        clock_t time_fdfmsum_end = clock(); // end timing fdfmsum loop

	double dfmsum;
        clock_t time_dfmsum_start = clock(); // begin timing dfmsum loop
    // Computing forward sum no division using double for terms iterations
    for ( dfmsum = 0, i = 1; i <= terms; i++)
    {
        dfmsum += FLT_EPSILON * i;
    }
        clock_t time_dfmsum_end = clock(); // end timing dfmsum loop


	long double ldfmsum;
        clock_t time_ldfmsum_start = clock(); // begin timing ldfmsum loop
    // Computing forward sum no division using long double for terms iterations
    for ( ldfmsum = 0, i = 1; i <= terms; i++)
    {
        ldfmsum += FLT_EPSILON * i;
    }
        clock_t time_ldfmsum_end = clock(); // end timing ldfmsum loop

	double udfmsum;
        double subnorm = DBL_MIN/pow(2.0,50);
        clock_t time_udfmsum_start = clock(); // begin timing udfmsum loop
    // Computing subnormal forward sum no division using double for terms iterations
    for ( udfmsum = 0, i = 1; i <= terms; i++)
    {
        udfmsum += subnorm * i;
    }
        clock_t time_udfmsum_end = clock(); // end timing udfmsum loop


    // Computing formula value using double
     long double terms2 = terms * terms;
     formula = log(static_cast<long double>(terms)) + Eulers
                + 1 / ( 2.0L * terms)
                - 1 / ( 12.0L * terms2)
                + 1 / ( 120.0L * terms2 * terms2);

    cout << setprecision(8);
    cout << "This program computes the differences in ordering " << endl;
    cout << "and precision of harmonic sums" << endl << endl;

    cout << "The number of terms is :" << terms << endl << endl;

    err = fabs((ldbsum - ffsum) / ldbsum);
    cout << "The forward sum in FLOAT precision is " << ffsum << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / FLT_EPSILON
         << " times the smallest possible FLOAT fraction, " << FLT_EPSILON
         << endl << endl;

// Begin Timing Calculations
    double looptime_ffsum = static_cast<double>(time_ffsum_end - time_ffsum_start);
    cout << "The ffsum loop required "
         << looptime_ffsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the ffsum loop required "
         << looptime_ffsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_ffsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    err = fabs((ldbsum - fbsum) / ldbsum);
    cout << "The backward sum in FLOAT precision is " << fbsum << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / FLT_EPSILON
         << " times the smallest possible FLOAT fraction, " << FLT_EPSILON
         << endl << endl;

// Begin Timing Calculations
    double looptime_fbsum = static_cast<double>(time_fbsum_end - time_fbsum_start);
    cout << "The fbsum loop required "
         << looptime_fbsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the fbsum loop required "
         << looptime_fbsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_fbsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    err = fabs((ldbsum - dfsum) / ldbsum);
    cout << "The forward sum in DOUBLE precision is " << dfsum << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / DBL_EPSILON
         << " times the smallest possible DOUBLE fraction, " << DBL_EPSILON
         << endl << endl;

// Begin Timing Calculations
    double looptime_dfsum = static_cast<double>(time_dfsum_end - time_dfsum_start);
    cout << "The dfsum loop required "
         << looptime_dfsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the dfsum loop required "
         << looptime_dfsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_dfsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    err = fabs((ldbsum - fdfsum) / ldbsum);
    cout << "The forward function sum in DOUBLE precision is " << fdfsum << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / DBL_EPSILON
         << " times the smallest possible DOUBLE fraction, " << DBL_EPSILON
         << endl << endl;

// Begin Timing Calculations
    double looptime_fdfsum = static_cast<double>(time_fdfsum_end - time_fdfsum_start);
    cout << "The fdfsum loop required "
         << looptime_fdfsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the fdfsum loop required "
         << looptime_fdfsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_fdfsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    err = fabs((ldbsum - dbsum) / ldbsum);
    cout << "The backward sum in DOUBLE precision is " << dbsum << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / DBL_EPSILON
         << " times the smallest possible DOUBLE fraction, " << DBL_EPSILON
         << endl << endl;

// Begin Timing Calculations
    double looptime_dbsum = static_cast<double>(time_dbsum_end - time_dbsum_start);
    cout << "The dbsum loop required "
         << looptime_dbsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the dbsum loop required "
         << looptime_dbsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_dbsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    err = fabs((ldbsum - ldfsum) / ldbsum);
    cout << "The forward sum in LONG DOUBLE precision is " << ldfsum << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / LDBL_EPSILON
         << " times the smallest possible LONG DOUBLE fraction, " << LDBL_EPSILON
         << endl << endl;

// Begin Timing Calculations
    double looptime_ldfsum = static_cast<double>(time_ldfsum_end - time_ldfsum_start);
    cout << "The ldfsum loop required "
         << looptime_ldfsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the ldfsum loop required "
         << looptime_ldfsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_ldfsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    cout << "The backward sum in long double precision is " << ldbsum << endl << endl;

// Begin Timing Calculations
    double looptime_ldbsum = static_cast<double>(time_ldbsum_end - time_ldbsum_start);
    cout << "The ldbsum loop required "
         << looptime_ldbsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the ldbsum loop required "
         << looptime_ldbsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_ldbsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

// Begin Timing Calculations
    double looptime_ldfmsum = static_cast<double>(time_ldfmsum_end - time_ldfmsum_start);
    cout << "The ldfmsum loop required "
         << looptime_ldfmsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the ldfmsum loop required "
         << looptime_ldfmsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_ldfmsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

// Begin Timing Calculations
    double looptime_sfmsum = static_cast<double>(time_sfmsum_end - time_sfmsum_start);
    cout << "The sfmsum loop required "
         << looptime_sfmsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the sfmsum loop required "
         << looptime_sfmsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_sfmsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

// Begin Timing Calculations
    double looptime_fdfmsum = static_cast<double>(time_fdfmsum_end - time_fdfmsum_start);
    cout << "The fdfmsum loop required "
         << looptime_fdfmsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the fdfmsum loop required "
         << looptime_fdfmsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_fdfmsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

// Begin Timing Calculations
    double looptime_dfmsum = static_cast<double>(time_dfmsum_end - time_dfmsum_start);
    cout << "The dfmsum loop required "
         << looptime_dfmsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the dfmsum loop required "
         << looptime_dfmsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_dfmsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

// Begin Timing Calculations
    double looptime_udfmsum = static_cast<double>(time_udfmsum_end - time_udfmsum_start);
    cout << "The udfmsum loop required "
         << looptime_udfmsum/CLOCKS_PER_SEC
         << " seconds\n"
         << " (measurement granularity: " << CLOCKS_PER_SEC
         << " of a second)\n\n";

    cout << "Each interation of the udfmsum loop required "
         << looptime_udfmsum/CLOCKS_PER_SEC/terms << " seconds\n"
         << "or " << 1/(looptime_udfmsum/CLOCKS_PER_SEC/terms)
         << " iterations / second\n\n\n";
// End Timing Calculations

    err = fabs((ldbsum - formula) / ldbsum);
    cout << "The formula value in LONG DOUBLE precision is " << formula << endl;
    cout << "It is within " << err * 100
         << "% of the backward sum in LONG DOUBLE precision" << endl
         << "and the err is " << err / LDBL_EPSILON
         << " times the smallest possible LONG DOUBLE fraction, " << LDBL_EPSILON
         << endl << endl;


    cout << "The ratio of long double times to double times is: "
         << looptime_ldfsum/looptime_dfsum << endl;

    return 0;
} // main

