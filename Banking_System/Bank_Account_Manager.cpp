/**
 * ============================================================================
 * Problem / Program: Bank Account Management System
 * Description: Multi-user banking management system supporting account creation, PIN-authenticated login, deposits, withdrawals, and balance inquiries stored persistently in accounts.txt file.
 * ============================================================================
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Structure to store account details
struct Account {
    int accountNumber;
    string userName;
    double balance;
    int pin;
};

const string DATA_FILE = "accounts.txt";

/**
 * Creates a new user bank account and appends details to file.
 */
void createAccount() {
    int accountNumber, pin;
    string userName;
    double balance;

    cout << "\n=== CREATE NEW ACCOUNT ===\n";
    cout << "Enter Account Number: ";
    cin >> accountNumber;
    cin.ignore(); // Clear newline from input buffer

    cout << "Enter Full Name / Username: ";
    getline(cin, userName);

    cout << "Enter Initial Deposit: $";
    cin >> balance;

    do {
        cout << "Create 4-digit PIN (1000-9999): ";
        cin >> pin;
    } while (pin < 1000 || pin > 9999);

    ofstream accFile(DATA_FILE.c_str(), ios::app);
    if (accFile.is_open()) {
        accFile << accountNumber << " " << userName << " " << balance << " " << pin << "\n";
        accFile.close();
        cout << "\nAccount created successfully!" << endl;
    } else {
        cout << "Error: Unable to open data file!" << endl;
    }
}

/**
 * Validates login with Account Number & PIN credentials.
 */
bool login(int &accountNumber, string &userName) {
    int enteredAccount, enteredPin, tries = 0;
    cout << "\n=== ACCOUNT LOGIN ===\n";
    cout << "Enter Account Number: ";
    cin >> enteredAccount;

    ifstream accFile(DATA_FILE.c_str());
    if (!accFile.is_open()) {
        cout << "No existing accounts dataset found." << endl;
        return false;
    }

    int fileAccount, filePin;
    double balance;
    string fileUserName;

    while (accFile >> fileAccount >> fileUserName >> balance >> filePin) {
        if (fileAccount == enteredAccount) {
            do {
                cout << "Enter 4-digit PIN: ";
                cin >> enteredPin;
                tries++;
                if (enteredPin == filePin) {
                    accountNumber = fileAccount;
                    userName = fileUserName;
                    cout << "Login successful! Welcome, " << fileUserName << "!" << endl;
                    accFile.close();
                    return true;
                } else {
                    cout << "Incorrect PIN (" << tries << "/3 tries used)\n";
                }
            } while (tries < 3);

            cout << "Access Denied: Maximum attempts exceeded!\n";
            accFile.close();
            return false;
        }
    }

    cout << "Account number not found!\n";
    accFile.close();
    return false;
}

/**
 * Deposits specified amount into target account and updates file.
 */
void deposit(int accountNumber) {
    double amount;
    cout << "\n=== DEPOSIT FUNDS ===\n";
    cout << "Enter deposit amount: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid deposit amount!\n";
        return;
    }

    ifstream accFile(DATA_FILE.c_str());
    ofstream tempFile("temp.txt");

    int fileAccount, filePin;
    double balance;
    string userName;
    bool found = false;

    while (accFile >> fileAccount >> userName >> balance >> filePin) {
        if (fileAccount == accountNumber) {
            balance += amount;
            found = true;
            cout << "Deposit successful! New Balance: $" << balance << endl;
        }
        tempFile << fileAccount << " " << userName << " " << balance << " " << filePin << "\n";
    }

    accFile.close();
    tempFile.close();

    remove(DATA_FILE.c_str());
    rename("temp.txt", DATA_FILE.c_str());

    if (!found) cout << "Account not found!\n";
}

/**
 * Withdraws funds from target account if balance is sufficient.
 */
void withdraw(int accountNumber) {
    double amount;
    cout << "\n=== WITHDRAW FUNDS ===\n";
    cout << "Enter withdrawal amount: $";
    cin >> amount;

    ifstream accFile(DATA_FILE.c_str());
    ofstream tempFile("temp.txt");

    int fileAccount, filePin;
    double balance;
    string userName;
    bool found = false;

    while (accFile >> fileAccount >> userName >> balance >> filePin) {
        if (fileAccount == accountNumber) {
            if (amount > balance) {
                cout << "Transaction Failed: Insufficient balance!\n";
            } else {
                balance -= amount;
                cout << "Withdrawal successful! Remaining Balance: $" << balance << endl;
            }
            found = true;
        }
        tempFile << fileAccount << " " << userName << " " << balance << " " << filePin << "\n";
    }

    accFile.close();
    tempFile.close();

    remove(DATA_FILE.c_str());
    rename("temp.txt", DATA_FILE.c_str());

    if (!found) cout << "Account not found!\n";
}

/**
 * Checks current balance for logged-in user.
 */
void checkBalance(int accountNumber) {
    ifstream accFile(DATA_FILE.c_str());

    int fileAccount, filePin;
    double balance;
    string userName;
    bool found = false;

    while (accFile >> fileAccount >> userName >> balance >> filePin) {
        if (fileAccount == accountNumber) {
            cout << "\nAccount Number : " << fileAccount << endl;
            cout << "Account Holder : " << userName << endl;
            cout << "Current Balance: $" << balance << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "Account not found!\n";
    accFile.close();
}

int main() {
    int choice, accountNumber;
    string userName;

    do {
        cout << "\n======================================" << endl;
        cout << "       BANK MANAGEMENT SYSTEM         " << endl;
        cout << "======================================" << endl;
        cout << "1. Create Account\n";
        cout << "2. Login to Account\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login(accountNumber, userName)) {
                    int userOption;
                    do {
                        cout << "\n--- ACCOUNT MENU (" << userName << ") ---\n";
                        cout << "1. Deposit\n";
                        cout << "2. Withdraw\n";
                        cout << "3. Check Balance\n";
                        cout << "4. Logout\n";
                        cout << "Select Option: ";
                        cin >> userOption;

                        switch (userOption) {
                            case 1: deposit(accountNumber); break;
                            case 2: withdraw(accountNumber); break;
                            case 3: checkBalance(accountNumber); break;
                            case 4: cout << "Logged out successfully.\n"; break;
                            default: cout << "Invalid option choice!\n"; break;
                        }
                    } while (userOption != 4);
                }
                break;
            case 3:
                cout << "Exiting system. Have a good day!\n";
                break;
            default:
                cout << "Invalid menu choice!\n";
        }
    } while (choice != 3);

    return 0;
}
