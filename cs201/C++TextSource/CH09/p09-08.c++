/*	Test driver for function that converts integer into
	time--hours, minutes, seconds.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

/*	Prototype Declarations */
	int secToHours (long time, int *hours, int *minutes, int *seconds);
	
int main (void)
{
/*	Local Definitions */
	int  hours;
	int  minutes;
	int  seconds;
	long time;
	
/*	Statements */
	cout << "Enter time in seconds: "; 
	cin  >> time;
	
	if (secToHours (time, &hours, &minutes, &seconds))
	    cout << time    << " seconds is " << hours << ":" 
	         << minutes << ":" << seconds << endl;
	else
	    cout << "Your time was invalid\n\a";
	    
	cout << "Thank you\n";
	return 0;
}	/* main */

/*	=================== secToHours ===================
	Given time in seconds, convert it to hours, minutes,
	and seconds.
	   Pre    time in seconds
	          addresses of hours, minutes, seconds
	   Post   hours, minutes, seconds calculated
	   Return error indicator--1 success, 0 bad time
*/
int secToHours (long  time,    int* hours,
                int*  minutes, int* seconds)
{
	long localTime = time;
	*seconds  = localTime % 60;
	localTime = localTime / 60;
	*minutes  = localTime % 60;
	*hours    = localTime / 60;
	
	if (*hours > 24)
	   return 0;
	else
	   return 1;
}	// secToHours 

/*	Results:
	Enter time in seconds: 0
	0 seconds is 0:0:0
	Thank you
	
	86400 seconds is 24:0:0
	
	43261 seconds is 12:1:1
	
	119 seconds is 0:1:59
	
	Enter time in seconds: 96400
	Your time was invalid
	Thank you
*/
