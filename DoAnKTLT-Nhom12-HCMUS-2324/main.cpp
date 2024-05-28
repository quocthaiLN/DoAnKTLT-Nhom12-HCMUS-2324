#include "Globals.h"

int main()
{
	/*menuAcademicStaff();
	menuUserAccount();*/
	//menuProfile();

	/*ham loginAccount nen tra ve kieu User de thuc hien cac ham con nho hon */
	int lc;
	while (1)
	{
		menuStudent();
		cout << "Nhap lua chon:\n";
		cin >> lc;
		switch (lc) 
		{
		case 1:
			int lc1;
			menuStudentUserAccount();
			cout << "Nhap lua chon:\n";
			cin >> lc1;
			switch (lc1) {
			case 1:
				//changePassword();
			case 2:
				//LoginAccount(s1, s2);
				//if(isUser == NULL);
				// loginAccount(s1,s2);
				//break;
			case 3:
				break;
			}
			break;
		case 2:
			//printInformationOfUser();
			break;
		case 3:
			break;
		case 8:
			return 0;
		}
	}
	cout << endl;
	menuStudentUserAccount();

	/*string src ="D:\\University\\sample\\CourseRegistrationSystem\\Data\\2020-2021\\classes\\first-year classes\\CTT\\20CTT5.csv";
	string dest;
	createClass(src, dest);*/
	return 0;
}
