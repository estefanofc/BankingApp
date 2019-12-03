// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include "account.h"
#include <iostream>

// default account constructor, initializes all sub-accounts to 0 balance
Account::Account(string LastName, string FirstName, int AccountID) :
        LastName{LastName}, FirstName{FirstName}, AccountID{AccountID} {
    for (int I = 0; I < ACCOUNT_TYPES; ++I) {
        History[I] = "";
        Funds[I] = 0;
    }
}

// account deconstructor
Account::~Account() = default;

// deposit into account method
bool Account::deposit(string Transaction, int Amount, int Fund) {
    if (Amount < 0) {
        cout << "ERROR: can't deposit negative amounts" << endl;
        return false;
    }
    Funds[Fund] += Amount;
    History[Fund] += "\t" + Transaction + '\n';
    return true;
}

// withdraw from account method
bool Account::withdraw(string Transaction, int Amount, int Fund) {
    int totalMoneyMarket = Funds[0] + Funds[1];
    switch (Fund) {
        case 0:
            if (Amount > Funds[0]) {
                if (Amount <= totalMoneyMarket) {
                    Funds[1] -= Amount - Funds[0];
                    Funds[0] = 0;
                } else {
                    if (Transaction != "") {
                        History[0] += "\t" + Transaction + " (Failed)" + '\n';
                    }
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
                    if (Transaction != "") {
                        History[1] += "\t" + Transaction + " (Failed)" + '\n';
                    }
                    return false;
                }
            } else {
                Funds[1] -= Amount;
            }
            break;
        default:
            if (Amount > Funds[Fund]) {
                if (Transaction != "") {
                    History[Fund] += "\t" + Transaction + " (Failed)" + '\n';
                }
                return false;
            }
            Funds[Fund] -= Amount;
            break;
    }
    if (Transaction != "") {
        History[Fund] += "\t" + Transaction + '\n';
    }
    return true;
}

// transfer method that calls withdraw and deposit methods between two
// different accounts
bool Account::transfer(string Transaction, Account &Id, int Amount, int Fund1,
                       int Fund2) {
    if (Amount < 0) {
        cout << "ERROR: can't transfer negative amounts" << endl;
        return false;
    }
    if (withdraw("", Amount, Fund1)) {
        Id.deposit("D " + to_string(Id.getAccountID()) + to_string(Fund2) +
                   " " + to_string(Amount), Amount, Fund2);
        History[Fund1] += "\t" + Transaction + '\n';
        Id.History[Fund2] += "\t" + Transaction + '\n';
        return true;
    }
    cout << "ERROR: not enough funds to make transfer" << endl;
    return false;
}

// transfer method that calls withdraw and deposit methods between 2 sub
// accounts on the same account
bool Account::transfer(string Transaction, int From, int To, int Amount) {
    if (Amount < 0) {
        cout << "ERROR: can't transfer negative amounts" << endl;
        return false;
    }
    if (withdraw("", Amount, From)) {
        deposit("D " + to_string(AccountID) + to_string(To) +
                " " + to_string(Amount), Amount, To);
        History[From] += "\t" + Transaction + '\n';
        return true;
    }
    return false;
}

// display method for all funds in sub-accounts
void Account::displayAllFunds() const {
    cout << "Displaying Transaction History for " << LastName << " " <<
         FirstName << " by fund." << endl;
    for (int I = 0; I < ACCOUNT_TYPES; I++) {
        cout << FUNDS[I] << ": $" << Funds[I] << endl;
        cout << History[I];
    }
}

// display method for funds from one sub-account
void Account::displayFund(int Fund) const {
    cout << "Displaying Transaction History for " << LastName << " " <<
         FirstName << "'s " << FUNDS[Fund] << ": $" << Funds[Fund] <<
         endl;
    cout << History[Fund];

}

// helper method to return account Id
int Account::getAccountID() const {
    return AccountID;
}

// helper method to get account holders last name
string Account::getLastName() const {
    return LastName;
}

// helper method to get account holders first name
string Account::getFirstName() const {
    return FirstName;
}

// ostream overloaded operator for specified output for accounts
ostream &operator<<(ostream &Os, const Account &Account) {
    Os << Account.getLastName() << " " << Account.getFirstName()
       << " Account ID: " << Account.getAccountID() << endl;
    for (int I = 0; I < ACCOUNT_TYPES; I++) {
        Os << "\t" << FUNDS[I] << ": $" << Account.Funds[I] << endl;
    }
    return Os;
}

