﻿#pragma once

//KHAI BÁO THƯ VIỆN
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <filesystem>
using namespace std;
//namespace fs = std::filesystem;


//KHAI BÁO CÁC ĐƯỜNG DẪN FILE VÀ CHUỖI CẦN THIẾT
extern string headerUserFile;
extern string userPath;
extern string semesterPath;
extern string schoolYearPath;

//KHAI BÁO CÁC CÂU TRÚC
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
	date dateOfBirth;
	int academicYear;//Nam 1, nam 2,... neu la AcademicStaff thi khong co
	bool isStaff;

};

struct nodeUser
{
	User info;
	nodeUser* pNext;
};

struct listUser
{
	nodeUser* pHead;
	nodeUser* pTail;
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
	course* info;
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
	int academicYear; // Năm học, 2021, 2022, ...
	string program; // Hệ học : đại trà, clc, ...
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
	filesystem::path path;	//fs:: path path;
	classes* next;
};

struct listClass
{
	classes* pHead;
	classes* pTail;
	int size;
};

struct Semester {
	int semester;
	date begin;
	date end;
};


//kHAI BÁO TÊN VÀ THAM SỐ CÁC HÀM
//THÁI
nodeUser* LoginAccount();
void actionAcademicStaff(User& info, listUser& lu);
//void ActionLogin(string& userName, string& password);
listUser InitListUsers();
nodeUser* GetNodeUser(User info);
void AddUser(listUser& lu, nodeUser* newUser);
void ReadingUsersData(listUser& lu, string fileUsersPath);
User ConvertingUserData(string data);
nodeUser* IsUser(nodeUser* data, listUser lu);
//tra ve user co trong danh sach, neu la null nghia la ko co
date ConvertingDate(string data);
void CopyFile(string src, string dest);
void CreateDirectory(string filePath);
void CreatingNewSchoolYear(string schoolYear, string firstYearPath);
string GetPreviousSchoolYear(string schoolYear);
void Profile(User info);
void PrintDate(date d);
void ChangePassword(User& info, listUser& lu);
void WritingUserData(listUser lu, string fileUsersPath);
void returnMenuActionAcademicStaff(User& info, listUser& lu);
void clearScreen();

//HỮU THẮNG
date GetCurDate();
void GetCurSchoolYear(string& curSchoolYear, date curDate);
//int to_date(string day);
void GetCurSemester(Semester& curSemester);
date strToDate(string day);
//void initClass(listClass& list);
//void getListClasses(string year, listClass& list);
//void addClass(listClass& list, classes* course);
//void writeFileClass(string path, ListStudent listSt);
//void initList(ListStudent& list);
//NodeStudent* convertStudentData(ifstream& ifs);
void addStudent(ListStudent& list, Student st);
//void removeStudent(ListStudent& list, NodeStudent* student);
//string studentYear(int year);


void menuAcademicStaff();
void menuUserAccount();
void menuProfile();
void menuManageStudent();
void menuManageCourses();
void menuStudent();
void menuStudentUserAccount();
void menuStudentProfile();
void menuCoursesRegis();



void createClass(const string src, string& dest);
void createSemester(listCourse& list);
void addCourseToFile(listCourse& list, course* c1);
void DisplayCourse(listCourse list);
void ChangeCourse(listCourse& list, nodeCourse* changedCourse);
void RemoveCourse(listCourse& list, nodeCourse* removedCourse);
void DisplayListEnrolledStudents(course enrolledCourse);


//QUANG THẮNG
course* convertingCourse(ifstream& ifs);
void addCourse(listCourse& lc, course* c1);
void getListCourse(listCourse& lc);
void printInformationOfUser(User us);
void changePassword(nodeUser*& us);
void logout(listUser lu);
void printSchoolYearInformation(User us);
void changeDateStartSchoolYear(User us);
void createFileListStudentInCourse();
//void addCourseToSemester(Semester s, course* c);
void addStudentToCourse(Student* s, course* c);
void addNodeStudent(ListStudent& list, NodeStudent* nS);
void exportStudentFromCourseToFile(ListStudent& list, course* c);
void importScoreBoard(ListStudent& list, nodeCourse* c);
void displayScoreBoardOfCourse(nodeCourse* c);



