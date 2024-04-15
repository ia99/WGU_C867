//
// Created by ian_a on 4/6/2024.
//

#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include "degree.h"

class Roster {

public:
    Student* studentArray[5];
    Roster();
    void populateStudentArray(std::string studentData);
    std::string degreeEnumToString (DegreeProgram degree);
    ~Roster();

};


#endif //ROSTER_H
