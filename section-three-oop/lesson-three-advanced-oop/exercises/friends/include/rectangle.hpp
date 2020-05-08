#pragma once
#include "square.hpp"

class Rectangle {
public:
    Rectangle(Square sq) : width_(sq.side_), height_(sq.side_) {}
    int Height(){return height_;}
    int Width(){return width_;}
    int Area(){return width_*height_;}

private:
    int width_;
    int height_;
};