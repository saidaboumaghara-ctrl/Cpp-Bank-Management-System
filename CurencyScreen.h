#pragma once
#include<iostream>
#include"clsstring.h"
#include"clsscreen.h"
#include"_ShowCurrenciesListScreen.h"
#include"FindCurency.h"
#include"Updaterate.h"
#include"Calucator.h"
class clsCurencyScreen : public clsscreen
{
private:
    enum enCurrenciesMainMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short ReadCurrenciesMainMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsstring::ReadShortnumberbetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrenciesMenue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
        ShowCurrenciesMenue();
    }

    static void _ShowCurrenciesListScreen()
    {
        clsShowCureentScreen::ShowCurentList();

    }

    static void _ShowFindCurrencyScreen()
    {
        clsfindcurency::ShowFindCurrencyScreen();

    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateRate::ShowUpdateRatescreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCalculator::ShowCalculatorscreen();

    }

    static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
    {

        switch (CurrenciesMainMenueOptions)
        {
        case enCurrenciesMainMenueOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenue();
            break;
        }

        case enCurrenciesMainMenueOptions::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:

    static void ShowCurrenciesMenue()
    {

        system("cls");
        _DrawMainScreen("Currancy Exhange Main Screen");
        int x = 85;
        cout << setw(x) << left << "" << "===========================================\n";
        cout << setw(x) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(x) << left << "" << "===========================================\n";
        cout << setw(x) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(x) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(x) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(x) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(x) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(x) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenueOptions((enCurrenciesMainMenueOptions)ReadCurrenciesMainMenueOptions());
    }

};