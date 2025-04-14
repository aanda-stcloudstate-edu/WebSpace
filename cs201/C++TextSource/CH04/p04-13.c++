/*	Sample of top-down development using stubs.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

//	 Prototype Declarations 
	int initialize  (void);
	int process     (void);
	int endOfJob    (void);

int main ()
{
	cout << "Begin program \n\n";

	initialize ( );
	process    ( );
	endOfJob   ( );
	
	return 0;
}	// main 
// ================= initialize ================== 
int initialize (void) 
//	Stub for initialize  
{
	cout << "In initialize: \n";
	return 0;
}	// initialize 
// ================== process ================== 
int process (void) 
//	Stub for process 
{
	cout << "In process: \n";
	return 0;
}	// process 
// ================== endOfJob ================== 
int endOfJob (void) 
//	Stub for endOfJob 
{
	cout << "In endOfJob: \n";
	return 0;
}	// endOfJob

/*	Results
Begin program 

In initialize: 
In process: 
In endOfJob: 
*/
