#pragma once

class Square {
public:
    Square(int side) : side_(side) {}

private:
    int side_;
    friend class Rectangle;
};