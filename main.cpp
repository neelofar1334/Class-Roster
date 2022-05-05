//
//  main.cpp
//  C867 Project
//
//  Created by Neelofar Karimi on 2/5/22.
//

#include <iostream>
#include <string>
using namespace std;

#include "roster.h"

void myHeader() {
    std::cout << "Language: C++ \n";
    std::cout << "Course: C867 Scripting & Programming Applications \n";
    std::cout << "Student ID: 008157334 \n";
    std::cout << "Name: Neelofar Karimi \n";
}

int main()
{
    const string StudentData[5] =
    {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Neelofar,Karimi,nkarim1@wgu.edu,26,30,40,35,SOFTWARE"
    };
    
    myHeader();
    Roster classRoster;
    
    //Parse+Add+Print
    
    for (int i = 0; i < 5; i++) {
        classRoster.parse(StudentData[i]);
    }
    
    cout << "\n" << "Displaying all students:" << endl;
    classRoster.printAll();
    cout << endl;
    
    //Invalid emails
    cout << "\n" << "Displaying invalid emails:" << endl;
    classRoster.printInvalidEmails();
    
    //Average Days in Course
    cout << "\n" << "Displaying average days in course:" << endl;
    for (int i = 0; i < Roster::numStudents; i++) classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    
    //Print by degree program
        cout << "\n" << "Showing students in degree program: " << degreeProgramStrings[2] << endl;
        classRoster.printByDegreeProgram(degreeProgram::SOFTWARE);
    
    
    //Removing
    cout << "\n" << "Removing A3 " << endl;
    classRoster.remove("A3");
    
    cout << "\n" << "Removing A3 again" << endl;
    classRoster.remove("A3");

    cout << "\n" << "DONE" << endl;
    
    return 0;

}
