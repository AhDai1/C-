#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<string>
#include<vector>
#include<fstream>
#include<iterator>
#include<algorithm>
#include "StudentDeal.h"
using namespace std;
int sub;
//char subjects[10][10] = { "语文","数学","英语","物理","生物","化学","历史","政治","地理" };
vector<string> subjects = { "语文","数学","英语","物理","生物","化学","历史","政治","地理" };
vector<int> courses(10,-1);//储存选择课程的序号 
void StudentDeal::creat_file()//创建学生成绩信息文件 
{
	system("cls");
	FILE *fp = NULL;
	if ((fp = fopen("student.txt", "rb")) == NULL)
	{
		if ((fp = fopen("student.txt", "wb")) == NULL)
		{
			printf("File opens error!\n");
			exit(0);
		}
	}

	if (fclose(fp))
	{
		printf("file close error!\n");
		exit(0);
	}
}
void StudentDeal::creat_list()//创建链表 
{
	int n = 0;
	system("cls");
	list_.clear();
	Student t;
	ifstream ifs("student.txt", ios::in);
	double temp;
	if(ifs)
	while (ifs >> t.id_ >> t.name_ >> t.term_ >> t.sex_)
	{
		n++;
		
		for (int i = 0; i < 10; i++) {
			ifs >> temp;
			t.score_[i] = temp;

		}
		ifs >> t.sum_;
		list_.push_back(t);
	}
	ifs.close();
}
void StudentDeal::add_student()//录入学生信息 
{
	Draw draw;
	long long id;//学号
	string name;//学生姓名
	string term;//学期
	string sex;//性别
	vector<double> score(10,-1);//课程分数
	double sum = 0;//总分
	double sum1 = 0;
	system("cls");
	int n;//学生的人数 
	int i;
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t请输入学生的人数:";
	cin >> n;
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t请输入该学期的课程数:";
	cin >> sub;
	if (sub < 1 || sub>9)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t输入错误请重新输入\n\t\t\t\t\t";
		system("pause");
		return;
	}
	system("cls");
	draw.DrawList(10, 4, 9, 1, 5, 1);
	draw.gotoxy(12, 5);
	printf("1、语文     2、数学     3、英语     4、物理     5、生物     6、化学     7、历史     8、政治     9、地理");
	printf("\n\n\n\n\n\t\t\t请输入该学期相应课程前的序号,输入一个序号回车确认:\n");
	printf("\t\t\t");
	for (i = 1; i <= sub; i++)
	{
		cin >> courses[i];
		cout << "\t\t\t";
		if (courses[i] < 1 || courses[i]>9 || courses[i] == courses[i - 1])
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t\t输入错误，请重新输入:";
			system("pause");
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sum1 = 0;
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t请输入第" << i << "位同学的学号 姓名 学期 性别:\n";
		draw.DrawList(45, 6, 2, 4, 6, 1);
		draw.gotoxy(50, 7); cout << "学号";
		draw.gotoxy(61, 7); cin >> id;
		draw.gotoxy(50, 9); cout << "姓名";
		draw.gotoxy(61, 9); cin >> name;
		draw.gotoxy(50, 11); cout << "学期";
		draw.gotoxy(61, 11); cin >> term;
		draw.gotoxy(50, 13); cout << "性别";
		draw.gotoxy(61, 13); cin >> sex;
		int k = 1;//控制课程输出
		int r = 1;
		system("cls");
		cout << "\n\n\n\n\n";
		/*for (int i = 1; i <= 9; i++)
		{
			score[i] = -1;
		}*/

		draw.gotoxy(45, 5); cout << "请输入课程的分数:";
		draw.DrawList(45, 6, 2, sub, 6, 1);
		int q = 7;
		for (int j = 1; j <= sub; j++)
		{
			draw.gotoxy(50, q);
			cout << subjects[courses[k++] - 1];
			draw.gotoxy(61, q);
			cin >> score[courses[r]];//1、语文，2、数学，3、英语 ,4、物理，5、生物，6、化学，7、历史，8、政治，9、地理 
			sum1 += score[courses[r]];
			sum = sum1;
			r++;
			q += 2;//控制光标下一行
		}
		//Student t(id, name, term, sex, score, sum);
		//fwrite(&t, sizeof(t), 1, fp);//结构体写入文件
		ofstream ofs("student.txt", ios::app);
		ofs << id << " " << name << " " << term << " " << sex << " ";
		for (int i = 0; i < 10; i++) {
			ofs << score[i] << " ";
		}
		ofs << sum << endl;
		ofs.close();
	}
}
void StudentDeal::print_stu_all()//打印所有学生成绩      
{
	system("cls");
	int i, j;

	creat_list();
	if (list_.empty())
	{
		cout << "\n\n\n\n\n\n\n\t\t\t\t没有学生信息\n";
		system("pause");
		return;
	}
	if (!list_.empty())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
		for (j = 1; j <= 9; j++)
		{
			//		count = courses[k++] - 1;
			cout << "\t" << subjects[j - 1];
		}
		cout << "\t总分" << endl;
	}
	else 
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t没有数据\n";
	list<Student>::iterator iter;
	for(iter=list_.begin();iter!=list_.end();iter++)
	{
		if (iter->id_ >= 1e7)
			cout << iter->id_ << "\t";
		else
			cout << iter->id_ << "\t\t";
		cout << iter->name_ << "\t" << iter->term_ << "\t" << iter->sex_;
		for (i = 1; i <= 9; i++)
		{
			if (iter->score_[i] >= 0)
			{
				cout << setprecision(0)<< "\t" << iter->score_[i];
			}
			else if (iter->score_[i] < 0)
			{
				cout << "\t";
			}
		}
		//cout << setprecision(2)<< "\t" << ptr->sum << endl;
		cout << setprecision(0)<< "\t" << iter->sum_ << endl;
	}
	system("pause");
}
void StudentDeal::update_stu_id_name()//更新某一个同学成绩 
{
	Draw draw;
	system("cls");
	int flag2 = 0;

	int sub_id;//要修改的课程序号 
	long long id;
	string name;
	double score;
	int flag1 = 0;//记录是否找到学生
	int flag;//判断是学号查询还是姓名查询 
	system("cls");
	creat_list();
	system("cls");
	draw.DrawList(45, 4, 1, 2, 9, 1);
	draw.gotoxy(47, 5); cout << "1、按学号查找";
	draw.gotoxy(47, 7); cout << "2、按姓名查找";
	draw.gotoxy(47, 9);
	cin >> flag;
	if (flag != 1 && flag != 2)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t\t输入错误请重新输入\n\t\t\t\t\t";
		system("pause");
		return;
	}
	if (flag == 1)
	{
		system("cls");
		draw.DrawList(45, 4, 2, 1, 9, 1);
		draw.gotoxy(50, 5); cout << "请输入学号";
		draw.gotoxy(67, 5); cin >> id;
	}
	else if (flag == 2)
	{
		system("cls");
		draw.DrawList(45, 4, 2, 1, 9, 1);
		draw.gotoxy(50, 5); cout << "请输入姓名";
		draw.gotoxy(67, 5); cin >> name;
	}
	system("cls");
	double temp;
	list<Student>::iterator iter;
	for(iter=list_.begin();iter!=list_.end();iter++)
	{
		if (flag == 1)
		{
			if (iter->id_ == id)
			{
				flag1 = 1;
				system("cls");
				draw.DrawList(10, 2, 9, 1, 5, 1);
				draw.gotoxy(12, 3);
				printf("1、语文     2、数学     3、英语     4、物理     5、生物     6、化学     7、历史     8、政治     9、地理");
				draw.DrawList(38, 5, 2, 2, 9, 1);
				draw.gotoxy(39, 6); cout << "请输入课程前的序号:";
				draw.gotoxy(60, 6); cin >> sub_id;
				if (sub_id < 1 || sub_id>9)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\t\t\t\t输入错误请重新输入\n\t\t\t\t";
					system("pause");
					return;
				}
				draw.gotoxy(39, 8); cout << "输入修改后的分数:";
				draw.gotoxy(60, 8); cin >> score;
				if (iter->score_[sub_id] >= 0)
				{
					temp = score - iter->score_[sub_id];//记录修改后与修改前分数的差值 
					iter->score_[sub_id] = score;
					iter->sum_ += temp;
					break;
				}
				else
				{
					iter->score_[sub_id] = score;
					iter->sum_ += score;
					break;
				}
			}
		}
		else if (flag == 2)
		{
			if (name==iter->name_)
			{
				flag1 = 1;
				system("cls");
				draw.DrawList(10, 2, 9, 1, 5, 1);
				draw.gotoxy(12, 3);
				printf("1、语文     2、数学     3、英语     4、物理     5、生物     6、化学     7、历史     8、政治     9、地理");
				draw.DrawList(38, 5, 2, 2, 9, 1);
				draw.gotoxy(39, 6); cout << "请输入课程前的序号:";
				draw.gotoxy(60, 6); cin >> sub_id;
				if (sub_id < 1 || sub_id>9)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\t\t\t\t输入错误请重新输入\n\t\t\t\t";
					system("pause");
					return;
				}
				draw.gotoxy(39, 8); cout << "输入修改后的分数:";
				draw.gotoxy(60, 8); cin >> score;
				if (iter->score_[sub_id] >= 0)
				{
					temp = score - iter->score_[sub_id];//记录修改后与修改前分数的差值 
					iter->score_[sub_id] = score;
					iter->sum_ += temp;
					break;
				}
				else
				{
					iter->score_[sub_id] = score;
					iter->sum_ += score;
					break;
				}
			}
		}
	}
	if (flag1 == 0)
	{
		cout << "\n\n\n\n\n\n\t\t\t\t\t没有学生信息\n\t\t\t\t\t";
		system("pause");
		return;
	}
	ofstream ofs("student.txt", ios::trunc | ios::out);
	for (iter = list_.begin(); iter != list_.end(); iter++)
	{
		ofs << iter->id_ << " " << iter->name_ << " " << iter->term_ << " " << iter->sex_ << " ";
		for (int i = 0; i < 10; i++) {
			ofs << iter->score_[i] << " ";
		}
		ofs << iter->sum_<<endl;
	}
	ofs.close();
	system("pause");
}
void StudentDeal::serch_stu()//查找某一个同学成绩 
{
	Draw draw;
	system("cls");
	long long id;
	Student *t = NULL;//记录找到学生的节点
	string name;
	int flag;
	creat_list();
	int flag1 = 0;
	system("cls");
	draw.DrawList(45, 4, 1, 2, 11, 1);
	draw.gotoxy(47, 5); cout << "1、按学号查找";
	draw.gotoxy(47, 7); cout << "2、按姓名查找";
	draw.gotoxy(47, 9);
	cin >> flag;
	if (flag != 1 && flag != 2)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t\t输入错误请重新输入\n\t\t\t\t\t";
		system("pause");
		return;
	}
	else if (flag == 1 || flag == 2)
	{
		if (flag == 1)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "请输入学号";
			draw.gotoxy(67, 5); cin >> id;
		}
		else if (flag == 2)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "请输入姓名";
			draw.gotoxy(67, 5); cin >> name;
		}
		list<Student>::iterator iter;
		for (iter = list_.begin(); iter != list_.end(); iter++)
		{
			if (flag == 1)
			{
				if (iter->id_ == id)
				{
					flag1 = 1;
					t = &*iter;
					int k = 1;
					system("cls");
					cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
					for (int i = 1; i <= 9; i++)
					{
						if (iter->score_[i] >= 0)
						{
							cout << "\t" << subjects[i - 1];
						}
					}
					cout << "\t总分" << endl;
					break;
				}
			}
			else if (flag == 2)
			{
				if (iter->name_==name)
				{
					flag1 = 1;
					t = &*iter;
					int k = 1;
					system("cls");
					cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
					for (int i = 1; i <= 9; i++)
					{
						if (iter->score_[i] >= 0)
						{
							cout << "\t" << subjects[i - 1];
						}
					}
					cout << "\t总分" << endl;
					break;
				}
			}
		}
		if (flag1 == 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t无该学生信息\n";
			system("pause");
			return;
		}
		else
		{
			if (iter->id_ >= 1e7)
				cout << iter->id_ << "\t";
			else
				cout << iter->id_ << "\t\t";
			cout << t->name_ << "\t" << t->term_ << "\t" << t->sex_;
			for (int i = 1; i <= 9; i++)
			{
				if (t->score_[i] >= 0)
				{
					cout << setprecision(0)<<"\t" << t->score_[i];
				}
			}
			cout << setprecision(0) << "\t" << t->sum_ << endl;
		}
	}
	system("pause");
}
void StudentDeal::delete_stu()//删除同学信息 
{
	Draw draw;
	system("cls");
	Student t;
	long long id;
	string name;
	creat_list();
	int len = 0;//判断链表多长
	int flag;
	int flag1 = 0;
	int flag2 = 0;
	system("cls");
	draw.DrawList(45, 4, 1, 2, 11, 1);
	draw.gotoxy(47, 5); cout << "1、删除某位同学信息";
	draw.gotoxy(47, 7); cout << "2、删除全部信息";
	draw.gotoxy(47, 9);
	cin >> flag2;
	if (flag2 == 2)
	{
		ofstream ofs("student.txt", ios::trunc | ios::out);
		ofs.close();
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t信息已全部删除\n";
		system("pause");
		return;
	}
	else if (flag2 == 1)
	{
		system("cls");
		draw.DrawList(45, 4, 1, 2, 9, 1);
		draw.gotoxy(47, 5); cout << "1、按学号查找";
		draw.gotoxy(47, 7); cout << "2、按姓名查找";
		draw.gotoxy(47, 9);
		cin >> flag;
		if (flag == 1)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "请输入学号";
			draw.gotoxy(67, 5); cin >> id;
		}
		else if (flag == 2)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "请输入姓名";
			draw.gotoxy(67, 5); cin >> name;
		}
		list<Student>::iterator iter;
		iter = list_.begin();
		while(iter!=list_.end())
		{
			if (flag == 1)
			{
				if (iter->id_ == id)//找到节点 
				{
					iter = list_.erase(iter);
					flag1 = 1;
					break;
				}
			}
			else if (flag == 2)
			{
				if (iter->name_==name)
				{
					iter = list_.erase(iter);
					flag1 = 1;
					break;
				}
			}
			iter++;
		}
		ofstream ofs("student.txt", ios::trunc | ios::out);
		for (iter = list_.begin(); iter != list_.end(); iter++)
		{
			ofs << iter->id_ << " " << iter->name_ << " " << iter->term_ << " " << iter->sex_ << " ";
			for (int i = 0; i < 10; i++) {
				ofs << iter->score_[i] << " ";
			}
			ofs << iter->sum_;
		}
		ofs.close();
		system("cls");
		if (flag1 == 1)
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t信息已删除\n";
		else
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t没有数据\n";

		system("pause");
	}
}
char StudentDeal::sort_selete()
{
	Draw draw;
	char selete;
	system("cls");
	draw.DrawList(45, 4, 1, 4, 13, 1);
	draw.gotoxy(46, 5); cout << "1、按学号从小到大排序";
	draw.gotoxy(46, 7); cout << "2、按总分从高到低排序";
	draw.gotoxy(46, 9); cout << "3、按课程成绩从高到底排序";
	draw.gotoxy(46, 11); cout << "请输入左边序号选择功能:";
	int count_id[15] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int q = 0;
	int k = 1;
	cin >> selete;
	for (;;)
	{
		if (selete >= '1' && selete <= '3')
		{
			return selete;
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t输入错误，请重新输入\n\t\t\t\t\t";
			system("pause");
			return 0;
		}
	}
	system("pause");
}
void StudentDeal::sort_stu()
{
	system("cls");
	char x;
	while (1)
	{
		x = sort_selete();
		switch (x)
		{
		case '1':sort_stu_id(); break;
		case '2':sort_stu_sum(); break;
		case '3':sort_stu_sub(); break;
		}
		break;
	}
}
void StudentDeal::sort_stu_id()//冒泡排序 
{
	system("cls");
	creat_list();
	/*std::sort(list_.begin(), list_.end(), [](Student s1, Student s2) {
		return s1.Get_Id() < s2.Get_Id();
	});*/
	list_.sort([](Student s1, Student s2) {
		return s1.Get_Id() < s2.Get_Id();
	});
	ofstream ofs("student.txt", ios::trunc | ios::out);
	list<Student>::iterator iter;
	for (iter = list_.begin(); iter != list_.end(); iter++)
	{
		ofs << iter->id_ << " " << iter->name_ << " " << iter->term_ << " " << iter->sex_ << " ";
		for (int i = 0; i < 10; i++) {
			ofs << iter->score_[i] << " ";
		}
		ofs << iter->sum_ << endl; ;
	}
	ofs.close();
	
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t排序已完成\n\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::sort_stu_sub()
{
	system("cls");
	int count_id[15] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int count;//储存课程的序号 
	int l = 0;//输出前的序号 
	int k = 1;
	printf("\n\n\n\n\n\t\t\t1、语文，2、数学，3、英语 ,4、物理，5、生物，6、化学，7、历史，8、政治，9、地理");
	cout << "\n\t\t\t\t请输入左边数字选择排序的课程\n";
	cout << "\t\t\t\t";
	while (1)
	{
		cin >> count;
		if (count < 1 || count>9)
		{
			cout << "\n\n\n\n\n\n\n\t\t\t\t输入错误，请重新输入\n\t\t\t\t\t\t";
			system("pause");
			return;
		}
		else break;
	}
	creat_list();

	list_.sort([=](Student s1, Student s2) {
		return s1.Get_Score()[count] > s2.Get_Score()[count];
	});
	ofstream ofs("student.txt", ios::trunc | ios::out);
	list<Student>::iterator iter;
	for (iter = list_.begin(); iter != list_.end(); iter++)
	{
		ofs << iter->id_ << " " << iter->name_ << " " << iter->term_ << " " << iter->sex_ << " ";
		for (int i = 0; i < 10; i++) {
			ofs << iter->score_[i] << " ";
		}
		ofs << iter->sum_ << endl;;
	}
	ofs.close();
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t排序已完成\n\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::sort_stu_sum()
{
	system("cls");
	creat_list();
	list_.sort([](Student s1, Student s2) {
		return s1.Get_Sum() > s2.Get_Sum();
	});
	ofstream ofs("student.txt", ios::trunc | ios::out);
	list<Student>::iterator iter;
	for (iter = list_.begin(); iter != list_.end(); iter++)
	{
		ofs << iter->id_ << " " << iter->name_ << " " << iter->term_ << " " << iter->sex_ << " ";
		for (int i = 0; i < 10; i++) {
			ofs << iter->score_[i] << " ";
		}
		ofs << iter->sum_ << endl;;
	}
	ofs.close();
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t排序已完成\n\t\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::screen()
{
	Draw draw;
	int nums = 0;//记录分数段中的人数
	creat_list();
	printf("\n\n\n\n\n\t1、语文，2、数学，3、英语 ,4、物理，5、生物，6、化学，7、历史，8、政治，9、地理\n");
	cout << "\t\t\t请输入筛选的课程序号:";
	int sub_id;
	cin >> sub_id;
	if (sub_id < 1 || sub_id>9)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t输入错误请重新输入\n\t\t\t\t";
		system("pause");
		return;
	}
	double score_low, score_high;
	system("cls");
	draw.DrawList(45, 4, 2, 2, 9, 1);
	draw.gotoxy(47, 5); cout << "1、请输入最低分";
	draw.gotoxy(67, 5); cin >> score_low;
	draw.gotoxy(47, 7); cout << "2、请输入最高分";
	draw.gotoxy(67, 7); cin >> score_high;
	system("cls");
	cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
	for (int j = 1; j <= 9; j++)
		cout << "\t" << subjects[j - 1];
	cout << "\t总分" << endl;
	int flag = 0;
	list<Student>::iterator iter;
	for (iter = list_.begin(); iter != list_.end(); iter++)
	{
		if (iter->score_[sub_id] >= score_low && iter->score_[sub_id] <= score_high)
		{
			nums++;
			flag = 1;
			if (iter->id_ >= 1e7)
				cout << iter->id_ << "\t";
			else
				cout << iter->id_ << "\t\t";
			cout << iter->name_ << "\t" << iter->term_ << "\t" << iter->sex_;
			for (int i = 1; i <= 9; i++)
			{
				if (iter->score_[i] >= 0)
					cout << setprecision(0) << "\t" << iter->score_[i];
				else
					cout << "\t";
			}
			cout << setprecision(0) << "\t" << iter->sum_ << endl;
		}
	}
	//printf("\t\t\t\t%s成绩%.2lf-%.2lf分数段一共有%d人\n", subjects[sub_id - 1], score_low, score_high, nums);
	cout << "\t\t\t\t" << subjects[sub_id - 1] << "成绩" << setprecision(2) << score_low << "-" << setprecision(2) << score_high <<
		"分数段一共有" << nums << "人" << endl;
	if (flag == 0)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t\t没有符合条件的数据\n";
		system("pause");
		return;
	}
	system("pause");
	return;
}
void StudentDeal::welcome()
{
	Draw draw;
	draw.gotoxy(45, 11);
	printf("欢"); Sleep(400);//延时 
	printf("迎"); Sleep(400);
	printf("使"); Sleep(400);
	printf("用"); Sleep(400);
	printf("成"); Sleep(400);
	printf("绩"); Sleep(400);
	printf("管"); Sleep(400);
	printf("理"); Sleep(400);
	printf("系"); Sleep(400);
	printf("统\n"); Sleep(400);
}