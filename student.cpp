#include <iostream>
#include <string>
#include "student.h"

using namespace std;

//Part D2d - Constructors annd destructor.
Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for(int i = 0; i < daysArraySize; i++) this->avgDays[i] = 0;
	this->degree = DegreeProgram::UNKNOWN;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int avgDays[], DegreeProgram degree) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->avgDays[i] = avgDays[i];
	this->degree = degree;
}

Student::~Student(){}

//Part D2a - Accessors (getters).
string Student::getStudentId() {
	return this->studentId;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}
int Student::getAge() {
	return this->age;
}
int* Student::getAvgDays() {
	return this->avgDays;
}
DegreeProgram Student::getDegree() {
	return this->degree;
}

//Part D2b - Mutators (setters).
void Student::setStudentId(string studentId) {
	this->studentId = studentId;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setAvgDays(int avgDays[]) {
	for (int i = 0; i < daysArraySize; i++)
		this->avgDays[i] = avgDays[i];
}
void Student::setDegreeProgram(DegreeProgram degree) {
	this->degree = degree;
}

//Part D2e - Print specific student data.
void Student::print() {
	cout << this->getStudentId() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getAvgDays()[0] << '\t';
	cout << this->getAvgDays()[1] << '\t';
	cout << this->getAvgDays()[2] << '\t';
	cout << degreeProgramStrings[this->getDegree()] << endl;
}