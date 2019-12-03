// Created by Estefano Felipa and Jonathan Young on 11-29-19
#ifndef ASS5_BANK_H
#define ASS5_BANK_H

#include "accounttree.h"
#include <fstream>
#include <string>
#include <queue>

using namespace std;

// bank class
class Bank {
public:
    // default constructor
    Bank();

    // bank class deconstructor
    ~Bank();

    // reads files and builds line by line que for FIFO processing
    void processTransactions(const string &FileName);

// method that displays balances for all sub accounts for specified account
    void displayAllBankBalances() const;

// receives string argument from signified process type to open new account
    void openNewAccount(string Process);

// receives string argument from signified process type to withdraw from
// account
    void withdrawFromAccount(string Process);

// receives string argument from signified process type to transfer funds
// between two accounts, parses between two accounts with substring
    void transferFunds(string Process);

// receives string argument from signified process type to deposit to account
    void depositFunds(string Process);

// receives string argument from signified process type to call account history
    void accountHistory(string Process) const;

private:
    AccountTree Accounts;
    queue<string> Transactions;

};

#endif // ASS5_BANK_H
