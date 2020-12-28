#include "AccountDeal.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"StudentDeal.h"
using namespace std;
int flagg = 0;
StudentDeal s;
void AccountDeal::creat_file_m()
{
	system("cls");
	FILE *fp = NULL;
	if ((fp = fopen("messages.txt", "r")) == NULL)
	{
		if ((fp = fopen("messages.txt", "w")) == NULL)
		{
			cout << "File opens error!\n";
			exit(0);
		}
	}
	if (fclose(fp))
	{
		cout << "file close error!\n";
		exit(0);
	}
}
void AccountDeal::register_m()
{
	Draw draw;
	FILE *fp = NULL;
	Account *ptr = NULL;
	Account *h;
	long long account;//账户账号
	char password[20];//账户密码
	char name[20];//账户户名
	char identify[10];//身份信息
	char a[10] = "老师";
	char b[10] = "学生";
	if ((fp = fopen("messages.txt", "a")) == NULL)
	{
		if ((fp = fopen("messages.txt", "w")) == NULL)
		{
			cout << "File opens error!\n";
			exit(0);
		}
	}
	system("cls");
	draw.DrawList(38, 4, 2, 4, 9, 1);
	draw.gotoxy(47, 5); cout << "账号";
	draw.gotoxy(60, 5); cin >> account;//写：判断文件中是否存在账号
	h = creat_list_message();
	ptr = h;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		if (ptr->account == account)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\t\t\t\t该账号已存在\n\t\t\t\t";
			system("pause");
			return;
		}
	}
	draw.gotoxy(47, 7); cout << "密码";
	draw.gotoxy(60, 7); cin >> password;
	draw.gotoxy(47, 9); cout << "姓名";
	draw.gotoxy(60, 9); cin >> name;
	draw.gotoxy(42, 11); cout << "身份(老师/学生)";
	draw.gotoxy(60, 11); cin >> identify;
	Account t(account, password, name, identify);
	if (strcmp(identify, a) != 0 && strcmp(identify, b) != 0)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t输入错误请重新输入\n\t\t\t\t\t\t";
		system("pause");
		menu_initial();
	}
	fwrite(&t, sizeof(t), 1, fp);
	if (fclose(fp))
	{
		cout << "file close error!\n";
		exit(0);
	}
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t账号创建成功\n\t\t\t\t\t\t\t";
	system("pause");
}
Account* AccountDeal::creat_list_message()
{
	Account t;
	Account *head, *p, *q;
	FILE *fp = NULL;
	p = new Account;
	head = p;
	if ((fp = fopen("messages.txt", "r")) == NULL)
	{
		cout << "File opens error!\n";
		exit(0);
	}
	rewind(fp);
	while (fread(&t, sizeof(t), 1, fp) != 0)
	{
		q = new Account;
		q->account = t.account;
		strcpy(q->password, t.password);
		strcpy(q->name, t.name);
		strcpy(q->identify, t.identify);
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
void AccountDeal::login()
{
	Draw draw;
	Account *ptr = NULL;
	Account *h;
	int flag = 0;//判断是否登陆成功
	h = creat_list_message();
	ptr = h;
	long long account;
	char a[10] = "老师";
	char b[10] = "学生";
	char c[20];//记录密码
	system("cls");
	draw.DrawList(38, 4, 2, 2, 9, 1);
	draw.gotoxy(47, 5); cout << "账号";
	draw.gotoxy(60, 5); cin >> account;
	draw.gotoxy(47, 7); cout << "密码";
	draw.gotoxy(60, 7);
	int i = 0;
	while (1)//密码星号处理
	{
		c[i] = _getch();
		if (c[i] == '\r')
			break;
		if (c[i] == '\b')
		{
			i--;
			putchar('\b');//退格键
			putchar(' ');
			putchar('\b');
		}
		else
		{
			putchar('*');
			i++;
		}
		if (i == -1)
		{
			i = 0;
		}
		if (i == 0)//保证光标在最开始位置不变
			draw.gotoxy(60, 7);

	}
	c[i] = '\0';
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		if (ptr->account == account)
		{
			if (strcmp(ptr->password, c) == 0)
			{
				flag = 1;
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t登录成功\n\t\t\t\t\t\t";
				system("pause");
				if (strcmp(ptr->identify, a) == 0)
				{
					flagg = 1;
					menu_teacher();
				}
				else if (strcmp(ptr->identify, b) == 0)
				{
					flagg = 0;
					menu_student();
				}
			}
		}
	}
	if (flag == 0)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t账号或密码错误\n\t\t\t\t\t";

		system("pause");
		return;
	}
}
void AccountDeal::menu_initial()
{
	int x;
	while (1)
	{
		x = menu_initial_selete();
		switch (x)
		{
		case 1: login(); break;
		case 2: register_m(); break;
		case 3: end(); break;
		}
	}
}
void AccountDeal::end()
{
	Draw draw;
	system("cls");
	draw.gotoxy(52, 13);
	cout << "谢谢使用\n";
	draw.gotoxy(85, 27);
	cout << "1905-陈汶君";
	Sleep(3000);
	exit(0);
}
char AccountDeal::menu_initial_selete()
{
	Draw draw;
	system("cls");
	draw.DrawList(45, 4, 1, 4, 11, 1);
	draw.gotoxy(47, 5); cout << "1、登录";
	draw.gotoxy(47, 7); cout << "2、注册";
	draw.gotoxy(47, 9); cout << "3、结束运行";
	draw.gotoxy(47, 11); cout << "输入左边数字选择功能:";
	char n;
	cin >> n;
	while (1)
	{
		if (n >= 1 && n <= 3)
		{
			return n;
		}
		else
		{
			cout << "\n\n\n\n\n\t\t\t\t\t输入错误，请重新输入\n";
			system("pause");
			return 0;
		}
	}
}
void AccountDeal::menu_student()
{
	int x;
	while (1)
	{
		x = menu_student_selete();
		switch (x)
		{
		case 1: s.print_stu_all(); break;
		case 2: s.serch_stu(); break;
		case 3: s.sort_stu(); break;
		case 4: end(); break;
		}
	}
}
char AccountDeal::menu_student_selete()
{
	Draw draw;
	system("cls");
	draw.DrawList(45, 4, 1, 5, 11, 1);
	draw.gotoxy(47, 5); cout << "1、打印学生信息";
	draw.gotoxy(47, 7); cout << "2、查询学生信息";
	draw.gotoxy(47, 9); cout << "3、对学生成绩进行排序";
	draw.gotoxy(47, 11); cout << "4、结束运行";
	draw.gotoxy(47, 13); cout << "输入左边数字选择功能:";
	char n;
	cin >> n;
	while (1)
	{
		if (n >= 1 && n <= 4)
		{
			return n;
		}
		else
		{
			cout << "\n\n\n\n\n\t\t\t\t\t输入错误，请重新输入" << endl;
			system("pause");
			return 0;
		}
	}
}
void AccountDeal::menu_teacher()
{
	int x;
	while (1)
	{
		x = menu_teacher_selete();
		switch (x)
		{
		case 1: s.add_student(); break;
		case 2: s.update_stu_id_name(); break;
		case 3: s.print_stu_all(); break;
		case 4: s.serch_stu(); break;
		case 5: s.delete_stu(); break;
		case 6: s.sort_stu(); break;
		case 7: s.screen(); break;
		case 8: end(); break;
		}
	}
}
char AccountDeal::menu_teacher_selete()
{
	Draw draw;
	system("cls");
	draw.DrawList(45, 4, 1, 9, 11, 1);
	draw.gotoxy(47, 5); cout << "1、添加学生信息";
	draw.gotoxy(47, 7); cout << "2、修改学生信息";
	draw.gotoxy(47, 9); cout << "3、打印学生信息";
	draw.gotoxy(47, 11); cout << "4、查询学生信息";
	draw.gotoxy(47, 13); cout << "5、删除学生信息";
	draw.gotoxy(47, 15); cout << "6、对学生成绩进行排序";
	draw.gotoxy(47, 17); cout << "7、筛选学生成绩";
	draw.gotoxy(47, 19); cout << "8、结束运行";
	draw.gotoxy(47, 21); cout << "输入左边数字选择功能:";
	char n;
	cin >> n;
	while (1)
	{
		if (n >= 1 && n <= 8)
		{
			return n;
		}
		else
		{
			cout << "\n\n\n\n\n\t\t\t\t\t输入错误，请重新输入\n\t\t\t\t";
			system("pause");
			return 0;
		}
	}
}