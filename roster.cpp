#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//Part E2a - Parse each set of data from studentData.
void Roster::parse(string studentData) {

	int sub1 = studentData.find(",");
	string studentId = studentData.substr(0, sub1);

	int sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	string firstName = studentData.substr(sub2, sub1 - sub2);

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	string lastName = studentData.substr(sub2, sub1 - sub2);

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	string emailAddress = studentData.substr(sub2, sub1 - sub2);

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	int age = stoi(studentData.substr(sub2, sub1 - sub2));

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	int avgDays1 = stoi(studentData.substr(sub2, sub1 - sub2));

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	int avgDays2 = stoi(studentData.substr(sub2, sub1 - sub2));

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);
	int avgDays3 = stoi(studentData.substr(sub2, sub1 - sub2));

	sub2 = sub1 + 1;
	sub1 = studentData.find(",", sub2);

	DegreeProgram degree = DegreeProgram::UNKNOWN;

	if (studentData.at(sub2) == 'S' && studentData.at(sub2 + 1) == 'E') degree = DegreeProgram::SECURITY;
	else if (studentData.at(sub2) == 'S' && studentData.at(sub2 + 1) == 'O') degree = DegreeProgram::SOFTWARE;
	else if (studentData.at(sub2) == 'N') degree = DegreeProgram::NETWORK;
	else if (studentData.at(sub2) == 'U') degree = DegreeProgram::UNKNOWN;

	add(studentId, firstName, lastName, emailAddress, age, avgDays1, avgDays2, avgDays3, degree);
}

//Part E3a - Define an add fucntion.
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int avgDays1, int avgDays2, int avgDays3, DegreeProgram degree) {
	int daysArray[3] = { avgDays1, avgDays2, avgDays3 };
	classRosterArray[++initial] = new Student(studentId, firstName, lastName, emailAddress, age, daysArray, degree);
}

//Part E3b - Define a remove function.
void Roster::removeStudent(string studentId) {
	bool remove = false;
	int  i = 0;
	for (; i < Roster::initial; ++i) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (studentId == classRosterArray[i]->getStudentId()) {
			remove = true;
			break;
		}
	}
	if (i <= Roster::initial) {
		Roster::initial -= 1;
		for (int j = i; j <= Roster::initial; j++) {
			classRosterArray[j] = classRosterArray[j + 1];
		}
	}
	if (remove == false) {
		cout << "Student " << studentId << " was not found." << endl;
	}
	else if (remove == true) {
		cout << "Student " << studentId << " was removed from the roster." << endl;
		Roster::printAll();
	}
	return;
}

//Part E3c - Define a print function.
void Roster::printAll() {
	for (int i = 0; i <= Roster::initial; i++) Roster::classRosterArray[i]->print();
}

//Part E3d - Define a function to print average days in course.
	void Roster::printAvgDays(string studentId) {
		for (int i = 0; i <= Roster::initial; i++) {
			if (classRosterArray[i]->getStudentId() == studentId) {
				cout << "Student ID: " << studentId << ", average days in course is: ";
				cout << (classRosterArray[i]->getAvgDays()[0] + classRosterArray[i]->getAvgDays()[1] + classRosterArray[i]->getAvgDays()[2]) / 3;
				cout << endl;
			}
		}
	}

//Part E3f - Define a fucntion to print by degree program.
void Roster::printDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i <= Roster::initial; i++) {
		if (Roster::classRosterArray[i]->getDegree() == degree) classRosterArray[i]->print();
	}
	cout << endl;
}

//Part E3e - Define a function that prints invalid emails.
void Roster::printInvalid() {
	bool invalid = false;
	for (int i = 0; i <= Roster::initial; i++) {
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) {
			invalid = true;
			cout << emailAddress << endl;
		}
	}
	if (!invalid) cout << "No invalid email addresses found." << endl;
}

//Part F5 - Release allocated memory.
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}