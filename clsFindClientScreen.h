#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsstring.h"

using namespace std;
class clsFindClient : protected clsscreen
{
private :
	static void _printClinet(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";




	}
public:
	static void ShowFindClient()
	{

		if (!chekacessright(clsUser::enPermisson::pfindclinet))
		{
			return;
		}

		_DrawMainScreen("FIND CLIENT SCREEN");
		string Accountnumer;
		cout << "Please enter Account number !";
		Accountnumer = clsstring::ReadString();
		while (!clsBankClient::IsClientExist(Accountnumer))
		{
			cout << "Account number is not found !\n";
			Accountnumer = clsstring::ReadString();

		}
		clsBankClient clinet1 = clsBankClient::Find(Accountnumer);
		if (!clinet1.isEmpty())
		{
			cout << "Clinet is founf :) " << endl;

		}
		else
			cout << "Account not found :(" << endl;

		_printClinet(clinet1);

	}









};