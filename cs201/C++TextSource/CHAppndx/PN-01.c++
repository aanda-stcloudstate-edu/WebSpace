/*	Demonstrate use of pointers to functions. 
	Written by: 
	Date: 
*/
#include <iostream>
using namespace std;

void strange (void(*ptrToFunction)(void)); 
void fun ();
void pun ();
void sun ();

int main (void)
{
// Statements 
strange (fun);
strange (pun);
strange (sun);
return 0;
} // main 
/* ================== strange ================== 
	This function will call whatever function is passed
	to it by the calling function.
	   Pre  ptrFun pointer to  function to be executed 
	   Post requested function has been executed
*/
void strange (void(*ptrToFunction)())
{
	(*ptrToFunction)(); 
	return;
}	// strange 
/* ================== fun ================== 
	Prints a simple message about fun.
	   Pre  Nothing
	   Post Message has been printed
*/
void fun ()
{
	cout << "Fun is being with good friends.\n";
	return;
}	// fun 
/* ================== pun ================== 
	Prints a simple message about pun.
	   Pre  Nothing
	   Post Message has been printed
*/
void pun ()
{
	cout << "Pun is a play on words.\n";
	return;
}	// pun 

/* ================== sun ================== 
	Prints a simple message about sun.
	   Pre  Nothing
	   Post Message has been printed
*/
void sun ()
{
	cout << "Sun is a bright star.\n";
	return;
}	// sun 

/* Run results:
Fun is being with good friends.
Pun is a play on words.
Sun is a bright star.
*/
