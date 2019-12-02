// Created by Estefano Felipe and Jonathan Young on 11-29-19
#include "account.h"

Account::Account(string LastName, string FirstName, int Id) :
                        LastName{LastName}, FirstName{FirstName}, Id{Id} {};

string Account::getLastName() const {
    return LastName;
}

string Account::getFirstName() const {
    return FirstName;
}

int Account::getAccountNum() const {
    return Id;
}

ostream& operator<<(ostream &Os, const Account &Account){
    Os << Account.getLastName() << " " << Account.getFirstName() << " Account "
            "ID: " << Account.getAccountNum() << endl;
    for (int I = 0; I < ACCOUNT_TYPES; I++){
        Os << "\t" << FUNDS[I] << ": $" << Account.displayFund(I) << endl;
    }
    return Os;
}