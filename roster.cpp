//
//  roster.cpp
//  C867 Project
//
//  Created by Neelofar Karimi on 2/5/22.
//

#include <iostream>
#include <string>
#include "roster.h"

#ifndef roster_cpp
#define roster_cpp
using namespace std;

//Constructors
Roster::Roster() {
}


//define functions
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degree) {
    
    int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
    
}

//Parse
void Roster::parse(string StudentData) {
     size_t rhs = StudentData.find(",");
     string studentID = StudentData.substr(0, rhs);
     
     size_t lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     string firstName = StudentData.substr(lhs, rhs - lhs);
     
     lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     string lastName = StudentData.substr(lhs, rhs - lhs);
     
     lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     string emailAddress = StudentData.substr(lhs, rhs - lhs);
     
     lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     int age = stoi(StudentData.substr(lhs, rhs - lhs));
     
     lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     int days0 = stoi(StudentData.substr(lhs, rhs - lhs));
     
     lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     int days1 = stoi(StudentData.substr(lhs, rhs - lhs));
     
     lhs = rhs + 1;
     rhs = StudentData.find(",", lhs);
     int days2 = stoi(StudentData.substr(lhs, rhs - lhs));
     
     lhs = rhs + 1;
     rhs = StudentData.find(',', lhs);
     string degree = StudentData.substr(lhs, rhs - lhs);
     
     degreeProgram program = degreeProgram::SOFTWARE;
     if (degree == "SECURITY") {
         program = degreeProgram::SECURITY;
     }
     
     else if (degree == "NETWORK") {
         program = degreeProgram::NETWORK;
     }
     
     else if (degree == "SOFTWARE") {
         program = degreeProgram::SOFTWARE;
     }
    
    int DaysInCourse[3] = {
        days0, days1, days2
    };
     
    add(studentID, firstName, lastName, emailAddress, age, DaysInCourse[0], DaysInCourse[1], DaysInCourse[2], program);
}


//Remove
void Roster::remove(string studentID) {
    bool done = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        
        if (classRosterArray[i]->getStudentID() == studentID) {
            
            done = true;
        Student* temp = classRosterArray[i];
        classRosterArray[i] = classRosterArray[numStudents - 1];
        classRosterArray[numStudents - 1] = temp;
        
        Roster::lastIndex--;
        }
    }
    if (done) {
    cout << "Student " << studentID << " removed." << endl;
    printAll();
}
    else cout << "The student with the ID: " << studentID << " was not found." << endl;
}

//Print
void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i]->print(); }
}

//Average Days
void Roster::printAverageDaysInCourse(string studentID) {

        for (int i = 0; i <= Roster::lastIndex; i++) {
            if (classRosterArray[i]->getStudentID() == studentID) {

        cout << "Student ID: " << studentID << ", " << "average days in course is: ";
                cout << (classRosterArray[i]->getDaysInCourse()[0] +
                 classRosterArray[i]->getDaysInCourse()[1] +
                 classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << endl;
                 }
    }
}
    
//Invalid Emails
void Roster::printInvalidEmails() {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find(' ') != string::npos || email.find('.') == string::npos || email.find('@') == string::npos)
            cout << email << " - is invalid" << endl;
    }
}

//Print Degree Program
void Roster::printByDegreeProgram(degreeProgram degree) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getdegreeProgram() == degree) classRosterArray[i]->print();
        }
    }

//Destructor
Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

#endif /* roster_cpp */
