#include "shapes.hpp"
#include <cstdio>
#include <cassert>

int main() {
    Rectangle rectangle{4, 3};
    Circle circle{3};

    printf("Rectangle perimeter: %f\n", rectangle.Perimeter());
    printf("Rectangle area:      %f\n", rectangle.Area());
    printf("Circle perimeter:    %f\n", circle.Perimeter());
    printf("Circle area:         %f\n", circle.Area());

    assert((rectangle.Perimeter() - 14) < 1);
    assert((rectangle.Area() - 12) < 1);
    assert((circle.Perimeter() - 18.85) < 1);
    assert((circle.Area() - 28.27) < 1);
}