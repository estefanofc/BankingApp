// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include "bank.h"
#include <iostream>
#include <string>


using namespace std;

int main(int Argc, char *Argv[]) {
//    Bank Bank;
//    //Note that tests were done in BankTransIn.txt
//    for(int I = 1; I < Argc; ++I) {
//        cout << "The command line argument(s) was " << Argv[I] << std::endl;
//        string FileName = Argv[I];
//        Bank.processTransactions(FileName);
//    }
//    cout << "Done" << endl;
    AccountTree tree;
    for (int i = 0; i < 15; ++i) {
        Account* hi = new Account("hola", "dd", i);
        tree.insert(hi);
    }
     tree.display();

    return 0;
}