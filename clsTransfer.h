#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsstring.h"
#include <iomanip>
#include"clsBankClient.h"
using namespace std;
class clsTransfer:clsscreen
{


	static void _print(clsBankClient &clinet)
	{
		cout << "                CLIENT CARD \n";
		cout << "=============================================\n";
		cout << "Clinet Accountnumber :" << clinet.AccountNumber() << endl;
		cout << "Clinet Full Name :" << clinet.FullName()<<endl;
		cout << "Clinet Blance :" << clinet.AccountBalance << endl;

		cout << "=============================================\n";

	}
	



public:
	static void ShowTransferScreen()
	{
		_DrawMainScreen("TRANSFER SCREEN");
		cout << "Please enter account number to transfer \n";
		string wAccountnumber = clsstring::ReadString();
		while (!clsBankClient::IsClientExist(wAccountnumber))
		{
			cout << "Acount number is not here plase try again \n";
			wAccountnumber = clsstring::ReadString();


		}
		clsBankClient clinet1=clsBankClient::Find(wAccountnumber);
		
		_print(clinet1);
		cout << "Please enter amount !\n ";
		float amount = clsstring::ReadFolat();

		cout << "Please enter account number to destional \n";
		string dAccountnumber = clsstring::ReadString();
		while (!clsBankClient::IsClientExist(dAccountnumber))
		{
			cout << "Acount number is not here plase try again \n";
			dAccountnumber = clsstring::ReadString();


		}
		clsBankClient clinet2 = clsBankClient::Find(dAccountnumber);
		_print(clinet2);
		clinet1.transfer(amount, clinet2);
		cout << "After : \n";
		_print(clinet1);
		cout << endl;
		_print(clinet2);
	}











};