#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsstring.h"
#include <iomanip>
#include "cslistusersscreen.h"
#include "clsAddnewuser.h"
#include "clsDeletescreeb..h"
#include "clsUpdateUserScreen.h"
#include "clsfindusers.h"


using namespace std;
class clsmangeuser :protected clsscreen
{
	enum enMenumangeoper {
		ListUsers = 1, AddNewUser = 2, DeleteUsers = 3, UpdateUsers = 4, FindUsers=5, MainMenu=6
	};

	static void _drawmangwscreen()
	{
		system("cls");
		cout << right;
		cout <<setw(125) <<"===========================================" << endl;
		cout<< setw(125)<< "==================Manga users==============" << endl;
		cout <<setw(100) <<" [1] List Users :\n";
		cout <<setw(102) << "[2] Add New User :\n";
		cout <<setw(102) << "[3] Delete Users :\n";
		cout << setw(102) <<"[4] Update Users :\n";
		cout <<setw(100) << "[5] Find Users :\n";
		cout <<setw(99) << "[6] Main Menu :\n";
		cout <<setw(125) << "===========================================" << endl;
		cout <<setw(115) << "Choise what do you want [1 to 6]\n";

     }
	static int _choiseinmangescreen()
	{
		short x = clsstring::ReadShortnumberbetween(1, 6, "Please try again");
		return x;

	}
	static void _showlistusersscren()
	{
		clslistuser::ShowUserList();


	}
	static void _goBacktomangeusersmenu()
	{
		
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		
		ShowMangaUsersscreen();



	}
	static void _showAddnewuserscreen()
	{
		clsnewuser::ShoeAddNewuserScreen();

	}
	static void _showdeleteusersscren()
	{
		clsDeleteuser::showdeleteuserscreen();
	}
	static void _showfindusersscren()
	{

		clsfinduserscreen::showfinduserscreen();
	}
	static void _showUpdateusersscren()
	{
		clsUpdateuserscreen::showUpdateuserscreen();


	}
	
	static void _Parformmangeusersmenuoper(enMenumangeoper oper)
	{
		switch (oper)
		{
		case enMenumangeoper::AddNewUser:
		{
			system("cls");
			_showAddnewuserscreen();
			_goBacktomangeusersmenu();
			break;
		}
		case enMenumangeoper::DeleteUsers:
		{
			system("cls");
			_showdeleteusersscren();
			_goBacktomangeusersmenu();
			break;
		}
		case enMenumangeoper::FindUsers:
		{
			system("cls");
			_showfindusersscren();
			_goBacktomangeusersmenu();
			break;
		}
		case enMenumangeoper::ListUsers:
		{
			system("cls");
			_showlistusersscren();
			_goBacktomangeusersmenu();
			break;
		}
		case enMenumangeoper::UpdateUsers:
		{
			system("cls");
			_showUpdateusersscren();
			_goBacktomangeusersmenu();
			break;
		}
		case enMenumangeoper::MainMenu:
		{
			break;
		}






        }

	}



public:
	static void ShowMangaUsersscreen()
	{

		if (!chekacessright(clsUser::enPermisson::pmangeusers))
		{
			return;
		}

		system("cls");
		_DrawMainScreen("MANGE USERS SCREEN");
		_drawmangwscreen();
		_Parformmangeusersmenuoper((enMenumangeoper)_choiseinmangescreen());



	}

























};