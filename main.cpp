#include <bits/stdc++.h>
#include "payment_subscription.h"
#include "playlist.h"
#include "account.h"
using namespace std;

int main()
{
    while (1)
    {
        cout << "\n\nEnter \n1.Maintainer \n2.User\n3.Exit\n";
        cout << "Enter your choice (1 or 2 or 3):";
        int n;
        cin >> n;
        if (n == 1)
        {   
            cout<<"\n\t\t----------------";
            cout << "\n\t\t   MAINTAINER\n";
            cout<<"\t\t----------------\n";
            while (1)
            {

                cout << "\n1.Do you want to add songs to the existing playlist:\n2.Do you want to see the playlist:\n3.Do you want to see the details:\n";
                int n1;
                cin >> n1;
                cin.ignore();
                songs *s1;
                Bollywood_songs Bs1;
                Hit_songs Hs1;
                English_songs Es1;
                if (n1 == 1)
                {
                    cout << "In which playlist do you want to add the song:\n";
                    cout << "1. Bollywood songs\t\t2. Hit songs\t\t 3.English songs\n";
                    int ch;
                    cin >> ch;
                    switch (ch)
                    {
                    case 1:
                        s1=&Bs1;
                        s1->Songs();
                        break;
                    case 2:
                        s1=&Hs1;
                        s1->Songs();
                        break;
                    case 3:
                        s1=&Es1;
                        s1->Songs();
                        break;
                    
                    default:
                        break;
                    }
                    cout << "Do you want to continue (y or n)?: ";
                    char c1;
                    cin >> c1;
                    if (c1 == 'n')
                    {
                        break;
                    }
                }

                else if (n1 == 3)
                {
                    cout << "Details of the Users:\n";
                    showdetails();
                    cout << "Do you want to continue (y or n)?: ";
                    char c1;
                    cin >> c1;
                    if (c1 == 'n')
                    {
                        break;
                    }
                }
                else
                {
                    Bs1.display_song();
                    Hs1.display_song();
                    Es1.display_song();
                    cout << "Do you want to continue (y or n)?: ";
                    char c2;
                    cin >> c2;
                    if (c2 == 'n')
                    {
                        break;
                    }
                }
            }
        }
        else if (n == 2)
        {
            cout<<"\n\t\t--------";
            cout << "\n\t\t  USER\n";
            cout<<"\t\t--------\n";
            cout << "\nWelcome to online music service.... we hope you enjoy a great time\n";
            cout << "\n1.Existing user account\n2.Create new user account\n";
            int n2;
            cin >> n2;
            Account a1;

            if (n2 == 1)
            {
                cin.ignore();
                a1.existing_account();
                cin.ignore();
                cout << "Do you want to change your password(y or n)? :\n";
                char c3;
                cin >> c3;
                if (c3 == 'y')
                {
                    a1.forgetpassword();
                }

            }
            else
            {
                cin.ignore();
                a1.create_new_account();
            }
            cout << "Do you want to take subscription (y or n):\n";
            char c4;
            cin >> c4;
            if (c4 == 'y')
            {
                subscription s1;
            }
            cout << "Do you want to create your own playlist(y or n):\n";
            char c5;
            cin >> c5;
            if (c5 == 'y')
            {
                Playlist p1;
            }
        }
        else if (n == 3)
        {
            break;
        }
    }
    return 0;
}
