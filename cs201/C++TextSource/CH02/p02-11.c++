/*	Display the decimal value of selected characters.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

int		main (void)
{
	char A         = 'A';
	char a         = 'a';
	char B         = 'B';
	char b         = 'b';
	char Zed       = 'Z';
	char zed       = 'z';
	char zero      = '0';
	char eight     = '8';
	char NL        = '\n';       // newline 
	char HT        = '\t';       // horizontal tab
	char VT        = '\v';       // vertical tab
	char SP        = ' ';        // blank or space 
	char BEL       = '\a';       // alert (bell) 
	char dblQuote  = '"';        // double quote 
	char backSlash = '\\';       // backslash itself 
	char oneQuote  = '\'';       // single quote itself 

	cout << "\nASCII char 'A'  is: "  << (int)A;
	cout << "\nASCII char 'a'  is: "  << (int)a;
	cout << "\nASCII char 'B'  is: "  << (int)B;
	cout << "\nASCII char 'b'  is: "  << (int)b;
	cout << "\nASCII char 'Z'  is: "  << (int)Zed;
	cout << "\nASCII char 'z'  is: "  << (int)zed;
	cout << "\nASCII char '0'  is: "  << (int)zero;
	cout << "\nASCII char '8'  is: "  << (int)eight;
	cout << "\nASCII char '\\n' is: " << (int)NL;
	cout << "\nASCII char '\\t' is: " << (int)HT;
	cout << "\nASCII char '\\v' is: " << (int)VT;
	cout << "\nASCII char ' '  is: "  << (int)SP;
	cout << "\nASCII char '\\a' is: " << (int)BEL;
	cout << "\nASCII char '\"'  is: " << (int)dblQuote;
	cout << "\nASCII char '\\'  is: " << (int)backSlash;
	cout << "\nASCII char '''  is: "  << (int)oneQuote;
	return 0;
}	// main 

/*	Results:
ASCII char 'A'  is: 65
ASCII char 'a'  is: 97
ASCII char 'B'  is: 66
ASCII char 'b'  is: 98
ASCII char 'Z'  is: 90
ASCII char 'z'  is: 122
ASCII char '0'  is: 48
ASCII char '8'  is: 56
ASCII char '\n' is: 10
ASCII char '\t' is: 9
ASCII char '\v' is: 11
ASCII char ' '  is: 32
ASCII char '\a' is: 7
ASCII char '"'  is: 34
ASCII char '\'  is: 92
ASCII char '''  is: 39


*/
