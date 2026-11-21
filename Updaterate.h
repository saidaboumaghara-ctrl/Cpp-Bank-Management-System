#pragma once
#include<iostream>
#include"clsscreen.h"
#include"clsstring.h"
#include"clsCurency.h"
class clsUpdateRate :protected clsscreen
{
	static void PleaseEnterCode()
	{

}




public:
	static void ShowUpdateRatescreen()
	{
		_DrawMainScreen("UPDATE RATE SCREEN");

		cout << "Please enter a Country code ?" << endl;
		string code = clsstring::ReadString();
		while(!clsCurrency::IsCurrencyExist(code))
		{
			cout << "Curency is not found Please try again\n";
			code = clsstring::ReadString();

		}
		clsCurrency curen1 = clsCurrency::FindByCode(code);
		clsCurrency::_Print(curen1);
		cout << "Are you sure do you want update ?[y\\n]" << endl;
		char answer='n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "Update curency rate \n";
			cout << "=====================\n";

			cout << "Please enter a new rate\n";
			float Rate = clsstring::ReadFolat();
			curen1.UpdateRate(Rate);

			cout << "Sytsem is :)" << endl;
			clsCurrency::_Print(curen1);




		}













	}


};