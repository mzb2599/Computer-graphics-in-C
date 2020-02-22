#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int Round(float p)
{
    return (int)(p+0.5);
}
void MyDDA(int x1,int y1,int x2,int y2,int color)
{
    int dx = x2 - x1,i,dy = y2 - y1;
    int steps;
    float x = x1, y = y1, xinc, yinc;
    if(abs(dx)>abs(dy))
    {
	steps = abs(dx);
    }
    else
    {
	steps = abs(dy);
    }
    xinc = dx / (float)steps;
    yinc = dy / (float)steps;
    putpixel(x, y, RED);
    for (i = 0; i < steps; i++)
    {
	putpixel(Round(x),Round(y), color);
	x += xinc;
	y += yinc;
    }
}
void main()
{   int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    MyDDA(150,100,130,170,RED);
    MyDDA(150,100,170,170,GREEN);
    MyDDA(130,170,50,170,RED);
    MyDDA(50,170,140,200,RED);
    MyDDA(140,200,120,270,RED);
    MyDDA(120,270,170,200,RED);
    MyDDA(170,200,205,270,GREEN);
    MyDDA(205,270,207,200,GREEN);
    MyDDA(207,200,280,180,GREEN);
    MyDDA(280,180,170,170,GREEN);
    getch();
}