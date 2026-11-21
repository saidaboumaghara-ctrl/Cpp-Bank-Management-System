#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsstring.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clswithdrawscren.h"
#include "clsshowtotal.h"
#include"clsTransfer.h"
#include"clsTransferLogscreen.h"
using namespace std;
class clsTransactions :protected clsscreen
{
private:
	enum entransmenuoptons {
		enDeposit = 1, enwithdraw = 2, enTotalBalances = 3, enmainMenu = 6,Trasfer=4,Showtrasferlog=5
	};

	static void _ShowDepositscreen()
	{
		clsDepsitscreen::showDepositscreen();
	

	}
	
	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		DrawTransactionsscren();
	}
	static void _showWithdrawscreen()
	{
		clswithdrawscreen::showWithdrawscreen();

	}
	static void _ShowTotalbalancescreen()
	{
		clstotalblance::showTotalBlancescreen();
	}
	static void _ShowTransferScreen()
	{
		clsTransfer::ShowTransferScreen();

	}
	static void _ShowTransferLogscreen()
	{
		clsTransferlogScreen::ShowTransferlogScreen();
	}
	static int Readtransactionmainmenuoper()
	{
		cout << "\t\t\t\t\t\t\t\t\tChoise what do you want to do [1 to 6] ?\n";
		short int choose = clsstring::ReadShortnumberbetween(1, 6, "Please try again :");
		return choose;
	}
	static void _parformmainmenuopertion(entransmenuoptons transmenu)
	{
		switch (transmenu)
		{
		case entransmenuoptons::enDeposit:
		{
			system("cls");

			_ShowDepositscreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case  entransmenuoptons::enmainMenu:
		{
			system("cls");

			break;
		}
		case  entransmenuoptons::enTotalBalances:
		{
			system("cls");
			_ShowTotalbalancescreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case  entransmenuoptons::enwithdraw:
		{
			system("cls");
			_showWithdrawscreen();
			_GoBackToTransactionsMenue();
			break;
		}
		case entransmenuoptons::Trasfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;



		}
		case entransmenuoptons::Showtrasferlog:
		{
			system("cls");
			_ShowTransferLogscreen();
			_GoBackToTransactionsMenue();

			break;
		}
		}





	};


public:
	static void DrawTransactionsscren()
	{
		if (!chekacessright(clsUser::enPermisson::ptranctons))
		{
			return;
		}
		system("cls");
		_DrawMainScreen("TRANSACTIONS  SCREEN ");
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t      Transaction  Menue\n ";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";
		cout << "\t\t\t\t\t\t\t\t\t[1] Deposit\n";
		cout << "\t\t\t\t\t\t\t\t\t[2] withdraw\n";
		cout << "\t\t\t\t\t\t\t\t\t[3] Total Balances\n";
		cout << "\t\t\t\t\t\t\t\t\t[4] Transfer  \n";
		cout << "\t\t\t\t\t\t\t\t\t[5] Transfer Log Screen \n";
		cout << "\t\t\t\t\t\t\t\t\t[6] Mani menu \n";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";
		_parformmainmenuopertion((entransmenuoptons)Readtransactionmainmenuoper());

	}
	
}; 