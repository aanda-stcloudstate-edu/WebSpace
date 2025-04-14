/** a text formatter
@file location: /home/STCLOUDSTATE/jq4933kt/CSCI301/Project3/format.cpp
@author: John Smith, CSCI 301-Section 1
@due date: September 21, Friday 
 **/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sctring>
#include <cstdlib>

using namespace std;

const int MIN = 30;	// Minimum line length
const int MAX = 80;	// Maximum line length

/** Opens for input a file named from the terminal.
@param: in_f is ifstream
@pre: None
@Post: A file stream has been opened for input.*/
void open_input_file ( ifstream& in_f );

/** Opens for output a file named from the terminal.
@param: in_f is ifstream
@pre: None
@Post: A file stream has been opened for output.*/ 
void open_output_file ( ofstream& out_f );

/** Reads an input value within specified bounds.
@param: small and large are two integers
@Pre: small and large are positive integers, with small <= large.
@Post: The function returns a value in [small,large] entered from the terminal.*/
int read_int ( int small, int large );

int main()
{
ifstream in_file;	// The input file stream ofstream out_file;	// The output file stream 
int max_length;	// Maximum line length
char s[MAX+1];	// Each string read in and printed out 
int s_len;	// The length of the string s
int line_len;	// The length of the current output line so far

// Open the input file. open_input_file(in_file);

// Open the output file.     open_output_file(out_file);

// Read the maximum line length. 
    max_length = read_int(MIN,MAX);

line_len = 0; 
in_file >> s;
while ( ! in_file.eof() )
{
s_len = strlen(s);
if ( line_len + s_len <= max_length )
{
out_file << s;
line_len = line_len + s_len;
}
else
{
out_file << endl << s; line_len = s_len;
}

if ( line_len < max_length )
{
out_file << ' ';
++line_len;
}
in_file >> s;
}
out_file << endl; in_file.close(); out_file.close();

return EXIT_SUCCESS;
}

void open_input_file ( ifstream &in_f )
{
char input_file_name[80];

do
{ in_f.clear();
cout << "Enter input file name: "; cin >> input_file_name; in_f.open(input_file_name);
} while ( in_f.fail() );
}

void open_output_file ( ofstream &out_f )
{
char output_file_name[80];

do
{ out_f.clear();
cout << "Enter output file name: "; cin >> output_file_name; out_f.open(output_file_name);
} while ( out_f.fail() );
}

int read_int ( int small, int large )
{
int value;

do
{ cout << "Enter an integer value between " << setw(1) << small
<< " and " << setw(1) << large << ": "; cin >> value;
} while ( value < small || value > large ); return value;
}
