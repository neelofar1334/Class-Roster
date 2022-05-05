//
//  student.cpp
//  C867 Project
//
//  Created by Neelofar Karimi on 2/5/22.
//

#include <string>
#include <iostream>
#include "student.h"
using namespace std;

//Constructor
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->days[0] = 0;
    this->days[1] = 0;
    this->days[2] = 0;
    this->degree = degreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int getDaysInCourse[], degreeProgram degree) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->days[0] = getDaysInCourse[0];
    this->days[1] = getDaysInCourse[1];
    this->days[2] = getDaysInCourse[2];
    this->degree = degree;
}

//Accessors-Getters
 string Student::getStudentID()
    { return this->studentID; }

string Student::getFirstName()
    { return this->firstName; }

string Student::getLastName()
    { return this->lastName; }

string Student::getEmailAddress()
    { return this->emailAddress; }

int Student::getAge() 
    { return this->age; }

degreeProgram Student::getdegreeProgram()
    { return this->degree; }

int * Student::getDaysInCourse()
    { return this->days; }


//Mutators-Setters
void Student::setStudentID(string studentID)
    { this->studentID = studentID; }

void Student::setFirstName(string firstName)
    { this->firstName = firstName; }

void Student::setLastName(string lastName)
    { this->lastName = lastName; }

void Student::setEmailAddress(string emailAddress)
    { this->emailAddress = emailAddress; }

void Student::setAge(int age)
    { this->age = age; }

void Student::setDaysInCourse(int getDaysInCourse[])
    { Student::days[0] = getDaysInCourse[0];
      Student::days[1] = getDaysInCourse[1];
      Student::days[2] = getDaysInCourse[2]; }

void Student::setDegreeProgram(degreeProgram degree)
    { this->degree = degree; }


//Function
void Student::print() {
    std::cout << this->studentID << '\t';
    std::cout << this->firstName << '\t';
    std::cout << this->lastName << '\t';
    std::cout << this->emailAddress << '\t';
    std::cout << this->age << '\t';
    std::cout << this->days[0] << '\t';
    std::cout << this->days[1] << '\t';
    std::cout << this->days[2] << '\t';

    string degree_string;
if (degree == degreeProgram::SECURITY) {
    degree_string = "Security";
}

else if (degree == degreeProgram::NETWORK) {
    degree_string = "Network";
}

else if (degree == degreeProgram::SOFTWARE) {
    degree_string = "Software";
}
    std::cout << degree_string << endl;

}


