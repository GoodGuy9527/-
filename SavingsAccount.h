#ifndef SAVINGSACCOUNT_H      // 防止重複包含
#define SAVINGSACCOUNT_H

#include "Account.h"         // 引入父類別

// SavingsAccount 繼承 Account
class SavingsAccount : public Account {

private:
    double interestRate;     // 利率

public:

    // 建構子
    // accNo=帳號
    // name=姓名
    // bal=初始餘額
    // rate=利率
    SavingsAccount(string accNo,
                   string name,
                   double bal,
                   double rate)
        : Account(accNo, name, bal),   // 呼叫父類別建構子
          interestRate(rate) {}        // 初始化利率

    // 覆寫父類別 withdraw()
    // 多型(Polymorphism)
    void withdraw(double amount) override {

        // 餘額足夠才能提款
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Insufficient balance (Savings)" << endl;
        }
    }

    // 計算利息
    void addInterest() {

        // 新餘額 = 原餘額 + 利息
        balance += balance * interestRate;
    }
};

#endif
