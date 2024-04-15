//
// Created by ian_a on 4/6/2024.
//
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <string>


Roster::Roster() {
    Student* studentArray[5];
    for(int i=0; i<=4; i++) {
        this->studentArray[i] = new Student;
    }
}

void populateStudentArray (std::string studentData) {

        auto *studentArray = new Student();

        int lengthInitial = studentData.find(",");
        std::string studentID = studentData.substr(0, lengthInitial);
        studentArray->set_student_id(studentID);

        int lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        std::string firstName = studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        studentArray->set_first_name(firstName);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        std::string lastName = studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        studentArray->set_last_name(lastName);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        std::string email = studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        studentArray->set_email(email);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        int age = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));
        studentArray->set_age(age);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        int days1 = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        int days2 = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        int days3 = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));
        studentArray->set_days_left(std::array<int, 3> {days1, days2, days3});

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(",", lengthCurrent);
        std::string degree =  studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        if(degree=="SOFTWARE")
            studentArray->set_program(SOFTWARE);
        else if (degree=="SECURITY")
            studentArray->set_program(SECURITY);
        else if (degree=="NETWORK")
            studentArray->set_program(NETWORK);
}