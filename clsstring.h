#pragma once
#include<iostream>
#include<string>
#include <algorithm>
#include <cctype>
#include<iomanip>
#include<vector>
using namespace std;

class clsstring
{
public:
	string _value;


	static string  EncryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey = 2)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}





public:
	clsstring()
	{
		_value = "";

	}
	clsstring(string value)
	{
		_value = value;
	}

	void Setvalue(string value)
	{
		_value = value;
	}
	string Getvalue()
	{
		return _value;

	}
	__declspec(property(get = Getvalue, put = Setvalue)) string Value;



	int CountLetters(string value)
	{
		return value.length();
	}
	int CountLetters()
	{
		return CountLetters(_value);

	}
	int CountCapitalLetters(string value)
	{
		int Counter = 0;

		for (char c : value)
		{
			if (isupper(c))
				Counter++;
		}

		return Counter;
	}
	int CountCapitalLetters()
	{
		return CountCapitalLetters(_value);
	}
	int CountSmallLetters(string value)
	{
		int Counter = 0;

		for (char c : value)
		{
			if (islower(c))
				Counter++;
		}

		return Counter;
	}
	int CountSmallLetters()
	{
		return CountSmallLetters(_value);
	}
	int CountSpaces(string value)
	{
		int Counter = 0;

		for (char c : value)
		{
			if (c == ' ')
				Counter++;
		}

		return Counter;
	}
	int CountSpaces()
	{
		return CountSpaces(_value);
	}
	int CountDigits(string value)
	{
		int Counter = 0;

		for (char c : value)
		{
			if (isdigit(c))
				Counter++;
		}

		return Counter;
	}
	int CountDigits()
	{
		return  CountDigits(_value);
	}
	int CountSpecialCharacters(string value)
	{
		int Counter = 0;

		for (char c :value )
		{
			if (!isalnum(c) && c != ' ')
				Counter++;
		}

		return Counter;
	}
	int CountSpecialCharacters()
	{

		return CountSpecialCharacters(_value);
	}
	static string UpperAllString(string value)
	{
		for (char& c : value)
		{
			c = toupper(c);
		}

		return value;
	}
	static vector<string> Split(string S1, string Delim) {
		vector<string> vString;
		short pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != string::npos) {
			sWord = S1.substr(0, pos);
			if (sWord != "") {
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "") {
			vString.push_back(S1);
		}

		return vString;
	}

	static float ReadFolat()
	{
		float Num = 0;
		cin >> Num;
		return Num;


	}

	static string ReadString()
	{
		string s1 = "";
		getline(cin >> ws, s1);

			return s1;

	}

	string UpperAllString()
	{
		return UpperAllString(_value);

	}
	string LowerAllString(string value)
	{
		for (char& c : value)
		{
			c = tolower(c);
		}

		return value;
	}
	string LowerAllString()
	{

		return LowerAllString(_value);
	}
	string UpperFirstLetterOfEachWord(string value)
	{
		bool IsFirstLetter = true;

		for (char& c : value)
		{
			if (c != ' ' && IsFirstLetter)
			{
				c = toupper(c);
				IsFirstLetter = false;
			}

			if (c == ' ')
				IsFirstLetter = true;
		}

		return value;
	}
	string UpperFirstLetterOfEachWord()
	{
		
		return  UpperFirstLetterOfEachWord(_value);
	}
	string LowerFirstLetterOfEachWord(string value)
	{
		bool IsFirstLetter = true;

		for (char& c : value)
		{
			if (c != ' ' && IsFirstLetter)
			{
				c = tolower(c);
				IsFirstLetter = false;
			}

			if (c == ' ')
				IsFirstLetter = true;
		}

		return value;
	}
	string LowerFirstLetterOfEachWord()
	{
		
		return LowerFirstLetterOfEachWord(_value);
	}
	string ReverseString(string value)
	{
		reverse(value.begin(), value.end());
		return value;
	}
	string ReverseString()
	{
		
		return ReverseString(_value);
	}
	string RemoveSpaces(string value)
	{
		string Result = "";

		for (char c : value)
		{
			if (c != ' ')
				Result += c;
		}

		return Result;
	}
	string RemoveSpaces()
	{
		

		return RemoveSpaces(_value);
	}
	int CountWords(string value)
	{
		int Counter = 0;
		bool InsideWord = false;

		for (char c : value)
		{
			if (c != ' ' && !InsideWord)
			{
				Counter++;
				InsideWord = true;
			}

			if (c == ' ')
				InsideWord = false;
		}

		return Counter;
	}
	int CountWords()
	{

		return CountWords(_value);
	}
	bool HasDigit(string value)
	{
		for (char c : value)
		{
			if (isdigit(c))
				return true;
		}

		return false;
	}
	bool HasDigit()
	{
		return HasDigit(_value);
	}
	bool HasCapitalLetter(string value)
	{
		for (char c : value)
		{
			if (isupper(c))
				return true;
		}

		return false;
	}
	bool HasCapitalLetter()
	{
		
		return HasCapitalLetter(_value);
	}
	int CountLetter(string value, char Letter)
	{
		int Counter = 0;

		for (char c : value)
		{
			if (c == Letter)
				Counter++;
		}

		return Counter;
	}
	int CountLetter( char Letter)
	{
		
		return CountLetter(_value,Letter);
	}
	int CountWord(string value, string Word)
	{
		int Counter = 0;
		size_t Position = 0;

		while ((Position = value.find(Word, Position)) != string::npos)
		{
			Counter++;
			Position += Word.length();
		}

		return Counter;
	}
	int CountWord(string Word)
	{
		
		return CountWord(_value,Word);
	}
	string RemoveLetter(string value, char Letter)
	{
		string Result = "";

		for (char c : value)
		{
			if (c != Letter)
				Result += c;
		}

		return Result;
	}
	string RemoveLetter( char Letter)
	{
		

		return RemoveLetter(_value,  Letter);
	}
	string ReplaceLetter(string value, char OldLetter, char NewLetter)
	{
		for (char& c : value)
		{
			if (c == OldLetter)
				c = NewLetter;
		}

		return value;
	}
	string ReplaceLetter( char OldLetter, char NewLetter)
	{
		

		return ReplaceLetter(_value, OldLetter, NewLetter);
	}
	static string NumberToWords(long long number) // استخدمنا long long ليدعم المبالغ الكبيرة جداً
	{
		if (number == 0) {
			return "Zero";
		}

		if (number < 0) {
			return "Minus " + NumberToWords(-number);
		}

		// مصفوفة الآحاد والأرقام حتى 19 مدمجة معاً لتبسيط المنطق
		static const string ones[] = {
			"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
			"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
			"Seventeen", "Eighteen", "Nineteen"
		};

		static const string tens[] = {
			"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
		};

		string result = "";

		// 1. معالجة المليارات (Billions)
		if (number >= 1000000000) {
			result += NumberToWords(number / 1000000000) + " Billion";
			if (number % 1000000000 > 0) {
				result += " " + NumberToWords(number % 1000000000);
			}
		}
		// 2. معالجة الملايين (Millions)
		else if (number >= 1000000) {
			result += NumberToWords(number / 1000000) + " Million";
			if (number % 1000000 > 0) {
				result += " " + NumberToWords(number % 1000000);
			}
		}
		// 3. معالجة الآلاف (Thousands) -> هنا سيتم معالجة الـ 15,000
		else if (number >= 1000) {
			result += NumberToWords(number / 1000) + " Thousand";
			if (number % 1000 > 0) {
				result += " " + NumberToWords(number % 1000);
			}
		}
		// 4. معالجة المئات (Hundreds)
		else if (number >= 100) {
			result += ones[number / 100] + " Hundred";
			if (number % 100 > 0) {
				result += " " + NumberToWords(number % 100);
			}
		}
		// 5. معالجة العشرات (Twenty, Thirty...)
		else if (number >= 20) {
			result += tens[number / 10];
			if (number % 10 > 0) {
				result += " " + ones[number % 10];
			}
		}
		// 6. معالجة الأرقام من 1 إلى 19
		else {
			result += ones[number];
		}

		return result;
	}

	static  int ReadShortnumberbetween(short X, short Y,string massege)
	{
		
		int choice;
		cout << setw(86) << "Enter Choice: ";
		cin >> choice;
		if (choice >= X && choice <= Y)
		{
			return choice;


		}
		else
			cout << massege;
		

	}

//Eng:said abou maghara 07.07.2026
};