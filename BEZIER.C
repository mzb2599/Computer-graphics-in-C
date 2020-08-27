#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
int x[4],y[4],i;
double put_x,put_y,t;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");
printf("Bezier curve:");
printf("Eter x and y co-ordinates");
for(i=0;i<4;i++)
{
scanf("%d%d",&x[i],&y[i]);
putpixel(x[i],y[i],3);
}
for(t=0.0;t<=1.0;t=t+0.001)
{
put_x=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*t*t*pow(1-t,1)*x[2]+pow(t,3)*x[3];
put_y=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*t*t*pow(1-t,1)*y[2]+pow(t,3)*y[3];
putpixel(put_x,put_y,WHITE);
}
getch();
closegraph();
}