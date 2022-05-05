//
//  student.h
//  C867 Project
//
//  Created by Neelofar Karimi on 2/5/22.
//

#ifndef student_h
#define student_h
#include <iostream>
#include "degree.h"
using namespace std;

//Attributes
class Student {
    
private:
    const static int daysInCourse = 3;
    
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int days[daysInCourse];
    degreeProgram  degree;
    
    //Constructor
public:
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysInCourse,  degreeProgram degree);
    
    //Accessors-Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int *getDaysInCourse();
    enum degreeProgram getdegreeProgram();
    
    
    //Mutators-Setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int getDaysInCourse[]);
    void setDegreeProgram(degreeProgram degree);
    
    
    //Functions
    void print();
    
    
};
#endif /* student_h */
