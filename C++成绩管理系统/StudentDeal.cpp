#include "StudentDeal.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<Windows.h>
using namespace std;
int sub;
char subjects[10][10] = { "语文","数学","英语","物理","生物","化学","历史","政治","地理" };
int courses[10];//储存选择课程的序号 
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
Student* StudentDeal::creat_list()//创建链表 
{
	int n = 0;
	system("cls");
	Student t;
	Student *head, *p, *q;
	FILE *fp = NULL;
	int i;
	p = new Student;
	head = p;
	if ((fp = fopen("student.txt", "rb")) == NULL)
	{
		cout << "File opens error!\n";
		exit(0);
	}
	rewind(fp);
	while (fread(&t, sizeof(t), 1, fp) != 0)
	{
		n++;
		q = new Student;
		q->id = t.id;
		strcpy(q->name, t.name);
		strcpy(q->term, t.term);
		strcpy(q->sex, t.sex);
		int k = 1;
		for (i = 1; i <= 9; i++)
		{
			q->score[i] = t.score[i];
		}
		q->sum = t.sum;
		p->next = q;
		p = q;
	}
	p->next = NULL;
	if (fclose(fp))
	{
		cout << "File close error!\n";
		exit(0);
	}
	return head;
}
void StudentDeal::add_student()//录入学生信息 
{
	long long id;//学号
	char name[20];//学生姓名
	char term[20];//学期
	char sex[5];//性别
	double score[10];//课程分数
	double sum = 0;//总分
	double sum1 = 0;
	system("cls");
	FILE *fp = NULL;
	int n;//学生的人数 
	int i;
	if ((fp = fopen("student.txt", "ab")) == NULL)
	{
		cout << "File opens error!\n";
		exit(0);
	}
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
	DrawList(10, 4, 9, 1, 5, 1);
	gotoxy(12, 5);
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
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t请输入第" << i << "位同学的学号 姓名 学期 性别:\n";
		DrawList(45, 6, 2, 4, 6, 1);
		gotoxy(50, 7); cout << "学号";
		gotoxy(61, 7); cin >> id;
		gotoxy(50, 9); cout << "姓名";
		gotoxy(61, 9); cin >> name;
		gotoxy(50, 11); cout << "学期";
		gotoxy(61, 11); cin >> term;
		gotoxy(50, 13); cout << "性别";
		gotoxy(61, 13); cin >> sex;
		int k = 1;//控制课程输出
		int r = 1;
		system("cls");
		cout << "\n\n\n\n\n";
		for (int i = 1; i <= 9; i++)
		{
			score[i] = -1;
		}

		gotoxy(45, 5); cout << "请输入课程的分数:";
		DrawList(45, 6, 2, sub, 6, 1);
		int q = 7;
		for (int j = 1; j <= sub; j++)
		{
			gotoxy(50, q);
			cout << subjects[courses[k++] - 1];
			gotoxy(61, q);
			cin >> score[courses[r]];//1、语文，2、数学，3、英语 ,4、物理，5、生物，6、化学，7、历史，8、政治，9、地理 
			sum1 += score[courses[r]];
			sum = sum1;
			r++;
			q += 2;//控制光标下一行
		}
		Student t(id, name, term, sex, score, sum);
		fwrite(&t, sizeof(t), 1, fp);//结构体写入文件
	}
	if (fclose(fp))
	{
		system("cls");
		cout << "file close error!\n";
		exit(0);
	}
}
void StudentDeal::print_stu_all()//打印所有学生成绩      
{
	system("cls");
	FILE *fp = NULL;
	int i, j;
	Student *ptr;
	Student *h;
	h = creat_list();
	ptr = h;
	if (h == NULL)
	{
		cout << "\n\n\n\n\n\n\n\t\t\t\t没有学生信息\n";
		system("pause");
		return;
	}
	if (ptr->next != NULL)
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
	else if (ptr->next == NULL)
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t没有数据\n";
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		if (ptr->id >= 1e7)
			cout << ptr->id << "\t";
		else
			cout << ptr->id << "\t\t";
		cout << ptr->name << "\t" << ptr->term << "\t" << ptr->sex;
		for (i = 1; i <= 9; i++)
		{
			if (ptr->score[i] >= 0)
			{
				cout << setprecision(0)<< "\t" << ptr->score[i];
			}
			else if (ptr->score[i] < 0)
			{
				cout << "\t";
			}
		}
		//cout << setprecision(2)<< "\t" << ptr->sum << endl;
		cout << setprecision(0)<< "\t" << ptr->sum << endl;
	}
	system("pause");
}
void StudentDeal::update_stu_id_name()//更新某一个同学成绩 
{
	system("cls");
	int flag2 = 0;

	FILE *fp = NULL;
	Student *ptr = NULL;
	int sub_id;//要修改的课程序号 
	long long id;
	char name[20];
	double score;
	int flag1 = 0;//记录是否找到学生
	int flag;//判断是学号查询还是姓名查询 
	system("cls");
	Student *h;
	h = creat_list();
	system("cls");
	DrawList(45, 4, 1, 2, 9, 1);
	gotoxy(47, 5); cout << "1、按学号查找";
	gotoxy(47, 7); cout << "2、按姓名查找";
	gotoxy(47, 9);
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
		DrawList(45, 4, 2, 1, 9, 1);
		gotoxy(50, 5); cout << "请输入学号";
		gotoxy(67, 5); cin >> id;
	}
	else if (flag == 2)
	{
		system("cls");
		DrawList(45, 4, 2, 1, 9, 1);
		gotoxy(50, 5); cout << "请输入姓名";
		gotoxy(67, 5); cin >> name;
	}
	system("cls");
	double temp;
	ptr = h;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		if (flag == 1)
		{
			if (ptr->id == id)
			{
				flag1 = 1;
				system("cls");
				DrawList(10, 2, 9, 1, 5, 1);
				gotoxy(12, 3);
				printf("1、语文     2、数学     3、英语     4、物理     5、生物     6、化学     7、历史     8、政治     9、地理");
				DrawList(38, 5, 2, 2, 9, 1);
				gotoxy(39, 6); cout << "请输入课程前的序号:";
				gotoxy(60, 6); cin >> sub_id;
				if (sub_id < 1 || sub_id>9)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\t\t\t\t输入错误请重新输入\n\t\t\t\t";
					system("pause");
					return;
				}
				gotoxy(39, 8); cout << "输入修改后的分数:";
				gotoxy(60, 8); cin >> score;
				if (ptr->score[sub_id] >= 0)
				{
					temp = score - ptr->score[sub_id];//记录修改后与修改前分数的差值 
					ptr->score[sub_id] = score;
					ptr->sum += temp;
					break;
				}
				else
				{
					ptr->score[sub_id] = score;
					ptr->sum += score;
					break;
				}
			}
		}
		else if (flag == 2)
		{
			if (strcmp(name, ptr->name) == 0)
			{
				flag1 = 1;
				system("cls");
				DrawList(10, 2, 9, 1, 5, 1);
				gotoxy(12, 3);
				printf("1、语文     2、数学     3、英语     4、物理     5、生物     6、化学     7、历史     8、政治     9、地理");
				DrawList(38, 5, 2, 2, 9, 1);
				gotoxy(39, 6); cout << "请输入课程前的序号:";
				gotoxy(60, 6); cin >> sub_id;
				if (sub_id < 1 || sub_id>9)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\t\t\t\t输入错误请重新输入\n\t\t\t\t";
					system("pause");
					return;
				}
				gotoxy(39, 8); cout << "输入修改后的分数:";
				gotoxy(60, 8); cin >> score;
				if (ptr->score[sub_id] >= 0)
				{
					temp = score - ptr->score[sub_id];//记录修改后与修改前分数的差值 
					ptr->score[sub_id] = score;
					ptr->sum += temp;
					break;
				}
				else
				{
					ptr->score[sub_id] = score;
					ptr->sum += score;
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
	if ((fp = fopen("student.txt", "wb")) == NULL)
	{
		printf("File opens error!\n");
		exit(0);
	}
	ptr = h;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		fwrite(ptr, sizeof(Student), 1, fp);
	}
	if (fclose(fp))
	{
		printf("File close error!\n");
		exit(0);
	}
	system("pause");
}
void StudentDeal::serch_stu()//查找某一个同学成绩 
{
	system("cls");
	FILE *fp = NULL;
	long long id;
	Student *t = NULL;//记录找到学生的节点
	char name[20];
	Student *ptr;
	int flag;
	Student *h;
	h = creat_list();
	ptr = h;
	int flag1 = 0;
	system("cls");
	DrawList(45, 4, 1, 2, 11, 1);
	gotoxy(47, 5); cout << "1、按学号查找";
	gotoxy(47, 7); cout << "2、按姓名查找";
	gotoxy(47, 9);
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
			DrawList(45, 4, 2, 1, 9, 1);
			gotoxy(50, 5); cout << "请输入学号";
			gotoxy(67, 5); cin >> id;
		}
		else if (flag == 2)
		{
			system("cls");
			DrawList(45, 4, 2, 1, 9, 1);
			gotoxy(50, 5); cout << "请输入姓名";
			gotoxy(67, 5); cin >> name;
		}
		ptr = h;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
			if (flag == 1)
			{
				if (ptr->id == id)
				{
					flag1 = 1;
					t = ptr;
					int k = 1;
					system("cls");
					cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
					for (int i = 1; i <= 9; i++)
					{
						if (ptr->score[i] >= 0)
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
				if (strcmp(name, ptr->name) == 0)
				{
					flag1 = 1;
					t = ptr;
					int k = 1;
					system("cls");
					cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
					for (int i = 1; i <= 9; i++)
					{
						if (ptr->score[i] >= 0)
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
			if (ptr->id >= 1e7)
				cout << ptr->id << "\t";
			else
				cout << ptr->id << "\t\t";
			cout << t->name << "\t" << t->term << "\t" << t->sex;
			for (int i = 1; i <= 9; i++)
			{
				if (t->score[i] >= 0)
				{
					cout << setprecision(0)<<"\t" << t->score[i];
				}
			}
			cout << setprecision(0) << "\t" << t->sum << endl;
		}
	}
	system("pause");
}
void StudentDeal::delete_stu()//删除同学信息 
{
	system("cls");
	Student *ptr, *q;
	Student t;
	long long id;
	char name[20];
	FILE *fp = NULL;
	Student *h;
	h = creat_list();
	Student *run;
	int len = 0;//判断链表多长
	run = h;
	ptr = h;
	int flag;
	int flag1 = 0;
	int flag2 = 0;
	system("cls");
	DrawList(45, 4, 1, 2, 11, 1);
	gotoxy(47, 5); cout << "1、删除某位同学信息";
	gotoxy(47, 7); cout << "2、删除全部信息";
	gotoxy(47, 9);
	cin >> flag2;
	if (flag2 == 2)
	{
		if ((fp = fopen("student.txt", "wb")) == NULL)
		{
			printf("File opens error!\n");
			exit(0);
		}
		if (fclose(fp))
		{
			printf("File close error!\n");
			exit(0);
		}
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t信息已全部删除\n";
		system("pause");
		return;
	}
	else if (flag2 == 1)
	{
		system("cls");
		DrawList(45, 4, 1, 2, 9, 1);
		gotoxy(47, 5); cout << "1、按学号查找";
		gotoxy(47, 7); cout << "2、按姓名查找";
		gotoxy(47, 9);
		cin >> flag;
		if (flag == 1)
		{
			system("cls");
			DrawList(45, 4, 2, 1, 9, 1);
			gotoxy(50, 5); cout << "请输入学号";
			gotoxy(67, 5); cin >> id;
		}
		else if (flag == 2)
		{
			system("cls");
			DrawList(45, 4, 2, 1, 9, 1);
			gotoxy(50, 5); cout << "请输入姓名";
			gotoxy(67, 5); cin >> name;
		}
		while (ptr->next != NULL)
		{
			q = ptr;
			ptr = ptr->next;
			if (flag == 1)
			{
				if (ptr->id == id)//找到节点 
				{
					q->next = ptr->next;
					free(ptr);//释放节点
					flag1 = 1;
					break;
				}
			}
			else if (flag == 2)
			{
				if (strcmp(ptr->name, name) == 0)
				{
					q->next = ptr->next;
					free(ptr);
					flag1 = 1;
					break;
				}
			}
		}
		if ((fp = fopen("student.txt", "wb")) == NULL)
		{
			printf("File opens error!\n");
			exit(0);
		}
		run = h;
		while (run->next != NULL)
		{
			run = run->next;
			fwrite(run, sizeof(Student), 1, fp);
		}
		if (fclose(fp))
		{
			system("cls");
			printf("file close error!\n");
			exit(0);
		}
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
	char selete;
	system("cls");
	DrawList(45, 4, 1, 4, 13, 1);
	gotoxy(46, 5); cout << "1、按学号从小到大排序";
	gotoxy(46, 7); cout << "2、按总分从高到低排序";
	gotoxy(46, 9); cout << "3、按课程成绩从高到底排序";
	gotoxy(46, 11); cout << "请输入左边序号选择功能:";
	int count_id[15] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int q = 0;
	int k = 1;
	cin >> selete;
	for (;;)
	{
		if (selete >= 1 && selete <= 3)
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
	int x;
	while (1)
	{
		x = sort_selete();
		switch (x)
		{
		case 1:sort_stu_id(); break;
		case 2:sort_stu_sum(); break;
		case 3:sort_stu_sub(); break;
		}
		break;
	}
}
void StudentDeal::sort_stu_id()//冒泡排序 
{
	system("cls");
	Student *q, *p, *tail;
	Student *t;
	FILE *fp = NULL;
	Student *run;
	tail = NULL;
	Student *h;
	h = creat_list();
	while (h->next != tail)
	{
		p = h;
		q = h->next;
		while (q->next != tail)
		{
			if (q->id > q->next->id)
			{
				t = q->next;
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = t;
			}
			// 节点后移
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	if ((fp = fopen("student.txt", "wb")) == NULL)
	{
		printf("File opens error!\n");
		exit(0);
	}
	run = h;
	//	rewind(fp);
	while (run->next != NULL)
	{
		run = run->next;
		fwrite(run, sizeof(Student), 1, fp);
	}
	if (fclose(fp))
	{
		system("cls");
		printf("file close error!\n");
		exit(0);
	}
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t排序已完成\n\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::sort_stu_sub()
{
	system("cls");
	FILE *fp = NULL;
	Student *run;
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
	Student *q, *p, *tail;
	Student *t;
	tail = NULL;
	Student *h;
	h = creat_list();
	while (h->next != tail)
	{
		p = h;
		q = h->next;
		while (q->next != tail)
		{
			if (q->score[count] < q->next->score[count])
			{
				t = q->next;
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = t;
			}
			// 节点后移
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	if ((fp = fopen("student.txt", "wb")) == NULL)
	{
		printf("File opens error!\n");
		exit(0);
	}
	run = h;
	//	rewind(fp);
	while (run->next != NULL)
	{
		run = run->next;
		fwrite(run, sizeof(Student), 1, fp);
	}
	if (fclose(fp))
	{
		system("cls");
		printf("file close error!\n");
		exit(0);
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t排序已完成\n\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::sort_stu_sum()
{
	FILE *fp = NULL;
	Student *run;
	system("cls");
	Student *q, *p, *tail;
	Student *t;
	tail = NULL;
	Student *h;
	h = creat_list();
	while (h->next != tail)
	{
		p = h;
		q = h->next;
		while (q->next != tail)
		{
			if (q->sum < q->next->sum)
			{
				t = q->next;
				p->next = q->next;
				q->next = q->next->next;
				p->next->next = q;
				q = t;
			}
			// 节点后移
			q = q->next;
			p = p->next;
		}
		tail = q;
	}
	if ((fp = fopen("student.txt", "wb")) == NULL)
	{
		printf("File opens error!\n");
		exit(0);
	}
	run = h;
	while (run->next != NULL)
	{
		run = run->next;
		fwrite(run, sizeof(Student), 1, fp);
	}
	if (fclose(fp))
	{
		system("cls");
		printf("file close error!\n");
		exit(0);
	}
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t排序已完成\n\t\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::screen()
{
	int nums = 0;//记录分数段中的人数
	FILE *fp = NULL;
	Student *ptr;
	if ((fp = fopen("student.txt", "rb")) == NULL)
	{
		printf("File opens error!\n");
		exit(0);
	}
	Student *h;
	h = creat_list();
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
	DrawList(45, 4, 2, 2, 9, 1);
	gotoxy(47, 5); cout << "1、请输入最低分";
	gotoxy(67, 5); cin >> score_low;
	gotoxy(47, 7); cout << "2、请输入最高分";
	gotoxy(67, 7); cin >> score_high;
	system("cls");
	cout << "\n\n\n\n\n\n\n学号\t\t姓名\t学期\t性别";
	for (int j = 1; j <= 9; j++)
		cout << "\t" << subjects[j - 1];
	cout << "\t总分" << endl;
	ptr = h;
	int flag = 0;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		if (ptr->score[sub_id] >= score_low && ptr->score[sub_id] <= score_high)
		{
			nums++;
			flag = 1;
			if (ptr->id >= 1e7)
				cout << ptr->id << "\t";
			else
				cout << ptr->id << "\t\t";
			cout << ptr->name << "\t" << ptr->term << "\t" << ptr->sex;
			for (int i = 1; i <= 9; i++)
			{
				if (ptr->score[i] >= 0)
					cout << setprecision(0) << "\t" << ptr->score[i];
				else
					cout << "\t";
			}
			cout << setprecision(0) << "\t" << ptr->sum << endl;
		}
	}
	printf("\t\t\t\t%s成绩%.2lf-%.2lf分数段一共有%d人\n", subjects[sub_id - 1], score_low, score_high, nums);
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
	gotoxy(45, 11);
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