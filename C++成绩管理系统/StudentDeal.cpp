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
//char subjects[10][10] = { "����","��ѧ","Ӣ��","����","����","��ѧ","��ʷ","����","����" };
vector<string> subjects = { "����","��ѧ","Ӣ��","����","����","��ѧ","��ʷ","����","����" };
vector<int> courses(10,-1);//����ѡ��γ̵���� 
void StudentDeal::creat_file()//����ѧ���ɼ���Ϣ�ļ� 
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
void StudentDeal::creat_list()//�������� 
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
void StudentDeal::add_student()//¼��ѧ����Ϣ 
{
	Draw draw;
	long long id;//ѧ��
	string name;//ѧ������
	string term;//ѧ��
	string sex;//�Ա�
	vector<double> score(10,-1);//�γ̷���
	double sum = 0;//�ܷ�
	double sum1 = 0;
	system("cls");
	int n;//ѧ�������� 
	int i;
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t������ѧ��������:";
	cin >> n;
	system("cls");
	cout << "\n\n\n\n\n\t\t\t\t\t�������ѧ�ڵĿγ���:";
	cin >> sub;
	if (sub < 1 || sub>9)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\t\t\t\t\t�����������������\n\t\t\t\t\t";
		system("pause");
		return;
	}
	system("cls");
	draw.DrawList(10, 4, 9, 1, 5, 1);
	draw.gotoxy(12, 5);
	printf("1������     2����ѧ     3��Ӣ��     4������     5������     6����ѧ     7����ʷ     8������     9������");
	printf("\n\n\n\n\n\t\t\t�������ѧ����Ӧ�γ�ǰ�����,����һ����Żس�ȷ��:\n");
	printf("\t\t\t");
	for (i = 1; i <= sub; i++)
	{
		cin >> courses[i];
		cout << "\t\t\t";
		if (courses[i] < 1 || courses[i]>9 || courses[i] == courses[i - 1])
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t\t�����������������:";
			system("pause");
			return;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		sum1 = 0;
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t�������" << i << "λͬѧ��ѧ�� ���� ѧ�� �Ա�:\n";
		draw.DrawList(45, 6, 2, 4, 6, 1);
		draw.gotoxy(50, 7); cout << "ѧ��";
		draw.gotoxy(61, 7); cin >> id;
		draw.gotoxy(50, 9); cout << "����";
		draw.gotoxy(61, 9); cin >> name;
		draw.gotoxy(50, 11); cout << "ѧ��";
		draw.gotoxy(61, 11); cin >> term;
		draw.gotoxy(50, 13); cout << "�Ա�";
		draw.gotoxy(61, 13); cin >> sex;
		int k = 1;//���ƿγ����
		int r = 1;
		system("cls");
		cout << "\n\n\n\n\n";
		/*for (int i = 1; i <= 9; i++)
		{
			score[i] = -1;
		}*/

		draw.gotoxy(45, 5); cout << "������γ̵ķ���:";
		draw.DrawList(45, 6, 2, sub, 6, 1);
		int q = 7;
		for (int j = 1; j <= sub; j++)
		{
			draw.gotoxy(50, q);
			cout << subjects[courses[k++] - 1];
			draw.gotoxy(61, q);
			cin >> score[courses[r]];//1�����ģ�2����ѧ��3��Ӣ�� ,4������5�����6����ѧ��7����ʷ��8�����Σ�9������ 
			sum1 += score[courses[r]];
			sum = sum1;
			r++;
			q += 2;//���ƹ����һ��
		}
		//Student t(id, name, term, sex, score, sum);
		//fwrite(&t, sizeof(t), 1, fp);//�ṹ��д���ļ�
		ofstream ofs("student.txt", ios::app);
		ofs << id << " " << name << " " << term << " " << sex << " ";
		for (int i = 0; i < 10; i++) {
			ofs << score[i] << " ";
		}
		ofs << sum << endl;
		ofs.close();
	}
}
void StudentDeal::print_stu_all()//��ӡ����ѧ���ɼ�      
{
	system("cls");
	int i, j;

	creat_list();
	if (list_.empty())
	{
		cout << "\n\n\n\n\n\n\n\t\t\t\tû��ѧ����Ϣ\n";
		system("pause");
		return;
	}
	if (!list_.empty())
	{
		system("cls");
		cout << "\n\n\n\n\n\n\nѧ��\t\t����\tѧ��\t�Ա�";
		for (j = 1; j <= 9; j++)
		{
			//		count = courses[k++] - 1;
			cout << "\t" << subjects[j - 1];
		}
		cout << "\t�ܷ�" << endl;
	}
	else 
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tû������\n";
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
void StudentDeal::update_stu_id_name()//����ĳһ��ͬѧ�ɼ� 
{
	Draw draw;
	system("cls");
	int flag2 = 0;

	int sub_id;//Ҫ�޸ĵĿγ���� 
	long long id;
	string name;
	double score;
	int flag1 = 0;//��¼�Ƿ��ҵ�ѧ��
	int flag;//�ж���ѧ�Ų�ѯ����������ѯ 
	system("cls");
	creat_list();
	system("cls");
	draw.DrawList(45, 4, 1, 2, 9, 1);
	draw.gotoxy(47, 5); cout << "1����ѧ�Ų���";
	draw.gotoxy(47, 7); cout << "2������������";
	draw.gotoxy(47, 9);
	cin >> flag;
	if (flag != 1 && flag != 2)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t\t�����������������\n\t\t\t\t\t";
		system("pause");
		return;
	}
	if (flag == 1)
	{
		system("cls");
		draw.DrawList(45, 4, 2, 1, 9, 1);
		draw.gotoxy(50, 5); cout << "������ѧ��";
		draw.gotoxy(67, 5); cin >> id;
	}
	else if (flag == 2)
	{
		system("cls");
		draw.DrawList(45, 4, 2, 1, 9, 1);
		draw.gotoxy(50, 5); cout << "����������";
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
				printf("1������     2����ѧ     3��Ӣ��     4������     5������     6����ѧ     7����ʷ     8������     9������");
				draw.DrawList(38, 5, 2, 2, 9, 1);
				draw.gotoxy(39, 6); cout << "������γ�ǰ�����:";
				draw.gotoxy(60, 6); cin >> sub_id;
				if (sub_id < 1 || sub_id>9)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\t\t\t\t�����������������\n\t\t\t\t";
					system("pause");
					return;
				}
				draw.gotoxy(39, 8); cout << "�����޸ĺ�ķ���:";
				draw.gotoxy(60, 8); cin >> score;
				if (iter->score_[sub_id] >= 0)
				{
					temp = score - iter->score_[sub_id];//��¼�޸ĺ����޸�ǰ�����Ĳ�ֵ 
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
				printf("1������     2����ѧ     3��Ӣ��     4������     5������     6����ѧ     7����ʷ     8������     9������");
				draw.DrawList(38, 5, 2, 2, 9, 1);
				draw.gotoxy(39, 6); cout << "������γ�ǰ�����:";
				draw.gotoxy(60, 6); cin >> sub_id;
				if (sub_id < 1 || sub_id>9)
				{
					system("cls");
					cout << "\n\n\n\n\n\n\t\t\t\t\t�����������������\n\t\t\t\t";
					system("pause");
					return;
				}
				draw.gotoxy(39, 8); cout << "�����޸ĺ�ķ���:";
				draw.gotoxy(60, 8); cin >> score;
				if (iter->score_[sub_id] >= 0)
				{
					temp = score - iter->score_[sub_id];//��¼�޸ĺ����޸�ǰ�����Ĳ�ֵ 
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
		cout << "\n\n\n\n\n\n\t\t\t\t\tû��ѧ����Ϣ\n\t\t\t\t\t";
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
void StudentDeal::serch_stu()//����ĳһ��ͬѧ�ɼ� 
{
	Draw draw;
	system("cls");
	long long id;
	Student *t = NULL;//��¼�ҵ�ѧ���Ľڵ�
	string name;
	int flag;
	creat_list();
	int flag1 = 0;
	system("cls");
	draw.DrawList(45, 4, 1, 2, 11, 1);
	draw.gotoxy(47, 5); cout << "1����ѧ�Ų���";
	draw.gotoxy(47, 7); cout << "2������������";
	draw.gotoxy(47, 9);
	cin >> flag;
	if (flag != 1 && flag != 2)
	{
		system("cls");
		cout << "\n\n\n\n\n\t\t\t\t\t\t�����������������\n\t\t\t\t\t";
		system("pause");
		return;
	}
	else if (flag == 1 || flag == 2)
	{
		if (flag == 1)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "������ѧ��";
			draw.gotoxy(67, 5); cin >> id;
		}
		else if (flag == 2)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "����������";
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
					cout << "\n\n\n\n\n\n\nѧ��\t\t����\tѧ��\t�Ա�";
					for (int i = 1; i <= 9; i++)
					{
						if (iter->score_[i] >= 0)
						{
							cout << "\t" << subjects[i - 1];
						}
					}
					cout << "\t�ܷ�" << endl;
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
					cout << "\n\n\n\n\n\n\nѧ��\t\t����\tѧ��\t�Ա�";
					for (int i = 1; i <= 9; i++)
					{
						if (iter->score_[i] >= 0)
						{
							cout << "\t" << subjects[i - 1];
						}
					}
					cout << "\t�ܷ�" << endl;
					break;
				}
			}
		}
		if (flag1 == 0)
		{
			system("cls");
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t�޸�ѧ����Ϣ\n";
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
void StudentDeal::delete_stu()//ɾ��ͬѧ��Ϣ 
{
	Draw draw;
	system("cls");
	Student t;
	long long id;
	string name;
	creat_list();
	int len = 0;//�ж�����೤
	int flag;
	int flag1 = 0;
	int flag2 = 0;
	system("cls");
	draw.DrawList(45, 4, 1, 2, 11, 1);
	draw.gotoxy(47, 5); cout << "1��ɾ��ĳλͬѧ��Ϣ";
	draw.gotoxy(47, 7); cout << "2��ɾ��ȫ����Ϣ";
	draw.gotoxy(47, 9);
	cin >> flag2;
	if (flag2 == 2)
	{
		ofstream ofs("student.txt", ios::trunc | ios::out);
		ofs.close();
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t��Ϣ��ȫ��ɾ��\n";
		system("pause");
		return;
	}
	else if (flag2 == 1)
	{
		system("cls");
		draw.DrawList(45, 4, 1, 2, 9, 1);
		draw.gotoxy(47, 5); cout << "1����ѧ�Ų���";
		draw.gotoxy(47, 7); cout << "2������������";
		draw.gotoxy(47, 9);
		cin >> flag;
		if (flag == 1)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "������ѧ��";
			draw.gotoxy(67, 5); cin >> id;
		}
		else if (flag == 2)
		{
			system("cls");
			draw.DrawList(45, 4, 2, 1, 9, 1);
			draw.gotoxy(50, 5); cout << "����������";
			draw.gotoxy(67, 5); cin >> name;
		}
		list<Student>::iterator iter;
		iter = list_.begin();
		while(iter!=list_.end())
		{
			if (flag == 1)
			{
				if (iter->id_ == id)//�ҵ��ڵ� 
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
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t��Ϣ��ɾ��\n";
		else
			cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tû������\n";

		system("pause");
	}
}
char StudentDeal::sort_selete()
{
	Draw draw;
	char selete;
	system("cls");
	draw.DrawList(45, 4, 1, 4, 13, 1);
	draw.gotoxy(46, 5); cout << "1����ѧ�Ŵ�С��������";
	draw.gotoxy(46, 7); cout << "2�����ִܷӸߵ�������";
	draw.gotoxy(46, 9); cout << "3�����γ̳ɼ��Ӹߵ�������";
	draw.gotoxy(46, 11); cout << "������������ѡ����:";
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
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t�����������������\n\t\t\t\t\t";
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
void StudentDeal::sort_stu_id()//ð������ 
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
	
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������\n\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::sort_stu_sub()
{
	system("cls");
	int count_id[15] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int count;//����γ̵���� 
	int l = 0;//���ǰ����� 
	int k = 1;
	printf("\n\n\n\n\n\t\t\t1�����ģ�2����ѧ��3��Ӣ�� ,4������5�����6����ѧ��7����ʷ��8�����Σ�9������");
	cout << "\n\t\t\t\t�������������ѡ������Ŀγ�\n";
	cout << "\t\t\t\t";
	while (1)
	{
		cin >> count;
		if (count < 1 || count>9)
		{
			cout << "\n\n\n\n\n\n\n\t\t\t\t�����������������\n\t\t\t\t\t\t";
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
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������\n\t\t\t\t\t";
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
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t���������\n\t\t\t\t\t\t";
	system("pause");
	return;
}
void StudentDeal::screen()
{
	Draw draw;
	int nums = 0;//��¼�������е�����
	creat_list();
	printf("\n\n\n\n\n\t1�����ģ�2����ѧ��3��Ӣ�� ,4������5�����6����ѧ��7����ʷ��8�����Σ�9������\n");
	cout << "\t\t\t������ɸѡ�Ŀγ����:";
	int sub_id;
	cin >> sub_id;
	if (sub_id < 1 || sub_id>9)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t�����������������\n\t\t\t\t";
		system("pause");
		return;
	}
	double score_low, score_high;
	system("cls");
	draw.DrawList(45, 4, 2, 2, 9, 1);
	draw.gotoxy(47, 5); cout << "1����������ͷ�";
	draw.gotoxy(67, 5); cin >> score_low;
	draw.gotoxy(47, 7); cout << "2����������߷�";
	draw.gotoxy(67, 7); cin >> score_high;
	system("cls");
	cout << "\n\n\n\n\n\n\nѧ��\t\t����\tѧ��\t�Ա�";
	for (int j = 1; j <= 9; j++)
		cout << "\t" << subjects[j - 1];
	cout << "\t�ܷ�" << endl;
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
	//printf("\t\t\t\t%s�ɼ�%.2lf-%.2lf������һ����%d��\n", subjects[sub_id - 1], score_low, score_high, nums);
	cout << "\t\t\t\t" << subjects[sub_id - 1] << "�ɼ�" << setprecision(2) << score_low << "-" << setprecision(2) << score_high <<
		"������һ����" << nums << "��" << endl;
	if (flag == 0)
	{
		system("cls");
		cout << "\n\n\n\n\t\t\t\tû�з�������������\n";
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
	printf("��"); Sleep(400);//��ʱ 
	printf("ӭ"); Sleep(400);
	printf("ʹ"); Sleep(400);
	printf("��"); Sleep(400);
	printf("��"); Sleep(400);
	printf("��"); Sleep(400);
	printf("��"); Sleep(400);
	printf("��"); Sleep(400);
	printf("ϵ"); Sleep(400);
	printf("ͳ\n"); Sleep(400);
}