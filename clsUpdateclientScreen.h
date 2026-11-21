#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsstring.h"

using namespace std;
class clsUpdateClinetinfo : protected clsscreen
{
private :
	static void _Readclientinfo(clsBankClient& client)
	{
		cout << "\nEnter FirstName: ";
		client.FirstName = clsstring::ReadString();

		cout << "\nEnter LastName: ";
		client.LastName = clsstring::ReadString();

		cout << "\nEnter Email: ";
		client.Email = clsstring::ReadString();

		cout << "\nEnter Phone: ";
		client.Phone = clsstring::ReadString();

		cout << "\nEnter PinCode: ";
		client.PinCode = clsstring::ReadString();

		cout << "\nEnter Account Balance: ";
		client.AccountBalance = clsstring::ReadFolat();
	}
	static void _PrintUpdate(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " <<Client.FirstName;
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
static	void UpdateClinet()
	{

	if (!chekacessright(clsUser::enPermisson::pupdateclient))
	{
		return;
	}

	_DrawMainScreen("UPDATE CLIIENT INFO SCREEN");
		string Accountnumber = "";
		cout << "Please enter account number !" << endl;
		Accountnumber = clsstring::ReadString();

		while (!clsBankClient::IsClientExist(Accountnumber))
		{
			cout << "\nAccount number is not found,chose another one : \n";
			Accountnumber = clsstring::ReadString();


		}
		clsBankClient clinet1 = clsBankClient::Find(Accountnumber);
		_PrintUpdate(clinet1);
		cout << "Update client unfo\n";
		cout << "______________________\n";
		_Readclientinfo(clinet1);
		clsBankClient::enSaveResults saveResult;
		saveResult = clinet1.Save();
		switch (saveResult)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
			cout << "Account update successfuly :) \n";
			_PrintUpdate(clinet1);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "Error acount was not saved beacsue its empety :(" << endl;
			break;
		}

	}







};