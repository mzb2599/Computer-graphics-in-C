#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void display(int xs1, int xy1, int x, int y);
void ellipse(int xs1,int ys1,int rx,int ry)
{
    int x, y;
    float d1, d2, dx, dy;
    x = 0;
    y = ry;
    d1 = pow(ry, 2) - (pow(rx, 2) * ry) + (0.25 * pow(rx, 2));
    dx = 2 * pow(ry, 2) * x;
    dy = 2 * pow(rx, 2) * y;
    do
    {

    }while (dx<dy);
    

}