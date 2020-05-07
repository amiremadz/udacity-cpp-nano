#include <stdexcept>
#include "sphere.hpp"

// constructor
Sphere::Sphere(int rad) : radius_(rad) {
    if (rad < 0) throw std::invalid_argument("radius must be positive");
    else this->CalcVolume();
}

// set new radius
void Sphere::Radius(int rad) {
    if (rad > 0) {
        this->radius_ = rad;
        this->CalcVolume();
    } else {
        throw std::invalid_argument("radius must be positive");
    }
}

void Sphere::CalcVolume() {
    this->volume_ = M_PI * pow(this->radius_,3) * (4.0/3.0);  // error was the rounding of 4/3 to 1 since they were entered as ints
}
