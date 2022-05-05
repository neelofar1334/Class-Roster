//
//  roster.h
//  C867 Project
//
//  Created by Neelofar Karimi on 2/5/22.
//

#ifndef roster_h
#define roster_h
#include "student.h"
using namespace std;

class Roster {

public:
        int lastIndex = -1;
        const static int numStudents = 5;
    
public:
    
    //Constructor
    Roster();

    Student* classRosterArray[numStudents];
            
    //Functions
    void parse(string StudentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(degreeProgram degree);
    
    
    //Destructor
    ~Roster();
    
};
#endif /* roster_h */
