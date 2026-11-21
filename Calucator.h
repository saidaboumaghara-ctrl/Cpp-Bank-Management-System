#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX

#include <windows.h>

#include <iostream>

#include "clsscreen.h"
#include "clsstring.h"
#include "clsCurency.h"

using namespace std;
using namespace std;
class clsCalculator :protected clsscreen
{
	
public:
	static void loadingBar() {
		cout << "Please wait";
		for (int i = 0; i < 5; i++) {
			Sleep(400);  // تأخير 0.2 ثانية
			cout << " .";
		}
		cout << " \n";
	}
	static void ShowCalculatorscreen()
	{
		_DrawMainScreen("CALCULATOR SCREEN");

		cout << "Please enter first country code  : " << endl;
		string code1 = clsstring::ReadString();
		while (!clsCurrency::IsCurrencyExist(code1))
		{
			cout << "Curency is not found Please try again\n";
			code1 = clsstring::ReadString();

		}
		clsCurrency curen1 = clsCurrency::FindByCode(code1);
		clsCurrency::_Print(curen1);
		cout << "Please enter secand country code  : " << endl;
		string code2 = clsstring::ReadString();
		while (!clsCurrency::IsCurrencyExist(code2))
		{
			cout << "Curency is not found Please try again\n";
			code2 = clsstring::ReadString();

		}
		clsCurrency curen2 = clsCurrency::FindByCode(code2);
		cout << endl;
		clsCurrency::_Print(curen2);
		
		

		int Rate1 = curen1.Rate();
		int Rate2 = curen2.Rate();
		float answer = float(Rate2) / Rate1;
		
		cout << "=================================="<<endl;
		cout<<" 1 ["<<curen1.CurrencyCode()<<"] =  "<< curen1.Rate()<<endl;
		cout << " 1 [" << curen2.CurrencyCode() << "] =  " << curen2.Rate() << endl;
		loadingBar();
		cout << " 1 [" << curen1.CurrencyCode() << "] = " << answer <<"[" << curen2.CurrencyCode()<<"]" << endl;








	}


};