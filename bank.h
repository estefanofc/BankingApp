// Created by Estefano Felipa and Jonathan Young on 11-29-19
#ifndef ASS5_BANK_H
#define ASS5_BANK_H

#include "accounttree.h"
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class Bank {
public:
  Bank();
  ~Bank();
  void processTransactions(const string &FileName);

  void displayAllBankBalances() const;

  void openNewAccount(string Process);

  void withdrawFromAccount(string Process);

  void transferFunds(string Process);

  void depositFunds(string Process);

  void accountHistory(string Process) const;

  void transactionOperation(const char Transaction);

private:
  AccountTree Accounts;
  queue<string> Transactions;

};
#endif // ASS5_BANK_H
