#include <cmath>

// base
class Shape {
public:
    virtual float Area() const = 0;
    virtual float Perimeter() const = 0;
};

// rectangle inherits base class shape
class Rectangle : public Shape {
public:
    // constructor
    Rectangle(int w, int h) : width_(w), height_(h) {}

    // public members
    float Area() const override {
        return this->width_ * this->height_;
    }
    float Perimeter() const override {
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
    float Area() const override {
        return M_PI * std::pow(this->radius_, 2);
    }
    float Perimeter() const override {
        return 2 * (M_PI * this->radius_);
    }

private:
    int radius_;
};