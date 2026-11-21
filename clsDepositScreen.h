#pragma once
#include <iostream>
#include"clsscreen.h"
#include"clsstring.h"
using namespace std;
class clsDepsitscreen :protected clsscreen
{
	static void _printClient(clsBankClient Client)
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
	static string _ReadAccountnumber()
	{
		cout << "Please enter  account number" << endl;
		return  clsstring::ReadString();

		
	}





public:
	static void showDepositscreen()
	{
		_DrawMainScreen("DEPOSIT SCREEN");
		string Accountnumber = _ReadAccountnumber();
		while (!clsBankClient::IsClientExist(Accountnumber))
		{
			cout << "clinet with [" << Accountnumber << "] does not exits \n";
			
		}
		clsBankClient client = clsBankClient::Find(Accountnumber);
		_printClient(client);
		double Amount = 0;
		cout << "Pleaase enter deposit amount ?\n";
		Amount = clsstring::ReadFolat();
		cout << "Are sure ?[Y\\N]\n";
		char chose = 'n';
		cin >> chose;
		if (chose == 'Y' || chose == 'y')
		{
			client.Deposit(Amount);
			cout << "Amount Deposited successfully\n";
			cout << "New Blanace is :" << client.AccountBalance;

		}
		else
			cout << "canseled\n";






	};





};