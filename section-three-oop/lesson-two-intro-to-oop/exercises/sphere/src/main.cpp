#include <cassert>
#include <stdexcept>
#include <printf.h>
#include "sphere.hpp"

int main() {
    Sphere sphere(5);

    printf("Radius: %i\n", sphere.Radius());
    printf("Volume: %f\n", sphere.Volume());

    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume()-523.6) < 1);

    sphere.Radius(13);

    printf("Radius: %i\n", sphere.Radius());
    printf("Volume: %f\n", sphere.Volume());

    assert(sphere.Radius() == 13);
    assert(abs(sphere.Volume()-9202.77) < 1);

    // exception testing
    try {
        sphere.Radius(-6);
    } catch (std::invalid_argument) {
        printf("Invalid argument was passes but was caught");
    }
}
