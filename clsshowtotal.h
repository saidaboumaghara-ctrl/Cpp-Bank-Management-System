#pragma once
#include <iostream>
#include"clsscreen.h"
#include<iomanip>
#include<vector>
#include"clsstring.h"
using namespace std;
class clstotalblance :protected clsscreen
{
	static void _printClient(clsBankClient Client)
	{

		cout << setw(72) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(30) << left << Client.AccountBalance;

	}
   





public:
	static void  showTotalBlancescreen()
	{
		_DrawMainScreen("TOTAL BLANCE");

		int TotalBalance = 0;
		vector<clsBankClient>vclient = clsBankClient::Getclinetlist();
		cout << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";
		cout << setw(85) << "" << "\t\tTotal Balances List\n";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";

		cout << setw(72) << "" << left
			<< "| " << setw(15) << "Account Number"
			<< "| " << setw(40) << "Client Name"
			<< "| " << setw(8) << "Balance"
			<< "|\n";

		cout << setw(72) << ""
			<< "--------------------------------------------------------------------------\n";

		if (vclient.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vclient)
			{
				_printClient(Client);
				cout << endl;
			}


		for (int i = 0; i < vclient.size(); i++)
		{

			TotalBalance += vclient[i].GetAccountBalance();
			
		}
	




	
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t \t\t\t\t\t\t\t\t\t       TOTAL BALANCE IS : " << TotalBalance << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  \t\t\t\t\t\t\t\t\t     (" << clsstring::NumberToWords(TotalBalance) << ")";
	}

	



};