#include "function.h"



string headerUserFile = "ID,Password,Last name,First name,Class,Gender,Date of Birth,Academic year,Staff";
string userPath = "Data\\Accounts\\users.csv";
string semesterPath;
string schoolYearPath = "Data\\SchoolYear";


void menuAcademicStaff() {
	cout << "HCMUS PORTAL" << endl;
	cout << GetCurDate().day << "/" << GetCurDate().month << "/" << GetCurDate().year << endl;
	cout << "1. User account\n";
	cout << "2. Profile\n";
	cout << "3. Manage Student\n";
	cout << "4. Manage courses\n";
	cout << "5. Setting\n";
	cout << "0. Exit\n";

}

void menuUserAccount() {
	system("cls");
	cout << "HCMUS PORTAL" << endl;
	cout << "User Account" << endl;
	cout << "1. Change Password\n";
	cout << "2. Logout\n";
	cout << "0. Back\n";
}

void menuProfile() {
	system("cls");
	cout << "HCMUS PORTAL" << endl;
	cout << "Last Name: " << "Nguyen Van" << endl;
	cout << "First Name: " << "Tuan" << endl;
	cout << "Gender: " << "Male" << endl;
	cout << "Staff ID: " << "2312.." << endl;
	cout << "Date of Birth: " << "01/05/2024" << endl;
	cout << "Back." << endl;
}

void menuManageStudent() {
	cout << "HCMUS PORTAL" << endl;
	cout << "Manage Student\n";
	cout << "1. Create School Year\n";
	cout << "2. School Year Information\n";
	cout << "3. Create Classes\n";
	cout << "4. List of Classes\n";
	cout << "5. Back\n";
}

void menuManageCourses() {
	cout << "HCMUS PORTAL" << endl;
	cout << "Manage Courses\n";
	cout << "1. Create Semester\n";
	cout << "2. Create Registration Session\n";
	cout << "3. Add Course\n";
	cout << "4. List Of Course\n";
	cout << "5. Semester Summary\n";
	cout << "Back\n";
}

void menuStudent() {
	cout << "HCMUS PORTAL\n";
	cout << GetCurDate().day << "/" << GetCurDate().month << "/" << GetCurDate().year;
	cout <<  endl;
	cout << "1. User account\n";
	cout << "2. Profile\n";
	cout << "3. Courses registration\n";
	cout << "4. Scoreboard\n";
	cout << "5. List of classes\n";
	cout << "6. List of courses\n";
	cout << "7. Setting\n";
	cout << "8. Exit\n";
}

void menuStudentUserAccount() {
	system("cls");
	cout << "HCMUS PORTAL\n";
	cout << "User Account\n";
	cout << "1. Change Password\n";
	cout << "2. Logout\n";
	cout << "3. Back\n";
}

void menuStudentProfile() {
	system("cls");
	cout << "HCMUS PORTAL\n";
	cout << "Profile" << endl;
	cout << "1. Last name: " << "Nguyen Le Hoang" << endl;
	cout << "2. First name: " << "Dung" << endl;
	cout << "3. Gender: " << "Female" << endl;
	cout << "4. Class: " << "23CTT5A" << endl;
	cout << "5. MSSV: " << "231203..." << endl;
	cout << "6. Date of Birth: " << "01/05/2024" << endl;
	cout << "7. Back" << endl;

}

void menuCoursesRegis() {
	system("clc");
	cout << "HCMUS PORTAL\n";
	cout << "Courses Registration\n";
	cout << "1. Register Courses\n";
	cout << "2. View Enrolled Courses\n";
	cout << "3. Back" << endl;
}

void DisplayCurSchoolYear()
{
	const int openingMonth = 9;
	date d = GetCurDate();
	string str1, str2;
	GetCurSchoolYear(str1, d);
	cout << setw(30) << "Current School Year: " << str1 << endl;
	// Nếu tháng hiện tại mà nhỏ hơn tháng 9
	if (d.month < openingMonth) {
		// Niên khóa sẽ là: năm hiện tại-1 -> năm hiện tại, vd: 2023 - 2024
		str2 = to_string(d.year - 1);
	}// Nếu tháng hiện tại mà lớn hơn hoặc bằng 9
	else {
		// Năm học sẽ bắt đầu là năm hiện tại cho đến năm hiện tại + 1, vd: 2024 - 2025
		str2 = to_string(d.year) + '-' + to_string(d.year + 1);
	}
	cout << setw(30) << "Begin Day: 5/9/" << str2 << endl;
	cout << setw(30) << "End Day: 9/" << to_string(stoi(str2) + 1) << endl;
 
}

void returnMenuActionAcademicStaff(User& info, listUser& lu)
{
	int x;
	do
	{
		cout << "An phim '0' de quay ve Menu" << endl;
		cin >> x;
	} while (x != 0);
	clearScreen();
	actionAcademicStaff(info, lu);

}

void actionAcademicStaff(User& info, listUser& lu)
{
	int x, y, z;
	menuAcademicStaff();
	cout << endl;
	cout << "CHOOSE ACTION: ";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		clearScreen();
		cout << setw(30) << "ID: " << info.id << endl;
		cout << "1. Change password." << endl;
		cout << "CHOOSE ACTION: ";
		cin >> y;
		if (y == 1)
		{
			clearScreen();
			ChangePassword(info, lu);
		}
		returnMenuActionAcademicStaff(info, lu);
		break;
	}
	case 2:
	{
		Profile(info);
		returnMenuActionAcademicStaff(info, lu);
		break;
	}
	case 3:
	{
		clearScreen();
		menuManageStudent();
		cout << "CHOOSE ACTION: ";
		cin >> y;
		switch(y)
		{
		case 1:
		{
			clearScreen();
			string schoolYear, firstYearPath;
			cout << "Curren School Year (Ex: 2023-2024): ";
			cin >> schoolYear;
			cout << "New First Year Student Path: ";
			cin >> firstYearPath;
			CreatingNewSchoolYear(schoolYear, firstYearPath);
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 2:
		{
			clearScreen();
			DisplayCurSchoolYear();
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		//case 3 là tạo lớp, tạm thời bỏ làm sau
		case 4:
		{
			DisplayClassInfo();
			//Đọc file class và hiển thị lên màn hình
		}
		}
	}
	}
	return;
}

