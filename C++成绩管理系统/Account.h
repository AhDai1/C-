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
	long long account_;//�˻��˺�
	//char password[20];//�˻�����
	//char name[20];//�˻�����
	//char identify[10];//�����Ϣ
	//Account *next;
	string password_;
	string name_;
	string identify_;
	
};


