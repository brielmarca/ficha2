#include <iostream>
#include <string> // Required to use std::string
#include <cstdlib> // Required for system() to clear the screen
using namespace std;

int main() {
    float balance = 0.0; // Initialize balance as 0.0 (implicitly double, but fine for float)
    int option;
    float amount;

    do {
        // Clear the screen depending on the operating system
        #if defined(_WIN32) || defined(_WIN64)  // For Windows
            system("cls");
        #else  // For Linux (Ubuntu) and macOS
            system("clear");
        #endif

        // Main menu
        cout << "\n=== MENU ===\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> option;

        switch (option) {
            case 1: // Deposit option
                cout << "Amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount; // Update balance
                    cout << "Deposit successful!\n";
                } else {
                    cout << "Invalid amount! The amount must be positive.\n";
                }
                break;

            case 2: // Withdrawal option
                cout << "Amount to withdraw: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount; // Update balance
                    cout << "Withdrawal successful!\n";
                } else if (amount <= 0) {
                    cout << "Invalid amount! The amount must be positive.\n";
                } else {
                    cout << "Insufficient balance!\n";
                }
                break;

            case 3: // Transfer option
                cout << "Amount to transfer: ";
                cin >> amount;
                if (amount > 0 && amount <= balance) {
                    balance -= amount; // Update balance
                    cout << "Transfer successful!\n";
                } else if (amount <= 0) {
                    cout << "Invalid amount! The amount must be positive.\n";
                } else {
                    cout << "Insufficient balance!\n";
                }
                break;

            case 4: // Check balance option
                cout << "Current balance: " << balance << " €\n";
                break;

            case 5: // Exit the program
                cout << "Exiting...\n";
                break;

            default: // Invalid option
                cout << "Invalid option! Please try again.\n";
        }

        // Pause for the user to see the message
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get(); // Wait for Enter key press

    } while (option != 5); // Repeat until the user chooses to exit

    return 0; // End of program
}