void DisplayClassInfo()
{
	int z;
	clearScreen();
	string* item;
	string SchYear, ClaYear, ClaName;
	int n;
	DisplayFilesInDirectory(schoolYearPath, item, n);
	DisplayArrString(item, n);
	cout << setw(20) << "Enter school year: ";
	cin >> z;
	SchYear = item[z - 1];
	DisplayFilesInDirectory(schoolYearPath + '\\' + SchYear + '\\' + "classes", item, n);
	DisplayArrString(item, n);
	cout << setw(20) << "Enter class year: ";
	cin >> z;
	ClaYear = item[z - 1];
	DisplayFilesInDirectory(schoolYearPath + '\\' + SchYear + '\\' + "classes" + '\\' + ClaYear, item, n);
	DisplayArrString(item, n);
	cout << setw(20) << "Enter class name: ";
	cin >> z;
	ClaName = item[z - 1];
	string path = schoolYearPath + '\\' + SchYear + '\\' + "classes" + '\\' + ClaYear + '\\' + ClaName;
	ListStudent lSt = InitListStudent();
	getListStudentInCLass(lSt, path);
	DisplayListStudent(lSt);
}

void menuClassYear()
{
	cout << "1. First-year classes.\n";
	cout << "2. Second-year classes.\n";
	cout << "3. Third-year classes.\n";
	cout << "4. Final-year classes.\n";
}

//void menuChooseClass(string source)
//{
//	string str;
//	DisplayFilesInDirectory(source);
//	cout << "Enter class name: ";
//	cin >> str;
//	//Viết 1 hàm đọc file class rồi hiển thị lên màn hình
//}

//Viết 1 hàm đọc file class rồi hiển thị lên màn hình

void DisplayFilesInDirectory(string directoryPath, string*& files, int& n) {
	n = 0; // Initialize count of files
	// Count files first to allocate memory for array
	for (const auto& entry : filesystem::directory_iterator(directoryPath)) {
			n++;
	}

	files = new string[n]; // Allocate memory for file names
	int i = 0;

	// Store file names into the array
	for (const auto& entry : filesystem::directory_iterator(directoryPath)) {
			files[i] = entry.path().filename().string();
			i++;
	}
}

void DisplayArrString(string* arrStr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << arrStr[i] << endl;
	}
}

void returnMenuActionStudent(User info, listUser lu, Student& infoSt)
{
	int x;
	do
	{
		cout << "An phim '0' de quay ve Menu" << endl;
		cin >> x;
	} while (x != 0);
	clearScreen();
	actionStudent(info, lu, infoSt);
}

