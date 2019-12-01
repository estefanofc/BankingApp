// Created by Estefano Felipe and Jonathan Young on 11-29-19
#ifndef ASS5_ACCOUNT_H
#define ASS5_ACCOUNT_H

#include <string>

using namespace std;

class Account {
public:
    //ss
    bool deposit(int Amount, int Fund);

    //s
    int withdraw(int Amount, int Fund);

    void displayAllFunds() const;

    void displayFund(int Fund) const;

    int getAccountNum() const;

private:
    int id;
    string firstName;
    int *Funds;
    string *history;
};

#endif // ASS5_ACCOUNT_H
