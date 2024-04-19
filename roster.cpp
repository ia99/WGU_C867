//
// Created by ian_a on 4/6/2024.
//
#include "roster.h"
#include "degree.h"
#include "student.h"
#include <string>
#include <iomanip>

Roster::Roster() {
    Student* studentArray[5];
}

Roster::~Roster() {
    std::cout << "Destructor called on roster" << std::endl;
    for (int i=0; i<std::size(this->studentArray); i++) {
        this->studentArray[i]=nullptr;
        delete this->studentArray[i];
    }
}

Student *Roster::populateStudentArray(const std::string& studentData) {
        auto *objStudent = new Student();

        int lengthInitial = studentData.find(',');
        const std::string studentID = studentData.substr(0, lengthInitial);
        objStudent->set_student_id(studentID);

        int lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const std::string firstName = studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        objStudent->set_first_name(firstName);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const std::string lastName = studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        objStudent->set_last_name(lastName);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const std::string email = studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        objStudent->set_email(email);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const int age = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));
        objStudent->set_age(age);

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const int days1 = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const int days2 = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const int days3 = std::stoi(studentData.substr(lengthCurrent, lengthInitial - lengthCurrent));
        objStudent->set_days_left(std::array<int, 3> {days1, days2, days3});

        lengthCurrent = lengthInitial+1;
        lengthInitial = studentData.find(',', lengthCurrent);
        const std::string degree =  studentData.substr(lengthCurrent, lengthInitial - lengthCurrent);
        if(degree=="SOFTWARE")
            objStudent->set_program(SOFTWARE);
        else if (degree=="SECURITY")
            objStudent->set_program(SECURITY);
        else if (degree=="NETWORK")
            objStudent->set_program(NETWORK);

    return &*objStudent;
}

void Roster::add(const std::string &studentID, const std::string &firstName, const std::string &lastName, const std::string &emailAddress, const int age,
                 const int daysInCourse1, const int daysInCourse2, const int daysInCourse3, const DegreeProgram degreeProgram) {
    this->studentArray[std::size(this->studentArray)] = new Student(studentID, age, daysInCourse1, daysInCourse2, daysInCourse3, firstName, lastName,
                                       emailAddress, degreeProgram);
}

void Roster::remove(const std::string &studentID) {
    for (int i=0; i<std::size(this->studentArray); i++) {
        if(this->studentArray[i]!=nullptr && this->studentArray[i]->get_student_id()==studentID) {
            studentArray[i] = nullptr;
            std::cout << "Deleted studentID: "<<studentID<<std::endl;
            return;
        }
    }
    std::cout << "Student ID: " << studentID << " not found" << std::endl;
}

    void Roster::printAll() const {
        std::cout << "Printing: all" << std::endl;
        for (int i=0; i<std::size(this->studentArray); i++) {
            if(this->studentArray[i]!=nullptr)
            this->studentArray[i]->print();
        }
    }

    void Roster::printAverageDaysInCourse(const std::string &studentID) const {
        for(int i=0; i<std::size(this->studentArray); i++) {
            if(this->studentArray[i]->get_student_id()==studentID) {
                std::cout<<"Student ID: "<<studentID<<" Average days in course: "<< std::fixed << std::setprecision(2) << (((float(this->studentArray[i]->get_days_left(0)))+(float(this->studentArray[i]->get_days_left(1)))+(float(this->studentArray[i]->get_days_left(2))))/3.0) << std::endl;
                return;
            }
        }
        std::cout<<"Student not found. ID: " << studentID << std::endl;
    }

    void Roster::printInvalidEmails() const {
        std::cout << "Invalid email:";
        for(int i=0; i<std::size(this->studentArray); i++) {
            if(this->studentArray[i]->get_email().find('@')== std::string::npos || this->studentArray[i]->get_email().find('.')== std::string::npos || (this->studentArray[i]->get_email().find(' ')!= std::string::npos))
                std::cout << " " << this->studentArray[i]->get_email();
        }
        std::cout<<std::endl;
    }

    void Roster::printByDegreeProgram(const DegreeProgram degreeProgram) const {
        std::cout << "Info for degree program: ";
        switch(degreeProgram) {
            case 0:
                std::cout << "SECURITY" << std::endl;
            break;
            case 1:
                std::cout << "NETWORK" << std::endl;
            break;
            case 2:
                std::cout << "SOFTWARE" << std::endl;
            break;
        }

        for(int i=0; i<std::size(this->studentArray); i++) {
            if(this->studentArray[i]->degreeEnumToString(this->studentArray[i]->get_program())=="SECURITY" && degreeProgram == SECURITY)
                studentArray[i]->print();
            else if(this->studentArray[i]->degreeEnumToString(this->studentArray[i]->get_program())=="NETWORK" && degreeProgram == NETWORK)
                studentArray[i]->print();
            else if(this->studentArray[i]->degreeEnumToString(this->studentArray[i]->get_program())=="SOFTWARE" && degreeProgram == SOFTWARE)
                studentArray[i]->print();
        }
}
