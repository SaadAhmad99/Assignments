#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Structure to store account details
struct Account {
    char name[50];
    int accountNumber;
    float balance;
};

// Function to create an account
void createAccount(Account &acc) {
    cout << "Enter account holder's name: ";
    cin.ignore(); // To clear buffer
    cin.getline(acc.name, 50);
    cout << "Enter account number: ";
    cin >> acc.accountNumber;
    acc.balance = 0.0; // Initial balance is 0
    cout << "Account created successfully!\n";

    // Save to file
    ofstream file("accounts.txt", ios::app);
    if (file) {
        file << acc.name << " " << acc.accountNumber << " " << acc.balance << endl;
        file.close();
    }
}

// Function to deposit money
void depositMoney(Account &acc, float amount) {
    if (amount > 0) {
        acc.balance += amount;
        cout << "Deposited $" << amount << " successfully.\n";
        cout << "New Balance: $" << acc.balance << endl;
    } else {
        cout << "Invalid amount.\n";
    }
}

// Function to withdraw money
void withdrawMoney(Account &acc, float amount) {
    if (amount > 0 && amount <= acc.balance) {
        acc.balance -= amount;
        cout << "Withdrawn $" << amount << " successfully.\n";
        cout << "Remaining Balance: $" << acc.balance << endl;
    } else {
        cout << "Insufficient funds or invalid amount.\n";
    }
}

// Function to display account details
void displayAccount(const Account &acc) {
    cout << "\nAccount Holder: " << acc.name << endl;
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Current Balance: $" << acc.balance << endl;
}

int main() {
    Account acc;
    int choice;
    float amount;

    do {
        cout << "\n===== Bank Account Management System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount(acc);
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                depositMoney(acc, amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdrawMoney(acc, amount);
                break;
            case 4:
                displayAccount(acc);
                break;
            case 5:
                cout << "Exiting... Thank you for using our system!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
