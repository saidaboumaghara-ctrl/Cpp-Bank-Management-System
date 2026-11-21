#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
using namespace std;
class clsDeleteClient : protected  clsscreen
{
private:
	static void _PrintDeleteClinet(clsBankClient Client)
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
	static void DeleteClient()
	{

		if (!chekacessright(clsUser::enPermisson::pdeleteclient))
		{
			return;
		}



		clsscreen::_DrawMainScreen("DELETE CLINET SCREEN");
		string Accountnumber = "";
		cout << "Please enter Account number\n";
		Accountnumber = clsstring::ReadString();
		while (!clsBankClient::IsClientExist(Accountnumber))
		{
			cout << "\nAccount number is not found,chose another one : \n";
			Accountnumber = clsstring::ReadString();


		}


		clsBankClient clinet2 = clsBankClient::Find(Accountnumber);
		_PrintDeleteClinet(clinet2);
		char answer = 'N';
		cout << "Are sure to delete Account ??[Y\\N]" << endl;
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (clinet2.Delete())
			{
				cout << "Clinet Deleted succsefly :) \n";
				_PrintDeleteClinet(clinet2);


			}
			else
				cout << "error clinet was not deleted\n";

		}




	}











};