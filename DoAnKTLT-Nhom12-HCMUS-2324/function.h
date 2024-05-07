#ifndef function_h
#define function_h

#include <iostream>
#include <string>
using namespace std;

struct date
{
	int day, month, year;
};

struct taiKhoan
{
	string nickName, password;
};




struct sinhVien
{
	string firstName, lastName;
	taiKhoan tk;
	int no, MSSV;
	date birth;
	int gender;
	long long socialID;
	string cls;
	int semester, schoolYear;
};

struct nodeSinhVien
{
	sinhVien info;
	nodeSinhVien* next;
};

struct ListSinhVien
{
	nodeSinhVien* pHead,* pTail;
};

struct giangVien
{
	string nickName;
	string passWord;
	int no, MSSV;
	date birth;
	int gender;
	long long socialID;
	string firstName, lastName;
};






#endif // !function_h

