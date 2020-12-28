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
	/*绘制表格 参数依次为 左顶点坐标 列数 行数  行宽 行高*/
	//画横线
	//第一排
	gotoxy(x, y);
	for (int i = 0; i < (width + 1)*column + 1; i++)  //第一排 //  每小格的左上角和宽度为单位 最后一个停止
	{
		if (i == 0)
		{
			printf("┏ ");			//值得注意 这里按理说这个字符应该占两个字符位 
									//但实际上只占了一个  所以我在制表符后面加了一个空格
									//不然会产生错误 下面所有制表符同样如此
			continue;
		}
		if (i == (width + 1)*column)
		{
			printf("┓ ");
			break;
		}
		if (i % (width + 1) == 0)
			printf("┳ ");
		else
			printf("━ ");
	}
	//中间排
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
				printf("┣ ");
				continue;
			}
			if (i == (width + 1)*column)
			{
				printf("┫ ");
				break;
			}
			if (i % (width + 1) == 0)
				printf("╋ ");
			else
				printf("━ ");
		}
	}
	//最后一排
	gotoxy(x, y + (hight + 1)*line);
	for (int i = 0; i < (width + 1)*column + 1; i++)
	{
		if (i == 0)
		{
			printf("┗ ");
			continue;
		}
		if (i == (width + 1)*column)
		{
			printf("┛ ");
			break;
		}
		if (i % (width + 1) == 0)
			printf("┻ ");
		else
			printf("━ ");
	}
	//画竖线
	for (int i = 0; i < line; i++)
		for (int j = 0; j <= column; j++)
		{
			if (i == 0)
				gotoxy(x + 2 * (width + 1)*j, y + i + 1);
			else
				gotoxy(x + 2 * (width + 1)*j, y + i * 2 + 1);
			printf("┃");
		}

}