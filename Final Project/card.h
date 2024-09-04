#pragma once

#include <string>
#include <vector>
#include <cstdlib>  // for system("pause") in Windows

using namespace std;

struct CardInfo {
    string cardNumber;
    string cardHolderName;
    string expirationDate;
};

void storeCardInfoToFile(const vector<CardInfo>& cardInfoList, const string& password)
{
    string fileName = "cards.dat";

    ofstream outputFile(fileName, ios::binary);
    if (!outputFile)
    {
        cout << "Error creating file. Please try again." << endl;
        return;
    }

    // Write the password length
    int passwordLength = password.length();
    outputFile.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));

    // Write the password
    outputFile.write(password.c_str(), passwordLength);

    // Write the number of card entries
    int numCards = cardInfoList.size();
    outputFile.write(reinterpret_cast<const char*>(&numCards), sizeof(numCards));

    for (const auto& cardInfo : cardInfoList)
    {
        // Write card number length
        int cardNumberLength = cardInfo.cardNumber.length();
        outputFile.write(reinterpret_cast<const char*>(&cardNumberLength), sizeof(cardNumberLength));

        // Write card number
        outputFile.write(cardInfo.cardNumber.c_str(), cardNumberLength);

        // Write card holder's name length
        int cardHolderNameLength = cardInfo.cardHolderName.length();
        outputFile.write(reinterpret_cast<const char*>(&cardHolderNameLength), sizeof(cardHolderNameLength));

        // Write card holder's name
        outputFile.write(cardInfo.cardHolderName.c_str(), cardHolderNameLength);

        // Write expiration date length
        int expirationDateLength = cardInfo.expirationDate.length();
        outputFile.write(reinterpret_cast<const char*>(&expirationDateLength), sizeof(expirationDateLength));

        // Write expiration date
        outputFile.write(cardInfo.expirationDate.c_str(), expirationDateLength);
    }

    outputFile.close();
    cout << "Card information saved to file: " << fileName << endl;
}

vector<CardInfo> readCardInfoFromFile(const string& fileName, const string& password)
{
    vector<CardInfo> cardInfoList;

    ifstream inputFile(fileName, ios::binary);
    if (!inputFile)
    {
        cout << "Error opening file. File May Not Exist Yet" << endl;
        return cardInfoList;
    }

    // Read the password length
    int storedPasswordLength = 0;
    inputFile.read(reinterpret_cast<char*>(&storedPasswordLength), sizeof(storedPasswordLength));

    // Read the stored password
    char* storedPasswordBuffer = new char[storedPasswordLength + 1];
    inputFile.read(storedPasswordBuffer, storedPasswordLength);
    storedPasswordBuffer[storedPasswordLength] = '\0';
    string storedPassword = storedPasswordBuffer;
    delete[] storedPasswordBuffer;

    try {
        if (password != storedPassword) {
            throw "Invalid Password";
           
        }

        // Rest of your code if the password is valid

    }
    catch (const char* errorMsg) {
        cout << errorMsg << endl;
        terminate();
    }

    // Read the number of card entries
    int numCards = 0;
    inputFile.read(reinterpret_cast<char*>(&numCards), sizeof(numCards));

    for (int i = 0; i < numCards; i++)
    {
        CardInfo cardInfo;

        // Read card number length
        int cardNumberLength = 0;
        inputFile.read(reinterpret_cast<char*>(&cardNumberLength), sizeof(cardNumberLength));

        // Read card number
        char* cardNumberBuffer = new char[cardNumberLength + 1];
        inputFile.read(cardNumberBuffer, cardNumberLength);
        cardNumberBuffer[cardNumberLength] = '\0';
        cardInfo.cardNumber = cardNumberBuffer;
        delete[] cardNumberBuffer;

        // Read card holder's name length
        int cardHolderNameLength = 0;
        inputFile.read(reinterpret_cast<char*>(&cardHolderNameLength), sizeof(cardHolderNameLength));

        // Read card holder's name
        char* cardHolderNameBuffer = new char[cardHolderNameLength + 1];
        inputFile.read(cardHolderNameBuffer, cardHolderNameLength);
        cardHolderNameBuffer[cardHolderNameLength] = '\0';
        cardInfo.cardHolderName = cardHolderNameBuffer;
        delete[] cardHolderNameBuffer;

        // Read expiration date length
        int expirationDateLength = 0;
        inputFile.read(reinterpret_cast<char*>(&expirationDateLength), sizeof(expirationDateLength));

        // Read expiration date
        char* expirationDateBuffer = new char[expirationDateLength + 1];
        inputFile.read(expirationDateBuffer, expirationDateLength);
        expirationDateBuffer[expirationDateLength] = '\0';
        cardInfo.expirationDate = expirationDateBuffer;
        delete[] expirationDateBuffer;

        cardInfoList.push_back(cardInfo);
    }

    inputFile.close();
    return cardInfoList;
}

