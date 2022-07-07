//Part B - Create a project in the IDE with six source files.
//Part F - In the main.cpp file, add an empty main() function.

#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main(){
    //Part A - Add the student data from the scenario and add your personal information.
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Richard,Mafera,rmafer1@wgu.edu,33,10,20,30,SOFTWARE"
    };

 //Part F1 - Print out your name, student number, course title, and programming language used.
    cout << "Name: Richard Guy Mafera III" << endl;
    cout << "Student ID: 010241506" << endl;
    cout << "Course: C867 Scripting and Programming - Applications" << endl;
    cout << "Lanuage: C++" << endl << endl;

   const int numStudents = 5;

// Part F2 - Create an instance of the Roster class.
    Roster roster;

//Part F3 - Function call.
    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);

//Part F4 - Various print statements.
    cout << "Displaying all students:" << endl;
    roster.printAll();
    cout << endl;

    cout << "Displaying invalid email addresses:" << endl;
    roster.printInvalid();
    cout << endl;

    cout << "Displaying average days in a course:" << endl;
    for (int i = 0; i < numStudents; i++) {
        roster.printAvgDays(roster.classRosterArray[i]->getStudentId());
    }
    cout << endl;

    cout << "Displaying students in the SOFTWARE degree program:" << endl;
    roster.printDegreeProgram(DegreeProgram::SOFTWARE);

    cout << "Removing student 'A3':" << endl;
    roster.removeStudent("A3");
    cout << endl;

    cout << "Removing student 'A3' again:" << endl;
    roster.removeStudent("A3");
    cout << endl;

    return 0;
}