#include <iostream>
#include <string>
using namespace std;

const char* szSampleString[50] = "ABCDEFGHIJKLMNOPQRSTUVXYABCDEFGHIJKLMNOPQRSTUVXY";

char DoiXung(char source_ch, char ch)
{
	char kytu = (char) toupper((int) source_ch);
	
}

int main()
{
	char character;
	string szOldString, szNewString;
	cin >> szOldString;
	cin >> character;
	for (int count = 0; count < szOldString.length(); count++)
	{
		if ((szOldString[count] >= 'A' && szOldString[count] <= 'Z') || (szOldString[count] >= 'a' && szOldString[count] <= 'z'))
			szNewString.push_back(DoiXung(szOldString[count], character));
		szNewString.push_back(szOldString[count]);
	}
	cout << szNewString << endl;
	return 0;
}