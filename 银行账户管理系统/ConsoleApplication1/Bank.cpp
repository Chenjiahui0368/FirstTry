#include<iostream>
#include "chen.h"
#include<cmath>
#include<fstream>
using namespace std;

//�����˻�
void Bank::SetAccount() {
	int choice = 0, i = 0;
	cout << "��ѡ������Ҫ�������˻����ͣ�1.�����˻� 2.�����˻�����";
	while (1) {
		cin >> choice;
		cin.ignore();
		if (choice != 1 && choice != 2) {
			cout << "�����������������룺";
			continue;
		}
		//���������˻�
		else if (choice == 1) {
			cout << "�������˻��ţ�";
		SaRepeat:
			getline(cin, sa.id);
			ifstream ifile;
			ifile.open("SavingAccount.txt");
			string line; int n = 0;
			getline(ifile, line);//�ȶ�ȡ��һ�У���������ֱ�Ӵ�id�н���
			while (1) {
				getline(ifile, line);
				if (n == 0) {
					if (line == sa.id) {
						ifile.close();//�����˻��ź����ͷ��ʼ�����ļ���������ȹر��ļ����ö�ȡ����
						cout << "�˻����ظ������������룺";
						goto SaRepeat;
					}
				}
				n++;
				if (n == 7) n = 0;//�����ж��Ƿ�id��
				if (ifile.eof() != 0) break;
			}
			ifile.close();
			cout << "���������룺";
			cin >> sa.password;
			WriteSa(sa);//�����˻�д���ļ�
			break;
		}
		//���������˻�
		else if (choice == 2) {
			cout << "�������˻��ţ�";
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
						cout << "�˻����ظ������������룺";
						goto CrRepeat;
					}
				}
				n++;
				if (n == 11) n = 0;
				if (ifile.eof() != 0) break;
			}
			ifile.close();
			cout << "���������룺";
			cin >> cr.password;
			WriteCr(cr);
			break;
		}
	}
}

//��ѯ�����˻�
void Bank::SearchAccount(SavingAccount& s1) {
	string str;
	cout << "�������˻��ţ�";
	getline(cin, str);
	ifstream ifile;
	ifile.open("SavingAccount.txt");
	string line; int n = 0;
	getline(ifile, line);
	while (1) {
		getline(ifile, line);
		if (n == 0) {
			if (line == str) {  //��ѯ���˻�������Ӧ���ݶ�ȡ��ֵ��s1
				s1.id = line;
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				s1.password = line;
				getline(ifile, line); n++;
				getline(ifile, line); n++;
				s1.remain = stod(line);//��ȡ��������string���ͣ������ת��
				break;
			}
		}
		n++;
		if (n == 7) n = 0;
		if (ifile.eof() != 0) {
			cout << "���˻��Ų�����" << endl;
			ifile.close();
			exit(1);
		}
	}
	ifile.close();
}

//��ѯ�����˻�
void Bank::SearchAccount(CreditAccount& c1) {
	string str;
	cout << "�������˻��ţ�";
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
			cout << "���˻��Ų�����" << endl;
			ifile.close();
			exit(1);
		}
	}
	ifile.close();
}

//ɾ�������˻�
void Bank::DeleteAccount(SavingAccount& s1) {
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
		getline(ifile, line2);
		if (line2 == s1.id) {
			for (n = 0; n < 7; n++) {
				getline(ifile, line2);//ֻ����д
				if (ifile.eof()) goto Deletesymbol1;//��ɾ���������һ���˻����������ǰ��ȡ��ϵ����
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
	CopyTranSa();//�������ļ����ݸ��ƣ����ǣ�����Ӧ�˻��ļ�
	const char* filename = "Transition.txt";
	if (remove(filename) != 0) cout << "Transition.txt������" << endl;//ɾ�������ļ�
}

//ɾ�������˻�
void Bank::DeleteAccount(CreditAccount& c1) {
	ifstream ifile;
	ifile.open("CreditAccount.txt");
	ofstream ofile;
	ofile.open("Transition.txt");
	string str; int n = 0;
	string line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11;
	for (; n < 7; n++) { getline(ifile, str); }//�������з�
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
	if (remove(filename) != 0) cout << "Transition.txt������" << endl;//ɾ�������ļ�
}