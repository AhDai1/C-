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
	long long id_;//学号
	string name_;//学生姓名
	string term_;//学期
	string sex_;//性别
	vector<double> score_;//课程分数
	double sum_;//总分
	//Student *next;
};

