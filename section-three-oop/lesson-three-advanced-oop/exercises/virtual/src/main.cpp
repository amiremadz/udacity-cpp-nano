#include "shapes.hpp"
#include <stdio.h>
#include <assert.h>

int main() {
    Rectangle rectangle{4, 3};
    Circle cirlce{3};

    printf("Rectangle parimeter: %f\n", rectangle.Parimeter());
    printf("Rectangle area:      %f\n", rectangle.Area());
    printf("Circle parimeter:    %f\n", cirlce.Parimeter());
    printf("Circle area:         %f\n", cirlce.Area());

    assert((rectangle.Parimeter() - 14) < 1);
    assert((rectangle.Area() - 12) < 1);
    assert((cirlce.Parimeter() - 18.85) < 1);
    assert((cirlce.Area() - 28.27) < 1);
}