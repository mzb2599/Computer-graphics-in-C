#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include "DDA.c"
#include "Bresencircle.c"
void viral(int x,int y,int xc,int yc,int color)
{
putpixel(x+xc,y+yc,color);
putpixel(x+xc,yc-y,color);
putpixel(xc-x,y+yc,color);
putpixel(xc-x,yc-y,color);
putpixel(y+xc,x+yc,color);
putpixel(y+xc,yc-x,color);
putpixel(xc-y,x+yc,color);
putpixel(xc-y,yc-x,color);
}
void midpoint(int xc,int yc,int radius,int color)
{
int x=0,y=radius,p=1-radius;
viral(x,y,xc,yc,color);
while(x<y)
{
x++;
if(p<0)
p=p+2*x+1;
else
{
y--;
p=p+2*(x-y)+1;
}
viral(x,y,xc,yc,color);
}
}
void main()
{
int gd=DETECT;
int gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
clrscr();
midpoint(200,200,100,RED);
Brescircle(200,170,10);
MyDDA(210,180,210,250,RED);
getch();
}