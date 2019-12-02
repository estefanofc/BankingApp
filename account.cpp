// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include "account.h"
#include <iostream>

Account::Account(string LastName, string FirstName, int Id) :
        LastName{LastName}, FirstName{FirstName}, Id{Id} {
    for (int I = 0; I < ACCOUNT_TYPES; ++I) {
        Funds[I] = 0;
    }
}

Account::~Account() {

}

bool Account::deposit(int Amount, int Fund) {
    if(Amount < 0) {
        return false;
    }
    Funds[Fund] += Amount;
    return true;
}

bool Account::withdraw(int Amount, int Fund) {
    return false;
}

bool Account::transfer(Account &Id, int Amount, int Fund1, int Fund2) {
    return false;
}

bool Account::transfer(int From, int To, int Amount) {
    if(Amount < 0) {
        return false;
    }
//    deposit(Amount)
    Funds[To] += Amount;
    Funds[From] -= Amount;
    return true;
}

void Account::displayAllFunds() const {

}

void Account::displayFund(int Fund) const {

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

ostream& operator<<(ostream &Os, const Account &Account){
    Os << Account.getLastName() << " " << Account.getFirstName() << " Account "
            "ID: " << Account.getAccountNum() << endl;
    for (int I = 0; I < ACCOUNT_TYPES; I++){
        Os << "\t" << FUNDS[I] << ": $" << Account.Funds[I] << endl;
    }
    return Os;
}