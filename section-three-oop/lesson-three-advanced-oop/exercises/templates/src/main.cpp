#include "comparison.hpp"
#include <cassert>

int main() {
  // test for int
  int a{3}, b{5};
  assert(Max(a, b) == b);

  // test for float
  float c{23.33}, d{13.45};
  assert(Max(c, d) == c);

  // test for char
  assert(Max('x', 'v') == 'x');
}