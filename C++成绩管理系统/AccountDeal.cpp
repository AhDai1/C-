#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<fstream>
#include "AccountDeal.h"
#include"StudentDeal.h"
using namespace std;
int flagg = 0;
StudentDeal s;
AccountDeal::AccountDeal(){}
void AccountDeal::register_m()
{
	Draw draw;
	long long account;//�˻��˺�
	string password;//�˻�����
	string name;//�˻�����
	string identify;//�����Ϣ
	string a = "��ʦ";
	string b = "ѧ��";
	
	system("cls");
	draw.DrawList(38, 4, 2, 4, 9, 1);
	draw.gotoxy(47, 5); cout << "�˺�";
	draw.gotoxy(60, 5); cin >> account;//д���ж��ļ����Ƿ�����˺�
	
	creat_list_message();
	list<Account>::iterator iter;
	for (iter = list_.begin(); iter != list_.end(); iter++) {
		if (iter->account_==account)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\t\t\t\t���˺��Ѵ���\n\t\t\t\t";
			system("pause");
			return;
		}
	}
	draw.gotoxy(47, 7); cout << "����";
	draw.gotoxy(60, 7); cin >> password;
	draw.gotoxy(47, 9); cout << "����";
	draw.gotoxy(60, 9); cin >> name;
	draw.gotoxy(42, 11); cout << "���(��ʦ/ѧ��)";
	draw.gotoxy(60, 11); cin >> identify;
	Account t(account, password, name, identify);
	if (identify!=a && identify!=b)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t�����������������\n\t\t\t\t\t\t";
		system("pause");
		menu_initial();
	}
	ofstream ofs("messages.txt", ios::out);
	ofs << t.account_ << " " << t.password_ << " " << t.name_ << " " << t.identify_;
	ofs.close();
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t�˺Ŵ����ɹ�\n\t\t\t\t\t\t\t";
	system("pause");
}
void AccountDeal::creat_list_message()
{
	FILE *fp = NULL;
	list_.clear();
	ifstream ifs("messages.txt",ios::in);
	while (!ifs.eof())
	{
		long long account;
		string password;
		string name;
		string identify;
		ifs >> account >> password >> name >> identify;
		Account t(account, password, name, identify);
		list_.push_back(t);
	}
	ifs.close();
	
}
void AccountDeal::login()
{
	Draw draw;
	int flag = 0;//�ж��Ƿ��½�ɹ�
	creat_list_message();
	long long account;
	string a = "��ʦ";
	string b = "ѧ��";
	string c;//��¼����
	system("cls");
	draw.DrawList(38, 4, 2, 2, 9, 1);
	draw.gotoxy(47, 5); cout << "�˺�";
	draw.gotoxy(60, 5); cin >> account;
	draw.gotoxy(47, 7); cout << "����";
	draw.gotoxy(60, 7);
	int i = 0;
	while (1)//�����ǺŴ���
	{
		char ch = _getch();
		if (ch == '\r')
			break;
		c += ch;
		if (ch == '\b'){
			i--;
			putchar('\b');//�˸��
			putchar(' ');
			putchar('\b');
		}
		else{
			putchar('*');
			i++;
		}
		if (i == -1){
			i = 0;
		}
		if (i == 0)//��֤������ʼλ�ò���
			draw.gotoxy(60, 7);

	}
	c[i] = '\0';
	list<Account>::iterator iter;
	for (iter = list_.begin(); iter != list_.end();iter++)
	{
		if (iter->account_ == account){
			if (iter->password_ == c){
				flag = 1;
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t��¼�ɹ�\n\t\t\t\t\t\t";
				system("pause");
				if (iter->identify_==a){
					flagg = 1;
					menu_teacher();
				}
				else if (iter->identify_==b){
					flagg = 0;
					menu_student();
				}
			}
		}
	}
	if (flag == 0){
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t�˺Ż��������\n\t\t\t\t\t";

		system("pause");
		return;
	}
}
void AccountDeal::menu_initial()
{
	char x;
	while (1)
	{
		x = menu_initial_selete();
		switch (x)
		{
		case '1': login(); break;
		case '2': register_m(); break;
		case '3': end(); break;
		}
	}
}
void AccountDeal::end()
{
	Draw draw;
	system("cls");
	draw.gotoxy(52, 13);
	cout << "ллʹ��\n";
	draw.gotoxy(85, 27);
	cout << "1905-�����";
	Sleep(3000);
	exit(0);
}
char AccountDeal::menu_initial_selete()
{
	Draw draw;
	system("cls");
	draw.DrawList(45, 4, 1, 4, 11, 1);
	draw.gotoxy(47, 5); cout << "1����¼";
	draw.gotoxy(47, 7); cout << "2��ע��";
	draw.gotoxy(47, 9); cout << "3����������";
	draw.gotoxy(47, 11); cout << "�����������ѡ����:";
	char n;
	cin >> n;
	while (1)
	{
		if (n >= '1' && n <= '3'){
			return n;
		}
		else{
			cout << "\n\n\n\n\n\t\t\t\t\t�����������������\n";
			system("pause");
			return 0;
		}
	}
}
void AccountDeal::menu_student()
{
	char x;
	while (1)
	{
		x = menu_student_selete();
		switch (x)
		{
		case '1': s.print_stu_all(); break;
		case '2': s.serch_stu(); break;
		case '3': s.sort_stu(); break;
		case '4': end(); break;
		}
	}
}
char AccountDeal::menu_student_selete()
{
	Draw draw;
	system("cls");
	draw.DrawList(45, 4, 1, 5, 11, 1);
	draw.gotoxy(47, 5); cout << "1����ӡѧ����Ϣ";
	draw.gotoxy(47, 7); cout << "2����ѯѧ����Ϣ";
	draw.gotoxy(47, 9); cout << "3����ѧ���ɼ���������";
	draw.gotoxy(47, 11); cout << "4����������";
	draw.gotoxy(47, 13); cout << "�����������ѡ����:";
	char n;
	cin >> n;
	while (1)
	{
		if (n >= '1' && n <= '4'){
			return n;
		}
		else{
			cout << "\n\n\n\n\n\t\t\t\t\t�����������������" << endl;
			system("pause");
			return 0;
		}
	}
}
void AccountDeal::menu_teacher()
{
	char x;
	while (1)
	{
		x = menu_teacher_selete();
		switch (x)
		{
		case '1': s.add_student(); break;
		case '2': s.update_stu_id_name(); break;
		case '3': s.print_stu_all(); break;
		case '4': s.serch_stu(); break;
		case '5': s.delete_stu(); break;
		case '6': s.sort_stu(); break;
		case '7': s.screen(); break;
		case '8': end(); break;
		}
	}
}
char AccountDeal::menu_teacher_selete()
{
	Draw draw;
	system("cls");
	draw.DrawList(45, 4, 1, 9, 11, 1);
	draw.gotoxy(47, 5); cout << "1�����ѧ����Ϣ";
	draw.gotoxy(47, 7); cout << "2���޸�ѧ����Ϣ";
	draw.gotoxy(47, 9); cout << "3����ӡѧ����Ϣ";
	draw.gotoxy(47, 11); cout << "4����ѯѧ����Ϣ";
	draw.gotoxy(47, 13); cout << "5��ɾ��ѧ����Ϣ";
	draw.gotoxy(47, 15); cout << "6����ѧ���ɼ���������";
	draw.gotoxy(47, 17); cout << "7��ɸѡѧ���ɼ�";
	draw.gotoxy(47, 19); cout << "8����������";
	draw.gotoxy(47, 21); cout << "�����������ѡ����:";
	char n;
	cin >> n;
	while (1)
	{
		if (n >= '1' && n <= '8'){
			return n;
		}
		else{
			cout << "\n\n\n\n\n\t\t\t\t\t�����������������\n\t\t\t\t";
			system("pause");
			return 0;
		}
	}
}