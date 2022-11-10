#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;
class Account
{
protected:
    string name;
    string email_id;
    string gender;
    string date_of_birth;

public:
    Account() {}

    void forgetpassword()
    {
        string new_password;
        string new_p;
        string email;
        ofstream fout;
        fout.open("details.txt", ios::in | ios::app);
        if (!fout.is_open())
        {
            cout << "File not opened";
        }
        else
        {
            string name, date_of_birth;
            cout << "<------Verify account----->\n";
            cout << "Enter your name:";
            cin.ignore();
            getline(cin, name);
            fout << name << " ";
            cout << "Enter date of birth:";
            getline(cin, date_of_birth);
            fout << date_of_birth << " ";
            cout << "Enter email-id: ";
            cin.ignore();
            getline(cin, email);
            fout << email << " ";
            int offset;
            string line;
            ifstream fin;
            fin.open("details.txt");
            while (!fin.eof())
            {
                getline(fin, line);
                if ((offset = line.find(email, 0)) != string::npos)
                {
                    cout << "<-------Email-id found------->\n";
                    cout << "Enter new password:\n";
                    getline(cin, new_password);
                    cout << "Re-enter password:\n";
                    getline(cin, new_p);
                    if (new_password == new_p)
                    {
                        cout << "<------Password changed------->\n";
                        fout << new_password << " " << endl;
                    }
                    else
                    {
                        cout << "password not matched";
                    }
                    fin.close();
                }
            }
        }
        fout.close();
    }

    void existing_account()
    {
        int offset;
        string line;
        ifstream fin;
        string email, password;
        cout << "Enter your email-id: ";
        getline(cin, email);
        cout << "Enter your password: ";
        getline(cin, password);
        fin.open("details.txt");
        while (!fin.eof())
        {
            getline(fin, line);
            if ((offset = line.find(email, 0)) != string::npos)
            {
                if (offset = line.find(password, 0) != string::npos)
                {
                    cout << "You have successfully verified\n";
                    fin.close();
                }
                
            }
            else
                {
                    int choice;
                    cout << "Your password and email does not match\n";
                    cout << "1.Create password\n2.Exit\n";
                    cout << "Enter your choice:";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        forgetpassword();
                        return;
                        break;

                    case 2:
                        exit(0);
                    }
                }
        }
    }
    void create_new_account()
    {
        ofstream fout;
        fout.open("details.txt", ios::out | ios::app);
        int age1;
        string name1, date_of_birth1, email_id1, password1;
        if (!fout.is_open())
        {
            cout << "File not opened";
        }
        else
        {
            cout << "Enter your name:";
            getline(cin, name1);
            cout << "Enter your date of birth:";
            cin.ignore();
            getline(cin, date_of_birth1);
            fout << date_of_birth1 << " ";
            cout << "Enter your email id:";
            getline(cin, email_id1);
            fout << email_id1 << " ";
            cout << "Enter your password:";
            getline(cin, password1);
            fout << password1 << "\n";
        }
        fout.close();
    }
};
