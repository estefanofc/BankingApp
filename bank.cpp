// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include <sstream>
#include "bank.h"

Bank::Bank() = default;

Bank::~Bank() = default;

void Bank::processTransactions(const string &FileName) {
    ifstream File;
    File.open(FileName);
    string ReadLine = "";
    if (!File) {
        cout << "ERROR: No File Found Matching :" << FileName;
        return;
    }
    while (!File.eof()) {
        getline(File, ReadLine);
        if (ReadLine == "") {
            break;
        }
        Transactions.push(ReadLine);
    }
    File.close();
    while (!Transactions.empty()) {
        char Type = Transactions.front()[0];
        string Process = Transactions.front().substr(2);
        switch (Type) {
            case 'O':
                openNewAccount(Process);
                break;
            case 'W':
                withdrawFromAccount(Process);
                break;
            case 'T':
                transferFunds(Process);
                break;
            case 'D':
                depositFunds(Process);
                break;
            case 'H':
                accountHistory(Process);
                break;
            default:
                cout << "ERROR: Invalid transaction type." << endl;
                break;
        }
        Transactions.pop();
    }
}


void Bank::displayAllBankBalances() const {
    if (Accounts.isEmpty()) {
        cout << "ERROR: No Accounts present" << endl;
        return;
    }
    cout << "\nProcessing Done. Final Balances." << endl;
    Accounts.display();

}

void Bank::openNewAccount(string Process) {
    stringstream ss(Process);
    string FirstName;
    string LastName;
    int Id;
    ss >> LastName >> FirstName >> Id;
    Account *NewAccount = new Account(LastName, FirstName, Id);
    if (!Accounts.insert(NewAccount)) {
        return;
    }

}

void Bank::withdrawFromAccount(string Process) {
    stringstream ss(Process);
    string First;
    int Id;
    int Fund;
    int Amount;
    ss >> First >> Amount;
    Id = stoi(First.substr(0, 4));
    Fund = First.back() - 48;
    Account *Account;
    if (!Accounts.retrieve(Id, Account)) {
        cout << "ERROR: Could not find Account " << Id
             << " Withdrawal cancelled." << endl;
        return;
    }
    Account->withdraw("W " + Process, Amount, Fund);
}

void Bank::transferFunds(string Process) {
    stringstream ss(Process);
    string First;
    string Second;
    int Id1;
    int Id2;
    int Fund1;
    int Fund2;
    int Amount;
    Account *Account1;
    Account *Account2;
    ss >> First >> Amount >> Second;
    Id1 = stoi(First.substr(0, 4));
    Id2 = stoi(Second.substr(0, 4));
    Fund1 = First.back() - 48;
    Fund2 = Second.back() - 48;
    if (!Accounts.retrieve(Id1, Account1)) {
        cout << "ERROR: Could not find Account " << Id1
             << " Transfer cancelled." << endl;
        return;
    }
    if (Id1 == Id2) {
        Account1->transfer("T " + Process, Fund1, Fund2, Amount);
    } else {
        if (!Accounts.retrieve(Id2, Account2)) {
            cout << "ERROR: Could not find Account " << Id2
                 << " Transfer cancelled." << endl;
            return;
        }
        Account1->transfer("T " + Process, *Account2, Amount,
                           Fund1, Fund2);
    }
}

void Bank::depositFunds(string Process) {
    stringstream ss(Process);
    string First;
    int Id;
    int Fund;
    int Amount;
    Account *Account;
    ss >> First >> Amount;
    Id = stoi(First.substr(0, 4));
    Fund = First.back() - 48;
    if (!Accounts.retrieve(Id, Account)) {
        cout << "ERROR: Could not find Account " << Id
             << " Deposit cancelled." << endl;
        return;
    }
    Account->deposit("D " + Process, Amount, Fund);

}

void Bank::accountHistory(string Process) const {
    stringstream ss(Process);
    string First;
    int Id;
    int Fund;
    Account *Account;
    ss >> First;
    Id = stoi(First.substr(0, 4));
    if (!Accounts.retrieve(Id, Account)) {
        cout << "ERROR: Could not find Account " << Id
             << " Display History cancelled." << endl;
        return;
    }
    if (First.length() > 4) {
        Fund = First.back() - 48;
        Account->displayFund(Fund);
    } else {
        Account->displayAllFunds();
    }
}
