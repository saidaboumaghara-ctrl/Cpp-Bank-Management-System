#pragma once
#include<iostream>
#include"clsscreen.h"
#include"clsstring.h"
#include"clsUser.h"
#include<iomanip>
using namespace std;
class clsnewuser:protected clsscreen
{


private:
	static int _Readpermisontoset()
	{
		int permison = 0;
		char chose = 'n';
		cout << "\nDo you want give full paermsson [y/n]?\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

			return -1;
		}
		cout << "Do you want give acess to\n?";
		cout << "show client list[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{
 
			 permison += clsUser::enPermisson::plistclients;
		}
		cout << "show Add new client[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

	 permison += clsUser::enPermisson::paddnewclient;
		}
		cout << "show dlete client[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

			 permison += clsUser::enPermisson::pdeleteclient;
		}
		cout << "show update client[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

			 permison += clsUser::enPermisson::pupdateclient;
		}
		cout << "show find client[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

			 permison += clsUser::enPermisson::pfindclinet;

		}
		cout << "show transhon client[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

			 permison += clsUser::enPermisson::ptranctons;

		}
		cout << "mangeuers[y\\n]\n";
		cin >> chose;
		if (chose == 'y' || chose == 'Y')
		{

			 permison += clsUser::enPermisson::pmangeusers;

		}
		return permison;

	}


	static void _readuserinfo(clsUser& user)
	{
		cout << "\nEnter FirstName: ";
		user.FirstName = clsstring::ReadString();

		cout << "\nEnter LastName: ";
		user.LastName = clsstring::ReadString();

		cout << "\nEnter Email: ";
		user.Email = clsstring::ReadString();

		cout << "\nEnter Phone: ";
		user.Phone = clsstring::ReadString();

		cout << "\nEnter Pasword: ";
		user.Password = clsstring::ReadString();
		cout << "\nEnter Permission: ";
		user.Permissions = _Readpermisontoset();



	}
	static void _printuser(clsUser user)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nUsername   : " << user.UserName;
		cout << "\nFirstName   : " << user.FirstName;
		cout << "\nLastName    : " << user.LastName;
		cout << "\nFull Name   : " << user.FullName();
		cout << "\nEmail       : " << user.Email;
		cout << "\nPhone       : " << user.Phone;
		cout << "\nPasword     :" << user.Password;
		cout << "\n permisson  :" << user.Permissions;
		cout << "\n___________________\n";


	}


public:

	static void ShoeAddNewuserScreen()
	{
		_DrawMainScreen("ADD NEW USER SCREEN");
		string Username = "";
		cout << "Please user name\n";
		Username = clsstring::ReadString();
		while (clsUser::IsUserExist(Username))
		{
			cout << "user name is alerday  used ,choese another one \n";
			Username = clsstring::ReadString();


		}

		clsUser NewUser = clsUser::GetAddNewUserObject(Username);
		_readuserinfo(NewUser);
		clsUser::enSaveResults saveresult;
		saveresult = NewUser.Save();

		switch (saveresult)
		{
		case clsUser::enSaveResults::svSucceeded:
			cout << "Account added succesfly :)\n";
			_printuser(NewUser);
			break;
		case clsUser::enSaveResults::svFaildUserExists:
			cout << " please try again\n";
			break;
		case clsUser::enSaveResults::svFaildEmptyObject:
			cout << "Error account was not saved because its  empty\n";
			break;



		}






	}


};