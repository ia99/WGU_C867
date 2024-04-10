//
// Created by ian_a on 4/6/2024.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <degree.h>
#include <array>
#include <string>

class Student {
public:


    // constructors
//Student() = default;

Student(int student_id, int age, int days1, int days2, int days3, const std::string &first_name,
        const std::string &last_name, const std::string &email, const DegreeProgram degree)
        : studentID(student_id),
          age(age),
          daysLeft({days1, days2, days3}),
          firstName(first_name),
          lastName(last_name),
          email(email),
          degree(degree)
    {
}

    // functions

    std::string degreeEnumToString (DegreeProgram degree) {
    switch (degree) {
        case 0:
            return "SECURITY";
        break;
        case 1:
            return "NETWORK";
        break;
        case 2:
            return "SOFTWARE";
        break;
    }
}

    void printAll() {
        std::cout << "A" << get_student_id() << ",";
        std::cout << get_first_name() << ",";
        std::cout << get_last_name() << ",";
        std::cout << get_email() << ",";
        std::cout << get_age() << ",";
        for(int i=0; i<=2; i++) {
            std::cout << get_days_left(i) << "," ;
        }
            std::cout << degreeEnumToString(get_program());

    }

    // setter
    void set_student_id(int student_id) {
        this->studentID = student_id;
    }

    void set_age(int age) {
        this->age = age;
    }

    void set_days_left(const std::array<int, 3> &days_left) {
        this->daysLeft = days_left;
}

    void set_first_name(const std::string &first_name) {
        this->firstName = first_name;
    }

    void set_last_name(const std::string &last_name) {
        this->lastName = last_name;
    }

    void set_email(const std::string &email) {
        this->email = email;
    }

    void set_program(DegreeProgram degree) {
        this->degree = degree;
    }

    // getter
    [[nodiscard]] int get_student_id() const {
        return studentID;
    }

    [[nodiscard]] int get_age() const {
        return age;
    }

//    [[nodiscard]] std::array<int, 3> get_days_left() const {
//        return daysLeft;
//    }

    [[nodiscard]] std::string get_first_name() const {
        return firstName;
    }

    [[nodiscard]] std::string get_last_name() const {
        return lastName;
    }

    [[nodiscard]] std::string get_email() const {
        return email;
    }

    [[nodiscard]] DegreeProgram get_program() const {
        return degree;
    }

    [[nodiscard]] int get_days_left(int i) const {
    return daysLeft[i];
}

private:
    // data types
    int studentID, age, days1, days2, days3;
    std::array<int, 3> daysLeft;
    std::string firstName, lastName, email;
    DegreeProgram degree;

};



#endif //STUDENT_H
