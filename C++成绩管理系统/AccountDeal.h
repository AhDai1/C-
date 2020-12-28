#pragma once
#include "Account.h"
#include"Draw.h"
class Draw;
class AccountDeal
{
public:

	void creat_file_m();//创建账户信息文件 
	void register_m();
	Account *creat_list_message();
	void login();
	void menu_initial();
	void end();
	char menu_initial_selete();
	void menu_student();
	char menu_student_selete();
	void menu_teacher();
	char menu_teacher_selete();
};


