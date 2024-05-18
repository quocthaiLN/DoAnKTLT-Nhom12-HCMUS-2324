#include "Globals.h"

void menuStudent() {
	cout << "HCMUS PORTAL\n";
	cout << GetCurDate().day << "/" << GetCurDate().month << "/" << GetCurDate().year;
	cout << "\t\t\t" << "Nguyen Van A" << endl;
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
	cout << "HCMUS PORTAL\n";
	cout << "User Account\n";
	cout << "1. Change Password\n";
	cout << "2. Logout\n";
	cout << "3. Back\n";
}

void menuStudentProfile() {
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
	cout << "HCMUS PORTAL\n";
	cout << "Courses Registration\n";
	cout << "1. Register Courses\n";
	cout << "2. View Enrolled Courses\n";
	cout << "3. Back" << endl;
}

//void menuScoreboard() {
//
//}


