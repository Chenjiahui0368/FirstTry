#include<iostream>
#include "chen.h"
#include<cmath>
#include<fstream>
using namespace std;

Account::Account() {
	id = "0000000000";
	password = "0000000000";
	remain = 0;
}
void Account::Show() {
	cout << id << endl << remain << endl;
}

//获取密码
string Account::GetPassword() { return password; }

//存款
void Account::deposit() {
	double amount = 0;
	cout << "请输入存款的金额：";
	cin >> amount;
	remain += amount;
}

//取款
void Account::withdrawal() {
	double amount = 0;
	cout << "请输入取款的金额：";
	cin >> amount;
	if (amount > remain) {
		cout << "余额不足" << endl;
	}
	else if (amount >= 0) {
		remain -= amount;
	}
}

//查询余额
void Account::query() {
	cout << "余额：" << remain << "元" << endl;
}