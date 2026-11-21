#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "clsscreen.h"

using namespace std;

class clsTransferlogScreen : public clsscreen
{
private:

    struct sttransferRecord
    {
        string UserName;
        string Accout1;
        string account2;
        string amount;
        string DateTime;
    };

    static vector<sttransferRecord> _transferdata()
    {
        vector<sttransferRecord> vRecords;

        fstream File("TransferLog.txt", ios::in);

        if (File.is_open())
        {
            string UserName;
            string Account1;
            string Account2;
            string amount;
            string DateTime;

            while (getline(File, Account1, '#') &&
                getline(File, Account2, '#') &&
                getline(File, amount, '#') &&
                getline(File, UserName, '#') &&
                getline(File, DateTime))
            {
                sttransferRecord Record;

                Record.Accout1 = Account1;
                Record.account2 = Account2;
                Record.amount = amount;
                Record.UserName = UserName;
                Record.DateTime = DateTime;

                vRecords.push_back(Record);
            }

            File.close();
        }

        return vRecords;
    }

    static void PrintLoginRegisterRecordLine(sttransferRecord Record)
    {
        cout << setw(8) << left << ""
            << "| " << setw(35) << left << Record.Accout1
            << "| " << setw(20) << left << Record.account2
            << "| " << setw(40) << left << Record.amount
            << "| " << setw(15) << left << Record.UserName
            << "| " << setw(20) << left << Record.DateTime;
    }

public:

    static void ShowTransferlogScreen()
    {
        vector<sttransferRecord> vLoginRegisterRecord = _transferdata();

        // إذا كانت موجودة في clsscreen
        //_DrawScreenHeader("Transfer Log List");

        cout << "\n\n";

        cout << setw(8) << left << ""
            << "________________________________________________________________________________________________________________________\n";

        cout << setw(8) << left << ""
            << "| " << setw(35) << left << "Account 1"
            << "| " << setw(20) << left << "Account 2"
            << "| " << setw(20) << left << "Amount"
            << "| " << setw(15) << left << "User Name"
            << "| " << setw(20) << left << "Date";

        cout << endl;

        cout << setw(8) << left << ""
            << "________________________________________________________________________________________________________________________\n";

        if (vLoginRegisterRecord.empty())
        {
            cout << "\t\tNo Logins Available In The System!";
        }
        else
        {
            for (sttransferRecord Record : vLoginRegisterRecord)
            {
                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }
        }

        cout << setw(8) << left << ""
            << "________________________________________________________________________________________________________________________\n";
    }
};