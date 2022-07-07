#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"

using namespace std;

//Part D1 - Create the student class. Variables are in the private section.
class Student {
public:
	const static int daysArraySize = 3;

//Part D2d - Constructors and destructor.
	Student();
	Student(string studentId,
			string firstName,
			string lastName,
			string emailAddress,
			int age,
			int avgDays[],
			DegreeProgram degree);
	~Student();

//Part D2a - Accessors (getters).
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getAvgDays();
	DegreeProgram getDegree();

//Part D2b - Mutators (setters).
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setAvgDays(int avgDays[]);
	void setDegreeProgram(DegreeProgram degree);

//Part D2e - Print specific student data.
	void print();

private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int avgDays[daysArraySize];
	DegreeProgram degree;
};

#endif