void actionStudent(User& infoUs, listUser& lu, Student& infoSt)
{
	int x, y, z;
	menuStudent();
	cout << endl;
	cout << "CHOOSE ACTION: ";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		clearScreen();
		cout << setw(30) << "ID: " << infoUs.id << endl;
		cout << "1. Change password." << endl;
		returnMenuActionStudent(infoUs, lu, infoSt);
		cin >> y;
		if (y == 1)
		{
			clearScreen();
			ChangePassword(infoUs, lu);
			
		}
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 2:
	{
		Profile(infoUs);
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 3:
	{
		RegistCourse(infoSt);
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 5:
	{
		DisplayClassInfo();
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	}
	return;
}


void RegistCourse(Student& infoSt)
{
	clearScreen();
	int x, y, z, n;
	string* item, SchYear, Sem;
	DisplayFilesInDirectory(schoolYearPath, item, n);
	DisplayArrString(item, n);
	cout << setw(20) << "Enter school year: ";
	cin >> x;
	SchYear = item[x - 1];

	DisplayFilesInDirectory(schoolYearPath + '\\' + SchYear + '\\' + "semester", item, n);
	cout << setw(20) << "Enter Semester: ";
	cin >> x;
	Sem = item[x - 1];

	clearScreen();

	Semester sem;
	ReadingSemesterInfo(sem, schoolYearPath + '\\' + SchYear + '\\' + "semester" + '\\' + Sem + '\\' + "course");
	DisplaySemester(sem);


}

void DisplaySemester(Semester sem)
{
	cout << setw(20) << "Semester: " << sem.semester << endl;

	cout << setw(20) << "Start date: ";
	PrintDate(sem.begin);
	cout << endl;

	cout << setw(20) << "End date: ";
	PrintDate(sem.end);
	cout << endl;

	cout << "List Of Course In Semester: " << endl;
	DisplayCourse(sem.lC);
}

//void addStudentAccount(ListStudent& listStudent, listUser& lu) {
//	NodeStudent* tmp = listStudent.pHead;
//	while (tmp) {
//		AddUser(lu, )
//	}
//}
//
//void saveListStudent(ListStudent listStudent);
//// Hàm nh?p thông tin l?p t? bàn phím
//void inputClassData() {
//
//}
// 
// Đường dẫn thư mục semester để lưu các khóa học có trong kỳ đó

void clearScreen()
{
	system("cls");
}

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
	else {
		if (lu.pHead == NULL)
		{
			lu.pHead = lu.pTail = newUser;
		}
		else
		{
			lu.pTail->pNext = newUser;
			lu.pTail = newUser;
			//lu.pTail->pNext = NULL;
		}
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

	getline(SSdata, info.firstName, ',');

	getline(SSdata, info.className, ',');

	getline(SSdata, info.gender, ',');

	string temp;
	getline(SSdata, temp, ',');
	info.dateOfBirth = ConvertingDate(temp);

	getline(SSdata, temp, ',');
	info.academicYear = stoi(temp);

	getline(SSdata, temp, ',');
	if (temp == "TRUE")
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
void GetCurSchoolYear(string& curSchoolYear, date curDate) {
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
	string temp;
	getline(ifs, temp, ',');
	cou->numberOfCredits = stoi(temp);
	//vi so luong hoc sinh max = 50 nen chi can get cho qua di thong tin k can luu lai vao course
	getline(ifs, maxNumStudent, ',');
	getline(ifs, cou->dayOfWeek, ',');
	getline(ifs, cou->session, '\n');
	return cou;
}
//tao mot node course moi 
nodeCourse* createNodeCourse(course* c1)
{
	nodeCourse* nc = new nodeCourse;
	nc->info = c1;
	nc->pNext = NULL;
	return nc;
}
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
void changePassword(nodeUser*& us)
{
	string tmp(us->info.password);
	cout << "Nhap vao mat khau hien tai: ";
	cin >> us->info.password;
	while (tmp != us->info.password)
	{
		cout << "Nhap sai mat khau yeu cau nhap lai!\n";
		cin >> us->info.password;
	}
	cout << "Nhap vao mat khau moi: ";
	cin >> us->info.password;
}
// ham log out
void logout(listUser lu)
{
	clearScreen();
	nodeUser* curUser = LoginAccount();
	if (IsUser(curUser, lu) == NULL)
	{
		cout << "TAI KHOAN VUA NHAP KHONG TON TAI !!!\n\n";
		clearScreen();
		LoginAccount();
	}
}
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


//void initClass(listClass& list) {
//	list.pHead = nullptr;
//	list.pTail = nullptr;
//	list.size = 0;
//}
//
/*void getListClasses(string year, listClass& list) {
	initClass(list);
	// File sẽ có định dạng là tmp\Data\currentSchoolYear\classes\year\class name\abc.csv
	string currentSchoolYear;
	GetCurSchoolYear(currentSchoolYear, GetCurDate());
	string path = "\\Data\\" + currentSchoolYear + "\\classes\\" + year + "\\";
	string extension = ".csv";


	// Duyệt qua toàn bộ folder trong project
	for (auto& p : filesystem::recursive_directory_iterator(path)) {
		if (p.path().extension() == extension) {
			classes* cls = new classes;
			// Lấy phần thân của đường dẫn, nghĩa là không có đuôi ".csv"
			cls->className = p.path().stem().string();
			cls->path = p.path();
			cls->next = nullptr;
			addClass(list, cls);
		}
	}
}*/
//
//void addClass(listClass& list, classes* course) {
//	if (course == nullptr) return;
//	course->next = nullptr;
//	if (list.pHead == nullptr) {
//		list.pHead = course;
//	}
//	else {
//		classes* last = list.pHead;
//		while (last->next) last = last->next;
//		last->next = course;
//	}
//}
//
//
//void writeFileClass(string path, ListStudent listSt) {
//	ofstream ofs;
//	ofs.open(path);
//	if (!ofs.is_open()) {
//		cout << "Not opening File\n";
//		return;
//	}
//
//	ofs << "No,Student ID,Last name,First name,Gender,Date of Birth,Social ID,Academic year" << endl;
//	int no = 1;
//	NodeStudent* p = listSt.pHead;
//
//	while (p != nullptr) {
//		string dob = to_string(p->Info.dateOfBirth.day) + '/' + to_string(p->Info.dateOfBirth.month) + '/' + to_string(p->Info.dateOfBirth.year);
//		ofs << no << ',' << p->Info.studentID << "," << p->Info.lastName << ',' << p->Info.firstName << ',' << p->Info.gender << "," << dob << ',';
//		ofs << p->Info.socialID << ',' << p->Info.academicYear;
//
//		no++;
//		p = p->pNext;
//		if (p != nullptr) ofs << endl;
//	}
//
//	ofs.close();
//}
//
//
//void initList(ListStudent& list) {
//	list.pHead = nullptr;
//	list.pTail = nullptr;
//}
//
//
//NodeStudent* convertStudentData(ifstream& ifs) {
//	NodeStudent* st = new NodeStudent;
//	string ch; 
//	string dob;
//	getline(ifs, ch, ',');
//	if (ch == "") return nullptr;
//
//	ifs >> st->Info.studentID; ifs >> ch;	
//	ifs.ignore();
//	getline(ifs, st->Info.lastName, ',');
//	getline(ifs, st->Info.firstName, ',');
//	getline(ifs, st->Info.gender, ',');
//	getline(ifs, dob, ',');
//
//	st->Info.dateOfBirth = strToDate(dob);
//
//	ifs >> st->Info.socialID; ifs >> ch;
//	ifs.ignore();
//	ifs >> st->Info.academicYear;
//
//	st->pNext = nullptr;
//
//	return st;
//
//}
//

//
//void removeStudent(ListStudent& list, NodeStudent* student) {
//	if (student == list.pHead && student == list.pTail) {
//		list.pHead = list.pTail = nullptr;
//		delete student;
//	}
//	else if (student == list.pHead) {
//		list.pHead = list.pHead->pNext;
//		delete student;
//	}
//	else if (student == list.pTail) {
//		NodeStudent* tmp = list.pHead;
//		while (tmp->pNext != list.pTail)  tmp = tmp->pNext;
//		list.pTail = tmp;
//		list.pTail = nullptr;
//		delete student;
//	}
//	else {
//		NodeStudent* t = list.pHead;
//		while (t->pNext != student) t = t->pNext;
//		t->pNext = student->pNext;
//		delete student;
//	}
//}

//string studentYear(int year) {
//	string s;
//	switch (year) {
//	case 1:
//		s = "first-year classes";
//		break;
//	case 2:
//		s = "second-year classes";
//		break;
//	case 3:
//		s = "third-year classes";
//		break;
//	default:
//		s = "final-year classes";
//		break;
//	}
//	return s;
//}

void createClass(const string src, string& dest) {
	ifstream ifs;
	ifs.open(src);
	if (!ifs.is_open()) {
		cout << "Mo file nguon khong thanh cong\n";
		return;
	}

	string res, line;
	while (getline(ifs, line)) {
		res += line + '\n';
	}

	ifs.close();

	ofstream ofs;
	string curSchoolYear;
	GetCurSchoolYear(curSchoolYear, GetCurDate());
	// Tạm thời sẽ chưa lấy folder năm nhất, năm hai.... Khi nào viết hàm lấy năm 1, năm 2... của học sinh thì sẽ sửa
	// Bây giờ thêm tay thông tin folder năm thứ bao nhiêu sau folder class
	// Và thông tin của ngành, tạm thời chỉ thêm ngành CTT sau folder first-year classes
	// Sau khi viết các hàm liên quan đến danh sách sinh viên sẽ thêm vào sau.
	string nameClass;

	// Bây giờ chỉ nhập CTT? chứ chưa nhập năm là 23CTT5. Sau này có hàm lấy studentYear
	// thì sửa lại + nameClass + ext; để file csv có tên theo đúng năm
	cout << "Name of Class: "; cin >> nameClass;
	string ext = ".csv";
	dest = "Data\\" + curSchoolYear + "\\classes\\" + "first-year classes\\" + "CTT\\" + nameClass + ext;
	ofs.open(dest);
	if (!ofs.is_open()) {
		cout << "Mo file dich khong thanh cong\n";
		return;
	}

	ofs << res;

	ofs.close();
}
// ham copy file danh sach hoc sinh qua danh sach mon hoc trong thu muc semester
void createFileListStudentInCourse()
{
	ofstream ofs;
	string cou;
	cout << "Nhap ten mon hoc:";
	cin >> cou;
	ofs.open("Data/semester/DSHS-" + cou + ".csv");
	ifstream ifs;
	date d = GetCurDate();
	string nienKhoa;
	GetCurSchoolYear(nienKhoa, d);
	string sc_year;
	string cla;
	cout << "Nhap vao ten lop hoc se tham gia vao mon hoc: ";
	cin >> cla;
	string s1(nienKhoa, 2, 3);
	string s2(cla, 0, 1);
	int tmp = stoi(s1) - stoi(s2);
	while (tmp > 3 || tmp < 0)
	{
		cout << "Nhap lai vao ten lop hoc se tham gia vao mon hoc: ";
		cin >> cla;
		string s3(cla, 0, 1);
		tmp = stoi(s1) - stoi(s3);
	}
	switch (tmp)
	{
	case 0:
		sc_year = "first-year classes";
		break;
	case 1:
		sc_year = "second-year classes";
		break;
	case 2:
		sc_year = "third-year classes";
		break;
	case 3:
		sc_year = "final-year classes";
		break;
	}
	/*
	co the them switch case de chon chuong trinh dag hoc la chinh quy hay clc,...
	*/
	ifs.open("Data/InfomationOfStudent/" + sc_year + "/CTT/" + cla + ".csv");
	if (!ifs.is_open())
	{
		cout << "Mo file that bai vui long kiem tra lai ten lop hoc!!!\n";
		return;
	}
	string line;
	while (!ofs.eof())
	{
		getline(ifs, line);
		if (ifs.eof())
		{
			ofs << line;
			break;
		}
		else
		{
			ofs << line << endl;
		}
	}
	ifs.close();
	ofs.close();
}
// ham trong semester
void addCourseToSemester(course* c)
{
	ofstream ofs;
	ofs.open(semesterPath + ".csv");
	if (!ofs.is_open())
	{
		cout << "Mo file that bai!!!\n";
		return;
	}
	ofs << endl;
	ofs << c->id << "," << c->courseName << "," << c->teacherName << ",";
	ofs << c->numberOfCredits << "," << c->maximunNumberOfStudent << ",";
	ofs << c->dayOfWeek << "," << c->session << "\n";
	ofs.close();
}
//them sinh vien vao khoa hoc
void addStudentToCourse(Student* s, course* c)
{
	//s->enrolledCourse->pTail->pNext = ;
	ofstream ofs;
	ofs.open(semesterPath + "/" + c->courseName + ".csv");
	if (!ofs.is_open())
	{
		cout << "Mo file that bai!!!\n";
		return;
	}
	ofs << endl;
	ofs << s->No << "," << s->studentID << "," << s->firstName << ",";
	ofs << s->lastName << "," << s->gender << ",";
	ofs << s->dateOfBirth.day << "-" << s->dateOfBirth.month << "-" << s->dateOfBirth.year;
	ofs << "," << s->academicYear << "," << s->program << "," << s->socialID << "," << "\n";
	ofs.close();
}

void CopyFile(string src, string dest)
{
	ifstream ifs;
	ifs.open(src);
	if (ifs.is_open() == false)
	{
		cout << "Mo file nguon khong thanh cong!\n";
		return;
	}

	ofstream ofs;
	ofs.open(dest);
	if (ofs.is_open() == false)
	{
		cout << "Mo file dich khong thang cong!\n";
		return;
	}

	string line;
	while (getline(ifs, line))
	{
		ofs << line;
		ofs << '\n';
	}

	ifs.close();
	ofs.close();
}

void CreateDirectory(string filePath)
{
	error_code ec;
	filesystem::create_directory(filePath, ec);

	if (ec)
	{
		cerr << "Error creating directory : " << ec.message() << endl;
	}
	else
	{
		cout << "Directory created succesfully" << endl;
	}
}

//Hàm này có vẻ như sai vì mình cần copyFolder, viết lại
void CreatingNewSchoolYear(string schoolYear, string firstYearPath)
{
	CreateDirectory(schoolYearPath + '\\' + schoolYear);
	CreateDirectory(schoolYearPath + '\\' + schoolYear + '\\' + "classes");
	string previousSchoolYear = GetPreviousSchoolYear(schoolYear);
	CopyFolder(schoolYearPath  + '\\' + previousSchoolYear + '\\' + "classes" + '\\' + "first-year classes", schoolYearPath + '\\'+ schoolYear + '\\' + "classes" + '\\' + "second-year classes");
	CopyFolder(schoolYearPath  + '\\' + previousSchoolYear + '\\' + "classes" + '\\' + "second-year classes", schoolYearPath + '\\' + schoolYear + '\\' + "classes" + '\\' + "third-year classes");
	CopyFolder(schoolYearPath  + '\\' + previousSchoolYear + '\\' + "classes" + '\\' + "third-year classes", schoolYearPath + '\\' + schoolYear + '\\' + "classes" + '\\' + "final-year classes");
	CopyFolder(firstYearPath, schoolYearPath + '\\' + schoolYear + '\\' + "classes" + '\\' + "first-year classes");

	/*
	CopyFile(schoolYear + '\\' + previousSchoolYear + "classes" + "first-year classes", schoolYearPath + schoolYear + "classes" + "second-year classes");
	CopyFile(schoolYear + '\\' + previousSchoolYear + "classes" + "second-year classes", schoolYearPath + schoolYear + "classes" + "third-year classes");
	CopyFile(schoolYear + '\\' + previousSchoolYear + "classes" + "third-year classes", schoolYearPath + schoolYear + "classes" + "final-year classes");
	CopyFile(firstYearPath, schoolYearPath + schoolYear + "classes" + "first-year classes");*/
}

string GetPreviousSchoolYear(string schoolYear)
{
	string f = schoolYear.substr(0, 4), e = schoolYear.substr(5);
	int a = stoi(f) - 1;
	int b = stoi(e) - 1;
	f = to_string(a);
	e = to_string(b);
	return f + '-' + e;
}

void createSemester(listCourse& list) {
	getListCourse(list);
	int semester;
	string starDate, endDate;

	cout << "HCMUS PORTAl\n";
	cout << "Create Semester\n";

	cout << "Semester(1/2/3): "; cin >> semester;
	cout << "Start Date: ";
	cin >> starDate; // Nhập theo đinh dạng d/m/y
	cout << "End Date: ";
	cin >> endDate;

	string semesterFolder = "semester " + to_string(semester);
	const string path = schoolYearPath + "\\semester.dat";

	std::filesystem::create_directories(schoolYearPath + "\\" + semesterFolder + "\\courses.csv");

	nodeCourse* p = list.pHead;

	while (p) {
		std::filesystem::create_directories(schoolYearPath + "\\" + semesterFolder + "\\" + p->info->courseName + ".csv");
		p = p->pNext;
	}
}

// ham them mot node course vao list - Quang Thang
void inputCourse(course& c) {
	cout << "Course ID: "; cin >> c.id;
	cout << "Teacher Name: ";
	cin.ignore();
	getline(cin, c.teacherName);
	cout << "Numbers of Credits: "; cin >> c.numberOfCredits;
	cout << "Day of Weeks: ";
	cin >> c.dayOfWeek; // MON, SUN, TUES
	cout << "Session: ";
	cin >> c.session;
}


void addCourseToFile(listCourse& list, course* c1) {
	inputCourse(*c1);
	nodeCourse* t = new nodeCourse;
	t->info = c1;
	t->pNext = NULL;

	if (list.pHead == NULL) list.pHead = list.pTail = t;
	else {
		list.pTail->pNext = t;
		list.pTail = t;
	}

	Semester se;
	GetCurSemester(se);

	string semesterFolder = "semester " + to_string(se.semester);
	ofstream ofs;
	ofs.open(schoolYearPath + "\\" + semesterFolder + "\\courses.csv");
	if (!ofs.is_open()) {
		cout << "Mo file khong thanh cong\n";
		return;
	}

	ofs << c1->id << "," << c1->courseName << "," << c1->teacherName << "," << c1->numberOfCredits << "," << c1->maximunNumberOfStudent << "," << c1->dayOfWeek << "," << c1->session << endl;

	ofs.close();

	std::filesystem::create_directories(schoolYearPath + "\\" + semesterFolder + "\\" + c1->courseName + ".csv");
	/*ofstream ofs;
	ofs.open(schoolYearPath + "\\" + semesterFolder + "\\" + c1->courseName + ".csv");
	if (!ofs.is_open()) {
		cout << "Mo file khong thanh cong\n";
		return;
	}*/


}

void DisplayCourse(listCourse list) {
	if (list.pTail == NULL) {
		cout << "No Course\n";
		return;
	}
	int cnt = 1;

	nodeCourse* p = list.pHead;
	while (p) {
		cout << "Course " << cnt << endl;
		cout << "ID Course: " << p->info->id << endl;
		cout << "Teacher: " << p->info->teacherName << endl;
		cout << "Number of Credits: " << p->info->teacherName << endl;
		cout << "Max Number of Students: " << p->info->maximunNumberOfStudent << endl;
		cout << "Day of Week: " << p->info->dayOfWeek << endl;
		cout << "Session: " << p->info->session << endl;
		cnt++;
		p = p->pNext;
	}
}


void ChangeCourse(listCourse& list, nodeCourse* changedCourse) {
	if (list.pHead == NULL) {
		cout << "Empty List\n";
		return;
	}
	else if (changedCourse == NULL) {
		cout << "Course does not exist\n";
		return;
	}

	nodeCourse* p = list.pHead;
	int choice = 0;
	cout << "1. Modify Teacher Name\n";
	cout << "2. Modify Number of Credits\n";
	cout << "3. Modify Day of weeks\n";
	cout << "4. Modify Session\n";
	cout << "Your choice: "; cin >> choice;
	while (p != changedCourse) {
		p = p->pNext;
	}

	if (p == NULL) {
		cout << "Not find!!\n";
		return;
	}

	if (choice == 1) {
		string newName;
		cout << "New Teacher Name: ";
		cin.ignore();
		getline(cin, newName);
		p->info->teacherName = newName;
	}
	else if (choice == 2) {
		int newCredits;
		cout << "New Credits: ";
		cin >> newCredits;
		p->info->numberOfCredits = newCredits;
	}
	else if (choice == 3) {
		string newDow;
		cout << "New Day of Weeks: ";
		cin >> newDow;
		p->info->dayOfWeek = newDow;
	}
	else if (choice == 4) {
		string newSession;
		cout << "New Session: ";
		cin >> newSession;
		p->info->session = newSession;
	}
	else {
		cout << "Errors Choice\n";
		return;
	}

}

void RemoveCourse(listCourse& list, nodeCourse* removedCourse) {
	if (list.pHead == NULL) {
		cout << "List is Empty\n";
		return;
	}
	else if (removedCourse == NULL) {
		cout << "Course does not exist\n";
		return;
	}

	nodeCourse* p = list.pHead;
	nodeCourse* q = list.pHead;

	if (removedCourse == list.pHead) {
		list.pHead = list.pHead->pNext;
		delete p;
	}

	while (p != removedCourse) {
		q = p;
		p = p->pNext;
	}

	if (p == NULL) {
		cout << "Mo file khong thanh cong\n";
		return;
	}

	if (p == list.pTail) {
		list.pTail = q;
		delete[] p;
		list.pTail->pNext = NULL;
	}
	else {
		q->pNext = p->pNext;
		delete p;
	}
}

void DisplayStudent(Student st) {
	cout << "Num: " << st.No << endl;
	cout << "MSSV: " << st.studentID << endl;
	cout << "First Name: " << st.firstName << endl;
	cout << "Last Name: " << st.lastName << endl;
	cout << "Gender: " << st.gender << endl;
	cout << "DOB: " << st.dateOfBirth.day << "/" << st.dateOfBirth.month << "/" << st.dateOfBirth.year << endl;
	cout << "Academic Year: " << st.academicYear << endl;
	cout << "Program: " << st.program << endl;
	cout << "Social ID: " << st.socialID << endl;
}

void DisplayListEnrolledStudents(course enrolledCourse) {
	ifstream ifs;
	Semester se;
	GetCurSemester(se);

	string semesterFolder = "semester " + to_string(se.semester);
	ifs.open(schoolYearPath + "\\" + semesterFolder + "\\" + enrolledCourse.courseName + ".csv");
	if (!ifs.is_open()) {
		cout << "Mo file khong thanh cong\n";
		return;
	}

	/*int No;
	int studentID;
	string firstName;
	string lastName;
	string gender;
	date dateOfBirth;
	int academicYear; // Năm học, 2021, 2022, ...
	string program; // Hệ học : đại trà, clc, ...
	int socialID;*/

	string line;
	ifs >> line;

	Student st;
	char ch;

	// Hiện tại chưa có cấu trúc file nên sẽ đọc trước các thông tin trên của sinh viên
	while (!ifs.eof()) {
		ifs >> st.No;
		ifs >> ch;
		ifs.ignore();
		getline(ifs, st.firstName, ',');
		getline(ifs, st.lastName, ',');
		getline(ifs, st.gender, ',');
		ifs >> st.dateOfBirth.day >> ch;
		ifs >> st.dateOfBirth.month >> ch;
		ifs >> st.dateOfBirth.year >> ch;
		ifs >> st.academicYear >> ch;
		ifs.ignore();
		getline(ifs, st.gender, ',');
		ifs >> st.socialID;
		DisplayStudent(st);
		st = {};
	}

}

void addStudent(ListStudent& list, Student st) {

	NodeStudent* t = new NodeStudent;
	t->Info = st;
	t->pNext = NULL;
	if (t == nullptr) return;
	if (list.pHead == nullptr) {
		list.pHead = list.pTail = t;
	}
	else {
		list.pTail->pNext = t;
		list.pTail = t;
	}
}

void addNodeStudent(ListStudent& list, NodeStudent* nS) {
	if (list.pHead == NULL)
	{
		list.pHead = list.pTail = nS;
		return;
	}
	list.pTail->pNext = nS;
	list.pTail = nS;
	list.pTail->pNext = nullptr;
}
void exportStudentFromCourseToFile(ListStudent& list, course* c)
{
	string line;
	ifstream ifs;
	ifs.open(semesterPath + " / " + c->courseName + ".csv");
	ofstream ofs;
	ofs.open("D:/DoAnKTLT-Nhom12-HCMUS-2324/DoAnKTLT-Nhom12-HCMUS-2324/Data/export/" + c->courseName + ".csv");
	ofs << left << setw(5) << "No" << left << setw(12) << "Student ID"
		<< left << setw(40) << "Student Full Name" << left << setw(14) << "Total Mark"
		<< left << setw(14) << "Final Mark" << left << setw(15) << "Midterm Mark"
		<< left << setw(15) << "Other Mark" << endl;
	getline(ifs, line, '\n');
	while (!ifs.eof()) {
		NodeStudent* st = new NodeStudent;
		string no;
		string id;
		getline(ifs, no, ',');
		st->Info.No = stoi(no);
		getline(ifs, id, ',');
		st->Info.studentID = stoi(id);
		getline(ifs, st->Info.firstName, ',');
		getline(ifs, st->Info.lastName, '\n');
		addNodeStudent(list, st);
		ofs << left << setw(5) << st->Info.No << left << setw(12) << st->Info.studentID
			<< left << setw(40) << st->Info.firstName + " " + st->Info.lastName << endl;
	}
}

void importScoreBoard(ListStudent& list, nodeCourse* c)
{
	ofstream ofs;
	ofs.open("D:/DoAnKTLT-Nhom12-HCMUS-2324/DoAnKTLT-Nhom12-HCMUS-2324/Data/import/" + c->info->courseName + ".csv");
	ifstream ifs;
	ifs.open("D:/DoAnKTLT-Nhom12-HCMUS-2324/DoAnKTLT-Nhom12-HCMUS-2324/Data/export/" + c->info->courseName + ".csv");
	string l;
	getline(ifs, l, '\n');
	ofs << l << endl;
	cout << l << endl;
	NodeStudent* temp = list.pHead;
	while (!ifs.eof() && temp != NULL) {
		string line;
		getline(ifs, line, '\n');
		cout << line;
		clearScreen();
		cout << "Final Mark:";
		cin >> temp->Info.cMark.finalMark;
		cout << "Midterm Mark:";
		cin >> temp->Info.cMark.midtermMark;
		cout << "Other Mark:";
		cin >> temp->Info.cMark.otherMark;
		cout << "ToTal Mark:";
		cin >> temp->Info.cMark.totalMark;
		clearScreen();
		NodeStudent* tmp = list.pHead;
		while (tmp != NULL)
		{
			cout << l << endl;
			cout << left << setw(5) << tmp->Info.No << left << setw(12) << tmp->Info.studentID
				<< left << setw(40) << tmp->Info.firstName + " " + tmp->Info.lastName
				<< left << setw(14) << tmp->Info.cMark.totalMark
				<< left << setw(14) << tmp->Info.cMark.finalMark
				<< left << setw(15) << tmp->Info.cMark.midtermMark
				<< left << setw(15) << tmp->Info.cMark.otherMark << endl;
			tmp = tmp->pNext;
		}
		ofs << line;
		ofs << left << setw(14) << temp->Info.cMark.totalMark
			<< left << setw(14) << temp->Info.cMark.finalMark
			<< left << setw(15) << temp->Info.cMark.midtermMark
			<< left << setw(15) << temp->Info.cMark.otherMark << endl;
		temp = temp->pNext;
	}

}

void displayScoreBoardOfCourse(nodeCourse* c) {
	ifstream ifs;
	ifs.open("D:/DoAnKTLT-Nhom12-HCMUS-2324/DoAnKTLT-Nhom12-HCMUS-2324/Data/export/" + c->info->courseName + ".csv");
	while (!ifs.eof()) {
		string line;
		getline(ifs, line);
		cout << line;
	}
}

void Profile(User info)
{
	clearScreen();
	cout << "INFORMATION OF USER" << endl;
	cout << setw(20) << "ID: " << info.id << endl;
	cout << setw(20) << "Firset Name: " << info.firstName << endl;
	cout << setw(20) << "Last Name: " << info.lastName << endl;
	cout << setw(20) << "Gender: " << info.gender << endl;
	if (info.isStaff == false)
	{
		cout << setw(20) << "Class name: " << info.className << endl;
		cout << setw(20) << "Academic Year: " << info.academicYear << endl;
	}
	PrintDate(info.dateOfBirth);
}

void PrintDate(date d)
{
	cout << "Date of Birth: " << d.day << "/" << d.month << "/" << d.year << endl;
}

void ChangePassword(User& info, listUser& lu)
{
	string newPass, checkUser;
	cout << setw(30) << "Enter current password: ";
	cin >> checkUser;

	while (checkUser != info.password)
	{
		cout << "Wrong password, enter password again!" << endl;
		cin >> checkUser;
	}

	cout << setw(30) << "Enter new password: ";
	cin >> newPass;
	info.password = newPass;
	WritingUserData(lu, userPath);
}


void WritingUserData(listUser lu, string fileUsersPath)
{
	ofstream ofs;
	ofs.open(fileUsersPath);
	if (ofs.is_open() == false)
	{
		cout << "Mo file that bai (WritingUserData)!" << endl;
		return;
	}
	if (lu.pHead == NULL)
	{
		cout << "Danh sach trong (WritingUserData)!" << endl;
		return;
	}

	nodeUser* cur = lu.pHead;
	ofs << headerUserFile;

	while (cur != NULL)
	{
		ofs << '\n';
		ofs << cur->info.id << ',';
		ofs << cur->info.password << ',';
		ofs << cur->info.lastName << ',';
		ofs << cur->info.firstName << ',';
		ofs << cur->info.lastName << ',';
		ofs << cur->info.gender << ',';
		ofs << cur->info.dateOfBirth.day << '/' << cur->info.dateOfBirth.month << '/' << cur->info.dateOfBirth.year << ',';
		ofs << cur->info.academicYear << ',';
		if (cur->info.isStaff == true)
		{
			ofs << "TRUE";
		}
		else
		{
			ofs << "FALSE";
		}
		cur = cur->pNext;
	}
	ofs.close();
}

void CopyFile(std::filesystem::path src, std::filesystem::path dest) {
	std::ifstream source(src, std::ios::binary);
	std::ofstream destination(dest, std::ios::binary);
	destination << source.rdbuf();
}

void CopyFolder(string src, string dest) {
	std::filesystem::path sourcePath(src);
	std::filesystem::path destPath(dest);

    try {
        if (!std::filesystem::exists(sourcePath) || !std::filesystem::is_directory(sourcePath)) {
            std::cerr << "Source path does not exist or is not a directory." << std::endl;
            return;
        }

        if (std::filesystem::exists(destPath)) {
            std::cerr << "Destination path already exists." << std::endl;
            return;
        }

        std::filesystem::create_directories(destPath);

        for (const auto& entry : std::filesystem::recursive_directory_iterator(sourcePath)) {
            const auto& path = entry.path();
            auto relativePath = std::filesystem::relative(path, sourcePath);
            if (entry.is_directory()) {
                std::filesystem::create_directories(destPath / relativePath);
            }
            else if (entry.is_regular_file()) {
                CopyFile(path, destPath / relativePath);
            }
            else {
                std::cerr << "Skipping non-regular file " << path << std::endl;
            }
        }
    }
    catch (std::filesystem::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

void getListStudentInCLass(ListStudent& list, string source) {
	ifstream ifs;
	ifs.open(source);
	if (!ifs.is_open()) {
		cout << "Mo file that bai!!!\n";
		return;
	}
	string l;
	getline(ifs, l);
	while (!ifs.eof()) {
		Student st;
		string No;
		getline(ifs, No, ',');
		st.No = stoi(No);
		string ID;
		getline(ifs, ID, ',');
		st.studentID = stoi(ID);
		getline(ifs, st.lastName, ',');
		getline(ifs, st.firstName, ',');
		getline(ifs, st.gender, ',');
		string D;
		getline(ifs, D, ',');
		st.dateOfBirth = ConvertingDate(D);
		string sID;
		getline(ifs, sID, ',');
		st.socialID = stoi(sID);
		addStudent(list, st);
	}
	ifs.close();
}

ListStudent InitListStudent()
{
	ListStudent lSt;
	lSt.pHead = lSt.pTail = NULL;
	return lSt;
}

void DisplayListStudent(ListStudent lSt)
{
	if (lSt.pHead == NULL)
	{
		cout << "Danh sach lop hoc trong!\n";
		return;
	}
	NodeStudent* p = lSt.pHead;
	while (p != NULL)
	{
		DisplayStudent(p->Info);
		p = p->pNext;
	}
}

course ConvertCourseInfo(string line)
{
	course c;
	stringstream ssData(line);
	getline(ssData,c.id, ',');
	getline(ssData, c.courseName, ',');
	getline(ssData, c.teacherName, ',');
	string temp;
	getline(ssData, temp, ',');
	c.numberOfCredits = stoi(temp);
	getline(ssData, temp, ',');
	c.numberOfCredits = stoi(temp);
	getline(ssData, c.dayOfWeek, ',');
	getline(ssData, c.session, '\0');
	return c;
}
void ReadingSemesterInfo(Semester& sem, string sourcePath)
{
	ifstream ifs;
	ifs.open(sourcePath);
	if (ifs.is_open() == false)
	{
		cout << "Mo file khong thanh cong! (ReadingSemesterInfo)\n";
		return;
	}

	string line, endD, startD;
	getline(ifs, line);
	startD = line.substr(line.find(',') + 1, 10);
	endD = line.substr(line.find(',') + 1);
	sem.begin = ConvertingDate(startD);
	sem.end = ConvertingDate(endD);
	getline(ifs, line);
	while (ifs.good())
	{
		getline(ifs, line);
		course c = ConvertCourseInfo(line);
		AddCourse(sem.lC, c);
	}
	ifs.close();
}
nodeCourse* GetNodeCourse(course info)
{
	nodeCourse* p = new nodeCourse;
	if (p == NULL)
	{
		return NULL;
	}
	p->info->courseName = info.courseName;
	p->info->dayOfWeek = info.dayOfWeek;
	p->info->id = info.id;
	p->info->numberOfCredits = info.numberOfCredits;
	p->info->session = info.session;
	p->info->teacherName = info.teacherName;
	p->pNext = NULL;
	return p;
}
void AddCourse(listCourse& lC, course info)
{
	nodeCourse* p = GetNodeCourse(info);
	if (lC.pHead == NULL)
	{
		lC.pHead = lC.pTail = p;
	}
	else
	{
		lC.pTail->pNext = p;
		lC.pTail = p;
	}
}

listCourse InitListCourse()
{
	listCourse lC;
	lC.pHead = lC.pTail = NULL;
	return lC;
}