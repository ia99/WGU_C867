//
// Created by ian_a on 4/6/2024.
//

#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "degree.h"

class Roster {

public:
    Student* studentArray[5]{};
    Roster();

    static Student *populateStudentArray(const std::string& studentData);

    void add(const std::string &studentID, const std::string &firstName, const std::string &lastName, const std::string &emailAddress, int age,
             int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(const std::string &studentID);
    void printAll() const;
    void printAverageDaysInCourse(const std::string &studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    ~Roster();

};


#endif //ROSTER_H
