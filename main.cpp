// Created by Estefano Felipa and Jonathan Young on 11-29-19
// A banking transaction processor
#include "bank.h"
#include <iostream>
#include <string>


using namespace std;

// main method that calls program
int main(int Argc, char *Argv[]) {
    Bank Bank;
    //Note that tests were done in BankTransIn.txt
    for (int I = 1; I < Argc; ++I) {
        cout << "The command line argument(s) was " << Argv[I] << std::endl;
        string FileName = Argv[I];
        Bank.processTransactions(FileName);
        Bank.displayAllBankBalances();
    }

    return 0;
}