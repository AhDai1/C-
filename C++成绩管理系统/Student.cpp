#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include "Student.h"
using namespace std;
Student::Student()
{
	score_.resize(10);
}
Student::Student(vector<double> score, double sum):score_(score),sum_(sum)
{
	
}
Student::Student(long long id, string name, string term, string sex, vector<double> score, double sum):
	id_(id),name_(name),term_(term),sex_(sex),score_(score),sum_(sum)
{
	
}
Student::~Student()
{

}
long long Student::Get_Id() const
{
	return id_;
}
vector<double> Student::Get_Score() const
{
	return score_;
}
double Student::Get_Sum() const
{
	return sum_;
}
