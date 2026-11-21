#pragma once
#include <iostream>
#include"clsscreen.h"
#include"clsstring.h"
using namespace std;
class clswithdrawscreen :protected clsscreen
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
	static void showWithdrawscreen()
	{


		


		_DrawMainScreen("WITHDRAW SCREEN");
		string Accountnumber = _ReadAccountnumber();
		while (!clsBankClient::IsClientExist(Accountnumber))
		{
			cout << "clinet with [" << Accountnumber << "] does not exits \n";
			break;
		}
		clsBankClient client = clsBankClient::Find(Accountnumber);
		_printClient(client);
		double Amount = 0;
		cout << "Pleaase enter withdraw amount ?\n";
		Amount = clsstring::ReadFolat();
		cout << "Are sure ?[Y\\N]\n";
		char chose = 'n';
		cin >> chose;
		if (chose == 'Y' || chose == 'y')
		{
			client.withdraw(Amount);
			cout << "Amount Deposited successfully\n";
			cout << "New Blanace is :" << client.AccountBalance;

		}
		else
			cout << "canseled\n";






	};





};