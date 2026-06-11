#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

// SavingsAccount 類別
// 繼承自 Account 類別（Inheritance）
class SavingsAccount : public Account {
private:
    // 私有成員：利率
    double interestRate;

public:
    // 建構子
    // 呼叫父類別 Account 的建構子初始化帳戶資料
    SavingsAccount(string accNo, string name, double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate) {}

    // 覆寫（Override）父類別的 withdraw() 函式
    // 展現多型（Polymorphism）
    void withdraw(double amount) override {
        // 若提款金額小於等於餘額，則允許提款
        if (amount <= balance) {
            balance -= amount;
        } else {
            // 餘額不足
            cout << "Insufficient balance (Savings)" << endl;
        }
    }

    // 計算並加入利息
    void addInterest() {
        balance += balance * interestRate;
    }
};

#endif
