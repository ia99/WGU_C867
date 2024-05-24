#include "student.h"
#include "degree.h"

    // constructors
Student::Student() = default;

Student::Student(const std::string& student_id, int age, int days1, int days2, int days3, const std::string& first_name,
    const std::string& last_name, const std::string& email, const DegreeProgram degree)
    : studentID(student_id),
    age(age),
    daysLeft({ days1, days2, days3 }),
    firstName(first_name),
    lastName(last_name),
    email(email),
    degree(degree)
{
}

// functions

std::string Student::degreeEnumToString(const DegreeProgram degree) {
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
    default:
        return "degreeEnumToString error";
    }
}


void Student::print() {
    std::cout << this->get_student_id() << "\t First Name: " << this->get_first_name() << "\t Last Name: " << this->get_last_name() << "\t Age:" << this->get_age() << "\t daysInCourse: {";
    std::cout << this->get_days_left(0) << ", " << this->get_days_left(1) << ", " << this->get_days_left(2) << "} Degree Program: " << this->degreeEnumToString(this->get_program()) << std::endl;
}

// setters
void Student::set_student_id(std::string student_id) {
    this->studentID = student_id;
}

void Student::set_age(int age) {
    this->age = age;
}

void Student::set_days_left(const std::array<int, 3>& days_left) {
    this->daysLeft = days_left;
}

void Student::set_first_name(const std::string& first_name) {
    this->firstName = first_name;
}

void Student::set_last_name(const std::string& last_name) {
    this->lastName = last_name;
}

void Student::set_email(const std::string& email) {
    this->email = email;
}

void Student::set_program(DegreeProgram degree) {
    this->degree = degree;
}

// getters
[[nodiscard]] std::string Student::get_student_id() {
    return studentID;
}

[[nodiscard]] int Student::get_age() {
    return age;
}


[[nodiscard]] std::string Student::get_first_name() {
    return firstName;
}

[[nodiscard]] std::string Student::get_last_name() {
    return lastName;
}

[[nodiscard]] std::string Student::get_email() {
    return email;
}

[[nodiscard]] DegreeProgram Student::get_program() {
    return degree;
}

[[nodiscard]] int Student::get_days_left(int i) {
    return daysLeft[i];
}