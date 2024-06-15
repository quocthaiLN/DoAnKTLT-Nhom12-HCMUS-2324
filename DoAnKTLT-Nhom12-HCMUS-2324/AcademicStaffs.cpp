
#include "AcademicStaffs.h"

void menuAcademicStaff() {
	cout << "HCMUS PORTAL" << endl;
	cout << GetCurDate().day << "/" << GetCurDate().month << "/" << GetCurDate().year;
	cout << "\t\t" << "Nguyen Van A" << endl;
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
	cout << "1. School Year Information\n";
	cout << "2. Create Classes\n";
	cout << "3. List of Classes\n";
	cout << "4. Back\n";
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

		ChangePassword(info, lu);
		break;
	}
	case 2:
	{
		Profile(info);
		break;
	}
	}
	return;
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

