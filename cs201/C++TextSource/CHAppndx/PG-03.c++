//	PG-03.cp  Conditional multiway selection -- Not executable

#define DENVER  0
#define PHOENIX 0
#define SANJOSE 1
#define SEATTLE 0
//	É
#if (DENVER)
	// Denver unique initialization 
	#include "Denver.h"
#elif (PHOENIX)
	// Phoenix unique initialization 
	#include "Phoenix.h"
#elif (SANJOSE)
	// San Jose unique initialization 
	#include "SanJose.h"
#else
	// Seattle unique initialization 
	#include "Seattle.h"
#endif

int main (void)
{
	cout << cHeader;
	return 0;
}	// main

/*	Results
San Jose Header
*/
