#pragma once
#include<iostream>
#include"clsscreen.h"
#include"clsstring.h"
#include"clsUser.h"
#include<iomanip>
using namespace std;
class clsDeleteuser :protected clsscreen
{
private:
	static void _printuser(clsUser& user)
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
	static void showdeleteuserscreen()
	{
		_DrawMainScreen("DELETE USER SCREEN");
		string username = "";
		cout << "Please enter user name : \n";
		username = clsstring::ReadString();
		while (!clsUser::IsUserExist(username))
		{
			cout << "user not found try again \n";
			username = clsstring::ReadString();

		}
		clsUser user = user.Find(username);
		_printuser(user);
		char answer = 'n';
		cout << "Do you want delete user are yoy sure?[y\\n]\n";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (user.Delete())
			{
				cout << "user deleted\n";
				_printuser(user);
			}
			else
			{
				cout << "erorr try again" << endl;
			}





		}



	};
};