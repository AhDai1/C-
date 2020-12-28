#pragma once
#include<list>
#include"Draw.h"
#include"Student.h"
class Draw;

class StudentDeal
{
public:
	friend class AccountDeal;
	void creat_file();
	void creat_list();
	void add_student();
	void print_stu_all();
	void update_stu_id_name();
	void serch_stu();
	void delete_stu();
	char sort_selete();
	void sort_stu();
	void sort_stu_id();
	void sort_stu_sub();
	void sort_stu_sum();
	void screen();
	void welcome();
private:
	list<Student> list_;
};

