#include "Globals.h"

// Đường dẫn thư mục semester để lưu các khóa học có trong kỳ đó
string semesterPath;
string schoolYearPath = "C:\\DoAn\\DoAnKTLT-Nhom12-HCMUS-2324\\DoAnKTLT-Nhom12-HCMUS-2324\\Data";
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
//void addStudent(ListStudent& list, NodeStudent* student) {
//	if (student == nullptr) return;
//	student->pNext = nullptr;
//	if (list.pHead == nullptr) {
//		list.pHead = list.pTail = student;
//	}
//	else {
//		list.pTail->pNext = student;
//		list.pTail = student;
//	}
//}
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

void createClass(const string src, string &dest) {
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
	ofs	<< c->dayOfWeek << "," << c->session << "\n";
	ofs.close();
}
//them sinh vien vao khoa hoc
void addStudentToCourse(Student* s,course* c)
{
	ofstream ofs;
	ofs.open(semesterPath + "/" +c->courseName + ".csv");
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
	CreateDirectory(schoolYearPath + '\\' + schoolYear + "classes");
	string previousSchoolYear = GetPreviousSchoolYear(schoolYear);
	CopyFile(schoolYear + '\\' + previousSchoolYear + "classes" + "first-year classes", schoolYearPath + schoolYear + "classes" + "second-year classes");
	CopyFile(schoolYear + '\\' + previousSchoolYear + "classes" + "second-year classes", schoolYearPath + schoolYear + "classes" + "third-year classes");
	CopyFile(schoolYear + '\\' + previousSchoolYear + "classes" + "third-year classes", schoolYearPath + schoolYear + "classes" + "final-year classes");
	CopyFile(firstYearPath, schoolYearPath + schoolYear + "classes" + "first-year classes");
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



