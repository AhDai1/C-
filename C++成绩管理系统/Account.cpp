#include "Account.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
using namespace std;
Account::Account(long long account, char password[20],char name[20],char identify[10])
{
	this->account = account;
	strcpy(this->password, password);
	strcpy(this->name, name);
	strcpy(this->identify, identify);
}
Account::Account()
{

}
Account::~Account()
{

}
