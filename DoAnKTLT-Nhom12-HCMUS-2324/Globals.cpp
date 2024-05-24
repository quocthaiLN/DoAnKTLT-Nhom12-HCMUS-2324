﻿#include "Globals.h"

// Đường dẫn thư mục semester để lưu các khóa học có trong kỳ đó
string semesterPath;

nodeUser* LoginAccount()
{
	string userName, password;
	cout << setw(15) << left << "User name/ ID" << ":";
	cin >> userName;
	cout << setw(15) << left << "Password" << ":";
	cin >> password;
	User p;
	p.id = userName;
	p.password = password;
	nodeUser* q = GetNodeUser(p);
	return q;
}//chinh lai tra ve User

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
		info.isStaff = true;
	}
	else
	{
		info.isStaff = false;
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

nodeUser* IsUser(nodeUser* data, listUser lu)
{
	nodeUser* p = lu.pHead;
	while (p != NULL)
	{
		if (data->info.id == p->info.id)
		{
			if (data->info.password == p->info.password)
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

// Lấy ngày hiện tại 
date GetCurDate() {
	time_t t = time(nullptr);

	tm* now = localtime(&t);

	date curDate;
	curDate.day = now->tm_mday;
	curDate.month = now->tm_mon + 1;	
	curDate.year = now->tm_year + 1900;

	return curDate;
}

// Niên khóa, năm học
void GetCurSchoolYear(string &curSchoolYear, date curDate) {
	// Lấy tháng bắt đầu năm học cố định là tháng 9
	const int openingMonth = 9;

	// Nếu tháng hiện tại mà nhỏ hơn tháng 9
	if (curDate.month < openingMonth) {
		// Niên khóa sẽ là: năm hiện tại-1 -> năm hiện tại, vd: 2023 - 2024
		curSchoolYear = to_string(curDate.year - 1) + '-' + to_string(curDate.year);
	}// Nếu tháng hiện tại mà lớn hơn hoặc bằng 9
	else {
		// Năm học sẽ bắt đầu là năm hiện tại cho đến năm hiện tại + 1, vd: 2024 - 2025
		curSchoolYear = to_string(curDate.year) + '-' + to_string(curDate.year + 1);
	}
}

// Hàm đổi chuỗi thành ngày
date strToDate(string day) {
	date _date;
	_date.day = 0;
	_date.month = 0;
	_date.year = 0;
	// Số lần gặp dấu '/'
	int numSlash = 0;
	for (int i = 0; i < day.length(); i++) {
		if (day[i] == '/') numSlash++;
		else if (numSlash == 0) {
			_date.day = _date.day * 10 + (day[i] - '0');
		}
		else if (numSlash == 1) {
			_date.month = _date.month * 10 + (day[i] - '0');
		}
		else if (numSlash == 2) {
			_date.year = _date.year * 10 + (day[i] - '0');
		}
	}

	return _date;
}

// Hàm lấy kỳ học hiện tại
void GetCurSemester(Semester& curSemester) {
	string schoolYear;
	GetCurSchoolYear(schoolYear, GetCurDate());
	// Lấy path có dạng thư mục Data \\ thư mục niên khóa \\ file semester.dat
	const string path = "Data\\" + schoolYear + "\\semester.dat";

	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open()) {
		cout << "File semester.dat khong ton tai" << endl;
		return;
	}

	ifs >> curSemester.semester;
	string begSemes, endSemes;
	ifs.ignore();
	getline(ifs, begSemes);
	getline(ifs, endSemes);

	if (begSemes.empty() || endSemes.empty()) {
		curSemester.semester = 0;
		curSemester.begin = strToDate("0/0/0");
		curSemester.end = strToDate("0/0/0");
	}
	else {
		curSemester.begin = strToDate(begSemes);
		curSemester.end = strToDate(endSemes);
		// Lưu Thư mục semester path để sau này lưu các khóa học trong kỳ này
		semesterPath = "\\Data" + schoolYear + "\\ semester " + to_string(curSemester.semester);
	}

	ifs.close();
}
 //ham convert thong tin khoa hoc 
course* convertingCourse(ifstream& ifs)
{
	course* cou = new course;
	string maxNumStudent;
	if (ifs.eof())
	{
		return NULL;
	}
	getline(ifs, cou->id, ',');
	getline(ifs, cou->courseName, ',');
	getline(ifs, cou->teacherName, ',');
	getline(ifs, cou->numberOfCredits, ',');
	//vi so luong hoc sinh max = 50 nen chi can get cho qua di thong tin k can luu lai vao course
	getline(ifs, maxNumStudent, ',');
	getline(ifs, cou->dayOfWeek, ',');
	getline(ifs, cou->session,'\n');
	return cou;
}
//tao mot node course moi 
nodeCourse* createNodeCourse(course* c1)
{
	nodeCourse* nc = new nodeCourse;
	if (c1 == NULL)
		return NULL;
	nc->info = c1;
	nc->pNext = NULL;
	return nc;
}
// ham them mot node course vao list
void addCourse(listCourse& lc, course* c1)
{
	nodeCourse* nc = createNodeCourse(c1);
	if (lc.pHead == NULL)
	{
		lc.pHead = lc.pTail = nc;
		return;
	}
	lc.pTail->pNext = nc;
	lc.pTail = nc;
	lc.pTail->pNext = NULL;
}
// 
void getListCourse(listCourse& lc)
{
	lc.pHead = lc.pTail = NULL;
	string path = semesterPath + "/course.csv";
	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open())
	{
		cout << "Mo file that bai!\n";
		return;
	}
	string line;
	getline(ifs, line);
	while (!ifs.eof())
	{
		addCourse(lc, convertingCourse(ifs));
	}
	ifs.close();
}
//in thong tin trong profile
void printInformationOfUser(User us)
{
	cout << "Last Name: " << us.lastName << endl;
	cout << "First Name: " << us.firstName << endl;
	cout << "Gender: " << us.gender << endl;
	if (us.isStaff == false)
	{
		cout << "Class Name: " << us.className << endl;
		cout << "Academic Year: " << us.academicYear << endl;
	}
	cout << "Date of Birth: " << us.dateOfBirth.day << "/" << us.dateOfBirth.month << "/" << us.dateOfBirth.year << endl;
}
//ham doi mat khau o phan account
void changePassword(User& us)
{
	string tmp(us.password);
	cout << "Nhap vao mat khau hien tai: ";
	cin >> us.password;
	while (tmp != us.password)
	{
		cout << "Nhap sai mat khau yeu cau nhap lai!\n";
		cin >> us.password;
	}
	cout << "Nhap vao mat khau moi: ";
	cin >> us.password;
}
// ham log out
//void logout(listUser lu)
//{
//	nodeUser* curUser = LoginAccount();
//	if (IsUser(curUser , lu) == NULL)
//	{
//		cout << "TAI KHOAN VUA NHAP KHONG TON TAI !!!\n\n";
//		LoginAccount(id, password);
//	}
//}
//ham hien thi thong tin school year
void printSchoolYearInformation(User us)
{
	date curDate = GetCurDate();
	string curSchoolYear;
	//lay school year
	GetCurSchoolYear(curSchoolYear, curDate);
	cout << "School Year: " << curSchoolYear << endl;
	//star
}
//ham doi ngay bat dau nam hoc
void changeDateStartSchoolYear(User us)
{
	if (us.isStaff == true)
	{
		Semester s;
		GetCurSemester(s);
		date d;
		string dateChange;
		cout << "Current Date: " << endl;
		cout << "Change Date: ";
		cin >> dateChange;
		s.begin = strToDate(dateChange);
	}
}
