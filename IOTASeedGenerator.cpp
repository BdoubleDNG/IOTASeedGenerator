// IOTASeedGenerator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <windows.h>
#include <string>
#include <random>
#include <iostream>
using namespace std;


int main()
{ 
	string temp = "n";
	do
	{
		char allowedChars[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','9' };
		random_device rn;
		mt19937 engine(rn());
		uniform_int_distribution<int> rand(0, 26);
		string seed = "";
		for (int i = 0; i < 81; i++)
		{
			seed += allowedChars[rand(engine)];
		}

		const char* output = seed.c_str();
		const size_t len = strlen(output) + 1;
		HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
		memcpy(GlobalLock(hMem), output, len);
		GlobalUnlock(hMem);
		OpenClipboard(0);
		EmptyClipboard();
		SetClipboardData(CF_TEXT, hMem);
		CloseClipboard();

		cout << seed << " in Zwischenablage gespeichert" << endl;
		cout << "Nochmal? y/n"<<endl;
		cin >> temp;
	} while (temp  == "y");

    return 0;
}

