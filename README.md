# wallet_cpp
The program will act as a Personal Wallet that can store data, Such as, user Information, transactions, credit/debit card informations in a password protected environment, Categorize the transactions, Seperate incomes and Expenses, Sort the transactions based on Amount and show them as a console Menu driven application.

Documentation
Project Name: Advance Personal Wallet
Name: Shishir Mahidul Alam
Instructor: Al-Magsoosi Husam


Budapest University of Technology and Economics
Chapter 1: Introduction and Problem Statement:

Overview: 
The app written in C++ to store and access data from the user storage device to work as a personal wallet to help the user to manage his incomes and expenses and list them and see the balance of his wallet. It also comes with a credit/debit card manager that can save the card details in a password protected environment.
Purpose:
The Program will act as a Personal Wallet that can:
	Store User Information
	Edit the user Information
	Make a Deposit
	Make a Withdraw
	List the Transactions. 
	Show the account Balance
	Store Credit/Debit card information’s
	Password Protected Environment

Technologies Used: 
The Program is a menu driven program written in C++ and project is made using the Visual Studio IDE(2022).
Tasks Involved:
The program is used to handle tasks such a saving user information, making transactions(Deposits/Withdraws), list the transactions and show them in to the user, Show the account balance and store the card information of the user.


The Problems this program will solve:
	Manage the user basic Data
	Keep track of user Incomes and Expenses
	List the expenses for User
	Show the Balance
	Store Card information Securely


Chapter 2: Solution Design and Implementation:

The Wallet App is a C++ class-based implementation that provides functionalities for managing user details, Transactions and Storing card details. It allows users to create, retrieve, update, and delete information by interacting with a file.

Class Definitions:
User Class(Fig: 1):
 
Fig: 1
The User class provides functionality to manage user details such as name, phone number, and email address. It allows users to save their details to a file, check if their details already exist in a file, and modify their details if needed.

Class Name: User
Constructors:
- User(): Default constructor. Creates an instance of the User class.
Public Member Functions:
- void setName(string name): Sets the name of the user.
    - Parameters:
        - name: A string representing the user's name.
- void setPhone(string phone): Sets the phone number of the user.
    - Parameters:
        - phone: A string representing the user's phone number.
- void setEmail(string email): Sets the email address of the user.
    - Parameters:
        - email: A string representing the user's email address.
- bool userExists(string filename): Checks if the user details already exist in a file.
    - Parameters:
        - filename: A string representing the name of the file to check.
    - Returns:
        - true if the file exists and contains user details.
        - false otherwise.
- void saveUserDetails(string filename): Saves the user details to a file.
    - Parameters:
        - filename: A string representing the name of the file to save the details to.

Example Usage:
User user;
user.setName("John Doe");
user.setPhone("123-456-7890");
user.setEmail("john.doe@example.com");

if (!user.userExists("user_details.txt")) {
    user.saveUserDetails("user_details.txt");
}



UserFileManager Class(Fig: 2):
 
Fig: 2
The UserFileManager class provides static methods to manage user details stored in files. It allows checking if user details exist, saving new user details, displaying existing user details, and editing user details.


Class Definition:
Class Name: UserFileManager
Static Member Functions:
- bool userExists(string filename): Checks if user details already exist in a file.
    - Parameters:
        - filename: A string representing the name of the file to check.
    - Returns:
        - true if the file exists and contains user details.
        - false otherwise.
- void saveUserDetails(string filename, string name, string phone, string email): Saves the user details to a file.
    - Parameters:
        - filename: A string representing the name of the file to save the details to.
        - name: A string representing the user's name.
        - phone: A string representing the user's phone number.
        - email: A string representing the user's email address.
- void showUserDetails(string filename): Displays the user details stored in a file.
    - Parameters:
        - filename: A string representing the name of the file containing the user details.
- void editUserDetails(string filename): Allows the user to edit their details stored in a file.
    - Parameters:
        - filename: A string representing the name of the file containing the user details.

Example Usage:
UserFileManager::showUserDetails("user_details.txt");
UserFileManager::editUserDetails("user_details.txt")


Transaction Class(Fig: 3)
 
Fig: 3
The Transaction class represents a transaction with various attributes such as transaction number, type, amount, and timestamp. It provides functionality to store and retrieve transactions, as well as calculate and update balances.

Constructor
•	Transaction(string type, double amount): Constructs a new transaction with the specified type and amount. It automatically generates a unique transaction number and assigns the current timestamp.
Public Member Functions
•	string getTransactionNo() const: Retrieves the transaction number of the transaction.
•	string getType() const: Retrieves the type of the transaction.
•	double getAmount() const: Retrieves the amount of the transaction.
Static Member Functions
•	static string getTime(): Retrieves the current system time in the format "YYYY-MM-DD".
•	static void storeTransaction(string filename, string typ): Stores a transaction in a specified file. It prompts the user to enter the amount and calculates the new balance based on the transaction type (deposit or withdrawal). The transaction details, including the transaction number, type, amount, and timestamp, are appended to the file.
•	static void showTransactions(string filename): Retrieves and displays all transactions stored in a specified file. It also retrieves and displays the current balance from a separate file.
File Handling
The code uses file handling to read and write transactions and balance information. The following files are utilized:
•	filename: The file where transaction details are stored.
•	Balance.txt: The file where the current balance is stored.
•	tempBalance.txt: A temporary file used for updating the balance.
It's worth noting that the code assumes the existence of these files and does not handle cases where the files are missing or inaccessible.
Overall, this code provides a basic framework for managing transactions and balances. However, it may require additional error handling, input validation, and other enhancements to ensure robustness and security in a real-world application.

