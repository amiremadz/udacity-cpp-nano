//
// Created by Michael Harris on 5/6/20.
//
#include <cassert> // std::assert
#include <iostream>  // std::cout
#include "student.hpp"

int main() {
    // initialization of student
    Student student("Bob", 2, 3.2);

    // print to console for visual verification
    std::cout << "Name:         " << student.Name() << "\n"
              << "Grade (1-12): " << student.Grade() << "\n"
              << "GPA (0-4):    " << student.GPA() << std::endl;

    // assertion test cases
    assert(student.Name() == "Bob");
    assert(student.Grade() == 2);
    assert(student.GPA() >= 3.2 && student.GPA() <= 3.21);  // asserts with floating points suck

    // test with try catch exception
    bool my_exception{false};
    try {
        student.Grade(-100);
    } catch (...) {
        my_exception = true;
    }
    assert(my_exception);
}