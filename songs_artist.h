#include <bits/stdc++.h>
using namespace std;

void showdetails()
{
    string ch;
    ifstream fin;
    fin.open("details.txt");
    if (fin.is_open())
    {
        while (getline(fin, ch))
        {
            cout << ch << endl;
        }
        fin.close();
    }
}

class Artist
{
private:
    string artistName;

public:
    Artist()
    {
    }
    string artist_name()
    {
        cout << "Enter the name of the artist: ";
        getline(cin, artistName);

        return artistName;
    }
};

class songs
{
private:
    string songName;
    Artist artistName;

public:
    songs() {}
    virtual void display_song() = 0;

    virtual void Songs() = 0;
};

class Bollywood_songs : public songs
{
private:
    string songName;
    Artist artistName;

public:
    fstream file_;
    void display_song()
    {
        cout << "\n\nThe songs we have in our Bollywood playlist are in the following format:\nSong --> Artist\n";
        string line;
        ifstream file_1("songs1.txt");
        if (file_1.is_open())
        {
            while (getline(file_1, line))
            {
                cout << line << endl;
            }
            file_1.close();
        }
    }
    void Songs()
    {
        file_.open("songs1.txt", ios::out | ios::in | ios::app);
        if (!file_.is_open())
        {
            cout << "Error\n";
        }
        else
        {

            cout << "Enter the song name: ";
            cin.ignore();
            getline(cin, songName);

            string artist_Name = artistName.artist_name();
            file_ << songName << " --> " << artist_Name ;
            file_<<endl;
        }
    }
};


class English_songs : public songs
{
private:
    string songName;
    Artist artistName;

public:
    fstream file_4;
    void display_song()
    {
        cout << "\n\nThe songs we have in our English playlist are in the following format:\nSong --> Artist\n";
        string line;
        ifstream file_5("songs2.txt");
        if (file_5.is_open())
        {
            while (getline(file_5, line))
            {
                cout << line << endl;
            }
            file_5.close();
        }
    }
    void Songs()
    {
        file_4.open("songs2.txt", ios::out | ios::in | ios::app);
        if (!file_4.is_open())
        {
            cout << "Error\n";
        }
        else
        {

            cout << "Enter the song name: ";
            cin.ignore();
            getline(cin, songName);
            
            string artist_Name = artistName.artist_name();
            file_4 << songName << " --> " << artist_Name;
            file_4<<endl;
        }
    }
};

class Hit_songs : public songs
{
private:
    string songName;
    Artist artistName;

public:
    fstream file_6;
    void display_song()
    {
        cout << "\n\nThe songs we have in our Hit songs' playlist are in the following format:\nSong --> Artist\n";
        string line;
        ifstream file_7("songs3.txt");
        if (file_7.is_open())
        {
            while (getline(file_7, line))
            {
                cout << line << endl;
            }
            file_7.close();
        }
    }
    void Songs()
    {
        file_6.open("songs3.txt", ios::out | ios::in | ios::app);

        if (!file_6.is_open())
        {
            cout << "Error\n";
        }
        else
        {

            cout << "Enter the song name: ";
            cin.ignore();
            getline(cin, songName);
            
            string artist_Name = artistName.artist_name();
            file_6 << songName << " --> " << artist_Name;
            file_6<<endl;
        }
    }
};
