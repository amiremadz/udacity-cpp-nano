#include <iostream>
#include "account.hpp"

using std::string;
using std::vector;
using std::cout;

void AuditAccount (Account a) {
    cout << "\n+----------------------+\n"
         << "|     Account Info     |\n"
         << "+----------------------+\n"
         << " Name:         " << a.GetName()    << "    \n"
         << " Address:      " << a.GetAddress() << " \n"
         << " Balance:      " << a.GetBalance() << "      \n"
         << " Tx History: \n";
    a.GetTxHistory();
}

int main() {
    Account account1("Bob", "0x9876", 30.00);
    Account account2("Alice", "0x5432", 30.00);
    Account account3("Clare", "0x1234", 30.00);

    // test sends
    account1.Send(&account2, 15.00);
    account2.Send(&account3, 15.00);
    account3.Send(&account1, 30.00);
    account1.Send(&account2, 15.00);
    account2.Send(&account3, 15.00);
    account3.Send(&account1, 30.00);

    // Show account information
    AuditAccount(account1);
    cout << "\n";
    AuditAccount(account2);
    cout << "\n";
    AuditAccount(account3);
    return 0;
}