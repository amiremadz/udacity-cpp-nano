#pragma once

#include <string>  // std::string

using std::string;

class Animal {
public:
    // constructor
    Animal(string color, string name, uint32_t age);

    // public member functions
    string Color() {return color_;}
    string Name() {return name_;}
    uint32_t Age() {return age_;}

private:
    string color_;
    string name_;
    uint32_t age_;
};