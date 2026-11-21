#pragma once
#include <iostream>
#include "Global.h"
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;
class clsscreen 
{
public:
	static void _Date()
	{
		time_t now = time(0);

		tm localTime;

		localtime_s(&localTime, &now);

		cout << localTime.tm_mday << "/"
			<< localTime.tm_mon + 1 << "/"
			<< localTime.tm_year + 1900;
	}
	static string GetDateTime()
	{
		time_t now = time(0);

		tm localTime;
		localtime_s(&localTime, &now);

		stringstream ss;

		ss << setfill('0')
			<< setw(2) << localTime.tm_mday << "/"
			<< setw(2) << localTime.tm_mon + 1 << "/"
			<< localTime.tm_year + 1900 << " "
			<< setw(2) << localTime.tm_hour << ":"
			<< setw(2) << localTime.tm_min << ":"
			<< setw(2) << localTime.tm_sec;

		return ss.str();
	}

	
protected:
	 static void _DrawMainScreen(string title)
	{
		cout << "\t\t\t\t\t\t\t\t\t_____________________________________________________________________\n";
		cout << "\t\t\t\t\t\t\t\t\t\t\t\t    "<< title <<"                                           " << "\n";
		cout << "\t\t\t\t\t\t\t\t\t_____________________________________________________________________\n\n";
		cout << "\t\t\t\t\t\t\t\t\t=====================================================================\n";


		
		cout <<"\t\t\t\t\t\t\t\t\t" <<"User :" << Currentuser11.UserName << "\n";
		cout << "\t\t\t\t\t\t\t\t\t"<< "Date : ";
		_Date();
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tSYRIAN BANK SYSTEM";
		cout << "\n";


	}

	 static bool chekacessright(clsUser::enPermisson permisson)
	 {
		 if (!Currentuser11.CheckAccessPermission(permisson))
		 {
			 int x = 125;
			 cout << setw(x) << "============================================\n";
			 cout << setw(x) << "Access denied!you dont have acess for this\n";

			 cout << setw(x) << "============================================\n";
			 return false;


		 }
		 else
			 return true;





     }
	



	 



};
