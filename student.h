#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"
#include <array>
#include <string>

class Student {
private:
    // data types
    int age, days1, days2, days3;
    std::array<int, 3> daysLeft;
    std::string studentID, firstName, lastName, email;
    DegreeProgram degree;

public:
    std::string degreeEnumToString (DegreeProgram degree);
    void print();
    Student();
    Student(const std::string& student_id, int age, int days1, int days2, int days3, const std::string& first_name,
        const std::string& last_name, const std::string& email, const DegreeProgram degree);
    void set_student_id(std::string student_id);
    void set_age(int age);
    void set_days_left(const std::array<int, 3>& days_left);
    void set_first_name(const std::string& first_name);
    void set_last_name(const std::string& last_name);
    void set_email(const std::string& email);
    void set_program(DegreeProgram degree);
    [[nodiscard]] std::string get_student_id();
    [[nodiscard]] int get_age();
    [[nodiscard]] std::string get_first_name();
    [[nodiscard]] std::string get_last_name();
    [[nodiscard]] std::string get_email();
    [[nodiscard]] DegreeProgram get_program();
    [[nodiscard]] int get_days_left(int i);
};



#endif //STUDENT_H