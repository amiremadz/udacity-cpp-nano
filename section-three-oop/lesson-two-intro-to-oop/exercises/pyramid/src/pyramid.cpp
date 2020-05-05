//
// Created by Michael Harris on 5/4/20.
//

#include <assert.h>  // std::assert
#include <cmath>  // std::sqrt && std::pow
#include "pyramid.hpp"

using std::pow;
using std::sqrt;

// constructor
Pyramid::Pyramid(double length, double width, double height) {
    assert(length > 0 && width > 0 && height > 0);
        this->length = length;
        this->width = width;
        this->height = height;
}

// set new length
void Pyramid::Length(double l) {
    assert(l > 0);
    this->length = l;
}

// set new width
void Pyramid::Width(double w) {
    assert(w > 0);
    this->width = w;
}

// set new height
void Pyramid::Height(double h) {
    assert(h > 0);
    this->height = h;
}

// calculate volume of the pyramid
double Pyramid::Volume() {
    return (this->length * this->width * this->height) / 3;
}

// calculate surface area
double Pyramid::SurfaceArea() {
    return (this->length * this->width)
    + this->length * sqrt( pow((this->width/2), 2) + pow(this->height,2))
    + this->width * sqrt( pow((this->length/2), 2) + pow(this->height,2));
}