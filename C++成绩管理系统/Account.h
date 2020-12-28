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
	long long account_;//’Àªß’À∫≈
	string password_;
	string name_;
	string identify_;
	
};


