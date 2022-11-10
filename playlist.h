#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#include "songs_artist.h"

class Playlist
{
private:
    string playlistName;
    string Song_name;
    Bollywood_songs Bs1;
    Hit_songs Hs1;
    English_songs Es1;
    vector<string> v;

public:
    bool valid_song(string song_name, string playlistname)
    {
        int offset;
        string line;
        ifstream myfile;
        string fileName;
        if (playlistname == "Bollywood songs")
        {
            fileName = "songs1.txt";
        }
        else if (playlistname == "Hits songs")
        {
            fileName = "songs2.txt";
        }
        else if (playlistname == "English songs")
        {
            fileName = "songs3.txt";
        }
        myfile.open(fileName);

        while (!myfile.eof())
        {
            getline(myfile, line);
            if ((offset = line.find(song_name, 0)) != string::npos)
            {
                myfile.close();
                return true;
            }
        }
        myfile.close();
        return false;
    }
    void input_song()
    {
        cin.ignore();
        cout << "Enter the song's name: ";
        getline(cin, Song_name);
    }

    void addExistingPlaylist(string playlist)
    {
        while (1)
        {
            input_song();
            if (valid_song(Song_name, playlist))
            {
                v.push_back(Song_name);
                cout << "Your playlist is successfully updated\n";
                cout << "Do you want to add song (0 or 1)\n";
                int i;
                // cin.ignore();
                cin>>i;
                if(i == 1){
                    continue;
                }
                else{
                    break;
                }
            }
            else
            {
                cout << "Song doesn't exist in our playlist.\n";
                cout << "Please re-enter.\n";
            }
        }
    }
    void display_playlist()
    {
        cout << "Songs in your playlist are:\n";
        for (auto &i : v)
        {
            cout << i << endl;
        }
    }

    void addSong(string playlistname)
    {

        input_song();
        valid_song(Song_name, playlistname);
        v.push_back(Song_name);
        cout << "Do you want to see your playlist (y or n)?\n";
        char chh;
        cin >> chh;
        if (chh == 'y')
        {
            display_playlist();
        }
        cout << "Do you want to add another song (y or n)?: ";
        char ch;
        cin >> ch;
        if (ch == 'y')
        {
            addExistingPlaylist(playlistname);
            cout << "Do you want to see your playlist (y or n)?\n";
            char chh1;
            cin >> chh1;
            if (chh1 == 'y')
            {
                display_playlist();
            }
        }
    }
    Playlist()
    {
        Bs1.display_song();
        Hs1.display_song();
        Es1.display_song();
        cout << "\nEnter your playlist name: ";
        cin >> playlistName;

        cout << "1. Bollywood songs\t\t2. Hit songs\t\t 3.English songs\n";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
            addSong("Bollywood songs");
            break;

        case 2:
            addSong("Hits songs");
            break;

        case 3:
            addSong("English songs");
            break;

        default:
            cout << "Wrong input\n";
            break;
        }
    }
};

// int main()
// {
//     Playlist p1;
//     return 0;
// }