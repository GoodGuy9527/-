#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

// CheckingAccount 類別
// 繼承自 Account 類別（Inheritance）
class CheckingAccount : public Account {
private:
    // 私有成員：透支額度
    double overdraftLimit;

public:
    // 建構子
    // 呼叫父類別 Account 的建構子初始化帳戶資料
    CheckingAccount(string accNo, string name, double bal, double limit)
        : Account(accNo, name, bal), overdraftLimit(limit) {}

    // 覆寫（Override）父類別的 withdraw() 函式
    // 展現多型（Polymorphism）
    void withdraw(double amount) override {

        // 可使用餘額加上透支額度進行提款
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
        } else {
            // 超過透支額度
            cout << "Overdraft limit exceeded (Checking)" << endl;
        }
    }
};

#endif
