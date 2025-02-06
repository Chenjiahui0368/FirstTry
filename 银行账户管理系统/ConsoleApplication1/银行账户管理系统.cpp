// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include<cmath>
#include"chen.h"
using namespace std;

int main() {
	Account a1; SavingAccount s1; CreditAccount c1; Bank b1;
	int choice = 0;
loop:
	cout << "功能菜单：" << endl;
	cout << "1.注册" << '\t' << "2.登录" << '\t' << "3.退出" << endl;
	cout << "请选择：";
	while (1) {
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3) {
			cout << "输入有误，请重新输入：";
			continue;
		}
		else if (choice == 1) {
			b1.SetAccount();
			cout << "注册成功，返回首页" << endl << endl;
			goto loop;
		}
		else if (choice == 2) {
			int type = 0;
			cout << endl;
			cout << "请选择账户类型（1.储蓄账户 2.信用账户）：";
			while (1) {
				cin >> type;
				cin.ignore();
				if (type != 1 && type != 2) {
					cout << "输入有误，请重新输入：";
					continue;
				}
				else if (type == 1) {
					b1.SearchAccount(s1);//查询对应账户
					InputPassword(s1);//查询完毕，输入密码
					cout << "登录成功" << endl << endl;
					SavingMenu(s1, b1);//进入对应用户菜单
					break;
				}
				else if (type == 2) {
					b1.SearchAccount(c1);
					InputPassword(c1);
					cout << "登录成功" << endl << endl;
					CreditMenu(c1, b1);
					break;
				}
			}
			break;
		}
		else if (choice == 3) return 0;
	}
	return 0;
}

//密码输入
void InputPassword(SavingAccount& s1) {
	string str;
	cout << "请输入密码：";
	while (1) {
		getline(cin, str);
		if (str != s1.GetPassword()) {
			cout << "密码错误，请重新输入：";
			continue;
		}
		break;
	}
}
void InputPassword(CreditAccount& c1) {
	string str;
	cout << "请输入密码：";
	while (1) {
		getline(cin, str);
		if (str != c1.GetPassword()) {
			cout << "密码错误，请重新输入：";
			continue;
		}
		break;
	}
}

//储蓄账户菜单
void SavingMenu(SavingAccount& s1, Bank& b1) {
	int choice = 0;
loop1:
	cout << "（储蓄）功能菜单：" << endl;
	cout << "1.存款" << '\t' << "2.取款" << '\t' << "3.查询余额" << '\t' << "4.注销账户" << '\t' << "5.退出" << endl;
	cout << "请选择：";
	while (1) {
		cin >> choice;
		cout << endl;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
			cout << "输入有误，请重新输入：";
			continue;
		}
		else if (choice == 1) {
			s1.deposit();
			ChangeSa(s1);
			cout << endl;
			goto loop1;
		}
		else if (choice == 2) {
			s1.withdrawal();
			ChangeSa(s1);
			cout << endl;
			goto loop1;
		}
		else if (choice == 3) {
			s1.query();
			cout << endl;
			goto loop1;
		}
		else if (choice == 4) {
			int again = 0;
			cout << "确认注销（1.确认 2.取消）：";
			while (1) {
				cin >> again;//再次确认
				if (again != 1 && again != 2) {
					cout << "输入有误，默认取消" << endl;
					break;
				}
				else if (again == 1) {
					b1.DeleteAccount(s1);//删除账户
					exit(0);
				}
				else if (again == 2) break;
			}
			cout << endl;
			goto loop1;
		}
		else if (choice == 5) break;
	}
}

//信用账户菜单
void CreditMenu(CreditAccount& c1, Bank& b1) {
	int choice = 0;
loop2:
	cout << "（信用）功能菜单：" << endl;
	cout << "1.存款" << '\t' << "2.取款" << '\t' << "3.查询余额及透支额度" << '\t' << "4.注销账户" << '\t' << "5.退出" << endl;
	cout << "请选择：";
	while (1) {
		cin >> choice;
		cout << endl;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
			cout << "输入有误，请重新输入：";
			continue;
		}
		else if (choice == 1) {
			c1.deposit();
			ChangeCr(c1);
			cout << endl;
			goto loop2;
		}
		else if (choice == 2) {
			c1.withdrawal();
			ChangeCr(c1);
			cout << endl;
			goto loop2;
		}
		else if (choice == 3) {
			c1.query();
			cout << endl;
			goto loop2;
		}
		else if (choice == 4) {
			int again = 0;
			cout << "确认注销（1.确认 2.取消）：";
			while (1) {
				cin >> again;
				if (again != 1 && again != 2) {
					cout << "输入有误，默认取消" << endl;
					break;
				}
				else if (again == 1) {
					b1.DeleteAccount(c1);
					exit(0);
				}
				else if (again == 2) break;
			}
			cout << endl;
			goto loop2;
		}
		else if (choice == 5) break;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
