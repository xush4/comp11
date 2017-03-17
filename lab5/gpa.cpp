/* COMP11
 * Spring 2017
 * Lab 5
 * SHeng Xu
 * Converting grades to GPAs */

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 50;

// Consts for grades
const double A_PLUS = 4.33;
const double A = 4.0;
const double A_MINUS = 3.67;
const double B_PLUS = 3.33;
const double B = 3.0;
const double B_MINUS = 2.67;
const double NO_GRADE = 0.0;

int main()
{
	// Variables for the filestream
	// and num classes the student has taken
	ifstream infile;
	int i = 0; //number of class;
	double gpas[MAX];
	char filename[15];
	cin >> filename;
	infile.open(filename);
	if (!infile.is_open())
	//check whether the file is open.
	{
		cout << "Failed to open file\n";
	}
	else {
	
	string course, grade;
	while (!infile.eof())
	  {
	    // Check for EOF sentinel
	    infile >> course;
	    if (course == "-1")
	      break;
	    
	    infile >> grade;
	    if (grade == "A+")
	      gpas[i] = A_PLUS;
	    else if (grade == "A")
	      gpas[i] = A;
	    else if (grade == "A-")
	      gpas[i] = A_MINUS;
	    else if (grade == "B+")
	      gpas[i] = B_PLUS;
	    else if (grade == "B")
	      gpas[i] = B;
	    else if (grade == "B-")
	      gpas[i] = B_MINUS;
	    else
	      gpas[i] = NO_GRADE;
	    i++;
	    
	  }
	
	// Close the file and return
	infile.close();
	// cout >> i;
	// Now the array is populated with doubles.
	// Calculate the average GPA of the student.
	double avg_gpa, total = 0.0;
	for (int j = 0; j < i; j++)
	{
		total += gpas[j];
	}
	avg_gpa = total / i;
	//cout<< i <<endl;
	cout << "The student's GPA is " 
	     << avg_gpa <<"." <<endl;
	}
	return 0;
}
