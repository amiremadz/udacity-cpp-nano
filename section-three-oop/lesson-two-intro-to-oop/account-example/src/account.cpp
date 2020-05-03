#include "../include/account.hpp"
using std::string;

// Account constructor
Account::Account(string name, string address, double balance) : name(name), address(address) {
    Account::balance += balance;
}

// getter functions
string Account::GetName()       {return name;}
string Account::GetAddress()    {return address;}
double Account::GetBalance()    {return balance;}
void Account::GetTxHistory()    {
    for (auto t: tx_history) {
        PrintTransfer(t);
    }
}

// Append a transfer to the accounts tx history
void Account::AppendTxHistory(Transfer t) {
    tx_history.push_back(t);
}

// Allow an account to receive an amount and update balance
void Account::Receive(double amount) {
    balance += amount;
}

// Send amount to another account updating both balances
void Account::Send(Account* a, double amount) {
    // check that account not sending to itself
    assert(a->GetName() != this->GetAddress());
    // update balances for both account
    balance -= amount;
    a->Receive(amount);
    // Record transfer
    Transfer t{this->name, a->name, amount};
    // append tx to account histories
    tx_history.push_back(t);
    a->AppendTxHistory(t);
}