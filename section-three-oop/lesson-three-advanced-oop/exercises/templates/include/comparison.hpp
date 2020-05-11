#pragma once

template <typename T> T Max(T a, T b) {
  // condition ? result_if_true : result_if_false
  return a > b ? a : b;
}