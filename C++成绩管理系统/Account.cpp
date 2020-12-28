#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<Windows.h>
#include "Account.h"
using namespace std;
Account::Account(long long account, string password, string name, string identify) :
	account_(account),password_(password),name_(name),identify_(identify)
{
	
}
Account::Account()
{

}
Account::~Account()
{

}
