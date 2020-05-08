#pragma once

#include <string>

using std::string;

class School {
public:
    // constructor
    School();

    // public member functions
    string SchoolName(){return name_;}
    string Headmaster(){return headmaster_;}
    string Location(){return location_;}
    uint32_t Founded(){return founded_;}
    string Motto(){return motto_;}

private:
    string name_{"Hogwarts"};
    string headmaster_{"Minerva McGonagall"};
    string location_{"Scottish Highlands"};
    uint32_t founded_{993};
    string motto_{"Draco Dormiens Nunquam Titillandus"};
};