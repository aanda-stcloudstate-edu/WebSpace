// program to approximate the sine and cosine function
// A. Anda
// Fall '02
// cs102
// homework 3

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

//  Global declarations

    const double Pi = 4 * atan(1.0);

int main (void)
{
//  Local declarations

    int degrees;
    int seed = 0;
    int cosDevisor = 1; // devisor for each cosine series term
    int sinDevisor = 1; // devisor for each sine series term
    double radians;
    double term;
    double sinx, cosx;
    double sin4x, cos4x;
    double cosx2;
    double trueSine, trueCosine;

// Statements

    cout << "\nEnter degrees as a non-negative integer "
         << endl << endl;

    cin >> degrees;

    radians = (degrees % 360) * Pi / 720; // reduce and convert to radians / 4

    //   We are dividing by four to further reduce the angle to a
    //   bounded region that the approximating series can operate on
    //   reasonably accurately.
    //   We then later restore the angle on demand.

    term = 1.0;
    cosx = term;
    term *= radians;
    sinx = term;                  // first term

    seed += 2;
    sinDevisor *= seed * (seed + 1);
    cosDevisor *= seed * (seed - 1);
    term *= radians;
    cosx -= term / cosDevisor;
    term *= radians;
    sinx -= term / sinDevisor;        // second term

    seed += 2;
    sinDevisor *= seed * (seed + 1);
    cosDevisor *= seed * (seed - 1);
    term *= radians;
    cosx += term / cosDevisor;
    term *= radians;
    sinx += term / sinDevisor;        // third term

    seed += 2;
    sinDevisor *= seed * (seed + 1);
    cosDevisor *= seed * (seed - 1);
    term *= radians;
    cosx -= term / cosDevisor;
    term *= radians;
    sinx -= term / sinDevisor;        // fourth term

    seed += 2;
    sinDevisor *= seed * (seed + 1);
    cosDevisor *= seed * (seed - 1);
    term *= radians;
    cosx += term / cosDevisor;
    term *= radians;
    sinx += term / sinDevisor;        // fifth term

//  formulae to convert to using a 4 * angle argument

//  sin(4x) = 8 sin(x) cos^3(x) - 4 sin(x) cos(x)
//  cos(4x) = 1 - 8 cos^2(x) + 8 cos^4(x)

    cosx2 = cosx * cosx;
    sin4x = cosx * sinx * 4 * (2 * cosx2 -  1);
    cos4x = 1 + 8 * cosx2 * (cosx2 - 1);

    trueSine = sin(4 * radians);
    trueCosine = cos(4 * radians);


    cout << "\nThe exact value of sin(" << degrees << ") is "
	 << trueSine << endl;

    cout << "\nThe 5 term expansion sine approximation is "
	 << sin4x
	 << endl;

    cout << "This approximation is within "
	 << (trueSine - sin4x) / trueSine * 100
	 << "% of the true value"
	 << endl;

    cout << "\nThe exact value of cos(" << degrees << ") is "
	 << trueCosine << endl;

    cout << "\nThe 5 term expansion cosine approximation is "
	 << cos4x
	 << endl;

    cout << "This approximation is within "
	 << (trueCosine - cos4x) / trueCosine * 100
	 << "% of the true value"
	 << endl;

    return 0;
} // main
