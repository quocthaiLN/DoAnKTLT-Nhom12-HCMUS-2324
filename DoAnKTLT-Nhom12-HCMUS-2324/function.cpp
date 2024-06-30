#include "function.h"
//project
string headerCourseBoard = "No,Student ID,StudentFull Name,Total Mark,Final Mark,Midterm Mark,Other Mark";
string headerRegistList = "ID,Password,Last name,First name,Class,Gender,Date of Birth,Academic year,Staff";
string headerUserFile = "ID,Password,Last name,First name,Class,Gender,Date of Birth,Academic year,Staff";
string userPath = "Data\\Accounts\\users.csv";
string semesterPath;
string schoolYearPath = "Data\\SchoolYear";
listCourse listInReg = InitListCourse();
date starDateReg;
date endDateReg;
string pathSemes = " ";
string exportPath = "ExportData";

//void menuAcademicStaff() {
//	cout << "HCMUS PORTAL" << endl;
//	cout << GetCurDate().day << "/" << GetCurDate().month << "/" << GetCurDate().year << endl;
//	cout << "1. User account\n";
//	cout << "2. Profile\n";
//	cout << "3. Manage Student\n";
//	cout << "4. Manage Courses\n";
//	//cout << "5. Setting\n";
//	cout << "0. Exit\n";
//
//}
//
//void menuUserAccount() {
//	system("cls");
//	cout << "HCMUS PORTAL" << endl;
//	cout << "User Account" << endl;
//	cout << "1. Change Password\n";
//	cout << "2. Logout\n";
//	cout << "0. Back\n";
//}
//
//void menuProfile() {
//	system("cls");
//	cout << "HCMUS PORTAL" << endl;
//	cout << "Last Name: " << "Nguyen Van" << endl;
//	cout << "First Name: " << "Tuan" << endl;
//	cout << "Gender: " << "Male" << endl;
//	cout << "Staff ID: " << "2312.." << endl;
//	cout << "Date of Birth: " << "01/05/2024" << endl;
//	cout << "Back." << endl;
//}
//
//void menuManageStudent() {
//	cout << "HCMUS PORTAL" << endl;
//	cout << "Manage Student\n";
//	cout << "1. Create School Year\n";
//	cout << "2. School Year Information\n";
//	cout << "3. Create Classes\n";
//	cout << "4. List of Classes\n";
//	cout << "5. Add Student To Course\n";
//	cout << "6. Back\n";
//}
//
//void menuManageCourses() {
//	cout << "HCMUS PORTAL" << endl;
//	cout << "Manage Courses\n";
//	cout << "1. Create Semester\n";
//	cout << "2. Create Registration Session\n";
//	cout << "3. Add Course\n";
//	cout << "4. List Of Course\n";
//	cout << "5. Semester Summary\n";
//	cout << "6. View Score Board\n";
//	cout << "7. Back\n";
//}
//
//void menuStudent() {
//	cout << "HCMUS PORTAL\n";
//	cout << GetCurDate().day << "/" << GetCurDate().month << "/" << GetCurDate().year;
//	cout <<  endl;
//	cout << "1. User account\n";
//	cout << "2. Profile\n";
//	cout << "3. Enrolled Course\n";
//	cout << "4. Scoreboard\n";
//	cout << "5. List of classes\n";
//	cout << "6. List of courses\n";
//	//cout << "7. Setting\n";
//	cout << "0. Exit\n";
//}
//
//void menuStudentUserAccount() {
//	system("cls");
//	cout << "HCMUS PORTAL\n";
//	cout << "User Account\n";
//	cout << "1. Change Password\n";
//	cout << "2. Logout\n";
//	cout << "3. Back\n";
//}
//
//void menuStudentProfile() {
//	system("cls");
//	cout << "HCMUS PORTAL\n";
//	cout << "Profile" << endl;
//	cout << "1. Last name: " << "Nguyen Le Hoang" << endl;
//	cout << "2. First name: " << "Dung" << endl;
//	cout << "3. Gender: " << "Female" << endl;
//	cout << "4. Class: " << "23CTT5A" << endl;
//	cout << "5. MSSV: " << "231203..." << endl;
//	cout << "6. Date of Birth: " << "01/05/2024" << endl;
//	cout << "7. Back" << endl;
//
//}

//void menuCoursesRegis() {
//	system("clc");
//	cout << "HCMUS PORTAL\n";
//	cout << "Courses Registration\n";
//	cout << "1. Register Courses\n";
//	cout << "2. View Enrolled Courses\n";
//	cout << "3. Back" << endl;
//}

void SetColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void gotoxy(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);
}

void drawBox(int width, int height, int startX, int startY) {
	for (int i = startX; i < startX + width; i++) {
		gotoxy(i, startY);
		cout << "-";
		gotoxy(i, startY + height);
		cout << "-";
	}
	for (int i = startY; i <= startY + height; i++) {
		gotoxy(startX, i);
		cout << "|";
		gotoxy(startX + width, i);
		cout << "|";
	}
	gotoxy(startX, startY);
	cout << "0";
	gotoxy(startX + width, startY);
	cout << "0";
	gotoxy(startX, startY + height);
	cout << "0";
	gotoxy(startX + width, startY + height);
	cout << "0";
}

void drawHeader(const string& title, int startX, int startY) {
	int consoleWidth = 50; // Chiều rộng của console, bạn có thể điều chỉnh
	int titlePosition = startX + (consoleWidth - title.length()) / 2;
	SetColor(14); // Màu vàng cho tiêu đề
	gotoxy(titlePosition, startY); // Căn lề trung tâm
	cout << title << endl;
	SetColor(7); // Đặt lại màu mặc định
}

void drawDate(int startX, int startY) {
	date curDate = GetCurDate();
	gotoxy(startX + 2, startY + 2); // Đặt vị trí cho ngày tháng
	cout << curDate.day << "/" << curDate.month << "/" << curDate.year << endl;
}

void drawMenuOption(int x, int y, const string& option, int color = 7) {
	SetColor(color); // Đặt màu được chỉ định
	gotoxy(x, y); // Đặt vị trí cho tùy chọn menu
	cout << option << endl;
	SetColor(7); // Đặt lại màu mặc định
}

void drawBackOption(int x, int y) {
	SetColor(4); // Màu đỏ cho tùy chọn quay lại/thông báo thoát
	gotoxy(x, y); // Đặt vị trí cho tùy chọn
	cout << "0. Back\n";
	SetColor(7); // Đặt lại màu mặc định
}

