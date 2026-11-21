#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

using namespace std;
class clsclientlist :protected clsscreen
{


public:
	static void showclinetlist()
	{
		if(!chekacessright(clsUser::enPermisson::plistclients))
		{
			return;
		}


		vector<clsBankClient> vclients = clsBankClient::Getclinetlist();

		cout <<setw(115) <<"CLINET LIST (" << vclients.size() << ")\n";
		_DrawMainScreen("CLINET LIST");
		int pedding = 25;
		cout << setw(pedding) << " ";
		cout <<  "=====================================================================================================================================\n\n";
		cout << setw(pedding) << " ";
		cout <<  "|" << left << setw(18) << "Account Number";
		cout <<  "|" << left << setw(25) << "Clinet Name";
		cout << "|" << left << setw(18) << "Phone";
		cout <<  "|" << left << setw(30) << "Email";
		cout <<  "|" << left << setw(18) << "Pin code";
		cout <<  "|" << left << setw(18) << "Blanace";
		cout <<  "|\n";
		cout << setw(pedding) << " ";
		cout <<  "======================================================================================================================================\n";


		if (vclients.size() == 0)
		{
			cout << "\t\t\tNO CLIENTS IN THE SYSTEM\n";
			return;
		}

		for (clsBankClient Clinet : vclients)
		{
			clsBankClient::PrintClinetRecordLine(Clinet);
			cout << endl;
		}
	};
};