void displayCardInfo(const CardInfo& cardInfo)
{
    cout << "Card Number: " << cardInfo.cardNumber << endl;
    cout << "Card Holder's Name: " << cardInfo.cardHolderName << endl;
    cout << "Expiration Date: " << cardInfo.expirationDate << endl;
    cout << endl;
}

void editCardInfo(vector<CardInfo>& cardInfoList)
{
    int cardIndex;

    cout << "Enter the index of the card to edit (0-" << cardInfoList.size() - 1 << "): ";
    cin >> cardIndex;
    cin.ignore(); // Ignore the newline character

    if (cardIndex < 0 || cardIndex >= cardInfoList.size())
    {
        cout << "Invalid card index. Please try again." << endl;
        return;
    }

    CardInfo& cardInfo = cardInfoList[cardIndex];

    cout << "Enter card number: ";
    getline(cin, cardInfo.cardNumber);

    cout << "Enter card holder's name: ";
    getline(cin, cardInfo.cardHolderName);

    cout << "Enter expiration date: ";
    getline(cin, cardInfo.expirationDate);

    cout << "Card information updated." << endl;
}

void deleteCard(vector<CardInfo>& cardInfoList)
{
    int cardIndex;

    cout << "Enter the index of the card to delete (0-" << cardInfoList.size() - 1 << "): ";
    cin >> cardIndex;
    cin.ignore(); // Ignore the newline character

    if (cardIndex < 0 || cardIndex >= cardInfoList.size())
    {
        cout << "Invalid card index. Please try again." << endl;
        return;
    }

    cardInfoList.erase(cardInfoList.begin() + cardIndex);

    cout << "Card deleted." << endl;
}

void displayAllCards(const vector<CardInfo>& cardInfoList)
{
    cout << endl << endl;
    if (cardInfoList.empty())
    {
        cout << "No cards found." << endl;
        return;
    }

    cout << "Saved Cards:" << endl;
    for (const auto& cardInfo : cardInfoList)
    {
        displayCardInfo(cardInfo);
    }
}

void cardMenu() {

    vector<CardInfo> cardInfoList;
    string fileName = "cards.dat";
    string password;

    cout << "Password to access the card information: ";
    getline(cin, password);

    cardInfoList = readCardInfoFromFile(fileName, password);

    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Add card information\n";
        cout << "2. Edit card information\n";
        cout << "3. Delete card\n";
        cout << "4. Save card information\n";
        cout << "5. Display all cards\n";
        cout << "6. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character

        switch (choice)
        {
        case 1:
        {
            CardInfo cardInfo;

            cout << "Enter card number: ";
            getline(cin, cardInfo.cardNumber);

            cout << "Enter card holder's name: ";
            getline(cin, cardInfo.cardHolderName);

            cout << "Enter expiration date: ";
            getline(cin, cardInfo.expirationDate);

            cardInfoList.push_back(cardInfo);
            cout << "Card information added." << endl;
            break;
        }
        case 2:
            editCardInfo(cardInfoList);
            break;
        case 3:
            deleteCard(cardInfoList);
            break;
        case 4:
            storeCardInfoToFile(cardInfoList, password);
            break;
        case 5:
            displayAllCards(cardInfoList);
            break;
        case 6:
            storeCardInfoToFile(cardInfoList, password);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 6);

    return;
}
