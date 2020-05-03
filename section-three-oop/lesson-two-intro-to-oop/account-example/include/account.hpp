#pragma once

#include <vector>  //std::vector
#include "transfer.hpp"

using std::string;
using std::vector;

class Account {
public:
    // Getters
    string GetName();
    string GetAddress();
    double GetBalance();
    void GetTxHistory();

    // Append a transfer to the accounts tx history
    void AppendTxHistory(Transfer t);

    // Allow an account to receive an amount and update balance
    void Receive(double amount);

    // Send amount to another account updating both balances
    void Send(Account* a, double amount);

    // Constructor
    Account(string name, string address, double balance);

private:
    string const name;
    string const address;
    double balance {0};
    std::vector<Transfer> tx_history;
};