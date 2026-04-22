#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

class Account {
private:
    string accountNumber;
    string ownerName;

protected:
    double balance;

public:
    // Constructor
    Account(string accNo, string name, double bal) {
        accountNumber = accNo;
        ownerName = name;
        balance = bal;
    }

    // Getter (Encapsulation)
    string getAccountNumber() const {
        return accountNumber;
    }

    string getOwnerName() const {
        return ownerName;
    }

    double getBalance() const {
        return balance;
    }

    // Common method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Pure virtual function (Abstract)
    virtual void withdraw(double amount) = 0;

    // Virtual destructor (best practice)
    virtual ~Account() {}

    // Display info
    void displayInfo() const {
        cout << "Account: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

#endif
