#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsstring.h"
#include "clsClientListScreen.h"
#include "clsAddNewclient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen..h"
#include "clslogin.h"
#include "Global.h"
#include"Loginwirte.h"
#include"CurencyScreen.h"
using namespace std;
class clsmainscreen :protected clsscreen
{
	static short _ReadMainMenuoption()
	{
		
		cout << "\t\t\t\t\t\t\t\t\tPlease choise what do you want to do?                                   \n";
		short choice = clsstring::ReadShortnumberbetween(1, 10,"Pleace try again and enter true number");
		return choice;
	}
	enum enmainmenuoptons {
		ShowClientList = 1, addnewclient = 2, deleteClient = 3, Updateclient = 4, findclient = 5, transctions = 6, mangeusers = 7, curency= 9,reister=8,logout=10
	};
	static void _ShowAllclientsscreen()
	{
		clsclientlist::showclinetlist();


	}
	static void _AddNewClient()
	{
		
		clsNewclient::ShoeAddNewClientScreen();


	}
	static void _DeleteClientscreen()
	{

	clsDeleteClient::DeleteClient();


	}
	static void _UpdateClientscreen()
	{

		clsUpdateClinetinfo::UpdateClinet();


	}
	static void _FindClient()
	{

		clsFindClient::ShowFindClient();


	}
	static void _Transactionsscreen()
	{
		clsTransactions::DrawTransactionsscren();


	}
	static void _ShowMangaUsers()
	{

		clsmangeuser::ShowMangaUsersscreen();


	}
	static void _ShowRegistersscren()
	{
		clslogincontrol::ShowRegisterScreen();


	}
	static void _Showcurencyscreen()
	{

		clsCurencyScreen::ShowCurrenciesMenue();


	}
	static void _goBacktoMainMenumenu()
	{
		cout << "\n\nPress any key to go back to Main Menu...";
		system("pause>0");
		ShowMainMenu(); // استدعاء دالة رسم القائمة الرئيسية من جديد
	}
	static void _logout()
	{
	///pr
		Currentuser11 = clsUser::Find("", "");

	}
	static void _parformmainmenuopertion(enmainmenuoptons mainmenu)
	{
		switch (mainmenu)
		{
		case enmainmenuoptons::ShowClientList:
		{ system("cls"); 
		_ShowAllclientsscreen();
		_goBacktoMainMenumenu();
		
		break;
		}
		case enmainmenuoptons::addnewclient:
		{
			system("cls");
			_AddNewClient();
			_goBacktoMainMenumenu();
			break;
		}
		case enmainmenuoptons::deleteClient:
		{
			system("cls"); 
			_DeleteClientscreen();
			_goBacktoMainMenumenu();
			break;
		}
		case enmainmenuoptons::findclient:
		{
			system("cls"); 
			_FindClient();
			_goBacktoMainMenumenu();
			break;
		}
		case enmainmenuoptons::logout:
		{
			system("cls"); 
			_logout();

			break;
		}
		case enmainmenuoptons::mangeusers:
		{
			system("cls"); 
			_ShowMangaUsers();
			_goBacktoMainMenumenu();
			break;
		}
		case enmainmenuoptons::Updateclient:
		{
			system("cls"); 
			_UpdateClientscreen();
			_goBacktoMainMenumenu();
			break;
		}
		case enmainmenuoptons::transctions:
		{
			system("cls"); 
			_Transactionsscreen();
			_goBacktoMainMenumenu();
			break;
		}
		case enmainmenuoptons::reister:
		{
			system("cls");

			_ShowRegistersscren();
			_goBacktoMainMenumenu();
			break;

		}
		case enmainmenuoptons::curency:
		{
			system("cls");
			_Showcurencyscreen();
			_goBacktoMainMenumenu();
			break;
		}
		}









	}




public:
	static void ShowMainMenu()
	{

		system("cls");
	
		_DrawMainScreen("MAIN SCREEN");
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\tMAIN MENU                                    \n";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";
		cout << "\t\t\t\t\t\t\t\t\t[1] Show Client List\n";
		cout << "\t\t\t\t\t\t\t\t\t[2] Add New Client\n";
		cout << "\t\t\t\t\t\t\t\t\t[3] Delete Client\n";
		cout << "\t\t\t\t\t\t\t\t\t[4] Update Client Info\n";
		cout << "\t\t\t\t\t\t\t\t\t[5] Find Client\n";
		cout << "\t\t\t\t\t\t\t\t\t[6] Transactions\n";
		cout << "\t\t\t\t\t\t\t\t\t[7] Mange users\n";
		cout << "\t\t\t\t\t\t\t\t\t[8] Registers screen\n";
		cout << "\t\t\t\t\t\t\t\t\t[9] Curency screen\n";
		cout << "\t\t\t\t\t\t\t\t\t[10] Logut\n";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";
		_parformmainmenuopertion((enmainmenuoptons)_ReadMainMenuoption());
	}
};



















