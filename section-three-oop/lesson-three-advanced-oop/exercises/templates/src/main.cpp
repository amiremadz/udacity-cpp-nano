#include "comparison.hpp"
#include <cassert>

int main() {
  // test for int
  int a{3}, b{5};
  assert(Max<int>(a, b) == b);  // you do not need to include the type info due to template deduction (C++17+)

  // test for float
  float c{23.33}, d{13.45};
  assert(Max<float>(c, d) == c);  // you do not need to include the type info due to template deduction (C++17+)

  // test for char
  assert(Max<char>('x', 'v') == 'x');  // you do not need to include the type info due to template deduction (C++17+)
}