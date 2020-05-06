#pragma once

#include <string>

using std::string;

class Student {
public:
    //constructor
    Student(string name, int grade, float gpa);

    // accessors/getters
    string Name() const {return name_;}
    int Grade() const {return grade_;}
    float GPA() const {return gpa_;}

    // modifiers/setters
    void Name(string n);
    void Grade(int g);
    void GPA(float g);


    // public member functions


private:
    string name_{"NONE"};
    int grade_{0};
    float gpa_{0.};

    // private validate function
    void Validate();
};