void menuAcademicStaff() {
	system("cls");

	// Kích thước của khung
	int boxWidth = 50;
	int boxHeight = 10;

	// Lấy kích thước của màn hình console
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	// Tính toán vị trí bắt đầu để căn giữa khung
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawDate(startX, startY);
	drawMenuOption(startX + 2, startY + 4, "1. User account", 11); // Màu xanh cyan cho các tùy chọn
	drawMenuOption(startX + 2, startY + 5, "2. Profile", 11);
	drawMenuOption(startX + 2, startY + 6, "3. Manage Student", 11);
	drawMenuOption(startX + 2, startY + 7, "4. Manage Courses", 11);
	//drawMenuOption(startX + 2, startY + 8, "5. Setting", 11);
	drawBackOption(startX + 2, startY + 8);
}

void menuUserAccount() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 10;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "User Account", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "1. Change Password", 11);
	drawMenuOption(startX + 2, startY + 5, "2. Logout", 11);
	drawBackOption(startX + 2, startY + 6);
}

void menuProfile() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 10;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "Profile", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "Last Name: Nguyen Van");
	drawMenuOption(startX + 2, startY + 5, "First Name: Tuan");
	drawMenuOption(startX + 2, startY + 6, "Gender: Male");
	drawMenuOption(startX + 2, startY + 7, "Staff ID: 2312..");
	drawMenuOption(startX + 2, startY + 8, "Date of Birth: 01/05/2024");
	drawBackOption(startX + 2, startY + 9);
}

void menuManageStudent() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 12;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "Manage Student", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "1. Create School Year", 11);
	drawMenuOption(startX + 2, startY + 5, "2. School Year Information", 11);
	drawMenuOption(startX + 2, startY + 6, "3. Create Classes", 11);
	drawMenuOption(startX + 2, startY + 7, "4. List of Classes", 11);
	drawMenuOption(startX + 2, startY + 8, "5. Add Student To Course", 11);
	drawBackOption(startX + 2, startY + 9);
}

void menuManageCourses() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 13;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "Manage Courses", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "1. Create Semester", 11);
	drawMenuOption(startX + 2, startY + 5, "2. Create Registration Session", 11);
	drawMenuOption(startX + 2, startY + 6, "3. Add Course", 11);
	drawMenuOption(startX + 2, startY + 7, "4. List Of Course", 11);
	drawMenuOption(startX + 2, startY + 8, "5. Semester Summary", 11);
	drawMenuOption(startX + 2, startY + 9, "6. View Score Board", 11);
	drawBackOption(startX + 2, startY + 10);
}

void menuStudent() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 12;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawDate(startX, startY);
	drawMenuOption(startX + 2, startY + 4, "1. User account", 11);
	drawMenuOption(startX + 2, startY + 5, "2. Profile", 11);
	drawMenuOption(startX + 2, startY + 6, "3. Enrolled Course", 11);
	drawMenuOption(startX + 2, startY + 7, "4. Scoreboard", 11);
	drawMenuOption(startX + 2, startY + 8, "5. List of classes", 11);
	drawMenuOption(startX + 2, startY + 9, "6. List of courses", 11);
	//drawMenuOption(startX + 2, startY + 10, "7. Setting", 11);
	drawBackOption(startX + 2, startY + 10);
}

void menuStudentUserAccount() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 10;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "User Account", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "1. Change Password", 11);
	drawMenuOption(startX + 2, startY + 5, "2. Logout", 11);
	drawBackOption(startX + 2, startY + 6);
}

void menuStudentProfile() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 12;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "Profile", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "Last name: Nguyen Le Hoang");
	drawMenuOption(startX + 2, startY + 5, "First name: Dung");
	drawMenuOption(startX + 2, startY + 6, "Gender: Female");
	drawMenuOption(startX + 2, startY + 7, "Class: 23CTT5A");
	drawMenuOption(startX + 2, startY + 8, "MSSV: 231203...");
	drawMenuOption(startX + 2, startY + 9, "Date of Birth: 01/05/2024");
	drawBackOption(startX + 2, startY + 10);
}

void menuCoursesRegis() {
	system("cls");

	int boxWidth = 50;
	int boxHeight = 10;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	int startX = (columns - boxWidth) / 2;
	int startY = (rows - boxHeight) / 2;

	drawBox(boxWidth, boxHeight, startX, startY);
	drawHeader("HCMUS PORTAL", startX, startY + 1);
	drawMenuOption(startX + 2, startY + 3, "Courses Registration", 10); // Màu xanh lá cho tiêu đề phụ
	drawMenuOption(startX + 2, startY + 4, "1. Register Courses", 11);
	drawMenuOption(startX + 2, startY + 5, "2. View Enrolled Courses", 11);
	drawBackOption(startX + 2, startY + 6);
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
	cout << setw(30) << "Begin Day:" << "5/9/" << str2 << endl;
	cout << setw(30) << "End Day:" << "9/" << to_string(stoi(str2) + 1) << endl;
 
}

