#include "Globals.h"

void LoginAccount(string& userName, string& password)
{
	cout << setw(15) << left << "User name/ ID" << ":";
	cin >> userName;
	cout << setw(15) << left << "Password" << ":";
	cin >> password;
}

