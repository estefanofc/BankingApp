// Created by Estefano Felipe and Jonathan Young on 11-29-19
#ifndef ASS5_ACCOUNT_H
#define ASS5_ACCOUNT_H

#include <string>

using namespace std;

class Account {
public:

    // Account constructor, all sub account funds initialized to 0 balance
    Account(string LastName, string FirstName, int Id);

    // Account deconstructor
    ~Account();

    // boolean deposit function, returns true if account exists, false otherwise
    bool deposit(int Amount, int Fund);

    // boolean withdraw function. Checks account index type for available
    // funds, if fund is bond account, and does not have have sufficient funds
    // checks opposite bond account (if 0 then 1, if 1 then 0)
    bool withdraw(int Amount, int Fund);

    // first account object calls second object to transfer to in argument,
    // calls withdraw and deposit methods
    bool transfer(Account &Id, int Amount, int Fund1, int Fund2);

    // overloaded transfer method for transfers in same account
    bool transfer(int From, int To, int Amount);

    // displays all funds from all sub-accounts related to main account
    void displayAllFunds() const;

    // displays balance for specified sub-account
    void displayFund(int Fund) const;

    // helper method to retrieve account number
    int getAccountNum() const;

    // constant variable that manages sub accounts as index size variable
    static const int ACCOUNT_TYPES = 10;

private:
    int Id;
    string LastName;
    string FirstName;
    int Funds[ACCOUNT_TYPES];
    string *History;
};

#endif // ASS5_ACCOUNT_H
