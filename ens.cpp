#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    int accountNumber;

public:
    // Constructor
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Getter methods
    string getAccountHolder() {
        return accountHolder;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    // Setter methods
    void setAccountHolder(string name) {
        accountHolder = name;
    }

    // Methods to handle transactions
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully" << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully" << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds" << endl;
        }
    }

    void displayInfo() {
        cout << "\nAccount Information:" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    // Creating a bank account
    BankAccount account("John Doe", 12345, 1000.0);
    
    // Display initial information
    account.displayInfo();
    
    // Performing transactions
    account.deposit(500.0);
    account.withdraw(200.0);
    
    // Display updated information
    account.displayInfo();
    
    // Trying invalid transactions
    account.deposit(-100.0);
    account.withdraw(2000.0);
    
    return 0;
}
