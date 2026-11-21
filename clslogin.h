#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include"Loginwirte.h"
class clsloginscreen :protected clsscreen
{
	
	
	static bool _loginscreen()
	{
	
		bool loginfaild = false;
		short loginfailedcount = 0;
		do
		{
			if (loginfaild)
			{
				int x = 125;
				loginfailedcount++;
				cout << setw(x) << "Please try agaian your username or password is false \n";
				cout << setw(x) << "You have : [" << 3 - loginfailedcount << "]Trails to login \n";
				if (loginfailedcount == 3)
				{
					cout << "Your locked becasue 3 try is false \n";
					return false;
				}
		    }
			

			int x = 125;
			cout << setw(x) << "========================================\n";
			cout << setw(x) << "=                                      =\n";
			cout << setw(x) << "=            LOGIN SCREEN              =\n";
			cout << setw(x) << "=                                      =\n";
			cout << setw(x) << "========================================\n";
			if (loginfaild)
			cout << setw(x) << "invalide username\\pasword\n";
			cout << setw(87) << "  \t\t    = Username :   ";
			string username;
			cin >> username;
			cout << setw(87) << "  \t\t    = Password :   ";
			string Pasword;
			cin >> Pasword;
			Currentuser11 = clsUser::Find(username, Pasword);
			loginfaild = Currentuser11.IsEmpty();
			clslogincontrol::Loginwriter();
		} while (loginfaild);
		clsmainscreen::ShowMainMenu();
		return true;
    }


public:
	
	static bool showloginscreen()
	{
		system("cls");
		_DrawMainScreen("LOGIN SCREEN");
		return _loginscreen();
	}






};