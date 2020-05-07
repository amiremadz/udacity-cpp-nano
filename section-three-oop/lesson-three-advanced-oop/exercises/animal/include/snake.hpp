#pragma once
#include "animal.hpp"

class Snake : public Animal {
public:
    // constructor
    Snake(string color, string name, uint32_t age, float length);

    // public member functions
    float Length() {return length_;}
    string MakeSound();

private:
    float length_{0};
};