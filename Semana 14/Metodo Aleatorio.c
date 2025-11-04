#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double f(double x, double y) {
  return y-x-(2*pow(x,2))-(2*x*y)-pow(y,2);
}
int main () {
  double x,y,fn;
  double xmax=0, ymax=0;
  double fmax=-1e9;
  int N=10000;
  srand(1);

  for(int i=0;i<N;i++) {
    double r1=(double)rand()/RAND_MAX;
    double r2=(double)rand()/RAND_MAX;

    x=-2+4*r1;
    y=1+2*r2;

    fn=f(x,y);

    if(fn>fmax) {
      fmax=fn;
      xmax=x;
      ymax=y;
    }

  }
printf("Maximo encontrado:\n");
printf("x=%.6f\n", xmax);
printf("y=%.6f\n", ymax);
printf("f(x,y)=%.6f\n", fmax);
return 0;
}