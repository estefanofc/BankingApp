// Created by Estefano Felipe and Jonathan Young on 11-29-19
#ifndef ASS5_ACCOUNT_H
#define ASS5_ACCOUNT_H

#include <string>

using namespace std;
// constant variable that manages sub accounts as index size variable
const int ACCOUNT_TYPES = 10;
const string FUNDS[10] = {
        "Money Market",
        "Prime Money Market",
        "Long-Term Bond",
        "Short-Term Bond",
        "500 Index Fund",
        "Capital Value Fund",
        "Growth Equity Fund",
        "Growth Index Fund",
        "Value Fund",
        "Value Stock Index"
};
class Account {
    friend ostream& operator<<(ostream& Os, const Account &Account);
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
    int displayFund(int Fund) const;

    // helper method to retrieve account number
    int getAccountNum() const;

    // helper method to retrieve account holders last name
    string getLastName() const;

    // helper method to retrieve account holders first name
    string getFirstName() const;



private:
    int Id;
    string LastName;
    string FirstName;
    int Funds[ACCOUNT_TYPES];
    string *History;
};

#endif // ASS5_ACCOUNT_H
