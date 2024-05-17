#ifndef Global_h
#define Global_h
//Chua thong tin ve struct

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


#include "AcademicStaffs.h"
#include "Students.h"
#include "LoginSystem.h"





struct date
{
	int day, month, year;
};

//struct thong tin User khi dang nhap vao, dung chung cho student va academicstaff
struct User
{
	string id;
	string password;
	string firstName;
	string lastName;
	string gender;
	string className;
	int academicYear;//Nam 1, nam 2,... neu la AcademicStaff thi khong co
	bool isStaff;
	date dateOfBirth;
};

struct nodeUser
{
	User info;
	nodeUser* pNext;
};

struct listUser
{
	nodeUser* pHead;
	nodeUser *pTail;
};

//struct mon hoc

struct course
{
	string id;
	string courseName;
	string teacherName;
	string numberOfCredits;//So tin chi
	const int maximunNumberOfStudent = 50;
	string dayOfWeek;//MON, WED, THU, ... 
	string session;//S1, S2, S3, S4
};

struct nodeCourse
{
	course info;
	nodeCourse* pNext;
};

struct listCourse
{
	nodeCourse* pHead;
	nodeCourse* pTail;
};

//Struct diem, chua biet su dung de lam gi
struct courseMark
{
	float otherMark = 0;
	float midtermMark = 0;
	float finalMark = 0;
	float totalMark = 0;
};

struct semesterMark
{
	float GPA = 0;
	float overallGPA = 0;
};


//struct thong tin sinh vien
struct Student
{
	int No;
	int studentID;
	string firstName;
	string lastName;
	string gender;
	date dateOfBirth;
	int socialID;
	listCourse enrolledCourse;//Cac mon da dang ky
	courseMark cMark;
	semesterMark sMark;
};

struct NodeStudent
{
	Student Info;
	NodeStudent* pNext;
};

struct ListStudent
{
	NodeStudent* pHead;
	NodeStudent* pTail;
};

//struct class
//Chua biet su dung nhu the nao nhung thu lam theo
struct classes
{
	string className;
	string path;	//fs:: path path;
};

struct listClass
{
	classes* pHead;
	classes* pTail;
};

void LoginAccount(string& userName, string& password);
listUser InitListUsers();
nodeUser* GetNodeUser(User info);
void AddUser(listUser& lu, nodeUser* newUser);
void ReadingUsersData(listUser& lu, string fileUsersPath);
User ConvertingUserData(string data);
nodeUser* IsUser(string userName, string password, listUser lu);//tra ve user co trong danh sach, neu la null nghia la ko co
date ConvertingDate(string data);



#endif // !function_h

