#include<iostream>
#include "chen.h"
#include<cmath>
#include<fstream>
#include<cstdio>
using namespace std;

SavingAccount::SavingAccount() :Account() {  }

//д�����˻�
void WriteSa(SavingAccount& sa) {
	ofstream ofile;
	ofile.open("SavingAccount.txt", ios::app);
	ofile << "�˻��ţ�" << endl << sa.id << endl;
	ofile << "���룺" << endl << sa.password << endl;
	ofile << "�˻���" << endl << sa.remain << endl << endl;
	ofile.close();
}

//�޸Ĵ����˻�
void ChangeSa(SavingAccount& sa) {
	ifstream ifile;
	ifile.open("SavingAccount.txt");
	ofstream ofile;
	ofile.open("Transition.txt");
	string str; int n = 0;
	string line1, line2, line3, line4, line5, line6, line7;
	for (; n < 7; n++) { getline(ifile, str); }//�������з�
	ifile.close();//�ر��ļ����ö�ȡ����
	ifile.open("SavingAccount.txt");
	while (!ifile.eof()) {
		getline(ifile, line1);
		if (line1 == str) break;//line1Ϊ���з�ʱ˵���ļ���ȡ���
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
	}
	ifile.close();
	ofile.close();
	CopyTranSa();
	const char* filename = "Transition.txt";
	if (remove(filename) != 0) cout << "Transition.txt������" << endl;//ɾ�������ļ�
}
//�������ļ����Ƶ�SavingAccount.txt
void CopyTranSa() {
	ifstream ifile;
	ifile.open("Transition.txt");
	ofstream ofile;
	ofile.open("SavingAccount.txt");
	string line, str; int n = 0;
	for (; n < 7; n++) { getline(ifile, str); }//�������з�
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