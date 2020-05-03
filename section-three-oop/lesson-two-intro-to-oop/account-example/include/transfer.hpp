#pragma once

#include <string>

using std::string;

struct Transfer {
    string to;
    string from;
    double amount;
};

void PrintTransfer(Transfer t);