#include <stdio.h>

double interpCuadraticaDirecta(double x,double x0,double x1,double x2,
                               double f0,double f1,double f2){
    double diff1=(f1-f0)/(x1-x0);
    double diff2=(f2-f1)/(x2-x1);
    double term0=f0;
    double term1=diff1*(x-x0);
    double term2=((diff2-diff1)/(x2-x0))*(x-x0)*(x-x1);
    return term0+term1+term2;
}

int main(){
    double x0=1,f0=0;
    double x1=4,f1=1.386294;
    double x2=6,f2=1.791752;
    double x=2;

    double resultado=interpCuadraticaDirecta(x,x0,x1,x2,f0,f1,f2);
    printf("F(%.2f) por interpolacion cuadratica = %.7f\n",x,resultado);
    return 0;
}
