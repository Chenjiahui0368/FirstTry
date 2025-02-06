#pragma once
#ifndef CHEN_H
#define CHEN_H
#include<string>
using namespace std;

//基类
class Account {
	friend class Bank;
protected:
	string id;//账户号
	string password;//密码
	double remain;//账户余额
public:
	Account();
	void deposit();//存款
	void withdrawal();//取款
	void query();//查询余额
	void Show();//显示
	string GetPassword();//获取密码
};

//储蓄账户
class SavingAccount :public Account {
public:
	SavingAccount();
	friend void WriteSa(SavingAccount&);//写储蓄账户
	friend void ChangeSa(SavingAccount&);//修改储蓄账户
};

//信用账户
class CreditAccount :public Account {
	friend class Bank;
	double overdraft;//透支额度
	double Overdraft;//最大允许透支额度
public:
	CreditAccount();
	void Show();//显示
	friend void WriteCr(CreditAccount&);//写信用账户
	friend void ChangeCr(CreditAccount&);//修改信用账户
	void deposit();//存款
	void withdrawal();//取款
	void query();//查询余额及透支额度
};

//Bank
class Bank {
	Account ac; SavingAccount sa; CreditAccount cr;
public:
	Bank() { }
	void SetAccount();//创建账户
	void SearchAccount(SavingAccount&);//查询储蓄账户
	void SearchAccount(CreditAccount&);//查询信用账户
	void DeleteAccount(SavingAccount&);//删除储蓄账户
	void DeleteAccount(CreditAccount&);//删除信用账户
};


void CopyTranSa();//将过渡文件复制到SavingAccount.txt
void CopyTranCr();//将过渡文件复制到CreditAccount.txt
void SavingMenu(SavingAccount&, Bank&);//储蓄账户菜单
void CreditMenu(CreditAccount&, Bank&);//信用账户菜单
void InputPassword(SavingAccount&);//输入密码
void InputPassword(CreditAccount&);

#endif // !CHEN_H