#include<iostream>
#include "chen.h"
#include<cmath>
#include<fstream>
using namespace std;

CreditAccount::CreditAccount() :Account() { overdraft = 200; Overdraft = 200; }
void CreditAccount::Show() {
	this->Account::Show();
	cout << overdraft << endl << Overdraft << endl;
}

//д�����˻�
void WriteCr(CreditAccount& cr) {
	ofstream ofile;
	ofile.open("CreditAccount.txt", ios::app);
	ofile << "�˻��ţ�" << endl << cr.id << endl;
	ofile << "���룺" << endl << cr.password << endl;
	ofile << "�˻���" << endl << cr.remain << endl;
	ofile << "͸֧��ȣ�" << endl << cr.overdraft << endl;
	ofile << "�������͸֧��ȣ�" << endl << cr.Overdraft << endl << endl;
	ofile.close();
}

//�޸������˻�
void ChangeCr(CreditAccount& cr) {
	ifstream ifile;
	ifile.open("CreditAccount.txt");
	ofstream ofile;
	ofile.open("Transition.txt");
	string str; int n = 0;
	string line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11;
	for (; n < 11; n++) { getline(ifile, str); }//�������з�
	ifile.close();//�ر��ļ����ö�ȡ����
	ifile.open("CreditAccount.txt");
	while (!ifile.eof()) {
		getline(ifile, line1);
		if (line1 == str) break;//line1Ϊ���з�ʱ˵���ļ���ȡ���
		ofile << line1 << endl;
		getline(ifile, line2);
		if (line2 == cr.id) {
			ofile << cr.id << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			getline(ifile, line2);
			ofile << cr.password << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			getline(ifile, line2);
			ofile << cr.remain << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			getline(ifile, line2);
			ofile << cr.overdraft << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			getline(ifile, line2);
			ofile << cr.Overdraft << endl;
			getline(ifile, line2);
			ofile << line2 << endl;
			continue;//�޸���ϣ����ؼ�����ȡ
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
		getline(ifile, line8);
		ofile << line8 << endl;
		getline(ifile, line9);
		ofile << line9 << endl;
		getline(ifile, line10);
		ofile << line10 << endl;
		getline(ifile, line11);
		ofile << line11 << endl;
	}
	ifile.close();
	ofile.close();
	CopyTranCr();
	const char* filename = "Transition.txt";
	if (remove(filename) != 0) cout << "Transition.txt������" << endl;//ɾ�������ļ�
}
//�������ļ����Ƶ�CreditAccount.txt
void CopyTranCr() {
	ifstream ifile;
	ifile.open("Transition.txt");
	ofstream ofile;
	ofile.open("CreditAccount.txt");
	string line, str; int n = 0;
	for (; n < 11; n++) { getline(ifile, str); }//�������з�
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

//���
void CreditAccount::deposit() {
	double amount = 0;
	if (overdraft < Overdraft) cout << "����͸֧" << Overdraft - overdraft << "Ԫ����ʣ" << overdraft << "Ԫ͸֧���" << endl;
	cout << "��������Ľ�";
	cin >> amount;
	if (overdraft < Overdraft) {
		amount = amount - (Overdraft - overdraft);
		if (amount >= 0) { remain = amount; overdraft = Overdraft; }
		else { remain = 0; overdraft = Overdraft + amount; }
	}
	else { remain += amount; }
}

//ȡ��
void CreditAccount::withdrawal() {
	double amount = 0;
	if (overdraft < Overdraft) cout << "����͸֧" << Overdraft - overdraft << "Ԫ����ʣ" << overdraft << "Ԫ͸֧���" << endl;
	cout << "������ȡ��Ľ�";
	cin >> amount;
	if (amount > (remain + overdraft)) {
		cout << "͸֧��Ȳ���" << endl;
	}
	else if (amount > remain) {
		overdraft = overdraft - (amount - remain);
		remain = 0;
	}
	else if (amount >= 0) {
		remain -= amount;
	}
}

//��ѯ��͸֧���
void CreditAccount::query() {
	cout << "��" << remain << '\t' << "͸֧��ȣ�" << overdraft << '\t' << "�������͸֧��ȣ�" << Overdraft << endl;
}