// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include <sstream>
#include "bank.h"


Bank::Bank() = default;

Bank::~Bank() = default;

void Bank::processTransactions(const string &FileName) {
    ifstream File;
    File.open(FileName);
    string ReadLine = "";
    if (!File){
        cout <<  "ERROR: No File Found Matching :" << FileName;
        return;
    }
    while (!File.eof()){
        getline(File, ReadLine);
        stringstream FileStream(ReadLine);
        char Type;
        FileStream >> Type;
        if (reinterpret_cast<const char *>(Type) == "O"){

        }
        else if (reinterpret_cast<const char *>(Type) == "W"){

        }
        else if (reinterpret_cast<const char *>(Type) == "T"){

        }
        else if (reinterpret_cast<const char *>(Type) == "D"){

        }
        else if (reinterpret_cast<const char *>(Type) == "H"){

        }
        else {
            cout << "ERROR: Invalid transaction type." << endl;
        }
        if (ReadLine == ""){
            break;
        }
        queue.push(ReadLine);
    }
    File.close();
    while (!queue.empty()){
        transactionOperation(static_cast<char>(queue.front()));
    }
}



void Bank::displayAllBankBalances() const {
    if (Accounts.isEmpty()){
        cout << "ERROR: No Accounts present" << endl;
        return;
    }
    else {
        cout << " Final Balances" << endl;
        Accounts.display();
    }
}