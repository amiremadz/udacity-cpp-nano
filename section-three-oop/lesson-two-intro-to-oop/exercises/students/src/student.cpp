//
// Created by Michael Harris on 5/6/20.
//

#include "student.hpp"

#include <utility>


// constructor
Student::Student(string name, int grade, float gpa) {
    this->name_ = std::move(name);
    this->grade_ = grade;
    this->gpa_ = gpa;
}

// validate inputs for grade and GPA to throw exceptions
void Student::Validate() {
    if (this->Grade() < 0 || this->Grade() > 12 || this->GPA() < 0.00 || this->GPA() > 5) {
        throw std::invalid_argument("argument out of bounds");
    }
}

void Student::Name(string n){
    if (n.length() < 24 && !n.empty()) {
        this->name_ = n;
    } else {
        throw std::invalid_argument("name must be less than 24 characters and not empty");
    }
}

void Student::Grade(int g) {
        this->grade_ = g;
        Student::Validate();
}

void Student::GPA(float g) {
        this->gpa_ = g;
        Student::Validate();
}

