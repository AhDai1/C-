#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
using namespace std;
#include "Draw.h"
void Draw::gotoxy(int x, int y)
{
	COORD xy = { 0,0 };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	xy.X = x;
	xy.Y = y;
	SetConsoleCursorPosition(hout, xy);
}

void Draw::DrawList(int x, int y, int column, int line, int width, int hight)
{
	/*���Ʊ�� ��������Ϊ �󶥵����� ���� ����  �п� �и�*/
	//������
	//��һ��
	gotoxy(x, y);
	for (int i = 0; i < (width + 1)*column + 1; i++)  //��һ�� //  ÿС������ϽǺͿ��Ϊ��λ ���һ��ֹͣ
	{
		if (i == 0)
		{
			printf("�� ");			//ֵ��ע�� ���ﰴ��˵����ַ�Ӧ��ռ�����ַ�λ 
									//��ʵ����ֻռ��һ��  ���������Ʊ���������һ���ո�
									//��Ȼ��������� ���������Ʊ��ͬ�����
			continue;
		}
		if (i == (width + 1)*column)
		{
			printf("�� ");
			break;
		}
		if (i % (width + 1) == 0)
			printf("�� ");
		else
			printf("�� ");
	}
	//�м���
	for (int j = 0; j < line; j++)
	{
		if (j == 0)
			gotoxy(x, y + 2 * hight);
		else
			gotoxy(x, y + 2 * hight*j);
		for (int i = 0; i < (width + 1)*column + 1; i++)
		{
			if (i == 0)
			{
				printf("�� ");
				continue;
			}
			if (i == (width + 1)*column)
			{
				printf("�� ");
				break;
			}
			if (i % (width + 1) == 0)
				printf("�� ");
			else
				printf("�� ");
		}
	}
	//���һ��
	gotoxy(x, y + (hight + 1)*line);
	for (int i = 0; i < (width + 1)*column + 1; i++)
	{
		if (i == 0)
		{
			printf("�� ");
			continue;
		}
		if (i == (width + 1)*column)
		{
			printf("�� ");
			break;
		}
		if (i % (width + 1) == 0)
			printf("�� ");
		else
			printf("�� ");
	}
	//������
	for (int i = 0; i < line; i++)
		for (int j = 0; j <= column; j++)
		{
			if (i == 0)
				gotoxy(x + 2 * (width + 1)*j, y + i + 1);
			else
				gotoxy(x + 2 * (width + 1)*j, y + i * 2 + 1);
			printf("��");
		}

}