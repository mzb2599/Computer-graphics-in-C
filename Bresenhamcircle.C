#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
int sign(int p)
{
  if(p > 0)
    return 1;
  if(p < 0)
    return -1;
  if(p == 0)
    return 0;
  return 2;
}
void Bresenham(int x1, int y1, int x2, int y2)
{
  int x, y,p, xend, yend, dx = abs(x2-x1), dy = abs(y2-y1), xinc, yinc;
  if(dx > dy)
  {
  x = x1;
  y = y1;
  xend = x2;
  yend = y2;
  xinc = sign(x2-x1);
  yinc = sign(y2-y1);
  p = 2*dy - dx;
  putpixel(x, y, WHITE);
  while(x  < xend)
  {
    x += xinc;
    if(p < 0)
      p = p + 2*dy;
    else
    {
      y += yinc;
      p = p + 2*(dy - dx);
    }
    putpixel(x, y, WHITE);
  }
  }
  else
  {
    x = x1;
  y = y1;
  xend = x2;
  yend = y2;
  xinc = sign(x2-x1);
  yinc = sign(y2-y1);
  p = 2*dx - dy;
  putpixel(x, y, WHITE);
  while(y  < yend)
  {
    y += yinc;
    if(p < 0)
      p = p + 2*dx;
    else
    {
      x += xinc;
      p = p + 2*(dx - dy);
    }
    putpixel(x, y, WHITE);
  }
  }
}
void main()
{
  int gd = DETECT, gm,i;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
  //Central flag
  Bresenham(100, 100, 50, 175);
  Bresenham(100, 100, 150, 175);
  //Boat
  Bresenham(150,175,400,175);
  Bresenham(400,175,350,250);
  Bresenham(0,175,70,250);
  Bresenham(0,175,50,175);
  //Flag
  Bresenham(70,250,350,250);
  Bresenham(250,80,250,175);
  Bresenham(250,80,290,85);
  Bresenham(290,85,295,115);
  Bresenham(250,110,295,115);
  getch();
}
