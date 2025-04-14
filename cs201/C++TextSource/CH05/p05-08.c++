/*	This program reads a test score, calculates the letter
	grade for the score, and prints the grade.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

char scoreToGrade (int score);

int main ()
{
	cout << "Enter the test score (0-100): ";
	int  score;
	cin  >> score;

	char grade = scoreToGrade (score);
	cout << "The grade is: " << grade << endl;

	return 0;
}	// main
/*	===================== scoreToGrade =====================
	This function calculates the letter grade for a score.
	   Pre    the parameter score
	   Post   Returns the grade
*/
char scoreToGrade (int score)
{
	int  temp = score / 10;
	char grade;
	switch (temp)
	   {
	    case 10 :
	    case  9 : grade = 'A';
	              break;
	    case  8 : grade = 'B';
	              break;
	    case  7 : grade = 'C';
	              break;
	    case  6 : grade = 'D';
	              break;
	    default : grade = 'F';
	   } // switch
	return grade;
}// scoreToGrade

/*	Results
Enter the test score (0-100): 90
The grade is: A

Enter the test score (0-100): 60
The grade is: D

*/
