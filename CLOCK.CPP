#include <stdio.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#include <time.h>
#include <process.h>
#include <stdlib.h>

#define PI 3.14


void layout(int mx,int my){
  setcolor(YELLOW);
  int ra=145;
  int rb=167;
  for(float i=0;i<3;i++){
  	circle(mx/2,my/2,180+i);
  }
    int k=1;

  for(double j=(PI/6)-PI/2;j<=(2*PI)-PI/2;j=j+(PI/6)){
    int xa=(mx/2) +ra*cos(j);
    int ya=(my/2)+ ra*sin(j);
    pieslice(xa,ya,0,360,2);
    

    int xb=(mx/2)+rb*cos(j);
    int yb=(my/2)+rb*sin(j);
    char* str;
    itoa(k,str,10);
    setcolor(LIGHTBLUE);
    outtextxy(xb,yb,str);
    setcolor(YELLOW);
    
    k++;

  }

}


void hour(int mx,int my,int hr,int min){
  hr=(hr>12)? hr-12:hr;
  int r=100;

  float theta=hr*(PI/6)-(PI/2)+(min/12)*(PI/30);
  line(mx/2,my/2,mx/2+r*cos(theta),my/2+r*sin(theta));

}


void minute(int mx, int my,int min){
  int r=120;
  float theta=min*(PI/30)-(PI/2);
  setcolor(WHITE);
  line(mx/2,my/2,mx/2+r*cos(theta),my/2+r*sin(theta));
}



void second(int mx, int my,int sec){
  int r=160;
  float theta=sec*(PI/30)-(PI/2);
  setcolor(RED);
  line(mx/2,my/2,mx/2+r*cos(theta),my/2+r*sin(theta));
}


void main(){

  int gdriver=DETECT,gmode,error,hr=0,min=0,sec=0;
  clrscr();
  initgraph(&gdriver,&gmode," ");
  struct time t;
  int maxx=getmaxx();
  int maxy=getmaxy();
     


  while(1) {

    gettime(&t);
    hr=t.ti_hour;
    min=t.ti_min;
    sec=t.ti_sec;
    layout(maxx,maxy);
    hour(maxx,maxy,hr,min);
    minute(maxx,maxy,min);
    second(maxx,maxy,sec);
    sleep(1);
    cleardevice();

  }



  getch();

}