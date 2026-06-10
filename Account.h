#ifndef ACCOUNT_H          // 防止 Account.h 被重複包含
#define ACCOUNT_H

#include <iostream>        // 輸入輸出函式庫
using namespace std;

// Account 類別 (基底類別 Base Class)
class Account {
private:
    string accountNumber;  // 帳號（封裝：只能透過函式存取）
    string ownerName;      // 戶名（封裝）

protected:
    double balance;        // 餘額（子類別可直接存取）

public:

    // 建構子(Constructor)
    // 建立帳戶時初始化帳號、姓名與餘額
    Account(string accNo, string name, double bal) {
        accountNumber = accNo;
        ownerName = name;
        balance = bal;
    }

    // Getter 函式
    // 回傳帳號
    string getAccountNumber() const {
        return accountNumber;
    }

    // 回傳戶名
    string getOwnerName() const {
        return ownerName;
    }

    // 回傳餘額
    double getBalance() const {
        return balance;
    }

    // 存款功能
    void deposit(double amount) {

        // 金額必須大於0才允許存款
        if (amount > 0) {
            balance += amount;
        }
    }

    // 純虛擬函式(Pure Virtual Function)
    // 每種帳戶提款規則不同
    // 強制子類別一定要實作 withdraw()
    virtual void withdraw(double amount) = 0;

    // 虛擬解構子(Virtual Destructor)
    // 使用父類別指標刪除子類別物件時可正確釋放記憶體
    virtual ~Account() {}

    // 顯示帳戶資訊
    void displayInfo() const {
        cout << "Account: " << accountNumber << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

#endif
