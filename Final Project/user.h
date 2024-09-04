#pragma once

class User
{
private:
    string name;
    string phone;
    string email;
public:
    User() {}

    void setName(string name)
    {
        this->name = name;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    void setEmail(string email)
    {
        this->email = email;
    }

    bool userExists(string filename)
    {
        ifstream file(filename);
        if (file) // File exists, so user details have already been saved
        {
            file.close();
            return true;
        }
        else // File does not exist, so user details need to be saved
        {
            return false;
        }
    }
    void saveUserDetails(string filename)
    {
        ofstream outfile(filename);
        if (!outfile)
        {
            cerr << "Error: Could not open file";
            return;
        }

        cout << "Enter your name: ";
        getline(cin, name);
        outfile << "Name: " << name << endl;

        cout << "Enter your phone number: ";
        getline(cin, phone);
        outfile << "Phone: " << phone << endl;

        cout << "Enter your email: ";
        getline(cin, email);
        outfile << "Email: " << email << endl;

        outfile.close();
        cout << "User details saved in file \"" << filename << "\".\n";
    }
};

class UserFileManager
{
public:
    static bool userExists(string filename)
    {
        ifstream file(filename);
        if (file) // File exists, so user details have already been saved
        {
            file.close();
            return true;
        }
        else // File does not exist, so user details need to be saved
        {
            return false;
        }
    }
    static void saveUserDetails(string filename, string name, string phone, string email)
    {
        ofstream outfile(filename);
        if (!outfile)
        {
            cerr << "Error: Could not open file";
            return;
        }

        outfile << "Name: " << name << endl;
        outfile << "Phone: " << phone << endl;
        outfile << "Email: " << email << endl;

        outfile.close();
        cout << "User details saved in file";
    }
    static void showUserDetails(string filename)
    {
        ifstream infile(filename);
        if (!infile)
        {
            cerr << "Error: Could not open file";
            return;
        }

        string line, name, phone, email;

        while (getline(infile, line))
        {
            if (line.substr(0, 5) == "Name:")
            {
                name = line.substr(6);
            }
            else if (line.substr(0, 6) == "Phone:")
            {
                phone = line.substr(7);
            }
            else if (line.substr(0, 6) == "Email:")
            {
                email = line.substr(7);
            }
        }

        infile.close();

        cout << "Your current details are:\n";
        cout << "--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;

    }
    static void editUserDetails(string filename)
    {
        ifstream infile(filename);
        if (!infile)
        {
            cerr << "Error: Could not open file";
            return;
        }

        string line, name, phone, email;

        while (getline(infile, line))
        {
            if (line.substr(0, 5) == "Name:")
            {
                name = line.substr(6);
            }
            else if (line.substr(0, 6) == "Phone:")
            {
                phone = line.substr(7);
            }
            else if (line.substr(0, 6) == "Email:")
            {
                email = line.substr(7);
            }
        }

        infile.close();

        cout << "Your current details are:\n";
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Email: " << email << endl;

        cout << "Enter your new details:\n";
        cout << "Name: ";
        getline(cin, name);

        cout << "Phone: ";
        getline(cin, phone);

        cout << "Email: ";
        getline(cin, email);

        saveUserDetails(filename, name, phone, email);
    }
};
