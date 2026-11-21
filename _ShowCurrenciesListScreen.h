#pragma once
#include<iostream>
#include"clsscreen.h"
#include"clsCurency.h"
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class clsShowCureentScreen :public clsscreen
{

private:
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }

public:
    static void ShowCurentList()
    {
        vector<clsCurrency>vcuren = clsCurrency::GetCurrenciesList();

        string tilte = "Curent list Screen\n";
        string subtitle = "\t    (" + to_string(vcuren.size()) + ")       \n";

        _DrawMainScreen(tilte);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vcuren.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vcuren)
            {
                PrintCurrencyRecordLine(Currency);

                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

    }












};


























