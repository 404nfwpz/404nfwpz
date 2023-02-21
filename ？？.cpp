#include <iostream> 
#include <windows.h>
#include <string>
#include <conio.h>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;

void rgb_init() {																// ��ʼ��
	HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);		//������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//������
	DWORD dwInMode, dwOutMode;
	GetConsoleMode(hIn, &dwInMode);						//��ȡ����̨����ģʽ
	GetConsoleMode(hOut, &dwOutMode);					//��ȡ����̨���ģʽ
	dwInMode |= 0x0200;									//����
	dwOutMode |= 0x0004;
	SetConsoleMode(hIn, dwInMode);						//���ÿ���̨����ģʽ
	SetConsoleMode(hOut, dwOutMode);					//���ÿ���̨���ģʽ
}

void rgb(int wr,int wg,int wb,int br,int bg,int bb) {						//����RGB
	printf("\033[38;2;%d;%d;%dm\033[48;2;%d;%d;%dm",wr,wg,wb,br,bg,bb);	//\033[38��ʾǰ����\033[48��ʾ����������%d��ʾ��ϵ���
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
//	LONG Style;	//���ڷ��
//	Style = GetWindowLong(hwnd, GWL_STYLE);	 // �õ����ڷ��   
//	Style = Style & ~WS_CAPTION;			 //ȥ��������
//	SetWindowLong(hwnd, GWL_STYLE, Style);	 //Ϊ���������µķ��
//	HideCursor();
	system("mode con: cols=43 lines=12");
	HWND hWnd=GetForegroundWindow();
	TopWindow(hwnd);
	copyright();
	while(1)
	{
	system("title 404jia v.1.1");
	cout << endl << "          ���������";
	rgb(r,g,b,0,0,0);
	cout << "404NotFound";
	rgb(255,255,255,0,0,0);
	cout << "������" << endl << endl;
	cout << "                 1.����" << endl << endl;
	cout << "                 2.����" << endl << endl;
	cout << "                 3.����" << endl << endl;
	cout << "                 4.�˳�" << endl << endl;
	char a = getch();
	if (a == '1')
	{
		system("cls");
		system("title 1.����");
		string s;
		unHideCursor();
		cout<<endl<<endl<<"  ��������ܵ�����: ";
		getline(cin, s);
		system("cls");
		for(int i=0;i<s.size();i++)
		{
			s[i] += 1;
		}
		jiantie(s);
		HideCursor();
		cout << endl << endl << endl << "      ������ϣ��Ѹ��Ƶ�������"<<endl;
		Sleep(1000);
		system("cls");
	}
	if (a == '2') 
	{
		system("cls");
		system("title 2.����");
		string s;
		unHideCursor();
		cout<<endl<<endl<<"  ��������ܵ�����: ";
	    getline(cin, s);
		system("cls");
		for(int i=0;i<s.size();i++)
		{
			s[i] -= 1;
		}
		jiantie(s); 
		HideCursor();
		cout << endl << endl << endl << "      ������ϣ��Ѹ��Ƶ�������"<<endl;
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
    	cout << endl << endl << endl << endl << "          " << "���������3��֮���˳�" << endl;
    	Sleep(1000);
    	system("cls");
    	cout << endl << endl << endl << endl << "          " << "���������2��֮���˳�" << endl;
    	Sleep(1000);
    	system("cls");
    	cout << endl << endl << endl << endl << "          " << "���������1��֮���˳�" << endl;
    	Sleep(1000);
		TerminateApp();
	}
//	if (a == '4')
//    {
//    	if(level = 1)
//    	{
//    		while(1)
//			{
//    		system("title 4.����");
//			rgb(255,255,255,0,0,0);
//			cout << endl << "          ���������";
//			rgb(0,204,255,0,0,0);
//			cout << "404NotFound";
//			rgb(255,255,255,0,0,0);
//			cout << "������" << endl << endl;
//			cout << "                 1.����" << endl << endl;
//			cout << "                2.��������" << endl << endl;
//			cout << "                 3.����" << endl << endl;
//			cout << "                 4.�˳�" << endl << endl;
//			int four = getch();
//			system("cls");
//			if(four = 1)
//			{
//				system("cls");
//				system("title 4.����");
//				rgb(255,255,255,0,0,0);
//				cout << endl << "          ����" endl << endl;
//				cout << "             �汾�ţ�" << endl << endl;
//				cout << "                2.��������" << endl << endl;
//				cout << "                 3.����" << endl << endl;
//				cout << "                 4.�˳�" << endl << endl;
//			}
//			}
//			
//		}
//	}
	}
	return 0;
}