Card.h
 

The code consists of several functions and a main menu function (cardMenu()) to interact with the user. Let's discuss the purpose of each function:
1.	void storeCardInfoToFile(const vector<CardInfo>& cardInfoList, const string& password)
•	Purpose: This function stores the card information provided by the user in a binary file.
•	Input:
•	cardInfoList: A vector containing CardInfo structures representing the card information.
•	password: A string representing the password to protect the card information file.
•	Output: None
2.	vector<CardInfo> readCardInfoFromFile(const string& fileName, const string& password)
•	Purpose: This function reads the card information stored in the binary file.
•	Input:
•	fileName: A string representing the name of the file to read the card information from.
•	password: A string representing the password to access the card information file.
•	Output: A vector containing CardInfo structures representing the card information.
3.	void displayCardInfo(const CardInfo& cardInfo)
•	Purpose: This function displays the details of a single card.
•	Input: cardInfo: A CardInfo structure representing the card information to be displayed.
•	Output: None
4.	void editCardInfo(vector<CardInfo>& cardInfoList)
•	Purpose: This function allows the user to edit the card information.
•	Input: cardInfoList: A vector containing CardInfo structures representing the card information.
•	Output: None
5.	void deleteCard(vector<CardInfo>& cardInfoList)
•	Purpose: This function allows the user to delete a card from the card information list.
•	Input: cardInfoList: A vector containing CardInfo structures representing the card information.
•	Output: None
6.	void displayAllCards(const vector<CardInfo>& cardInfoList)
•	Purpose: This function displays the details of all the cards in the card information list.
•	Input: cardInfoList: A vector containing CardInfo structures representing the card information.
•	Output: None
7.	void cardMenu()
•	Purpose: This function serves as the main menu for the Card Information Management System.
•	Input: None
•	Output: None

Usage
To use the Card Information Management System, follow these steps:
1.	Include the necessary headers: <string>, <vector>, <cstdlib>.
2.	Create a struct CardInfo with the following members:
•	string cardNumber: Represents the card number.
•	string cardHolderName: Represents the card holder's name.
•	string expirationDate: Represents the card's expiration date.
3.	Implement the cardMenu() function, which serves as the entry point for the system. The function should display a menu to the user and call the appropriate functions based on the user's choice.
4.	Inside the cardMenu() function, define a vector cardInfoList to store the card information.
5.	When the user chooses to save or load the card information, call the storeCardInfoToFile() or readCardInfoFromFile() function, respectively, to perform the respective file operations.
6.	Implement the remaining functions (storeCardInfoToFile(), readCardInfoFromFile(), displayCardInfo(), editCardInfo(), deleteCard(), and displayAllCards()) according to your requirements.
7.	Customize the main menu options and add additional functionality as needed.


Chapter 3: External Solutions and Deviations:
No external library was used to build the project.
Chapter 4: Testing and Verification:
The program was tested using various measures:
1.	Test cases for individual functions and classes to verify their correctness.
2.	Ensure that the functions and classes under test produce the expected output for each test case.
3.	Test the interactions between different components or classes and functions of the program.
4.	The components work correctly together, and exchange data as expected.
5.	Develop test cases that cover different scenarios and use various combinations of components.
6.	Test the entire program as a whole to ensure it meets the overall requirements.
7.	Use debugging tools provided by the development environment (Visual Studio Debugger) to identify and fix issues.

Chapter 5: Results, Discussion, and Future Enhancements:
The program work as a menu driven console app. Where we can choose to number an press enter to run the function.
 

1.	Upon clicking 1, the console shows the user details already saved in user.txt file.
 
2.	Upon clicking 2, the program let’s the user to edit his/her details. 
3.	Upon clicking 3, the program lets the user to make a Deposit and shows the data of the deposit with balance. 
4.	Upon clicking 4, the program lets the user to make a Withdraw and shows the data of the deposit with balance.  

5.	Shows the transactions 
6.	Shows the option to add card information with a password option. 


The program works correctly with the with the scope of the project described in the project description. It can handle the tasks of a wallet and manage the transactions for a user to satisfy his daily needs.
In future the program would be able to secure the data of the user more securely by using an external library (openssl: https://www.openssl.org/) for the encryption of the data. Besides a GUI will be implemented that’ll make the program more useable and interactive.

Chapter 6: Conclusion and References:
In conclusion, the project was a part of our learning process of C++ by practicing different problems and finding their solution using the knowledge object-oriented paradigm, dynamic memory management(new/delete), exception handling (try/catch), and file management. We faced problem with the file handling and dynamic memory management and with the help of lab instructor and lectures from the Respected professor, we are able to overcome it a make a compiled the project successfully.


References:
Classes and objects:
https://www.geeksforgeeks.org/c-classes-and-objects/
File Handling:
https://www.geeksforgeeks.org/file-handling-c-classes/
ctime.h usage:
https://stackoverflow.com/questions/36927699/how-to-correctly-use-ctime-to-print-different-time-stamps
Dynamic memory Management(new/delete)
https://www.tutorialspoint.com/cplusplus/cpp_dynamic_memory.htm

