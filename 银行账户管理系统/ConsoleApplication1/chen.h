#pragma once
#ifndef CHEN_H
#define CHEN_H
#include<string>
using namespace std;

//����
class Account {
	friend class Bank;
protected:
	string id;//�˻���
	string password;//����
	double remain;//�˻����
public:
	Account();
	void deposit();//���
	void withdrawal();//ȡ��
	void query();//��ѯ���
	void Show();//��ʾ
	string GetPassword();//��ȡ����
};

//�����˻�
class SavingAccount :public Account {
public:
	SavingAccount();
	friend void WriteSa(SavingAccount&);//д�����˻�
	friend void ChangeSa(SavingAccount&);//�޸Ĵ����˻�
};

//�����˻�
class CreditAccount :public Account {
	friend class Bank;
	double overdraft;//͸֧���
	double Overdraft;//�������͸֧���
public:
	CreditAccount();
	void Show();//��ʾ
	friend void WriteCr(CreditAccount&);//д�����˻�
	friend void ChangeCr(CreditAccount&);//�޸������˻�
	void deposit();//���
	void withdrawal();//ȡ��
	void query();//��ѯ��͸֧���
};

//Bank
class Bank {
	Account ac; SavingAccount sa; CreditAccount cr;
public:
	Bank() { }
	void SetAccount();//�����˻�
	void SearchAccount(SavingAccount&);//��ѯ�����˻�
	void SearchAccount(CreditAccount&);//��ѯ�����˻�
	void DeleteAccount(SavingAccount&);//ɾ�������˻�
	void DeleteAccount(CreditAccount&);//ɾ�������˻�
};


void CopyTranSa();//�������ļ����Ƶ�SavingAccount.txt
void CopyTranCr();//�������ļ����Ƶ�CreditAccount.txt
void SavingMenu(SavingAccount&, Bank&);//�����˻��˵�
void CreditMenu(CreditAccount&, Bank&);//�����˻��˵�
void InputPassword(SavingAccount&);//��������
void InputPassword(CreditAccount&);

#endif // !CHEN_H