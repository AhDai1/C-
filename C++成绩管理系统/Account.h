#pragma once
#include<string>
using namespace std;
class Account
{
public:
	friend class AccountDeal;
	Account(long long account, string password, string name, string identify);
	~Account();
	Account();

private:
	long long account_;//账户账号
	//char password[20];//账户密码
	//char name[20];//账户户名
	//char identify[10];//身份信息
	//Account *next;
	string password_;
	string name_;
	string identify_;
	
};


