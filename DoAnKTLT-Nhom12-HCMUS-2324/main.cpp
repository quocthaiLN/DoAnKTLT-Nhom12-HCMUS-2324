﻿#include "function.h"

//TKHS: 20126001 1
//TKGV: 110 111


int main()
{
	nodeUser* curUser = NULL;
	nodeUser* tempUser = NULL;
	listUser listUs = InitListUsers();
	do
	{
		tempUser = LoginAccount();
		ReadingUsersData(listUs, userPath);
		curUser = IsUser(tempUser, listUs);
		if (curUser != NULL)
		{
			cout << "Dang nhap thanh cong!\n";
		}
	} while (curUser == NULL);
	system("cls");
	if (curUser->info.isStaff == true)
	{
		actionAcademicStaff(curUser->info, listUs);
	}
	else
	{
		//actionStudent(curUser->info, listUs, infoSt);
	}





	return 0;
}
























//int main()
//{
//	/*menuAcademicStaff();
//	menuUserAccount();*/
//	//menuProfile();
//
//	/*ham loginAccount nen tra ve kieu User de thuc hien cac ham con nho hon */
//	nodeUser* us = new nodeUser;
//	listUser lu = InitListUsers();
//	int lc;
//	while (1)
//	{
//		menuStudent();
//		cout << "Nhap lua chon:\n";
//		cin >> lc;
//		switch (lc) 
//		{
//		case 1:
//			int lc1;
//			menuStudentUserAccount();
//			cout << "Nhap lua chon:\n";
//			cin >> lc1;
//			switch (lc1) {
//			case 1:
//				changePassword(us);
//				break;
//			case 2:
//			{
//				us = LoginAccount();
//				if (IsUser(us, lu) == NULL);
//				us = LoginAccount();
//				break;
//			}
//			case 3:
//				break;
//			}
//			break;
//		case 2:
//			//printInformationOfUser();
//			break;
//		case 3:
//			break;
//		case 8:
//			return 0;
//		}
//	}
//	cout << endl;
//	menuStudentUserAccount();
//
//	/*string src ="D:\\University\\sample\\CourseRegistrationSystem\\Data\\2020-2021\\classes\\first-year classes\\CTT\\20CTT5.csv";
//	string dest;
//	createClass(src, dest);*/
//	return 0;
//}
