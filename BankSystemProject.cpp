#include <iostream>
#include"clslogin.h"
#include<iomanip>



using namespace std;

int main()
{
	system("color F0");
	while (true)
	{
		if(!clsloginscreen::showloginscreen())
		{
			break;
		}

	}


}

