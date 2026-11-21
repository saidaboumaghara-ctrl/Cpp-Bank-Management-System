#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

#include "Global.h"
#include "clsscreen.h"

using namespace std;


class clslogincontrol
{

public:

    struct stLoginRegisterRecord
    {
        string UserName;
        string Password;
        int Permissions;
        string DateTime;
    };


private:

    static vector<stLoginRegisterRecord> _LoadLoginRegisterData()
    {
        vector<stLoginRegisterRecord> vRecords;

        fstream File;
        File.open("Loginwriter.txt", ios::in);

        if (File.is_open())
        {
            string UserName;
            string Password;
            string Permissions;
            string DateTime;

            while (getline(File, UserName, '#') &&
                getline(File, Password, '#') &&
                getline(File, Permissions, '#') &&
                getline(File, DateTime))
            {

                stLoginRegisterRecord Record;

                Record.UserName = UserName;
                Record.Password = Password;
                Record.Permissions = stoi(Permissions);
                Record.DateTime = DateTime;

                vRecords.push_back(Record);
            }

            File.close();
        }

        return vRecords;
    }


public:


    static string userlogindatetoline()
    {
        string line;

        line += Currentuser11.UserName + "#";
        line +=clsstring::EncryptText(Currentuser11.Password)+ "#";
        line += to_string(Currentuser11.Permissions) + "#";
        line += clsscreen::GetDateTime();

        return line;
    }


    static void Loginwriter()
    {
        fstream Loginfile;

        Loginfile.open("Loginwriter.txt", ios::out | ios::app);

        if (Loginfile.is_open())
        {

            string line = userlogindatetoline();

            Loginfile << line << endl;

            Loginfile.close();
        }
    }



    static void PrintLoginRegisterRecordLine(stLoginRegisterRecord Record)
    {

        cout << setw(8) << left << ""
            << "| " << setw(35) << left << Record.DateTime;

        cout << "| " << setw(20) << left << Record.UserName;

        cout << "| " << setw(20) << left << Record.Password;

        cout << "| " << setw(10) << left << Record.Permissions;

    }



    static void ShowRegisterScreen()
    {

        vector<stLoginRegisterRecord> vLoginRegisterRecord =
            _LoadLoginRegisterData();


        cout << "\n\n";

        cout << setw(8) << left << ""
            << "_______________________________________________________________\n";


        cout << setw(8) << left << ""
            << "| " << setw(35) << left << "Date/Time";

        cout << "| " << setw(20) << left << "UserName";

        cout << "| " << setw(20) << left << "Password";

        cout << "| " << setw(10) << left << "Permissions";


        cout << "\n";

        cout << setw(8) << left << ""
            << "_______________________________________________________________\n";


        if (vLoginRegisterRecord.empty())
        {
            cout << "\t\tNo Logins Available In The System!";
        }
        else
        {

            for (stLoginRegisterRecord Record : vLoginRegisterRecord)
            {
                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        }


        cout << setw(8) << left << ""
            << "_______________________________________________________________\n";

    }

};