#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main() {
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ian,Allen,ialle66@wgu.edu,38,18,23,29,SOFTWARE" };

    std::cout << "Course: Scripting and Programming - Applications - C867" << std::endl;
    std::cout << "Programming language: C++" << std::endl;
    std::cout << "Student ID: 012131931" << std::endl;
    std::cout << "Student name: Ian Allen" << std::endl;

    // create class roster and loop through array, populate w/ student data
    Roster * classRoster = new Roster();
    for (int i=0;i<=4;i++) {
        classRoster->studentArray[i]=classRoster->populateStudentArray(studentData[i]);
    }
    
    classRoster->printAll();
    classRoster->printInvalidEmails();
    for(int i=0; i<=4; i++) {
        classRoster->printAverageDaysInCourse(classRoster->studentArray[i]->get_student_id());
    }
    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    classRoster->~Roster();
}