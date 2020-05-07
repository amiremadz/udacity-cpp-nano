#pragma once

#include "animal.hpp"

class Cat : public Animal {
public:
    // constructor
    Cat(string color, string name, uint32_t age, float height);

    // public member function
    float Height() {return height_;}
    string MakeSound();

private:
    float height_;
};