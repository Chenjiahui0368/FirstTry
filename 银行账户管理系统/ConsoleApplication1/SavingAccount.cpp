#include<iostream>
#include "chen.h"
#include<cmath>
#include<fstream>
#include<cstdio>
using namespace std;

SavingAccount::SavingAccount() :Account() {  }

//写储蓄账户
void WriteSa(SavingAccount& sa) {
	ofstream ofile;
	ofile.open("SavingAccount.txt", ios::app);
	ofile << "账户号：" << endl << sa.id << endl;
	ofile << "密码：" << endl << sa.password << endl;
	ofile << "账户余额：" << endl << sa.remain << endl << endl;
	ofile.close();
}

//修改储蓄账户
void ChangeSa(SavingAccount& sa) {
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
		ofile << line1 << endl;
		getline(ifile, line2);
		if (line2 == sa.id) {
			ofile << sa.id << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			getline(ifile, line2);
			ofile << sa.password << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			getline(ifile, line2);
			ofile << sa.remain << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			continue;//修改完毕，返回继续读取
		}
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
	ifile.close();
	ofile.close();
	CopyTranSa();
	const char* filename = "Transition.txt";
	if (remove(filename) != 0) cout << "Transition.txt不存在" << endl;//删除过渡文件
}
//将过渡文件复制到SavingAccount.txt
void CopyTranSa() {
	ifstream ifile;
	ifile.open("Transition.txt");
	ofstream ofile;
	ofile.open("SavingAccount.txt");
	string line, str; int n = 0;
	for (; n < 7; n++) { getline(ifile, str); }//读出换行符
	ifile.close();
	ifile.open("Transition.txt");
	while (!ifile.eof()) {
		getline(ifile, line);
		if (line == str) {
			n++;
			if (n == 2) { n = 0; break; }
		}
		else if (line != str) n = 0;
		ofile << line << endl;
	}
	ifile.close();
	ofile.close();
}