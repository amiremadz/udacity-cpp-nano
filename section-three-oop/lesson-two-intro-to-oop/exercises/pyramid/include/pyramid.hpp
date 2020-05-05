#pragma once

class Pyramid {
public:
    // accessors/getters
    double Length() {return length;}
    double Width() {return width;}
    double Height() {return height;}

    // mutator/setters
    void Length(double l);
    void Width(double w);
    void Height(double h);

    // public member functions
    double Volume();
    double SurfaceArea();

    // constructor
    Pyramid(double length, double width, double height);

private:
    double length{0};
    double width{0};
    double height{0};
};