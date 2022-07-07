#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"

class Roster {
public:
//Part E1 - Create an array of pointers.
	int initial = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

//Part E2a - Parse all sets of data in the studentData table.
	void parse(string row);

//Part E3a - Define the add function.
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int avgDays1, int avgDays2, int avgDays3, DegreeProgram degree);

//Part E3b - Define the remove function.
	void removeStudent(string studentId);

//Part E3c - Define a print fucntion.
	void printAll();
	void printDegreeProgram(DegreeProgram degree);

//Part E3d - Define a function to print the average days in the course.
	void printAvgDays(string studentId);

//Part E3e - Define a function to print invalid emails.
	void printInvalid();

	~Roster();
};

#endif