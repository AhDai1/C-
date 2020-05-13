#pragma once



class Student
{
public:
	friend class StudentDeal;
	Student();
	Student(double score[10], double sum);
	Student(long long id, char name[20], char term[20], char sex[5], double score[10], double sum);
	~Student();
private:
	long long id;//ѧ��
	char name[20];//ѧ������
	char term[20];//ѧ��
	char sex[5];//�Ա�
	double score[10];//�γ̷���
	double sum;//�ܷ�
	Student *next;
};

