#pragma once
class Account
{
public:
	friend class AccountDeal;
	Account(long long account, char password[20], char name[20], char identify[10]);
	~Account();
	Account();

private:
	long long account;//�˻��˺�
	char password[20];//�˻�����
	char name[20];//�˻�����
	char identify[10];//�����Ϣ
	Account *next;
};


