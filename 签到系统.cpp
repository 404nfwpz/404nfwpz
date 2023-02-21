//签到系统 
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<time.h>
#include<cstdio>
#include<windows.h>
#include<string>
#pragma comment(linker, "/subsystem:\"windows\"/entry:\"mainGRTStartup\"")
using namespace std; 
void HideCursor()
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
}
void TopWindow(HWND &hWnd)
{
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}
void rgb_init()
{
	HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);
	GetConsoleMode(hOut, &dwOutMode);
	dwInMode |= 0x0200;
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);
	SetConsoleMode(hOut, dwOutMode);
}
void rgb(int wr, int wg, int wb, int br, int bg, int bb)
{
	printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm", wr, wg, wb, br, bg, bb);
}
void copyright()
{
	HideCursor();
	system("title 苏联特供版签到系统");
	HWND hwnd=GetConsoleWindow();
	TopWindow(hwnd);
	LONG Style;
	Style = GetWindowLong(hwnd, GWL_STYLE);
	Style = Style & ~WS_CAPTION;
	SetWindowLong(hwnd, GWL_STYLE, Style);
	system("mode con: cols=40 lines=10");
	cout << endl << endl << endl << endl << "Copyright (c) 2022 ";
	rgb(0, 204, 255, 12, 12, 12);
	cout << "Peizhi Wang";
	rgb(255, 255, 255, 12, 12, 12);
	cout << ",";
	rgb(0, 204, 255, 12, 12, 12);
	cout << "Xipeng Yu";
	rgb(255, 255, 255, 12, 12, 12);
	Sleep(2000);
	system("cls");
	cout << endl << endl << endl << endl << "          all rights reserved.";
	Sleep(2000);
	system("cls");
}
int main()
{
	copyright(); 
	int bdbd=0, a=time(NULL), c, cjb=0, cjbsl;
	a /= 86400;
	a *= 86400;
	ifstream ifs;
	ifs.open("D:\\WindowsTime.Manifest", ios::in);
	SetFileAttributes("D:\\WindowsTime.Manifest", FILE_ATTRIBUTE_NORMAL);
	if(ifs.is_open() == false)
	{
		bdbd = 1;
		cjb = 1;
		fstream ofs;
		ofs.open("D:\\WindowsTime.Manifest", ios::out);
		ofs << a;
		ofs.close();
	}
	else
	{
		ifs >> c;
		if(a > c)
		{
			bdbd = 1;
			cjb = 1;
		}
		else
		{
		}
		fstream ofs2;
		ofs2.open("D:\\WindowsTime.Manifest", ios::out);
		ofs2 << a;
		ofs2.close();
	}
	if(cjb == 1)
	{
		ifstream ifs2;
		ifs2.open("D:\\diagcjb.xml", ios::in);
		SetFileAttributes("D:\\diagcjb.xml", FILE_ATTRIBUTE_NORMAL);
		if(ifs2.is_open() == false)
		{
			fstream ofs3;
			ofs3.open("D:\\diagcjb.xml", ios::out);
			ofs3 << 1;
			ofs3.close();
			ifs2.close();
		}
		else
		{
			ifs2 >> cjbsl;
			ifs2.close();
			cjbsl++;
			fstream ofs4;
			ofs4.open("D:\\diagcjb.xml", ios::out);
			ofs4 << cjbsl;
			ofs4.close();
		}
	}
	time_t timep;
	time(&timep);
	char tmp[256];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	int b=0;
	string name;
	SYSTEMTIME sys;
	GetLocalTime( &sys );
	if(bdbd == 1)
	{
		cout << endl << endl << endl << endl << "         请输入你在群内的名字：" << endl;
		cin >> name;
		system("cls");
		cout << endl << endl << "    签到成功！获得";
		rgb(0, 204, 255, 12, 12, 12);
		cout << 5;
		rgb(255, 255, 255, 12, 12, 12);
		cout << "积分与";
		rgb(0, 204, 255, 12, 12, 12);
		cout << 1;
		rgb(255, 255, 255, 12, 12, 12);
		cout << "抽奖币！" << endl << "     请将此截图发到群内（注意：每" << endl << "    人一天只有一次显示签到的机会）" << endl << "   当前时间：" << sys.wYear << "-";
		if(sys.wMonth < 10)
		{
			cout << "0";
		}
		cout << sys.wMonth << "-";
		if(sys.wDay < 10)
		{
			cout << "0";
		}
		cout << sys.wDay << " ";
		if(sys.wHour < 10)
		{
			cout << "0";
		}
		cout << sys.wHour << ":";
		if(sys.wMinute < 10)
		{
			cout << "0";
		}
		cout << sys.wMinute << ":";
		if(sys.wSecond < 10)
		{
			cout << "0";
		}
		cout << sys.wSecond << ".";
		if(sys.wMilliseconds < 100)
		{
			cout << "0";
			if(sys.wMilliseconds < 10)
			{
				cout << "0";
			}
		}
		cout << sys.wMilliseconds << endl;
		cout << "        当前版本：v1.5" << endl;
		cout << "    名称：" << name << endl << "       ";
		system("pause");
	}
	else
	{
		cout << endl << endl << endl << endl << "      签到失败，您今日已签到！" << endl << "         ";
		system("pause");
	}
	return 0;
}
