#ifndef DEGREE_H
#define DEGREE_H
#include <string>

using namespace std;

//Part C - Create an enumerated data type DegreeProgram with the appropriate information.
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, UNKNOWN};

static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNKNOWN" };

#endif