void returnMenuActionAcademicStaff(User& info, listUser& lu)
{
	int x;
	COORD consoleSize;
	consoleSize.X = 110; // Width of the console
	consoleSize.Y = 25; // Height of the console

	// Calculate the position to place the prompt at the bottom left
	short inputX = 42; // Adjust as needed to position towards the center
	short inputY = consoleSize.Y - 3; // 3 lines from the bottom

	do
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { inputX, inputY });
		SetColor(14); // Yellow color for the prompt
		cout << "An phim '0' de quay ve Menu: ";
		SetColor(7); // Reset to default color
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
		menuUserAccount();
		cout << "CHOOSE ACTION: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			{
				clearScreen();
				ChangePassword(info, lu);
				returnMenuActionAcademicStaff(info, lu);
				break;
			}
		}
		case 2:
		{
			clearScreen();
			logout(lu);
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 3: {
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		}
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
		switch (y)
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
		case 3:
		{
			clearScreen();
			CreateClass();
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 4:
		{
			clearScreen();
			DisplayClassInfo();
			returnMenuActionAcademicStaff(info, lu);
			break;
			//Đọc file class và hiển thị lên màn hình
		}// Add Student To Course
		case 5: {
			listCourse list = InitListCourse();
			clearScreen();
			AddStudentToCourse(list);
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 6: {
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		}
		break;
	}
	case 4:
	{
		clearScreen();
		//listCourse l = InitListCourse();
		menuManageCourses();
		cout << endl;
		cout << "CHOOSE ACTION: ";
		cin >> x;
		switch (x)
		{
		case 1:
		{
			clearScreen();
			createSemester(listInReg);
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 2:
		{
			clearScreen();
			createRegistrationSession(starDateReg, endDateReg);
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 3:
		{
			clearScreen();
			cout << "HCMUS PORTAl\n";
			cout << "1.Input Courses Data\n";
			cout << "2.Import Courses Data File\n";
			cout << "3.Back\n";
			int lch;
			cout << "Nhap lua chon: ";
			cin >> lch;
			switch (lch) {
			case 1: {
				clearScreen();
				if (pathSemes == " ") {
					//pathSemes la bien toan cuc
					//pathSemes duoc lay tu ham createSemester 
					//neu da create thi se duoc them vao luon
					//neu khong thi phai nhap nam hoc va hoc ki can them mon hoc
					//neu hoc ki do da duoc tao thi se thuc hien duoc neu k se hien thi SEMESTER IS NOT CREATED!!!
					//ben duoi o dong 2067 co them 1 ham hien thi thong tin khac voi duong dan duoc truyen vao
					createPathSemes();
					clearScreen();
					ifstream ifs;
					ifs.open(pathSemes);
					if (!ifs.is_open()) {
						cout << "SEMESTER IS NOT CREATED!!!\n";
						Sleep(500);
						pathSemes = " ";
						returnMenuActionAcademicStaff(info, lu);
						break;
					}
					else {
						getListCourse2(listInReg, ifs);
						addCourseToSemester(listInReg);
					}
				}
				else {
					addCourseToSemester(listInReg);
				}
				returnMenuActionAcademicStaff(info, lu);
				break;
			}
			case 2: {
				clearScreen();
				if (pathSemes == " ") {
					createPathSemes();
					clearScreen();
					ifstream ifs;
					ifs.open(pathSemes);
					if (!ifs.is_open()) {
						cout << "SEMESTER IS NOT CREATED!!!\n";
						Sleep(500);
						pathSemes = " ";
						returnMenuActionAcademicStaff(info, lu);
						break;
					}
					else {
						getListCourse2(listInReg, ifs);
						importCourseData(listInReg);
					}
				}
				else {
					importCourseData(listInReg);
				}
				returnMenuActionAcademicStaff(info, lu);
				break;
			}
			case 3: {
				returnMenuActionAcademicStaff(info, lu);
				break;
			}
			}
		}
		case 4: {
			clearScreen();
			DisplayCourseInfo();
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 5:
		{
			clearScreen();
			//void DisplayExportCourseBoard();


			int z, n;
			string* item;
			string SchYear, Sem;
			DisplayFilesInDirectory(schoolYearPath, item, n);
			DisplayArrString(item, n);
			cout << setw(20) << "Choose school year: ";
			cin >> z;
			SchYear = item[z - 1];

			cout << "Choose semester(1/2/3): ";
			cin >> Sem;

			listCourse lC = InitListCourse();
			ReadingCourse(lC, schoolYearPath + '\\' + SchYear + '\\' + "semester " + Sem + '\\' + "courses.csv");
			CreateScoreBoardFile(lC, schoolYearPath + '\\' + SchYear + '\\' + "semester " + Sem);
			cout << "Xuat bang diem hoc ki " << Sem << " nam hoc " << SchYear << " thanh cong. Hay kiem tra ExportData!" << endl;


			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 6:
		{
			clearScreen();
			viewScoreBoard();
			returnMenuActionAcademicStaff(info, lu);
			break;
		}
		case 7:
		{
			clearScreen();
			returnMenuActionAcademicStaff(info, lu);
		}
		}
	}
	}
	return;
}

void DisplayCourseInfo()
{
	int z, n;
	string* item;
	string SchYear, Sem;
	DisplayFilesInDirectory(schoolYearPath, item, n);
	DisplayArrString(item, n);
	cout << setw(20) << "Choose school year: ";
	cin >> z;
	SchYear = item[z - 1];

	cout << "Choose semester(1/2/3): ";
	cin >> Sem;

	pathSemes = "Data\\SchoolYear\\" + SchYear + "\\semester " + Sem + "\\courses.csv";
	ifstream ifs;
	ifs.open(pathSemes);
	getListCourse2(listInReg, ifs);
	if (listInReg.pHead == NULL) {
		cout << "LIST IS EMPTY!!!\n";
		Sleep(1000);
	}
	else {
		printListCourse(listInReg);
	}
}

void DisplayExportCourseBoard()
{
	
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
		cout << "An phim '0' de quay ve Menu: ";
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
	case 0: {
		/*clearScreen();
		returnMenuActionAcademicStaff(infoUs, lu);*/
		break;
	}
	case 1:
	{
		clearScreen();
		menuUserAccount();
		cout << "CHOOSE ACTION: ";
		cin >> y;
		switch (y)
		{
		case 1:
		{
			{
				clearScreen();
				ChangePassword(infoUs, lu);
				returnMenuActionAcademicStaff(infoUs, lu);
				break;
			}
		}
		case 2:
		{
			clearScreen();
			logout(lu);
			returnMenuActionAcademicStaff(infoUs, lu);
			break;
		}
		case 3: {
			returnMenuActionAcademicStaff(infoUs, lu);
			break;
		}
		}
	}
	case 2:
	{
		Profile(infoSt, infoUs);
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 3:
	{
		clearScreen();
		string courseID[10], stuID, SchYear, Sem;
		cout << "Choose Semester(1/2/3): ";
		cin >> Sem;
		GetCurSchoolYear(SchYear, GetCurDate());
		int n;
		listCourse lC = InitListCourse();
		ReadingEnrolledCourse(courseID, n, "Data/InformationOfStudent/" + infoUs.id + ".txt");
		FindCourseByID(courseID, n, lC, schoolYearPath + "/" + SchYear + "/semester " + Sem + "/courses.csv");
		clearScreen();
		if (lC.pHead == NULL) {
			cout << "LIST IS EMPTY!!!\n";
		}
		else {
			printListCourse(lC);
		}
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 4:
	{
		clearScreen();
		viewScoreBoardSt(infoSt, infoUs);
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 5:
	{
		clearScreen();
		DisplayClassInfo();
		returnMenuActionStudent(infoUs, lu, infoSt);
		break;
	}
	case 6:
	{
		clearScreen();
		DisplayCourseInfo();
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

	system("cls");
	drawBox(50, 10, 35, 5);
	drawHeader("LOGIN", 35, 6);


	SetColor(14);


	short inputX = 40; 
	short inputY = 8;  

	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { inputX, inputY });
	cout << "User name/ ID:";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(inputX + 15), inputY });
	SetColor(7); 
	cin >> userName;

	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { inputX, static_cast<short>(inputY + 2) });
	SetColor(14); 
	cout << "Password:";
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { static_cast<short>(inputX + 15), static_cast<short>(inputY + 2) });
	SetColor(7); 
	cin >> password;


	User newUser;
	newUser.id = userName;
	newUser.password = password;

	nodeUser* newUserNode = GetNodeUser(newUser);

	return newUserNode;
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
	const string path = "Data\\SchoolYear\\" + schoolYear + "\\semester.dat";
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
		delete cou;
		return NULL;
	}
	getline(ifs, cou->id, ',');
	getline(ifs, cou->courseName, ',');
	getline(ifs, cou->teacherName, ',');
	string tmp;
	getline(ifs, tmp, ',');
	if (tmp < "0" || tmp > "9") {
		delete cou;
		return NULL;
	}
	cou->numberOfCredits = stoi(tmp);
	string academic;
	getline(ifs, academic, ',');
	//vi so luong hoc sinh max = 50 nen chi can get cho qua di thong tin k can luu lai vao course
	getline(ifs, maxNumStudent, ',');
	string tmp1;
	getline(ifs, tmp1, ',');
	getline(ifs, cou->dayOfWeek, ',');
	getline(ifs, cou->session);
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
	if (c1 == NULL) return;
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
void getListCourse2(listCourse& lc, ifstream& ifs)
{
	string line;
	getline(ifs, line);
	while (!ifs.eof())
	{
		course* c = convertingCourse(ifs);
		addCourse(lc, c);
	}
	ifs.close();
}

void getListCourse(listCourse& lc)
{
	lc.pHead = lc.pTail = NULL;
	//string path = semesterPath + "/course.csv";
	string path;

	ifstream ifs;
	ifs.open("ImportData\\courses1.csv");
	if (!ifs.is_open())
	{
		cout << "Mo file that bai!\n";
		return;
	}
	string line;
	getline(ifs, line);
	while (!ifs.eof())
	{
		course* c = convertingCourse(ifs);
		addCourse(lc, c);
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
	nodeUser* curUser = NULL;
	nodeUser* tempUser = NULL;
	int n = 0;
	do
	{
		clearScreen();
		if (n >= 1) {
			cout << "Tai khoan hoac mat khau sai!!\n";
		}
		tempUser = LoginAccount();
		ReadingUsersData(lu, userPath);
		curUser = IsUser(tempUser, lu);
		clearScreen();
		if (curUser != NULL)
		{
			cout << "DANG NHAP THANH CONG!\n";
			Sleep(500);
			n = -1;
		}
		n++;
	} while (curUser == NULL);
	system("cls");
	if (curUser->info.isStaff == true)
	{
		actionAcademicStaff(curUser->info, lu);
	}
	else
	{
		Student infoSt = createInfoStFromUserInfo(curUser->info);
		actionStudent(curUser->info, lu, infoSt);
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
void createPathSemes() {
	string scy;
	int semester;
	cout << "Enter school year: "; cin >> scy;
	cout << "Enter semester: "; cin >> semester;
	pathSemes = "Data\\SchoolYear\\" + scy + "\\semester " + to_string(semester) + "\\courses.csv";
}
void addCourseToSemester(listCourse& l)
{
	int n;
	cout << "Nhap vao so mon duoc them: ";
	cin >> n;
	
	clearScreen();
	cout << "Nhap vao danh sach mon hoc duoc them \n";
	for (int i = 0; i < n; i++) {
		course* c = new course;
		cout << "Thong tin mon hoc thu " << i + 1 << endl;
		cout << "ID: "; cin >> c->id; cin.ignore();
		cout << "Course Name: "; getline(cin, c->courseName);
		cout << "Teacher Name: "; getline(cin, c->teacherName);
		cout << "Number Of Credits: "; cin >> c->numberOfCredits; cin.ignore();
		cout << "NumBer Of Student: 50\n"; 
		cout << "Day Of Week: "; getline(cin, c->dayOfWeek);
		cout << "Session: "; getline(cin, c->session);
		addCourse(l, c);
		string path(pathSemes, 0, pathSemes.length() - 11);
		ofstream ofs;
		ofs.open(path + c->id + ".csv");
		ofs.close();
	}
	ofstream ofs;
	//
	ofs.open(pathSemes);
	if (!ofs.is_open())
	{
		cout << "Mo file that bai!!!\n";
		return;
	}
	nodeCourse* n1 = l.pHead;
	while (n1 != NULL) {
		ofs << n1->info->id << "," << n1->info->courseName << "," << n1->info->teacherName << ",";
		ofs << n1->info->numberOfCredits << "," << n1->info->maximunNumberOfStudent << ",";
		ofs << n1->info->dayOfWeek << "," << n1->info->session << "\n";
		n1 = n1->pNext;
	}
	ofs.close();
}
void importCourseData(listCourse& l) {
	string path;
	cout << "Nhap vao duong dan den file:\n";
	cin >> path;
	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open())
	{
		cout << "Mo file that bai!!!\n";
		return;
	}
	while (!ifs.eof()) {
		course* c = convertingCourse(ifs);
		addCourse(l, c);
		string path(pathSemes, 0, pathSemes.length() - 11);
		ofstream ofs;
		ofs.open(path + c->id + ".csv");
		ofs.close();
	}
	ofstream ofs;
	//
	ofs.open(pathSemes);
	if (!ofs.is_open())
	{
		cout << "Mo file that bai!!!\n";
		return;
	}
	nodeCourse* n1 = l.pHead;
	while (n1 != NULL) {
		ofs << n1->info->id << "," << n1->info->courseName << "," << n1->info->teacherName << ",";
		ofs << n1->info->numberOfCredits << "," << n1->info->maximunNumberOfStudent << ",";
		ofs << n1->info->dayOfWeek << "," << n1->info->session << "\n";
		n1 = n1->pNext;
	}
	ofs.close();
}
//them sinh vien vao khoa hoc
//void AddStudentToCourse(Student* s, course* c)
//{
//	//s->enrolledCourse->pTail->pNext = ;
//	ofstream ofs;
//	ofs.open(semesterPath + "/" + c->courseName + ".csv");
//	if (!ofs.is_open())
//	{
//		cout << "Mo file that bai!!!\n";
//		return;
//	}
//	ofs << endl;
//	ofs << s->No << "," << s->studentID << "," << s->firstName << ",";
//	ofs << s->lastName << "," << s->gender << ",";
//	ofs << s->dateOfBirth.day << "-" << s->dateOfBirth.month << "-" << s->dateOfBirth.year;
//	ofs << "," << s->academicYear << "," << s->program << "," << s->socialID << "," << "\n";
//	ofs.close();
//}

//void CopyFile(string src, string dest)
//{
//	ifstream ifs;
//	ifs.open(src);
//	if (ifs.is_open() == false)
//	{
//		cout << "Mo file nguon khong thanh cong!\n";
//		return;
//	}
//
//	ofstream ofs;
//	ofs.open(dest);
//	if (ofs.is_open() == false)
//	{
//		cout << "Mo file dich khong thang cong!\n";
//		return;
//	}
//
//	string line;
//	while (getline(ifs, line))
//	{
//		ofs << line;
//		ofs << '\n';
//	}
//
//	ifs.close();
//	ofs.close();
//}

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
	string curSchoolYear;
	GetCurSchoolYear(curSchoolYear, GetCurDate());
	string _schoolYearPath = "Data\\SchoolYear\\" + curSchoolYear;

	cout << "HCMUS PORTAl\n";
	cout << "Create Semester\n";

	cout << "Semester(1/2/3): "; cin >> semester;
	cout << "Start Date: ";
	cin >> starDate; // Nhập theo đinh dạng d/m/y
	cout << "End Date: ";
	cin >> endDate;

	string semesterFolder = "semester " + to_string(semester);
	const string path = _schoolYearPath + "\\semester.dat";
	std::filesystem::create_directories(_schoolYearPath + "\\" + semesterFolder);

	pathSemes = _schoolYearPath + "\\" + semesterFolder + "\\courses.csv";
	ofstream ofs(_schoolYearPath + "\\" + semesterFolder + "\\courses.csv");
	ofs.close();

	ofstream fileDat;
	fileDat.open(path);
	fileDat << semester << endl;
	fileDat << starDate << endl;
	fileDat << endDate;
	fileDat.close();

	string fileCSV;
	cout << "Enter file csv: ImportData/";
	cin >> fileCSV;
	fs::path filePath = fileCSV;

	if (filePath.extension() != ".csv") {
		fileCSV += ".csv";
	}

	CopyFile("ImportData\\" + fileCSV, _schoolYearPath + "\\" + semesterFolder + "\\courses.csv");
	nodeCourse* p = list.pHead;

	while (p) {
		string coursePath = _schoolYearPath + "\\" + semesterFolder;
		std::filesystem::create_directories(coursePath);
		ofstream courseFile(coursePath + "\\" + p->info->id + ".csv");
		courseFile << headerCourseBoard << endl;
		courseFile.close();
		p = p->pNext;
	}

	cout << "Create Semester Successfully\n";
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
		cout << "Number of Credits: " << p->info->numberOfCredits << endl;
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
	string d = to_string(st.dateOfBirth.day) + "/" + to_string(st.dateOfBirth.month) + "/" + to_string(st.dateOfBirth.year);
	cout << left << setw(5) << st.No
		<< left << setw(12) << st.studentID
		<< left << setw(20) << st.lastName
		<< left << setw(12) << st.firstName
		<< left << setw(8) << st.gender
		<< left << setw(14) << d
		<< left << setw(15) << st.academicYear
		// << left << setw(9) /* << "Program: " */<< st.program
		<< left << setw(15) << st.socialID << endl;
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
	ofs.open("Data/export/" + c->courseName + ".csv");
	ofs << "No" << "," << "Student ID" << ","
		<< "Student Full Name" << "," << "Total Mark" << ","
		<< "Final Mark" << "," << "Midterm Mark" << ","
		<< "Other Mark" << endl;
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
		ofs << st->Info.No << "," << st->Info.studentID << ","
			<< st->Info.firstName + " " + st->Info.lastName << endl;
	}
}

void importScoreBoard(ListStudent& list, nodeCourse* c)
{
	ofstream ofs;
	ofs.open("Data/import/ " + c->info->courseName + ".csv");
	ifstream ifs;
	ifs.open("Data/export/" + c->info->courseName + ".csv");
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
		ofs << temp->Info.cMark.totalMark << ","
			<< temp->Info.cMark.finalMark << ","
			<< temp->Info.cMark.midtermMark << ","
			<< temp->Info.cMark.otherMark << endl;
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

	// Draw the box for the profile information
	int boxWidth = 60;
	int boxHeight = 12;
	int startX = 32;
	int startY = 5;
	drawBox(boxWidth, boxHeight, startX, startY);

	// Draw the header
	drawHeader("INFORMATION OF USER", startX + 4, startY + 1);

	// Set color for the profile information
	SetColor(14); // Yellow color for labels

	// Adjust coordinates to place profile information inside the box
	short infoX = static_cast<short>(startX + 5);
	short infoY = static_cast<short>(startY + 3);

	// Print the profile information
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, infoY });
	cout << setw(20) << "ID: " << info.id;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, static_cast<short>(infoY + 1) });
	cout << setw(20) << "First Name: " << info.firstName;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, static_cast<short>(infoY + 2) });
	cout << setw(20) << "Last Name: " << info.lastName;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, static_cast<short>(infoY + 3) });
	cout << setw(20) << "Gender: " << info.gender;

	if (info.isStaff == false)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, static_cast<short>(infoY + 4) });
		cout << setw(20) << "Class name: " << info.className;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, static_cast<short>(infoY + 5) });
		cout << setw(20) << "Academic Year: " << info.academicYear;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { infoX, static_cast<short>(infoY + 6) });
	PrintDate(info.dateOfBirth);

	// Reset color to default
	SetColor(7);
}

