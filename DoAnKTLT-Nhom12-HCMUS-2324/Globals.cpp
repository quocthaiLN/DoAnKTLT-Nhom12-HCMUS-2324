#include "Globals.h"


void LoginAccount(string& userName, string& password)
{
	cout << setw(15) << left << "User name/ ID" << ":";
	cin >> userName;
	cout << setw(15) << left << "Password" << ":";
	cin >> password;
}

listUser InitListUsers()
{
	listUser lu;
	lu.pHead = NULL;
	lu.pTail = NULL;
	return lu;
}

nodeUser* GetNodeUser(User info)
{
	nodeUser* p = new nodeUser;
	if (p == NULL)
	{
		return NULL;
	}
	p->info = info;
	p->pNext = NULL;
	return p;
}

void AddUser(listUser& lu, nodeUser* newUser)
{
	if (newUser == NULL)
	{
		return;
	}
	else if (lu.pHead == NULL)
	{
		lu.pHead = lu.pTail = newUser;
	}
	else
	{
		lu.pTail->pNext = newUser;
		lu.pTail = newUser;
	}
}

void ReadingUsersData(listUser& lu, string fileUsersPath)
{
	ifstream ifs;
	ifs.open(fileUsersPath);
	if (ifs.is_open() == false)
	{
		cout << "Can not reading user data file!!!" << endl;
		return;
	}
	string lineData;
	getline(ifs, lineData);
	while (ifs.good())
	{
		getline(ifs, lineData);
		User info = ConvertingUserData(lineData);
		nodeUser* newUser = GetNodeUser(info);
		AddUser(lu, newUser);
	}
	ifs.close();

}

User ConvertingUserData(string data)
{
	User info;
	stringstream SSdata(data);

	getline(SSdata, info.id, ',');

	getline(SSdata, info.password, ',');
	
	getline(SSdata, info.lastName, ',');

	getline(SSdata, info.firstName, ' ');

	getline(SSdata, info.className, ',');

	getline(SSdata, info.gender, ',');

	string temp;
	getline(SSdata, temp, ',');
	info.dateOfBirth = ConvertingDate(temp);

	getline(SSdata, temp, ',');
	info.academicYear = stoi(temp);

	getline(SSdata, temp, ',');
	if (temp == "True")
	{
		info.isStaff == true;
	}
	else
	{
		info.isStaff == false;
	}

	return info;

}

date ConvertingDate(string data)
{
	date day;
	stringstream SSdata(data);

	string temp;
	getline(SSdata, temp, '/');
	day.day = stoi(temp);

	getline(SSdata, temp, '/');
	day.month = stoi(temp);

	getline(SSdata, temp, '/');
	day.year = stoi(temp);

	return day;
}

nodeUser* IsUser(string userName, string password, listUser lu)
{
	nodeUser* p = lu.pHead;
	while (p != NULL)
	{
		if (userName == p->info.id)
		{
			if (password == p->info.password)
			{
				return p;
			}
			else
			{
				return NULL;
			}
		}
		p = p->pNext;
	}
	return NULL;
}
