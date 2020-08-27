#include <stdio.h>
#include <conio.h>
#include <graphics.h>
int xmin,ymin,xmax,ymax;
void liangBarskyLCA(int x1, int y1, int x2, int y2);
void main()
{
    int graphDriver = DETECT, graphMode;
    initgraph(&graphDriver, &graphMode, "C:\\TURBOC3\\BGI");

    xmin = 100;
    ymin = 100;
    xmax = 400;
    ymax = 400;
    //setbkcolor(WHITE);
    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(LIGHTGRAY);
    line(200, 250, 500, 250); //original line
    setcolor(GREEN);
    liangBarskyLCA(200, 250, 500, 250); // clipped line
    getch();
}
void liangBarskyLCA(int x1, int y1, int x2, int y2)
{
    int i;
    int dx, dy;
    int tx1, ty1, tx2, ty2;
    float tmin, tmax, p[4], q[4], t;

    dx = x2 - x1;
    dy = y2 - y1;
    p[0] = -dx;
    p[1] = dx;
    p[2] = -dy;
    p[3] = dy;
    q[0] = x1 - xmin;
    q[1] = xmax - x1;
    q[2] = y1 - ymin;
    q[3] = ymax - y1;
    for (i = 0; i < 4; i++)
	if (p[i] == 0)
	{
	    printf("Line is parallel\n.");
	    if (q[i] >= 0)
	    {
		if(i < 2)
		{
		    if(y1 < ymin)
			y1 = ymin;
		    if(y2 > ymax)
			y2 = ymax;
		    line(x1, y1, x2, y2);
		}
		if(i > 1)
		{
		    if (x1 < xmin)
			x1 = xmin;
		    if (x2 > xmax)
			x2 = xmax;
		    line(x1, y1, x2, y2);
		}
	    }
	}
    tmin = 0;
    tmax = 1;
    for (i = 0; i < 4; i++)
    {
	t = q[i] / p[i];
	if (p[i] < 0 && tmin <= t)
	    tmin = t;
	else if(tmax > t)
	    tmax = t;
    }
    if (tmin < tmax)
    {
	tx1 = x1 + tmin * p[1];
	tx2 = x1 + tmax * p[1];
	ty1 = y1 + tmin * p[3];
	ty2 = y1 + tmax * p[3];
	setcolor(GREEN);
	line(tx1, ty1, tx2, ty2);
    }
}
