#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x, double y) {
  return y-x-(2*pow(x,2))-(2*x*y)-pow(y,2);
}

int main () {
  double x,y,fn;
  double xmax=0, ymax=0;
  double fmax;
  double paso=0.25;
  double tol=1e-5;
  int N=500;

  x=0;
  y=0;
  fmax=f(x,y);

  for(int i=0;i<N;i++) {
    int improved=0;
    double moves[4][2]= {
      {x+paso,y},
      {x-paso,y},
      {x,y+paso},
      {x,y-paso}
    };
    for(int j=0;j<4;j++){
      double xn=moves[j][0];
      double yn=moves[j][1];
      fn=f(xn,yn);

      if(fn>fmax){
        fmax=fn;
        xmax=xn;
        ymax=yn; 
        improved=1;
      }
    }
    if(improved){
      x=xmax;
      y=ymax;
    }else {
      paso*=0.25;
      if(paso<tol)break;
    }
  }
  printf("Maximo encontrado:\n");
  printf("x=%.6f\n", xmax);
  printf("y=%.6f\n", ymax);
  printf("f(x,y)=%.6f\n", fmax);
  return 0;
}


