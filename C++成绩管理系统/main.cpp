#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Account.h"
#include"AccountDeal.h"
#include"Draw.h"
#include"Student.h"
#include"StudentDeal.h"
using namespace std;

int main()
{
	AccountDeal Act;
	StudentDeal S;
	S.creat_file();
	Act.creat_file_m();
	//S.welcome();
	Act.menu_initial();
	return 0;
}
