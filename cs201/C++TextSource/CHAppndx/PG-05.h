#ifndef MSGa 
#define MSGa
#include "PG-06.h"

const char* MSG_A = "**PG-05 called from: ";

void printMsgA (const char* from)
{
cout << MSG_A << from << endl;
printMsgB ("PG-05");
return;
} // printMsgA 
#endif
