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

//��ȡ����
string Account::GetPassword() { return password; }

//���
void Account::deposit() {
	double amount = 0;
	cout << "��������Ľ�";
	cin >> amount;
	remain += amount;
}

//ȡ��
void Account::withdrawal() {
	double amount = 0;
	cout << "������ȡ��Ľ�";
	cin >> amount;
	if (amount > remain) {
		cout << "����" << endl;
	}
	else if (amount >= 0) {
		remain -= amount;
	}
}

//��ѯ���
void Account::query() {
	cout << "��" << remain << "Ԫ" << endl;
}