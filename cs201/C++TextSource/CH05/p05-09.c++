/*	This program reads a test score, calculates the letter 
	grade based on the absolute scale, and prints it.
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
/*	=================== scoreToGrade ===================
	This function calculates the letter grade for a score.
	   Pre    the parameter score
	   Post   Returns the grade
*/
char scoreToGrade (int score)
{
	char grade;
	if (score >= 90)
	    grade = 'A';
	else if (score >= 80)
	    grade = 'B';
	else if (score >= 70)
	    grade = 'C';
	else if (score >= 60)
	    grade = 'D';
	else
	    grade = 'F';
	return grade;
}  // scoreToGrade

/*	Results

Enter the test score (0-100): 89
The grade is: B

Enter the test score (0-100): 80
The grade is: B

*/