void PrintDate(date d)
{
	cout << setw(20) << "Date of Birth: " << d.day << "/" << d.month << "/" << d.year << endl;
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
		string year;
		getline(ifs, year);
		st.academicYear = stoi(year);
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
	clearScreen();
	cout << right << setw(55) << "Danh sach hoc sinh" << endl;
	cout << left << setw(5) << "No"
		<< left << setw(12) << "Student ID"
		<< left << setw(20) << "Last Name"
		<< left << setw(12) << "First Name"
		<< left << setw(8) << "Gender"
		<< left << setw(14) << "Day Of Birth"
		<< left << setw(15) << "Academic Year"
		// << left << setw(9) << "Program"
		<< left << setw(15) << "Social ID" << endl;
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
	/*p->info->courseName = info.courseName;
	p->info->dayOfWeek = info.dayOfWeek;
	p->info->id = info.id;
	p->info->numberOfCredits = info.numberOfCredits;
	p->info->session = info.session;
	p->info->teacherName = info.teacherName;*/
	p->info = &info;
	p->pNext = NULL;
	return p;
}
void AddCourse(listCourse& lC, course info)
{
	nodeCourse* p = GetNodeCourse(info);
	if (lC.pHead == NULL)
	{
		lC.pHead = p;
		lC.pTail = p;
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


void displayListClass(ListStudent list) {
	NodeStudent* temp = list.pHead;
	if (temp == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		cout << left << setw(5) << temp->Info.No << left << setw(10) << temp->Info.studentID
			<< left << setw(30) << temp->Info.lastName << left << setw(10) << temp->Info.firstName
			<< left << setw(8) << temp->Info.gender << temp->Info.dateOfBirth.day
			<< "/" << temp->Info.dateOfBirth.month << "/" << left << setw(6) << temp->Info.dateOfBirth.year
			<< left << setw(14) << temp->Info.socialID << endl;
		temp = temp->pNext;
	}
}

void createRegistrationSession(date& star, date& end) {
	cout << "HCMUS PORTAl\n";
	cout << "Create Registration Session\n";
	string starDate, endDate;
	cout << "Start Date(dd/mm/yyyy): ";
	cin >> starDate; 
	star = ConvertingDate(starDate);
	cout << "End Date(dd/mm/yyyy): ";
	cin >> endDate;
	end = ConvertingDate(endDate);
}
void expireReg() {

}
void printListCourse(listCourse l) {
	nodeCourse* n1 = l.pHead;
	cout << left << setw(10) << "ID" << left << setw(31) << "Course Name"
		<< left << setw(24) << "Teacher Name" << left << setw(8) << "Credits"
		<< left << setw(19) << "Number Of Student" << left << setw(14) << "Day Of Week"
		<< left << setw(9) << "Session" << endl;
	while (n1 != NULL) {
		cout << left << setw(10) << n1->info->id << left << setw(31) << n1->info->courseName
			<< left << setw(24) << n1->info->teacherName << left << setw(8) << n1->info->numberOfCredits
			<< left << setw(19) << n1->info->maximunNumberOfStudent << left << setw(14) << n1->info->dayOfWeek
			<< left << setw(9) << n1->info->session << endl;
		n1 = n1->pNext;
	}
}

//ham doc file voi duong dan co the tu nhap
void printListCourse(listCourse& l, string path) {
	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open()) {
		cout << "Mo file k thanh cong!!!\n";
		return;
	}
	getListCourse2(l, ifs);
	printListCourse(l);
}

void CreateClass() {
	string SchoolYear;

	// School Year: 2023-2024 , 2022-2023
	cout << "Enter School Year: ";
	cin >> SchoolYear;

	int year;
	cout << "1. first-year classes.\n";
	cout << "2. second-year classes.\n";
	cout << "3. third-year classes.\n";
	cout << "4. final-year classes.\n";
	cout << "Enter X-year: "; cin >> year;
	string x_year;
	switch (year)
	{
	case 1:
		x_year = "first-year classes";
		break;
	case 2:
		x_year = "second-year classes";
		break;
	case 3:
		x_year = "third-year classes";
		break;
	case 4:
		x_year = "final-year classes";
		break;
	default:
		break;
	}

	string _class;
	cout << "Enter Class: "; cin >> _class;
	
	string dir;
	cout << ".ImportData/";
	cin >> dir;

	fs::path fileDir = dir;

	if (fileDir.extension() != ".csv") {
		dir += ".csv";
	}

	const string SrcPath = "ImportData\\" + dir;
	const string DestPath = "Data\\SchoolYear\\" + SchoolYear + "\\classes\\" + x_year + "\\" + _class + ".csv";

	ofstream fcreate(DestPath);
	fcreate.close();

	CopyFile(SrcPath, DestPath);

	cout << "Create Class Successfully\n";
}


void ReadingCourse(listCourse& lC, string path)
{
	ifstream ifs;
	ifs.open(path);
	if (ifs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!(Reading Course)\n";
		return;
	}
	string line;
	getline(ifs, line);
	//while (ifs.good())
	//{
	//	/*getline(ifs, line);
	//	course c = ConvertingCourse(line);
	//	AddCourse(lC, c);*/
	//	/*cout << c.id << endl; 
	//	cout << c.courseName << endl;
	//	cout << c.teacherName << endl;
	//	cout << c.numberOfCredits << endl;
	//	cout << c.maximunNumberOfStudent << endl;
	//	cout << c.dayOfWeek << endl;
	//	cout << c.session << endl;*/
	//}
	getListCourse2(lC, ifs);
	
	ifs.close();
}

course ConvertingCourse(string line)
{
	course c;
	stringstream ssLine(line);
	getline(ssLine, c.id, ',');
	
	getline(ssLine, c.courseName, ',');
	
	getline(ssLine, c.teacherName, ',');
	
	string temp;
	getline(ssLine, temp, ',');
	c.numberOfCredits = stoi(temp);
	
	string temp1, temp2, temp3;
	getline(ssLine, temp1, ',');
	
	getline(ssLine, temp2, ',');

	getline(ssLine, temp3, ',');


	getline(ssLine, c.dayOfWeek, ',');

	getline(ssLine, c.session, ',');

	/*cout << c.id << endl;
		cout << c.courseName << endl;
		cout << c.teacherName << endl;
		cout << c.numberOfCredits << endl;
		cout << c.maximunNumberOfStudent << endl;
		cout << c.dayOfWeek << endl;
		cout << c.session << endl;*/

	return c;
}


void CreateScoreBoardFile(listCourse lC, string path)
{
	nodeCourse* p = lC.pHead;
	int i = 0;
	while (p != NULL)
	{
		string src = path + '\\' + p->info->id + ".csv", dest = exportPath + '\\' + p->info->id + ".csv";
		CopyFile(src, dest);
		p = p->pNext;
	}
}

Student convertingStData(ifstream& ifs) {
	Student st;
	string no;
	getline(ifs, no, ',');
	st.No = stoi(no);
	string id;
	getline(ifs, id, ',');
	st.studentID = stoi(id);
	getline(ifs, st.firstName, ',');
	getline(ifs, st.lastName, ',');
	getline(ifs, st.gender, ',');
	string dob;
	getline(ifs, dob, ',');
	st.dateOfBirth = ConvertingDate(dob);
	string sID;
	getline(ifs, sID, ',');
	st.socialID = stoi(sID);
	string aca;
	getline(ifs, aca);
	st.academicYear = stoi(aca);
	return st;
}

void readInfoOfStudent(ListStudent& list, string cla) {
	string path = "ImportData/" + cla + ".csv";
	ifstream ifs;
	ifs.open(path);
	if (!ifs.is_open()) {
		cout << "Mo file that bai!!!\n";
		return;
	}
	string line;
	getline(ifs, line);
	while (!ifs.eof()) {
		Student st = convertingStData(ifs);
		//chi co chuong trinh dai tra 
		string pro{ cla,2,3 };
		st.program = pro;
		addStudent(list, st);
	}
	ifs.close();
}

Student createInfoStFromUserInfo(User us) {
	Student st;
	ListStudent list = InitListStudent();
	readInfoOfStudent(list, us.className);
	NodeStudent* n = list.pHead;
	while (n != NULL) {
		string sID = to_string(n->Info.studentID);
		if (sID == us.id) {
			st = n->Info;
			break;
		}
		n = n->pNext;
	}
	return st;
}

void Profile(Student info, User us)
{
	clearScreen();
	cout << "INFORMATION OF USER" << endl;
	cout << setw(20) << "Student ID: " << info.studentID << endl;
	cout << setw(20) << "Firset Name: " << info.firstName << endl;
	cout << setw(20) << "Last Name: " << info.lastName << endl;
	cout << setw(20) << "Gender: " << info.gender << endl;
	cout << setw(20) << "Class name: " << us.className << endl;
	cout << setw(20) << "Academic Year: " << info.academicYear << endl;
	cout << setw(20) << "Social ID: " << info.socialID << endl;
	PrintDate(info.dateOfBirth);
}

void DisplayIDCourse(listCourse list) {
	if (list.pTail == NULL) {
		cout << "No Course\n";
		return;
	}
	int cnt = 1;

	nodeCourse* p = list.pHead;
	while (p) {
		cout << "Course " << cnt << endl;
		cout << "ID Course: " << p->info->id << endl;
		cnt++;
		p = p->pNext;
	}
}

void AddStudentToCourse(listCourse& list) {
	// Lấy thông tin Course
	getListCourse(list);
	DisplayIDCourse(list);

	// Cho người dùng nhập mã môn
	string PathID;
	cout << "Enter your ID Course: ";
	cin >> PathID;

	string tmpPath = PathID;
	// Lấy shoolYear hiện tại để đi vào folder niên khóa hiện tại(2023-2024)
	string curSchoolYear;
	GetCurSchoolYear(curSchoolYear, GetCurDate());

	// Lấy semester hiện tại để đi vào folder semester 1, 2, ....
	Semester semes;
	GetCurSemester(semes);
	string curSemes = to_string(semes.semester);

	
	// Người dùng nhập mã môn sẽ không có đuôi ".csv" nên ta kiểm tra rồi thêm vào
	fs::path filePath = PathID;
	if (filePath.extension() != ".csv") {
		PathID += ".csv";
	}

	// Lấy hoàn thành pathCourse
	const string pathCourse = "Data\\SchoolYear\\" + curSchoolYear + "\\semester " + curSemes + "\\" + PathID;
	clearScreen();
	// Path của file csv lớp để lấy danh sách học sinh
	string pathClass = "ImportData\\";
	int choice;
	cout << "1. Add Students using File\n";
	cout << "2. Add one Student by Hand\n";
	cout << "Your choice: "; cin >> choice;
	switch (choice)
	{
	case 1:
	{
		clearScreen();
		string className;
		cout << "Enter Class Name: "; cin >> className;

		fs::path filePath = className;
		if (filePath.extension() != ".csv") {
			className += ".csv";
		}

		pathClass += className;

		// Lấy sinh viên
		ListStudent listS = InitListStudent();
		getListStudentInCLass(listS, pathClass);

		// Ghi sinh viên vào file csv môn học
		ofstream ofs;
		// Mở file để ghi vào cuối file, chứ không ghi đè
		ofs.open(pathCourse, ios::app);
		if (!ofs.is_open()) {
			cout << "Mo file khong thanh cong\n";
			cout << "Ham AddStudentToCourse\n";
			return;
		}


		NodeStudent* st = listS.pHead;
		while (st) {
			ofs << st->Info.No << "," << st->Info.studentID << "," << st->Info.lastName + ' ' + st->Info.firstName << ",";
			// Total Mark
			ofs << 0 << ",";
			// Final Mark
			ofs << 0 << ',';
			// Midterm Mark
			ofs << 0 << ',';
			// Other Mark
			ofs << 0 << endl;

			// Tạo file mssv và ghi môn học vào File mssv trong folder InformationOfStudent
			string FileMssv = "Data\\InformationOfStudent\\";
			FileMssv += to_string(st->Info.studentID) + ".txt";
			ofstream mssvFile(FileMssv, ios::app);
			mssvFile << tmpPath << endl;
			mssvFile.close();
			st = st->pNext;
		}

		ofs.close();

		cout << "Add Student Successfully\n";

		break;
	}
	case 2: {
		clearScreen();

		// Đếm số No tiếp theo của student sắp được nhập tay vào
		ifstream cnt(pathCourse);
		if (!cnt.is_open()) {
			cout << "Mo file khong thanh cong\n";
			return;
		}

		int count = 0;
		string line;
		getline(cnt, line);
		while (getline(cnt, line)) count++;
		cnt.close();

		count += 1;

		// Nhập mssv
		int mssv;
		cout << "Student ID: "; cin >> mssv;

		// Nhập tên
		cin.ignore();
		string tmp;
		cout << "Full name: "; getline(cin, tmp);
		
		// Ghi file
		ofstream fout;
		fout.open(pathCourse, ios::app);
		if (!fout.is_open()) {
			cout << "Mo file khong thanh cong\n";
			return;
		}

		fout << count << "," << mssv << "," << tmp << "," << 0 << "," << 0 << "," << 0 << "," << 0 << endl;
		
		fout.close();


		// Tạo file mssv và ghi môn học vào File mssv trong folder InformationOfStudent
		string FileMssv = "Data\\InformationOfStudent\\";
		FileMssv += to_string(mssv) + ".txt";
		ofstream mssvFile(FileMssv, ios::app);
		mssvFile << tmpPath << endl;
		mssvFile.close();

		cout << "Add Student Successfully\n";

		break;
	}
	default:
		break;
	}
}


void ReadingEnrolledCourse(string ID[], int& n, string path)
{
	ifstream ifs;
	ifs.open(path);
	if (ifs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!(ReadingEnrolledCourse)\n";
		return;
	}
	n = 0;
	while (!ifs.eof())
	{
		getline(ifs, ID[n], '\n');
		/*cout << ID[n] << endl;
		Sleep(500);*/
		n++;
	}
	ifs.close();
}



void FindCourseByID(string ID[], int n, listCourse& lC, string path)
{
	ifstream ifs;
	ifs.open(path);
	if (ifs.is_open() == false)
	{
		cout << "Mo file khong thanh cong!(FindCourseByID)\n";
		return;
	}

	listCourse lcSRC = InitListCourse();
	/*string line;
	getline(ifs, line);*/
	getListCourse2(lcSRC, ifs);
	ifs.close();
	nodeCourse* p = lcSRC.pHead;
	while (p != NULL)
	{
		for (int i = 0; i < n; i++) {
			if (p->info->id == ID[i])
			{
				addCourse(lC, p->info);
			}
		}
		p = p->pNext;
	}

}
void viewScoreBoard() {

	int z, numItem;
	string scy;
	string semester;
	string couID;
	string* item;

	/*cout << "Enter your school year(ex:2023-2024): ";
	cin >> scy;
	cout << "Enter semester(ex:1/2/3): "; cin >> semester;
	cout << "Enter course name: "; getline(cin, cou); getline(cin, cou);
	ifstream ifs;
	ifs.open("Data/SchoolYear/" + scy + "/semester " + semester + "/courses.csv");
	if (!ifs.is_open()) {
		cout << "SEMESTER OR SCHOOL YEAR IS NOT FOUND!!!\n";
		Sleep(1000);
		return;
	}*/
	/*int z, n;
	string* item;
	string SchYear, Sem;*/



	DisplayFilesInDirectory(schoolYearPath, item, numItem);
	DisplayArrString(item, numItem);
	cout << setw(20) << "Choose school year: ";
	cin >> z;
	scy = item[z - 1];
	cout << "Choose semester(1/2/3): ";
	cin >> semester;
	ifstream ifs;
	ifs.open("Data/SchoolYear/" + scy + "/semester " + semester + "/courses.csv");
	if (!ifs.is_open()) {
		cout << "SEMESTER OR SCHOOL YEAR IS NOT FOUND!!!\n";
		Sleep(1000);
		return;
	}
	

	listCourse tempList = InitListCourse();
	printListCourse(tempList, "Data/SchoolYear/" + scy + "/semester " + semester + "/courses.csv");
	cout << "Enter course ID: ";
	cin.ignore();
	getline(cin, couID);
	clearScreen();
	toLower(couID);



	listCourse list = InitListCourse();
	getListCourse2(list, ifs);
	nodeCourse* n = list.pHead;

	
	int cnt = 0;
	while (n != NULL)
	{
		toLower(n->info->id);
		if (n->info->id == couID) {
			cnt++;
			break;
		}
		n = n->pNext;
	}
	if (cnt == 0) {
		cout << "COURSE IS NOT FOUND IN SEMESTER!!!\n";
		Sleep(500);
		return;
	}



	ifs.close();
	ifstream iFS;
	iFS.open("Data/SchoolYear/" + scy + "/semester " + semester + "/" + n->info->id + ".csv");
	if (!iFS.is_open()) {
		cout << "COURSE IS NOT IN SEMESTER!!!\n";
		Sleep(1000);
		return;
	}
	ListStudent l = InitListStudent();
	string line;
	getline(iFS, line);
	while (!iFS.eof()) {
		Student s = convertingScoreBoardData(iFS);
		addStudent(l, s);
	}
	iFS.close();
	printScoreBoard(l);
}

Student convertingScoreBoardData(ifstream& ifs) {
	Student st;
	string no;
	string id;
	getline(ifs, no, ',');
	st.No = stoi(no);
	getline(ifs, id, ',');
	st.studentID = stoi(id);
	getline(ifs, st.firstName, ',');
	string total;
	string final;
	string midterm;
	string other;
	getline(ifs, total, ',');
	st.cMark.totalMark = stof(total);
	getline(ifs, final, ',');
	st.cMark.finalMark = stof(final);
	getline(ifs, midterm, ',');
	st.cMark.midtermMark = stof(midterm);
	getline(ifs, other, '\n');
	st.cMark.otherMark = stof(other);
	return st;
}
void toLower(string& str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
}
/*
2023-2024
1
nhap mon lap trinh
*/
void printScoreBoard(ListStudent list) {
	cout << right << setw(57) << "SCORE BOARD" << endl;
	cout << left << setw(5) << "No" << left << setw(12) << "studentID"
		<< left << setw(25) << "Student Full Name"
		<< left << setw(14) << "totalMark"
		<< left << setw(14) << "finalMark"
		<< left << setw(15) << "midtermMark"
		<< left << setw(15) << "otherMark" << endl;
	NodeStudent* tmp = list.pHead;
	while (tmp != NULL) {
		cout << left << setw(5) << tmp->Info.No << left << setw(12) << tmp->Info.studentID
			<< left << setw(25) << tmp->Info.firstName
			<< left << setw(14) << tmp->Info.cMark.totalMark
			<< left << setw(14) << tmp->Info.cMark.finalMark
			<< left << setw(15) << tmp->Info.cMark.midtermMark
			<< left << setw(15) << tmp->Info.cMark.otherMark << endl;
		tmp = tmp->pNext;
	}
}
void viewScoreBoardSt(Student infoUs, User us) {
	int n = 0;
	string courseID[10], stuID, SchYear, Sem;
	cout << "Choose Semester(1/2/3): ";
	cin >> Sem;
	GetCurSchoolYear(SchYear, GetCurDate());
	listCourse l = InitListCourse();
	ReadingEnrolledCourse(courseID, n, "Data/InformationOfStudent/" + us.id + ".txt");
	FindCourseByID(courseID, n, l, schoolYearPath + "/" + SchYear + "/" + "semester " + Sem + "/" + "courses.csv");
	cout << right << setw(53) << "SCOREBOARD OF SEMESTER " << Sem << endl;
	nodeCourse* n1 = l.pHead;
	if (n1 == NULL) {
		cout << "YOU HAVE NOT ENROLLED COURSES!!!\N";
		Sleep(500);
		return;
	}
	ListStudent ls = InitListStudent();
	while (n1 != NULL) {
		ifstream ifs;
		ifs.open("Data/SchoolYear/" + SchYear + "/semester " + Sem + "/" + n1->info->id + ".csv");
		string line;
		getline(ifs, line);
		while (!ifs.eof()) {
			Student s = convertingScoreBoardData(ifs);
			if (s.studentID == infoUs.studentID) {
				addStudent(ls, s);
				break;
			}
		}
		ifs.close();
		n1 = n1->pNext;
	}
	printScoreBoard1(ls, l);
}
void printScoreBoard1(ListStudent list, listCourse l) {
	cout << left << setw(4) << "No"
		<< left << setw(12) << "Course ID"
		<< left << setw(25) << "Course Name"
		<< left << setw(14) << "totalMark"
		<< left << setw(14) << "finalMark"
		<< left << setw(15) << "midtermMark"
		<< left << setw(15) << "otherMark" << endl;
	NodeStudent* tmp = list.pHead;
	nodeCourse* n = l.pHead;
	int cnt = 1;
	while (tmp != NULL) {
		cout << left << setw(4) << cnt
			<< left << setw(12) << n->info->id
			<< left << setw(30) << n->info->courseName
			<< left << setw(14) << tmp->Info.cMark.totalMark
			<< left << setw(14) << tmp->Info.cMark.finalMark
			<< left << setw(15) << tmp->Info.cMark.midtermMark
			<< left << setw(15) << tmp->Info.cMark.otherMark << endl;
		tmp = tmp->pNext;
		n = n->pNext;
		cnt++;
	}
}