#include <iostream> 
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;

void rgb_init() {																// 初始化
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//输入句柄
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//输出句柄
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//获取控制台输入模式
	GetConsoleMode(hOut, &dwOutMode);					//获取控制台输出模式
	dwInMode |= 0x0200;									//更改
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//设置控制台输入模式
	SetConsoleMode(hOut, dwOutMode);					//设置控制台输出模式
}

void rgb(int wr,int wg,int wb,int br,int bg,int bb) {						//设置RGB
	printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm",wr,wg,wb,br,bg,bb);	//\033[38表示前景，\033[48表示背景，三个%d表示混合的数
}

void HideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
}

void unHideCursor()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = true;
	SetConsoleCursorInfo(handle, &CursorInfo);
}

void TopWindow(HWND &hWnd)
{
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}

void jiantie(string text){
	HWND hWnd=NULL;
	OpenClipboard(hWnd);
	EmptyClipboard();
	HANDLE hHandle=GlobalAlloc(GMEM_FIXED,1000);
	char* pData=(char*)GlobalLock(hHandle);
	strcpy(pData,text.c_str());
	SetClipboardData(CF_TEXT,hHandle);
	GlobalUnlock(hHandle);
	CloseClipboard();
}

void DeleteGoAway() {
	DeleteMenu(GetSystemMenu(GetConsoleWindow(), FALSE),
		SC_CLOSE, MF_DISABLED);
	DrawMenuBar(GetConsoleWindow());
}

void SizeGoAway() {
	SetWindowLongPtrA(
		GetConsoleWindow(),
		GWL_STYLE,
		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE) & ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX);
}

void TerminateApp()
{
	HANDLE hself = GetCurrentProcess();   
	TerminateProcess(hself, 0); 
}

void copyright()
{
	system("title Copyright (C) 2020-2022  Peizhi Wang");
	cout << endl << endl << endl << endl << "  Copyright (C) 2020-2022  Peizhi Wang" << endl;
	Sleep(1500);
	system("cls");
	system("title https://404nfwpz.tk");
	cout << endl << endl << endl << endl << "        https://404nfwpz.tk" << endl;
	Sleep(1000);
	system("cls");
}

int main()
{
	int r, g, b;
	r = 0;
	g = 204;
	b = 255;
	HWND hwnd = GetConsoleWindow();
	DeleteGoAway();
	SizeGoAway();
//	LONG Style;	//窗口风格
//	Style = GetWindowLong(hwnd, GWL_STYLE);	 // 得到窗口风格   
//	Style = Style & ~WS_CAPTION;			 //去掉标题栏
//	SetWindowLong(hwnd, GWL_STYLE, Style);	 //为窗口设置新的风格
//	HideCursor();
	system("mode con: cols=43 lines=12");
	HWND hWnd=GetForegroundWindow();
	TopWindow(hwnd);
	copyright();
	while(1)
	{
	system("title 404jia v.1.1");
	cout << endl << "          加密软件（";
	rgb(r,g,b,0,0,0);
	cout << "404NotFound";
	rgb(255,255,255,0,0,0);
	cout << "制作）" << endl << endl;
	cout << "                 1.加密" << endl << endl;
	cout << "                 2.解密" << endl << endl;
	cout << "                 3.设置" << endl << endl;
	cout << "                 4.退出" << endl << endl;
	char a = getch();
	if (a == '1')
	{
		system("cls");
		system("title 1.加密");
		string s;
		unHideCursor();
		cout<<endl<<endl<<"  请输入加密的内容: ";
		getline(cin, s);
		system("cls");
		for(int i=0;i<s.size();i++)
		{
			s[i] += 1;
		}
		jiantie(s);
		HideCursor();
		cout << endl << endl << endl << "      加密完毕，已复制到剪贴板"<<endl;
		Sleep(1000);
		system("cls");
	}
	if (a == '2') 
	{
		system("cls");
		system("title 2.解密");
		string s;
		unHideCursor();
		cout<<endl<<endl<<"  请输入解密的内容: ";
	    getline(cin, s);
		system("cls");
		for(int i=0;i<s.size();i++)
		{
			s[i] -= 1;
		}
		jiantie(s); 
		HideCursor();
		cout << endl << endl << endl << "      解密完毕，已复制到剪贴板"<<endl;
		Sleep(1000);
		system("cls");
	}
	if (a == '3')
    {
    	system("cls");
    	
	}
    if (a == '4')
    {
    	system("cls");
    	cout << endl << endl << endl << endl << "          " << "本软件将在3秒之后退出" << endl;
    	Sleep(1000);
    	system("cls");
    	cout << endl << endl << endl << endl << "          " << "本软件将在2秒之后退出" << endl;
    	Sleep(1000);
    	system("cls");
    	cout << endl << endl << endl << endl << "          " << "本软件将在1秒之后退出" << endl;
    	Sleep(1000);
		TerminateApp();
	}
//	if (a == '4')
//    {
//    	if(level = 1)
//    	{
//    		while(1)
//			{
//    		system("title 4.更多");
//			rgb(255,255,255,0,0,0);
//			cout << endl << "          加密软件（";
//			rgb(0,204,255,0,0,0);
//			cout << "404NotFound";
//			rgb(255,255,255,0,0,0);
//			cout << "制作）" << endl << endl;
//			cout << "                 1.关于" << endl << endl;
//			cout << "                2.加入我们" << endl << endl;
//			cout << "                 3.作者" << endl << endl;
//			cout << "                 4.退出" << endl << endl;
//			int four = getch();
//			system("cls");
//			if(four = 1)
//			{
//				system("cls");
//				system("title 4.更多");
//				rgb(255,255,255,0,0,0);
//				cout << endl << "          关于" endl << endl;
//				cout << "             版本号：" << endl << endl;
//				cout << "                2.加入我们" << endl << endl;
//				cout << "                 3.作者" << endl << endl;
//				cout << "                 4.退出" << endl << endl;
//			}
//			}
//			
//		}
//	}
	}
	return 0;
}
