#include<iostream>
#include "chen.h"
#include<cmath>
#include<fstream>
using namespace std;

//创建账户
void Bank::SetAccount() {
	int choice = 0, i = 0;
	cout << "请选择您需要创建的账户类型（1.储蓄账户 2.信用账户）：";
	while (1) {
		cin >> choice;
		cin.ignore();
		if (choice != 1 && choice != 2) {
			cout << "输入有误，请重新输入：";
			continue;
		}
		//创建储蓄账户
		else if (choice == 1) {
			cout << "请输入账户号：";
		SaRepeat:
			getline(cin, sa.id);
			ifstream ifile;
			ifile.open("SavingAccount.txt");
			string line; int n = 0;
			getline(ifile, line);//先读取第一行，后续操作直接从id行进行
			while (1) {
				getline(ifile, line);
				if (n == 0) {
					if (line == sa.id) {
						ifile.close();//重输账户号后需从头开始检索文件，因此需先关闭文件重置读取进度
						cout << "账户号重复，请重新输入：";
						goto SaRepeat;
					}
				}
				n++;
				if (n == 7) n = 0;//用于判断是否id行
				if (ifile.eof() != 0) break;
			}
			ifile.close();
			cout << "请输入密码：";
			cin >> sa.password;
			WriteSa(sa);//将新账户写入文件
			break;
		}
		//创建信用账户
		else if (choice == 2) {
			cout << "请输入账户号：";
		CrRepeat:
			getline(cin, cr.id);
			ifstream ifile;
			ifile.open("CreditAccount.txt");
			string line; int n = 0;
			getline(ifile, line);
			while (1) {
				getline(ifile, line);
				if (n == 0) {
					if (line == cr.id) {
						ifile.close();
						cout << "账户号重复，请重新输入：";
						goto CrRepeat;
					}
				}
				n++;
				if (n == 11) n = 0;
				if (ifile.eof() != 0) break;
			}
			ifile.close();
			cout << "请输入密码：";
			cin >> cr.password;
			WriteCr(cr);
			break;
		}
	}
}

//查询储蓄账户
void Bank::SearchAccount(SavingAccount& s1) {
	string str;
	cout << "请输入账户号：";
	getline(cin, str);
	ifstream ifile;
	ifile.open("SavingAccount.txt");
	string line; int n = 0;
	getline(ifile, line);
	while (1) {
		getline(ifile, line);
		if (n == 0) {
			if (line == str) {  //查询到账户，将对应数据读取赋值给s1
				s1.id = line;
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				s1.password = line;
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				s1.remain = stod(line);//读取出来的是string类型，需进行转换
				break;
			}
		}
		n++;
		if (n == 7) n = 0;
		if (ifile.eof() != 0) {
			cout << "该账户号不存在" << endl;
			ifile.close();
			exit(1);
		}
	}
	ifile.close();
}

//查询信用账户
void Bank::SearchAccount(CreditAccount& c1) {
	string str;
	cout << "请输入账户号：";
	getline(cin, str);
	ifstream ifile;
	ifile.open("CreditAccount.txt");
	string line; int n = 0;
	getline(ifile, line);
	while (1) {
		getline(ifile, line);
		if (n == 0) {
			if (line == str) {
				c1.id = line;
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				c1.password = line;
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				c1.remain = stod(line);
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				c1.overdraft = stod(line);
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				c1.Overdraft = stod(line);
				break;
			}
		}
		n++;
		if (n == 11) n = 0;
		if (ifile.eof() != 0) {
			cout << "该账户号不存在" << endl;
			ifile.close();
			exit(1);
		}
	}
	ifile.close();
}

//删除储蓄账户
void Bank::DeleteAccount(SavingAccount& s1) {
	ifstream ifile;
	ifile.open("SavingAccount.txt");
	ofstream ofile;
	ofile.open("Transition.txt");
	string str; int n = 0;
	string line1, line2, line3, line4, line5, line6, line7;
	for (; n < 7; n++) { getline(ifile, str); }//读出换行符
	ifile.close();//关闭文件重置读取进度
	ifile.open("SavingAccount.txt");
	while (!ifile.eof()) {
		getline(ifile, line1);
		if (line1 == str) break;//line1为换行符时说明文件读取完毕
		getline(ifile, line2);
		if (line2 == s1.id) {
			for (n = 0; n < 7; n++) {
				getline(ifile, line2);//只读不写
				if (ifile.eof()) goto Deletesymbol1;//若删除的是最后一个账户，会出现提前读取完毕的情况
			}
		}
		ofile << line1 << endl;
		ofile << line2 << endl;
		getline(ifile, line3);
		ofile << line3 << endl;
		getline(ifile, line4);
		ofile << line4 << endl;
		getline(ifile, line5);
		ofile << line5 << endl;
		getline(ifile, line6);
		ofile << line6 << endl;
		getline(ifile, line7);
		ofile << line7 << endl;
	}
Deletesymbol1:
	ifile.close();
	ofile.close();
	CopyTranSa();//将过渡文件内容复制（覆盖）到对应账户文件
	const char* filename = "Transition.txt";
	if (remove(filename) != 0) cout << "Transition.txt不存在" << endl;//删除过渡文件
}

//删除信用账户
void Bank::DeleteAccount(CreditAccount& c1) {
	ifstream ifile;
	ifile.open("CreditAccount.txt");
	ofstream ofile;
	ofile.open("Transition.txt");
	string str; int n = 0;
	string line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11;
	for (; n < 7; n++) { getline(ifile, str); }//读出换行符
	ifile.close();
	ifile.open("CreditAccount.txt");
	while (!ifile.eof()) {
		getline(ifile, line1);
		if (line1 == str) break;
		getline(ifile, line2);
		if (line2 == c1.id) {
			for (n = 0; n < 11; n++) {
				getline(ifile, line2);
				if (ifile.eof()) goto Deletesymbol2;
			}
		}
		ofile << line1 << endl;
		ofile << line2 << endl;
		getline(ifile, line3);
		ofile << line3 << endl;
		getline(ifile, line4);
		ofile << line4 << endl;
		getline(ifile, line5);
		ofile << line5 << endl;
		getline(ifile, line6);
		ofile << line6 << endl;
		getline(ifile, line7);
		ofile << line7 << endl;
		getline(ifile, line8);
		ofile << line8 << endl;
		getline(ifile, line9);
		ofile << line9 << endl;
		getline(ifile, line10);
		ofile << line10 << endl;
		getline(ifile, line11);
		ofile << line11 << endl;
	}
Deletesymbol2:
	ifile.close();
	ofile.close();
	CopyTranCr();
	const char* filename = "Transition.txt";
	if (remove(filename) != 0) cout << "Transition.txt不存在" << endl;//删除过渡文件
}