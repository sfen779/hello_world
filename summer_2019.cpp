#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
struct Balls {
	int radius, x, y;
}ball_0 = { 25, 100, 150 };
Balls ball_1 = { 25,455,455 };
struct Squre
{
	int top, left, right, bottom;
}squre_0 = {0,0,1200,800};
Squre squre_1 = { 250,250,810,560 };
struct Speed {
	int x;
	int y;
}speed_0 = { 5,5 };
Speed speed_1 = { 5,5 };

struct Colors {
	int R,G,B;
}color_0 = { 250 ,50 ,50 };
Colors color_1 = { 50,250,50 };
void drawBall(Balls ball, Colors color) {
	setfillcolor(RGB(color.R, color.G, color.B));
	setlinecolor(RGB(color.R, color.G, color.B));
	fillcircle(ball.x, ball.y, ball.radius);
}

void drawRectangle(Squre squre, Colors color) {
	setfillcolor(RGB(color.R, color.G, color.B));
	setlinecolor(RGB(color.R, color.G, color.B));
	fillrectangle(squre.top, squre.left, squre.right,squre.bottom);
}

void changeDirection_0(Balls ball, Speed* speed_0,Squre squre) {
	if (ball.x + ball.radius >= squre.right || ball.x - ball.radius <= squre.left) {
		speed_0->x = -speed_0->x;
	}
	if (ball.y + ball.radius >= squre.bottom || ball.y - ball.radius <= squre.top) {
		speed_0->y = -speed_0->y;
	}
}
void changeDirection_1(Balls ball, Speed* speed_1, Squre squre) {
	if (ball.x + ball.radius >= squre.right || ball.x - ball.radius <= squre.left) {
		speed_1->x = -speed_1->x;
	}
	if (ball.y + ball.radius >= squre.bottom || ball.y - ball.radius <= squre.top) {
		speed_1->y = -speed_1->y;
	}
}
void changeDirection_polar(Balls ball, Speed* speed, Squre squre) {
	int x, y;
	for (int i = 0; i < 360; i++)
	{
		x = ball.x + sin(i * 3.1415926 / 180) * ball.radius;
		y = ball.y + cos(i * 3.1415926 / 180) * ball.radius;
		if (x >= squre.left && x <= squre.right) {
			int Top = abs(y - squre.top);
			int Bottom = abs(y - squre.bottom);
			if (Top <= 5 || Bottom <= 5) {
				speed->y = -speed->y;
			}
		}
		if (y >= squre.top && y <= squre.bottom) {
			int Left = abs(x - squre.left);
			int Right = abs(x - squre.right);
			if (Left<=5||Right<=5)
			{
				speed->x = -speed->y;
			}
		}
	}
}

int main(void)
{
	initgraph(1200, 800);
	while (1)
	{
		BeginBatchDraw();
		drawRectangle(squre_1, color_1);
		changeDirection_polar(ball_0, &speed_0, squre_1);
		changeDirection_0(ball_0, &speed_0,squre_0);
		changeDirection_1(ball_1, &speed_1, squre_1);
		ball_0.x += speed_0.x;
		ball_0.y += speed_0.y;
		ball_1.x += speed_1.x;
		ball_1.y += speed_1.y;
		drawBall(ball_0, color_0);
		drawBall(ball_1, color_0);
		FlushBatchDraw();
		Sleep(10);
		cleardevice();
	}
	return 0;
}