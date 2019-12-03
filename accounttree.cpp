// Created by Estefano Felipa and Jonathan Young on 11-29-19
#include "accounttree.h"

// Default constructor for account tree
AccountTree::AccountTree() = default;

// Delete all nodes in BST
AccountTree::~AccountTree() {
    clear();
}

// Insert new account
bool AccountTree::insert(Account *Account) {
    if (isEmpty()) {
        Root = new Node(Account);
        return true;
    }
    Node *Curr = Root;
    while (Curr != nullptr) {
        if (Account->getAccountID() == Curr->Account->getAccountID()) {
            cout << "ERROR: Account " << Account->getAccountID() <<
                 " is already open. Transaction refused." << endl;
            return false;
        }
        if (Account->getAccountID() > Curr->Account->getAccountID()) {
            if (Curr->Right == nullptr) {
                Curr->Right = new Node(Account);
                return true;
            }
            Curr = Curr->Right;
        }
        if (Account->getAccountID() < Curr->Account->getAccountID()) {
            if (Curr->Left == nullptr) {
                Curr->Left = new Node(Account);
                return true;
            }
            Curr = Curr->Left;
        }
    }
    return false;
}

// Retrieve account
// returns true if successful AND *Account points to account
bool AccountTree::retrieve(const int &AccountNumber, Account *&Account) const {
    if (isEmpty()) {
        Account = nullptr;
        return false;
    }
    Node *Curr = Root;
    while (Curr != nullptr) {
        if (AccountNumber > Curr->Account->getAccountID()) {
            Curr = Curr->Right;
        } else if (AccountNumber < Curr->Account->getAccountID()) {
            Curr = Curr->Left;
        } else {
            Account = Curr->Account;
            return true;
        }
    }
    Account = nullptr;
    return false;
}

// Display information on all accounts
void AccountTree::display() const {
    display(Root);
}

void AccountTree::display(Node *Curr) const {
    if (Curr != nullptr) {
        display(Curr->Left);
        cout << *(Curr->Account) << endl;
        display(Curr->Right);
    }
}

// delete all information in AccountTree
void AccountTree::clear() {
    if (isEmpty()) {
        cout << "There are no Accounts present to delete" << endl;
        return;
    }
    recursiveRemove(Root);
    if (Root->Right == nullptr && Root->Left == nullptr) {
        cout << "Deleting Account number: " << Root->Account->getAccountID() <<
             endl;
        delete Root;
    }

}

// Method for removing children in a binary tree
void AccountTree::recursiveRemove(Node *Curr) {
    if (Curr == nullptr) {
        return;
    }
    recursiveRemove(Curr->Left);
    recursiveRemove(Curr->Right);
    cout << "Deleting Account number: " << Curr->Account->getAccountID() <<
         endl;
    delete Curr->Account;
    delete Curr;
}

// check if tree is empty
bool AccountTree::isEmpty() const {
    return Root == nullptr;
}
