#include "function.h"

//TKHS: 231201 1
//TKGV: 110 123


int main() {
    // Khởi tạo cửa sổ console
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

    nodeUser* curUser = nullptr;
    nodeUser* tempUser = nullptr;
    listUser listUs = InitListUsers(); // Khởi tạo danh sách người dùng
    int n = 0;

    do {
        clearScreen();
        if (n >= 1) {
            SetColor(12); // Màu đỏ
            cout << "Tai khoan hoac mat khau sai!!\n";
            SetColor(7); // Màu trắng
        }
        tempUser = LoginAccount(); // Đăng nhập và lấy thông tin người dùng tạm thời
        ReadingUsersData(listUs, userPath); // Đọc dữ liệu người dùng từ file
        curUser = IsUser(tempUser, listUs); // Kiểm tra xem người dùng có tồn tại trong danh sách không
        clearScreen();
        if (curUser != nullptr) {
            SetColor(10); // Màu xanh lá cây
            cout << "DANG NHAP THANH CONG!\n";
            SetColor(7); // Màu trắng
            Sleep(500);
            n = -1;
        }
        n++;
    } while (curUser == nullptr);


    system("cls");

    // Dựa vào loại người dùng, gọi hàm thích hợp để thực hiện các hành động
    if (curUser->info.isStaff == true) {
        actionAcademicStaff(curUser->info, listUs);
    }
    else {
        Student infoSt = createInfoStFromUserInfo(curUser->info);
        actionStudent(curUser->info, listUs, infoSt);
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
