// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include "account.h"
#include <iostream>

Account::Account(string LastName, string FirstName, int Id) :
        LastName{LastName}, FirstName{FirstName}, Id{Id} {
    for (int I = 0; I < ACCOUNT_TYPES; ++I) {
        Funds[I] = 0;
    }
}

Account::~Account() = default;

bool Account::deposit(int Amount, int Fund) {
    if (Amount < 0) {
        cout << "ERROR: can't deposit negative amounts" << endl;
        return false;
    }
    Funds[Fund] += Amount;
    return true;
}

bool Account::withdraw(int Amount, int Fund) {
    int totalMoneyMarket = Funds[0] + Funds[1];
    switch (Fund) {
        case 0:
            if (Amount > Funds[0]) {
                if (Amount <= totalMoneyMarket) {
                    Funds[1] -= Amount - Funds[0];
                    Funds[0] = 0;
                } else {
                    cout << "ERROR: not enough funds to make withdrawal"
                         << endl;
                    return false;
                }
            } else {
                Funds[0] -= Amount;
            }
            break;
        case 1:
            if (Amount > Funds[1]) {
                if (Amount <= totalMoneyMarket) {
                    Funds[0] -= Amount - Funds[1];
                    Funds[1] = 0;
                } else {
                    cout << "ERROR: not enough funds to make withdrawal"
                         << endl;
                    return false;
                }
            } else {
                Funds[1] -= Amount;
            }
            break;
        default:
            if (Amount > Funds[Fund]) {
                cout << "ERROR: not enough funds to make withdrawal" << endl;
                return false;
            }
            Funds[Fund] -= Amount;
            break;
    }
    return true;
}

bool Account::transfer(Account &Id, int Amount, int Fund1, int Fund2) {
    if (Amount < 0) {
        cout << "ERROR: can't transfer negative amounts" << endl;
        return false;
    }
    if (withdraw(Amount, Fund1)) {
        Id.deposit(Amount, Fund2);
        return true;
    }
    cout << "ERROR: not enough funds to make transfer" << endl;
    return false;
}

bool Account::transfer(int From, int To, int Amount) {
    if (Amount < 0) {
        cout << "ERROR: can't transfer negative amounts" << endl;
        return false;
    }
    if (withdraw(Amount, From)) {
        deposit(Amount, To);
        return true;
    }
    cout << "ERROR: not enough funds to make transfer" << endl;
    return false;
}

void Account::displayAllFunds() const {
    cout << LastName << " " << FirstName
         << " Account ID: " << Id << endl;
    for (int I = 0; I < ACCOUNT_TYPES; I++) {
        displayFund(I);
    }
}

void Account::displayFund(int Fund) const {
    cout << FUNDS[Fund] << ": $" << Funds[Fund] << endl;
}

int Account::getAccountNum() const {
    return Id;
}


string Account::getLastName() const {
    return LastName;
}

string Account::getFirstName() const {
    return FirstName;
}

ostream &operator<<(ostream &Os, const Account &Account) {
    Os << Account.getLastName() << " " << Account.getFirstName()
       << " Account ID: " << Account.getAccountNum() << endl;
    for (int I = 0; I < ACCOUNT_TYPES; I++) {
        Os << "\t" << FUNDS[I] << ": $" << Account.Funds[I] << endl;
    }
    return Os;
}

