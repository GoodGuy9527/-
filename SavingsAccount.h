#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string accNo, string name, double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate) {}

    // Override (Polymorphism)
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient balance (Savings)" << endl;
        }
    }

    void addInterest() {
        balance += balance * interestRate;
    }
};

#endif
