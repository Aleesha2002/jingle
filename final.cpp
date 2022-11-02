#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, string> m;

class songs
{
private:
    vector<string> songName;

public:
    songs() {}
    void add_song(string songname)
    {
        songName.push_back(songname);
    }

    vector<string> display_song()
    {
        return songName;
    }
};

class Artist
{
private:
    vector<string> artistName;

public:
    Artist() {}
    vector<string> Display_Artist_Name()
    {
        return artistName;
    }

    void Store_Artist_Name(string name)
    {
        artistName.push_back(name);
    }
};

class Playlist
{
private:
    vector<string> addSong;
    string playlistName;
    songs songs_list;

public:
    Playlist()
    {
    }
    Playlist(string addSong, string playlistName)
    {

        this->addSong.push_back(addSong);
        this->playlistName = playlistName;
    }

    void addExistingPlaylist(string songName)
    {
        addSong.push_back(songName);
    }

    vector<string> display_playlist()
    {
        return addSong;
    }
};

class Account
{
protected:
    string name;
    int age;
    string email_id;
    string gender;
    string date_of_birth;

public:
    Account() {}
    Account(string name1, int age1, string gender1, string date_of_birth1, string email_id1, string password1)
    {
        name = name1;
        age = age1;
        gender = gender1;
        date_of_birth = date_of_birth1;
        email_id = email_id1;
        m.insert({email_id, password1});
    }
    void showdetails()
    {
        cout << "Account Detalis\n";
        cout << "Username: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Email-id: " << email_id << endl;
    }

    void forgetpassword()
    {
        string new_password;
        string new_p;
        string email;
        cout << "Enter email-id: ";
        cin >> email;
        for (auto &value : m)
        {
            if (value.first == email)
            {
                cout << "Email-id found:\n";
                cout << "Enter new password:\n";
                cin >> new_password;
                cout << "Re-enter password:\n";
                cin >> new_p;
                if (new_password == new_p)
                {
                    cout << "Password changed\n";
                    value.second = new_password;
                }
                else
                {
                    cout << "password not matched";
                }
            }
        }
    }

    void existing_account(string email, string password)
    {
        for (auto &v : m)
        {
            if (v.first == email && v.second == password)
            {
                cout << "Account Detalis\n";
                cout << "Email-id: " << email << endl;
                cout << "Password: " << password << endl;
            }
            else if (v.first == email && v.second != password)
            {
                forgetpassword();
            }
        }
    }
};

class Payment
{
protected:
    map<int, int> plans;

public:
    void plan_details()
    {
        plans.insert({1, 20});
        plans.insert({2, 75});
        plans.insert({3, 200});
        plans.insert({4, 350});
    }
    Payment()
    {
        plan_details();
    }

    void pay_now(int planNumber)
    {
        for (auto i = plans.begin(); i != plans.end(); i++)
        {
            if ((*i).first == planNumber)
            {
                int amount = (*i).second;
                cout << "Rs." << amount << " has been detected from your bank account.\n";
                cout << "Thank you for taking the subscription\n";
            }
        }
    }
};
class subscription : public Account
{
protected:
    string subscriptonId;
    int planNumber;
    Payment payment_details;

public:
    subscription()
    {
    }
    bool valid_email(string e_mail)
    {
        for (auto i = m.begin(); i != m.end(); i++)
        {
            if ((*i).first == e_mail)
            {
                return true;
            }
        }
        return false;
    }

    void displayPlan()
    {
        cout << "Plan 1: for 7 days- Rs.20"
             << "\n";
        cout << "Plan 2: for 1 month- Rs.75"
             << "\n";
        cout << "Plan 3: for 3 months- Rs.200"
             << "\n";
        cout << "Plan 4: for 6 months- Rs.350"
             << "\n";
    };

    void planTaken(int planNumber)
    {
        cout << "yes yes ";
        payment_details.pay_now(planNumber);
    };

    subscription(string subscriptionId, string email)
    {
        if (valid_email(email))
        {
            subscriptonId = subscriptionId;
            displayPlan();

            int planNum;
            cout << "Enter the plan number that you want to take\n";
            cin >> planNum;

            planTaken(planNum);
        }
        else
        {
            cout << "Sorry, your entered email_id is not matching.\n ";
        }
    }
};

int main()
{
    songs song;
    vector<string> songs{"Kesariya", "Aankon ke Batana", "Dhol Bajaa", "Kachhi Doriyaan"};

    for (auto &i : songs)
    {
        song.add_song(i);
    }

    Artist artistName;
    vector<string> Artists{"Arijit Singh", "Alka Yagnik", "Asha Bhosle", "Neha Kakkar"};

    for (auto &i : Artists)
    {
        artistName.Store_Artist_Name(i);
    }

    cout << "Welcome... we hope you have a great time here \n";

    string email1;
    string password1;
    cout << "Enter the value of email and password ";
    cin >> email1 >> password1;

    Account a2("Y", 17, "f", "09-09-2004", email1, password1);

    string email2;
    string password2;

    cout << "Enter the value of email and password ";
    cin >> email2 >> password2;
    Account a3("Q", 17, "m", "09-03-2004", email2, password2);

    // Account a4("R", 17, "f", "09-10-2004", "rft@gmail.com", "192@#5");
    cout << "Do you have an account? y or n\n";
    char input;
    cin >> input;
    if (input == 'y')
    {
        cout << "please enter your email_id:\n";
        string str1;
        cin >> str1;
        cout << "please enter your password to sign in\n";
        string str2;
        cin >> str2;
        Account a1;
        a1.existing_account(str1, str2);

        cout << "Do you want subscription? y/n \n";
        char ch1;
        cin >> ch1;

        if (ch1 == 'y')
        {
            string subscriptonId01;
            cout << "enter subscriptonId:\n";
            cin >> subscriptonId01;
            string email;
            cout << "Enter the email: ";
            cin >> email;
            subscription s1(subscriptonId01, email);
        }
    }
    else if (input == 'n')
    {
        cout << "please create an account:\n";
        string name1;
        int age1;
        string gender1;
        string date_of_birth1;
        string email_id1;
        string password1;
        cout << "Enter your name: ";
        cin >> name1;
        cout << "Enter your age: ";
        cin >> age1;
        cout << "Enter your gender: ";
        cin >> gender1;
        cout << "Enter your date_of_birth: ";
        cin >> date_of_birth1;
        cout << "Enter your email-id: ";
        cin >> email_id1;
        cout << "Enter your password: ";
        cin >> password1;
        Account a5(name1, age1, gender1, date_of_birth1, email_id1, password1);

        cout << "Do you want subscription? y/n \n";
        char ch1;
        cin >> ch1;

        if (ch1 == 'y')
        {
            string subscriptonId01;
            cout << "enter subscriptonId:\n";
            cin >> subscriptonId01;
            string email;
            cout << "Enter the email: ";
            cin >> email;
            subscription s1(subscriptonId01, email);
        }
    }

    cout << "Do you want to create a playlist? y or n ";
    char pl;

    cin >> pl;

    if (pl == 'y')
    {

        string songName;
        cout << "Enter the song name ";
        getline(cin, songName);

        string playlistName;
        cout << "Enter the playlist name ";
        getline(cin, playlistName);

        Playlist playlist1(songName, playlistName);
    }

    return 0;
}
