#include "../include/transfer.hpp"
#include <iostream>

using std::cout;

// print a transfer
void PrintTransfer(Transfer t) {
    cout << t.from << " --> " << t.amount << " --> " << t.to << "\n";
}