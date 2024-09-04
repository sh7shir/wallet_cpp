#pragma once

class Transaction
{
private:
    string transactionNo;
    string type;
    double amount;
    time_t timestamp;
public:
    Transaction(string type, double amount)
    {
        this->transactionNo = "TX" + to_string(time(NULL));
        this->type = type;
        this->amount = amount;
        this->timestamp = time(NULL);
    }

    string getTransactionNo() const
    {
        return transactionNo;
    }

    string getType() const
    {
        return type;
    }

    double getAmount() const
    {
        return amount;
    }

    static string getTime() {

        // Get the current system time
        time_t currentTime;
        time(&currentTime);

        // Convert the system time to local time
        struct tm localTime;
        localtime_s(&localTime, &currentTime);

        // Extract the date components
        int year = localTime.tm_year + 1900;  // tm_year represents years since 1900
        int month = localTime.tm_mon + 1;     // tm_mon is zero-based (0 = January)
        int day = localTime.tm_mday;

        // Create a string representing the date
        string date = to_string(year) + "-" + to_string(month) + "-" + to_string(day);

        return date;

    }

    static void storeTransaction(string filename, string typ)
    {

        ofstream file(filename, ios::app);
        if (!file)
        {
            cerr << "Error: Could not open file \"" << filename << "\" for writing.\n";
            return;
        }

        string transaction_no = "TX" + to_string(time(NULL));
        string type = typ;
        double amount;
        double newBalance = 0.0;
        double value = 0.0;

        cout << "Enter Amount(HUF): ";
        cin >> amount;

        string timeOfTrans = Transaction::getTime();

        file << transaction_no << "   " << type << "   " << amount << "   " << timeOfTrans << endl;

        // Calculating Balance

        string getBalance = "Balance.txt";
        string tempBalance = "tempBalance.txt";


        ifstream preBalanceFile(getBalance);

        if (preBalanceFile.is_open()) {

            if (preBalanceFile >> value) {
                cout << "Previously Recorded balance: " << value << " HUF" << endl;

            }
            else {
                cout << "No previous Balance Recorded Before" << endl;
            }

            if (type == "Deposit") {
                newBalance = value + amount;
            }
            else {
                newBalance = value - amount;
            }

        }
        else {
            cout << "Failed to open the file: " << filename << endl;
        }

        ofstream newBal(getBalance);

        if (!newBal)
        {
            cerr << "Error: Could not open file \"" << tempBalance << "\" for writing.\n";
            return;
        }

        newBal << newBalance;
        cout << endl;
        cout << "Balance Updated!!" << endl;
        cout << "------------------- " << endl << endl;
        cout << "New Balance: " << newBalance << " HUF" << endl;
        cout << endl;

        getBalance = tempBalance;


        file.close();
        preBalanceFile.close();
        newBal.close();

        cout << "Transactions saved.\n";

    }


    static void showTransactions(string filename)
    {
        ifstream file(filename);
        if (!file)
        {
            cerr << "Error: Could not open file \"" << filename << "\" for reading.\n";
            return;
        }

        string line;
        cout << "Transactions: " << endl << endl;
        cout << "Trans. No      " << "Type      " << "Amount   " << "Date" << endl << endl;
        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();

        cout << endl << endl;

        ifstream BalanceFile("Balance.txt");

        if (BalanceFile.is_open()) {
            string line;
            while (getline(BalanceFile, line)) {
                cout << "Balance: " << line << " HUF" << endl;
            }

            BalanceFile.close();
        }
        else {
            cout << "Failed to open the file: " << "Balance.txt" << endl;
        }


    }

};

