#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int delta_a=y1-y0;
  int delta_b=-(x1-x0);
  double slope;
  if (delta_b==0)
    slope=2;
  else
    slope=(delta_a*-1.0)/(delta_b*-1.0);
  printf("slope: %d\n",slope);
  if (slope>=0 && slope<=1){
    int delta=2*delta_a+delta_b;
    while(x0<=x1){
      plot(s,c,x0,y0);
      if (delta>0){
	y0+=1;
	delta+=2*delta_b;
      }
      x0+=1;
      delta+=2*delta_a;
    }
  }
  if (slope>1){
    int delta=delta_a+2*delta_b;
    while(y0<=y1){
      plot(s,c,x0,y0);
      if (delta>0){
	x0+=1;
	delta+=2*delta_a;
      }
      y0+=1;
      delta+=2*delta_b;
    }
  }
  if (slope<0 && slope>= -1){
    int delta=2*delta_a+delta_b;
    while(x0<=x1){
      plot(s,c,x0,y0);
      if (delta>0){
	y0-=1;
	delta+=2*delta_b;
      }
      x0+=1;
      delta+=2*delta_a;
    }
  }
}

