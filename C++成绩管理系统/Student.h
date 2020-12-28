#pragma once

#include<vector>
#include<string>
using namespace std;
class Student
{
public:
	friend class StudentDeal;
	Student();
	Student(vector<double> score, double sum);
	Student(long long id, string name, string term, string sex, vector<double> score, double sum);
	~Student();
	long long Get_Id() const;
	vector<double> Get_Score() const;
	double Get_Sum() const;

private:
	long long id_;//ѧ��
	string name_;//ѧ������
	string term_;//ѧ��
	string sex_;//�Ա�
	vector<double> score_;//�γ̷���
	double sum_;//�ܷ�
	//Student *next;
};

