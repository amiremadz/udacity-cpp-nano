#include <cmath>

// base
class Shape {
public:
    virtual float Area() const = 0;
    virtual float Parimeter() const = 0;
};

// rectangle inherits base class shape
class Rectangle : Shape {
public:
    // constructor
    Rectangle(int w, int h) : width_(w), height_(h) {}

    // public members
    float Area() const {
        return this->width_ * this->height_;
    }
    float Parimeter() const {
        return 2 * (this->width_ + this->height_);
    }

private:
    int width_;
    int height_;
};

// circle inherits base class shape
class Circle : Shape {
public:
    // constructor
    Circle(int r) : radius_(r) {}

    // public members
    float Area() const {
        return M_PI * std::pow(this->radius_, 2);
    }
    float Parimeter() const {
        return 2 * (M_PI * this->radius_);
    }

private:
    int radius_;
};