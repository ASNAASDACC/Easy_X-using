#include<iostream>
#include<stdio.h>
#include<easyx.h>
#include<time.h>
#include<windows.h>
using namespace std;
#define DesktopLength 500//540
#define Desktopwidth 700//430
#define DifferenceValue (DesktopLength-20)/20
int arry[12][20] = { 0 };

void  background() {
	initgraph(Desktopwidth,  DesktopLength, EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(BLACK);
	fillrectangle(10, 10, Desktopwidth-10, DesktopLength-10);
	setfillcolor(WHITE);
	fillrectangle(20, 20, Desktopwidth-20, DesktopLength-20);//游戏桌面300*500，一共12列 20行，一列行25象素
	//设置细线
	setlinecolor(BLACK);
	int i = 1;
	for (; i <= 20; i++) {
		line(20+i* DifferenceValue, 20, 20+i* DifferenceValue, 520);
	}
	for (i = 1; i <= 20; i++) {
		line(20, 20 + i * DifferenceValue, 500, 20 + i * DifferenceValue);
	}
}
int x = 10, y = 10;
void photospit() {//length:500  width:700
	IMAGE wuyukang;
	loadimage(&wuyukang, "C:\\Users\\小广子\\Downloads\\加菲猫.jpeg",150,150);
		putimage(x, y, &wuyukang);
		if (x < 530 && y == 10)
			x += 5;
		if (x == 530 && y < 340)
			y += 5;
		if (y == 340 && x > 10)
			x -= 5;
		/*if (x == 10 && y > 10);
		y += 5;*/
		int FPS = 1000 / 60;
		int starttime = 0;
		starttime = clock();
		int freamtime = clock() - starttime;
		if (FPS - freamtime > 0)
			Sleep(FPS - freamtime);
		setbkcolor(RGB(27, 23, 776));
		clearrectangle(0, 0, 700, 500);	
		setbkcolor(RGB(27, 230, 76));
		clearrectangle(180, 200, 520, 300);
		settextcolor(BLACK);
		settextstyle(30, 0, "");
		setbkmode(TRANSPARENT);
		outtextxy(180, 200, "点一下试一下？");
		ExMessage msg;
			if (peekmessage(&msg, EX_MOUSE))
			{
				switch (msg.message) {
				case WM_LBUTTONDOWN:
				{
					if (180 < msg.x < 520 && 200 < msg.y < 300)
						cout << "我是加菲猫，你是？" << endl;
				}
				}
			}
}