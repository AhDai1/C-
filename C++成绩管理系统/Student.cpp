#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
using namespace std;
Student::Student(double score[10], double sum)
{
	for (int i = 1; i <= 10; i++)
	{
		this->score[i] = score[i];
	}
	this->sum = sum;
}
Student::Student(long long id, char name[20], char term[20], char sex[5], double score[10], double sum)
{
	this->id = id;
	strcpy(this->name, name);
	strcpy(this->term, term);
	strcpy(this->sex, sex);
	for (int i = 1; i <= 10; i++)
	{
		this->score[i] = score[i];
	}
	this->sum = sum;
}
Student::~Student()
{

}
Student::Student()
{

}