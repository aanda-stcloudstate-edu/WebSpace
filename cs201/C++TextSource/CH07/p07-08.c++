/*	Create a grades file for transmission to Registrar.
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

	bool getStu    (ifstream& stuFile,
	                int&      stuID, int& exam1,
	                int&      exam2, int& final);
	void writeStu  (ofstream& gradesFile, int  stuID,
	                int       avrg,       char grade);
	void calcGrade (int   exam1, int   exam2, int  final,
	                int&  avrg,  char& grade);

int main ()
{
	ifstream stuFile;
	cout << "Begin student grades\n";
	stuFile.open ("ch7STUFL.DAT");
	if (!stuFile)
	    {
	     cerr << "\aError opening student file\n";
	     exit (100);
	    }  // if open fail

	ofstream gradesFile;
	gradesFile.open ("ch7STUGR.DAT");
	if (!gradesFile)
	    {
	     cerr << "\aError opening grades file\n";
	     exit (102);
	    }  // if open fail 

	int  stuID;
	int  exam1;
	int  exam2;
	int  final;
	int  avrg;
	char grade;
	while (getStu (stuFile, stuID, exam1, 
	               exam2,   final))
	   {
	    calcGrade (exam1, exam2, final, avrg, grade);
	    writeStu  (gradesFile,   stuID, avrg, grade);
	   } // while

	stuFile.close ();
	gradesFile.close();
	cout << "End student grades\n";
	return 0;
}	// main 
/* ===================== getStu ====================
	Reads data from student file.

	   Pre  stuFile is an open file
	        stuID, exam1, exam2, final-ref's to int
	   Post reads student ID and exam scores into 
	        parameter references
	   Return  true  if data read 
	           -- false if end of file
*/
bool getStu (ifstream& stuFile, int& stuID,
             int&      exam1,   int& exam2,
             int&      final)
{
	// !stuFile is either eof or bad file
	stuFile >> stuID >> exam1 >> exam2 >> final;
	if (!stuFile)
	    // Read problem or at end of file
	    return false;
	return true;
}	// getStu
/*	================= calcGrade ================
	Determine student grade based on absolute scale.
	   Pre  exam1, exam2, and final contain scores
	        avrg and grade are references to variables
	   Post Average and grade copied to references
*/
void calcGrade (int  exam1, int   exam2, int final,
                int& avrg,  char& grade)
{
	avrg = (exam1 + exam2 + final ) / 3;
	if (avrg >= 90)
	   grade = 'A';
	else if (avrg >= 80)
	   grade = 'B';
	else if (avrg >= 70)
	   grade = 'C';
	else if (avrg >= 60)
	   grade = 'D';
	else
	   grade = 'F';
	return;
}	// calcGrade
/*	================= writeStu =================
	Writes student grade data to output file.
	   Pre  gradesFile is an open file
	        stuID, avrg, and grade have values to write
	   Post Data written to file
*/
void writeStu (ofstream& gradesFile, int  stuID,
               int       avrg,       char grade)
{
	gradesFile.fill ('0');
	gradesFile << setw (4) << stuID;
	gradesFile.fill (' ');
	gradesFile << setw (3) << avrg;
	gradesFile << ' ' << grade << endl;
	return;
}	// writeStu

/*	Results:
Begin student grades
End student grades

Input--------
0090 90 90 90
0089 88 90 89
0081 80 82 81
0079 79 79 79
0070 70 70 70
0069 69 69 69
0060 60 60 60
0059 59 59 59
	
Output----
0090 90 A
0089 89 B 
0081 81 B 
0079 79 C 
0070 70 C 
0069 69 D 
0060 60 D 
0059 59 F 
*/
