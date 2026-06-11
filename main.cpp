#include <iostream>     // 輸入輸出功能
#include <vector>       // vector動態陣列
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main() {

    // 建立 Account 指標的 vector
    // 可同時存放 SavingsAccount 與 CheckingAccount
    // 利用多型(Polymorphism)
    vector<Account*> accounts;

    int mainChoice;

    // 主選單迴圈
    do {

        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Create Account\n";
        cout << "2. Select Account\n";
        cout << "0. Exit\n";
        cout << "Choose: ";

        cin >> mainChoice;

        // ======================
        // 建立新帳戶
        // ======================
        if (mainChoice == 1) {

            string accNo;
            string name;
            double balance;
            int type;

            // 輸入帳號
            cout << "Account Number: ";
            cin >> accNo;

            // 輸入姓名
            cout << "Name: ";
            cin >> name;

            // 輸入初始金額
            cout << "Initial Balance: ";
            cin >> balance;

            // 選擇帳戶類型
            cout << "Type (1: Savings, 2: Checking): ";
            cin >> type;

            // 建立 SavingsAccount
            if (type == 1) {

                accounts.push_back(

                    new SavingsAccount(
                        accNo,
                        name,
                        balance,
                        0.05)       // 利率5%
                );
            }

            // 建立 CheckingAccount
            else {

                accounts.push_back(

                    new CheckingAccount(
                        accNo,
                        name,
                        balance,
                        200)        // 透支額度200
                );
            }

            cout << "Account created!\n";
        }

        // ======================
        // 選擇帳戶
        // ======================
        else if (mainChoice == 2) {

            // 沒有帳戶時
            if (accounts.empty()) {
                cout << "No accounts available.\n";
                continue;
            }

            // 顯示所有帳戶
            cout << "\nAvailable Accounts:\n";

            for (int i = 0; i < accounts.size(); i++) {

                cout << i
                     << ". "
                     << accounts[i]->getAccountNumber()
                     << endl;
            }

            int index;

            cout << "Select index: ";
            cin >> index;

            // 檢查索引是否合法
            if (index < 0 ||
                index >= accounts.size()) {

                cout << "Invalid index\n";
                continue;
            }

            // 指向選擇的帳戶
            Account* acc = accounts[index];

            int choice;

            // ======================
            // 帳戶功能選單
            // ======================
            do {

                cout << "\n--- ACCOUNT MENU ---\n";
                cout << "1. Deposit\n";
                cout << "2. Withdraw\n";
                cout << "3. Show Info\n";
                cout << "0. Back\n";
                cout << "Choose: ";

                cin >> choice;

                // ----------------------
                // 存款
                // ----------------------
                if (choice == 1) {

                    double amt;

                    cout << "Amount: ";
                    cin >> amt;

                    acc->deposit(amt);
                }

                // ----------------------
                // 提款
                // ----------------------
                else if (choice == 2) {

                    double amt;

                    cout << "Amount: ";
                    cin >> amt;

                    // 多型
                    // 自動呼叫對應子類別的 withdraw()
                    acc->withdraw(amt);
                }

                // ----------------------
                // 顯示帳戶資訊
                // ----------------------
                else if (choice == 3) {

                    acc->displayInfo();
                }

            } while (choice != 0);
        }

    } while (mainChoice != 0);

    // ======================
    // 釋放記憶體
    // ======================

    for (Account* acc : accounts) {

        delete acc;
    }

    return 0;
}
