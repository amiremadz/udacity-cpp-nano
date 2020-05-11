#include "mapping.hpp"
#include <cassert>

int main() {
    Mapping<std::string , int> mapping1("age", 20);
    assert(mapping1.Print() == "age: 20");
}