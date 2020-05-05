//
// Created by Michael Harris on 5/4/20.
//

#include <iostream>  // std::cout && std::cin
#include "pyramid.hpp"

using std::cin;
using std::cout;

int main() {
    double length, width, height;

    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;

    Pyramid pyramid(length, width, height);

    cout << "\nLength: " << pyramid.Length() << "\n";
    cout << "Width:  " << pyramid.Width() << "\n";
    cout << "Height: " << pyramid.Height() << "\n";
    cout << "Volume: " << pyramid.Volume() << "\n";
    cout << "Area:   " << pyramid.SurfaceArea() << "\n";
}