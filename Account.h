#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
using namespace std;

// Account 類別（抽象類別）
class Account {
private:
    // 封裝（Encapsulation）：私有成員，只能透過 Getter 存取
    string accountNumber;   // 帳號
    string ownerName;       // 帳戶持有人姓名

protected:
    // 受保護成員，可供子類別直接存取
    double balance;         // 帳戶餘額

public:
    // 建構子（Constructor）
    Account(string accNo, string name, double bal) {
        accountNumber = accNo;
        ownerName = name;
        balance = bal;
    }

    // Getter 方法（封裝）
    string getAccountNumber() const {
        return accountNumber;
    }

    string getOwnerName() const {
        return ownerName;
    }

    double getBalance() const {
        return balance;
    }

    // 存款功能
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // 純虛擬函式（Pure Virtual Function）
    // 強制子類別實作提款功能
    virtual void withdraw(double amount) = 0;

    // 虛擬解構子（Virtual Destructor）
    // 確保刪除子類別物件時能正確釋放資源
    virtual ~Account() {}

    // 顯示帳戶資訊
    void displayInfo() const {
        cout << "Account: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

#endif
