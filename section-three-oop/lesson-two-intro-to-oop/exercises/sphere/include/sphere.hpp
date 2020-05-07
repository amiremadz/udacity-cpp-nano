#pragma once

#include <cmath>

class Sphere{
public:
    // getters
    int Radius() {return radius_;}
    float Volume() {return volume_;}

    // setters
    void Radius(int rad);

    // constructor
    Sphere(int rad);

private:
    int radius_;
    float volume_;

    // private member function for volume
    void CalcVolume();
};
