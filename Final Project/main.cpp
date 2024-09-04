#include "header.h"
#include "user.h"
#include "transaction.h"
#include "card.h"



int main()
{
    User user;
    bool userExists = user.userExists("user.txt");
    
    if (userExists)
    {
        cout << "User details already exist in file \"user.txt\".\n" << endl << endl;
    }
    else
    {
        cout << "No user details found. Please enter your details.\n";
        user.saveUserDetails("user.txt");
    }

    while (true)
    {
        cout << endl << endl << endl;
        cout << "==================== Advance Personal Wallet ====================" << endl << endl;
        cout << "" << endl;
        cout << "==== Menu ====" << endl;
        cout << "" << endl << endl;
        cout << "1. View Wallet Info" << endl;
        cout << "2. Edit Wallet Info" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Withdraw" << endl;
        cout << "5. List Transactions" << endl;
        cout << "6. Store Card Details" << endl <<endl;
        cout << "0. Exit" << endl << endl << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        cout << endl << endl;

        switch (choice)
        {
        case 1: // View Wallet info
            UserFileManager::showUserDetails("user.txt");
            break;
        case 2: // Edit Wallet Info
            UserFileManager::editUserDetails("user.txt");
            break;
        case 3: // Deposit
            Transaction::storeTransaction("transactions.txt", "Deposit");
            break;
        case 4: // Withdraw
            Transaction::storeTransaction("transactions.txt", "Withdraw");
            break;
        case 5: // List transactions
            Transaction::showTransactions("transactions.txt");
            break;
        case 6: // Store Card Details
            cardMenu();
            break;
        case 0:
            return 0;

        default:
            cout << "Invalid choice. Please enter a valid number from the menu\n";
            break;
        }
    }

    return 0;
}
