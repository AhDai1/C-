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
	long long id;//学号
	char name[20];//学生姓名
	char term[20];//学期
	char sex[5];//性别
	double score[10];//课程分数
	double sum;//总分
	Student *next;
};

