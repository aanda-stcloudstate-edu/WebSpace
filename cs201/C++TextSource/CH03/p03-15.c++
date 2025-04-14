/*	Calculate a student's average score for a course 
	with 4 quizzes, 2 midterms, and a final. The quizzes 
	are weighted 30%, the midterms 40%, & the final 30%. 
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int   cQuizWeight    =  30;
const int   cMidtermWeight =  40;
const int   cFinalWeight   =  30;
const float cQuizMax       = 400.00;
const float cMidtermMax    = 200.00;
const float cFinalMax      = 100.00;

int main ()
{
	cout << "=========== QUIZZES =================\n";
	cout << "Enter the score for the first quiz:  ";
	int  quiz1;
	cin  >> quiz1;
	cout << "Enter the score for the second quiz: ";
	int  quiz2;
	cin  >> quiz2;
	cout << "Enter the score for the third quiz:  ";
	int  quiz3;
	cin  >> quiz3;
	cout << "Enter the score for the fourth quiz: ";
	int  quiz4;
	cin  >> quiz4;
	cout << "============= MIDTERM  =============\n";
	cout << "Enter the score for the first midterm:  ";
	int  midterm1;
	cin  >> midterm1;
	cout << "Enter the score for the second midterm: ";
	int  midterm2;
	cin  >> midterm2;
	cout << "=============== FINAL ==============\n";
	cout << "Enter the score for the final: ";
	int  final;
	cin  >> final;
	cout << endl;

	int totalQuiz = quiz1 + quiz2 + quiz3 + quiz4;
	int totalMidterm = midterm1 + midterm2;

	float quizPercent    = static_cast<float>
	      (totalQuiz * cQuizWeight) / cQuizMax;
	float midtermPercent = static_cast<float>
	      (totalMidterm * cMidtermWeight) / cMidtermMax;
	float finalPercent   = static_cast<float>
	      (final * cFinalWeight) / cFinalMax;
	float totalPercent = 
	   quizPercent + midtermPercent + finalPercent;

	cout << fixed;
	cout << showpoint;
	cout << setprecision(1);
	
	cout << "First Quiz       " 
	     << setw(3) << quiz1     << endl;
	cout << "Second Quiz      " 
	     << setw(3) << quiz2     << endl;
	cout << "Third Quiz       " 
	     << setw(3) << quiz3     << endl;
	cout << "Fourth Quiz      " 
	     << setw(3) << quiz4     << endl;
	cout << "Quiz Total       " 
	     << setw(3) << totalQuiz << endl << endl;
	cout << "First Midterm    " 
	     << setw(3) << midterm1     << endl;
	cout << "Second Midterm   " 
	     << setw(3) << midterm2     << endl;
	cout << "Total Midterms   " 
	     << setw(3) << totalMidterm << endl << endl;
	cout << "Final            " 
	     << setw(3) << final << endl << endl;
	cout << "Quiz    " 
	     << setw(6) << quizPercent    << "%\n";
	cout << "Midterm " 
	     << setw(6) << midtermPercent << "%\n";
	cout << "Final   " 
	     << setw(6) << finalPercent   << "%\n";
	cout << "--------------\n";
	cout << "Total   " 
	     << setw(6) << totalPercent   << "%\n";
	return 0;
}	// main

/*	Results:

=========== QUIZZES =================
Enter the score for the first quiz:  98
Enter the score for the second quiz: 89
Enter the score for the third quiz:  78
Enter the score for the fourth quiz: 79
============= MIDTERM  =============
Enter the score for the first midterm:  90
Enter the score for the second midterm: 100
=============== FINAL ==============
Enter the score for the final: 92

First Quiz        98
Second Quiz       89
Third Quiz        78
Fourth Quiz       79
Quiz Total       344

First Midterm     90
Second Midterm   100
Total Midterms   190

Final             92

Quiz      25.8%
Midterm   38.0%
Final     27.6%
--------------
Total     91.4%

*/
