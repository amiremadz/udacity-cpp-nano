#include "snake.hpp"
#include <exception>
#include <printf.h>

// constructor
Snake::Snake(string color, string name, uint32_t age, float length) : Animal(color, name, age) {
    if (length < 0) throw std::invalid_argument("length must be positive");
    this->length_ = length;
}

string Snake::MakeSound() {
    return "Sssss";
}