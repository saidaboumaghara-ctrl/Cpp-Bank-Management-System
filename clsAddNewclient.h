#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsstring.h"
#include <iomanip>

using namespace std;
class clsNewclient:protected clsscreen
{
private:
	static void _Readclientinfo( clsBankClient &client)
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


public:

	static void ShoeAddNewClientScreen()
	{

		if (!chekacessright(clsUser::enPermisson::paddnewclient))
		{
			return;
		}

		_DrawMainScreen("ADD NEW CLIENT SCREEN");
		string Accounnumber = "";
		cout << "Please enter Accounnumber\n";
		Accounnumber = clsstring::ReadString();
		while (clsBankClient::IsClientExist(Accounnumber))
		{
			cout << "Account number is alerday  used ,choese another one \n";
			Accounnumber = clsstring::ReadString();


		}

		clsBankClient Newclinet = clsBankClient::GetAddNewClient(Accounnumber);
		_Readclientinfo(Newclinet);
		clsBankClient::enSaveResults saveresult;
		saveresult = Newclinet.Save();

		switch (saveresult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "Account added succesfly :)\n";
			_printClient(Newclinet);
			break;
		case clsBankClient::enSaveResults::svfaileAcoountnumberexiese:
			cout << " please try again\n";
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "Error account was not saved because its  empty\n";
			break;



		}






	}







};