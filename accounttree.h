// Created by Estefano Felipa and Jonathan Young on 11-29-19
#ifndef ASS5_ACCOUNTTREE_H
#define ASS5_ACCOUNTTREE_H

#include "account.h"
#include <iostream>

// Class to manage accounts into a Binary tree
class AccountTree {
public:
    // Create BST
    AccountTree();

    // Delete all nodes in BST
    ~AccountTree();

    // Insert new account
    bool insert(Account *Account);

    // Retrieve account
    // returns true if successful AND *Account points to account
    bool retrieve(const int &AccountNumber, Account *&Account) const;

    // Display information on all accounts
    void display() const;

    // delete all information in AccountTree
    void clear();

    // check if tree is empty
    bool isEmpty() const;


private:
    // Node class to create node Binary tree objects
    class Node {
    public:
        // explicit constructor for Node objects
        explicit Node(Account *Account)
                : Account{Account}, Right{nullptr}, Left{nullptr} {};
        Account *Account;
        Node *Right;
        Node *Left;
    };

    Node *Root = nullptr;

    // Method for recursively removing children in a binary tree
    void recursiveRemove(Node *Curr);

    // recursive display method
    void display(Node *Root) const;

};

#endif // ASS5_ACCOUNTTREE_H
