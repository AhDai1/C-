#pragma once
class Account
{
public:
	friend class AccountDeal;
	Account(long long account, char password[20], char name[20], char identify[10]);
	~Account();
	Account();

private:
	long long account;//账户账号
	char password[20];//账户密码
	char name[20];//账户户名
	char identify[10];//身份信息
	Account *next;
};


