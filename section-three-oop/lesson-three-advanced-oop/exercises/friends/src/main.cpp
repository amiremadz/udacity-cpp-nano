#include "rectangle.hpp"
#include <stdio.h>
#include <assert.h>

int main() {
    Square square(4);
    Rectangle rectangle(square);

    printf("Width:  %i\n", rectangle.Width());
    printf("Length: %i\n", rectangle.Height());
    printf("Area:   %i\n", rectangle.Area());

    assert(rectangle.Width()  == 4);
    assert(rectangle.Height() == 4);
    assert(rectangle.Area()   == 16);
}