#include "ehglobal.h"

void ehglobal::clrscr()//clear screen
{
	system("cls");
}

void ehglobal::timeflow(int millisecond)//sleep system
{
	Sleep(millisecond);
}

int ehglobal::getnum()//enter number
{
	int num;
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	sscanf(buf, "%d", &num);
	return num;
}

string ehglobal::getstr()//enter string
{
	char buf[255 + 1];
	cin.getline(buf, 255);
	cin.clear();
	return buf;
}

int ehglobal::getkey()//get keyinfo
{
	int key = getch();
	if (key == 27)
	{
		return ESC;
	}

	if (key == 0)
	{
		key = getch();
		switch (key)
		{
		case 59: return F1;
		case 60: return F2;
		case 61: return F3;
		case 62: return F4;
		case 63: return F5;
		case 64: return F6;
		case 65: return F7;
		case 66: return F8;
		case 67: return F9;
		case 568: return F10;

		}
	}
	return NO_DEFINED;
}

