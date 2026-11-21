#pragma once
#include<iostream>
#include"clsperson.h"
#include <fstream>
#include<vector>
#include<iomanip>
using namespace std;

class clsBankClient : public clsperson
{
private :
	enum enMode {Emptymode=0,Updatemode=1,Addnewmode=2};
	enMode _Mode;
	string _AccountNumber;
	string _pincode;
	float _AccountBalance;
	bool _markforDelete = false;
	static clsBankClient _LineToOpejet(string line, string sperator = "#//#")
	{
		vector<string>vclintdata;
		vclintdata = clsstring::Split(line, sperator);
		return clsBankClient(enMode::Updatemode, vclintdata[0], vclintdata[1], vclintdata[2],
			vclintdata[3], vclintdata[4], vclintdata[5], stod(vclintdata[6]));


	}


	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#")
	{
		string TransferLogRecord = "";

		TransferLogRecord += _AccountNumber + Seperator;
		TransferLogRecord += DestinationClient._AccountNumber + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += UserName + Seperator;
		TransferLogRecord += clsscreen::GetDateTime();

		return TransferLogRecord;
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::Emptymode, "", "", "", "", "", "", 0);

	}
	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // وضع الكتابة ومسح القديم

		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient C : vClients)
			{
				Line = _ConverClientObjectToLine(C);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}
	static void _SaveClientsDataToFile2(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // وضع الكتابة ومسح القديم
		string Dataline;
		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C._markforDelete== false)
				{
					Dataline = _ConverClientObjectToLine(C);
					MyFile << Dataline << endl;


                }

			}




			MyFile.close();
		}
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
		
		;

	}
	 

	void _Transferlogweiter(float amount, clsBankClient client, string username)
	{
		string dataline = _PrepareTransferLogRecord(amount, client, username);

		fstream File;
		File.open("TransferLog.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << dataline << endl;

			File.close();

		}
	}
public :
	clsBankClient(enMode Mode,string FirstName,string LastName,string Email,
	string Phone,string AccountNumber,string Pincode,float AccountBalance):clsperson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_AccountNumber=AccountNumber;
		_pincode = Pincode;
		_AccountBalance=AccountBalance;


	}

	bool isEmpty()
	{
		return (_Mode == enMode::Emptymode);

	}
	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string pincode)
	{
		_pincode = pincode;


	}
	string GetPinCode()
	{
		return _pincode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	/*
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		clsperson::print();
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _pincode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}
	*/
	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);
		return stClientRecord;
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;
		fstream myfile;
		myfile.open("Clients.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsBankClient Client = _LineToOpejet(line);

				vClients.push_back(Client);

			}
			myfile.close();


			

		}

		return vClients;













	}

	void Update()
	{
		vector<clsBankClient>_vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveClientsDataToFile(_vClients);

	}
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankClient Find(string AccountNumber)
	{


		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _LineToOpejet(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClientObject();
		

	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{



		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _LineToOpejet(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}
		return _GetEmptyClientObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1,svfaileAcoountnumberexiese=2 };

	enSaveResults Save()
	{

		switch (_Mode)
		{
		case enMode::Emptymode:
		{

			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::Updatemode:
		{


			Update();

			return enSaveResults::svSucceeded;

			break;
		}
		case enMode::Addnewmode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
				return enSaveResults::svfaileAcoountnumberexiese;
			else
				_AddNew();

		}

		}



	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.isEmpty());
	}

	static clsBankClient GetAddNewClient(string Accountnumber)
	{
		return clsBankClient(enMode::Addnewmode, "", "", "", "", Accountnumber, "",0);

	}
	static vector<clsBankClient> Getclinetlist()
	{
		return _LoadClientsDataFromFile();


	}
	bool Delete()
	{
		vector<clsBankClient>_vclinets;
		_vclinets = _LoadClientsDataFromFile();
		for (clsBankClient &C :_vclinets)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._markforDelete = true;
				break;

			}

		}
		_SaveClientsDataToFile2(_vclinets);
		*this = _GetEmptyClientObject();
		return true;
	}
	static void PrintClinetRecordLine(clsBankClient client)
	{
		int pedding = 25;
		cout << setw(pedding) << " ";
		cout <<  "|" << left << setw(18) << client.AccountNumber();
		cout <<  "|" << left << setw(25) << client.FullName();
		cout <<  "|" << left << setw(18) << client.Phone;
		cout <<  "|" << left << setw(30) << client.Email;
		cout << "|" << left << setw(18) << client.PinCode;
		cout << "|" << left << setw(18) << client.AccountBalance;
		cout << "|";
	}
	bool transfer(float amount, clsBankClient& destionalclinet)
	{

		_Transferlogweiter(amount, destionalclinet,Currentuser11.UserName);
		if (amount > AccountBalance)
		{
			return false;
        }
		withdraw(amount);
		destionalclinet.Deposit(amount);
		return true;



	}
	void Deposit(double num)
	{
		_AccountBalance += num;
		Save();

	}
	void withdraw(double num)
	{
		if (_AccountBalance > num)
		{
			_AccountBalance -= num;
			Save();
		}
		else
		{
			cout << "Please enter a true number\n";
			num = clsstring::ReadFolat();
			withdraw(num);
		}
	 }
};