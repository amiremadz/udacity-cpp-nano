#include "snake.hpp"
#include "cat.hpp"
#include <iostream>

using std::cin;
using std::cout;

int main() {
    // init
    Snake snake{"brown", "Jack", 3, 23.3};
    Cat cat{"black", "Mowgli", 4, 12.2};

    // speed up cin and cout
    std::ios::sync_with_stdio(false);

    cout << "Snake\n"
         << "___________\n"
         << "Color: " << snake.Color() << "\n"
         << "Name: " << snake.Name() << "\n"
         << "Age: " << snake.Age() << "\n"
         << "Length: " << snake.Length() << "\n"
         << "The snake says: " << snake.MakeSound() << "\n";

    cout << "Cat\n"
         << "___________\n"
         << "Color: " << cat.Color() << "\n"
         << "Name: " << cat.Name() << "\n"
         << "Age: " << cat.Age() << "\n"
         << "Height: " << cat.Height() << "\n"
         << "The cat says: " << cat.MakeSound() << "\n";

    // error checking
    bool valid_input{false};

    while(!valid_input) {
        // vars
        string type;
        string color, name;
        uint32_t age;
        float h_or_l;

        // initial input for animal type
        cout << "Type of animal (snake or cat): ";
        cin >> type;
        cout << "Name: ";
        cin >> name;
        cout << "Color: ";
        cin >> color;
        cout << "Age: ";
        cin >> age;

        if (type == "snake" || type == "Snake") {
            cout << "Length: ";
            cin >> h_or_l;

            Snake your_snake{color, name, age, h_or_l};

            cout << "Your snake\n"
                 << "___________\n"
                 << "Color: " << your_snake.Color() << "\n"
                 << "Name: " << your_snake.Name() << "\n"
                 << "Age: " << your_snake.Age() << "\n"
                 << "Length: " << your_snake.Length() << "\n"
                 << "The snake says: " << your_snake.MakeSound() << "\n";
            valid_input = true;
        } else if (type == "cat" || type == "Cat") {
            cout << "Height: ";
            cin >> h_or_l;

            Cat your_cat{color, name, age, h_or_l};

            cout << "Your cat\n"
                 << "___________\n"
                 << "Color: " << your_cat.Color() << "\n"
                 << "Name: " << your_cat.Name() << "\n"
                 << "Age: " << your_cat.Age() << "\n"
                 << "Length: " << your_cat.Height() << "\n"
                 << "The cat says: " << your_cat.MakeSound() << "\n";
            valid_input = true;
        } else {
            cout << "Please enter a valid animal type (either cat or snake)\n";
        }
    }
}