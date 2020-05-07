#include "cat.hpp"
#include <exception>
#include <printf.h>

Cat::Cat(string color, string name, uint32_t age, float height) : Animal(color, name, age) {
    if (height < 0) throw std::invalid_argument("height cannot be negative");
    this->height_ = height;
}

string Cat::MakeSound() {
    return "Meow";
}