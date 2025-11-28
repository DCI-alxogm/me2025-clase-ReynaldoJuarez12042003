#include <stdio.h>

double interpCubica(double x,double x0,double x1,double x2,double x3,
                    double f0,double f1,double f2,double f3){

    double f01=(f1-f0)/(x1-x0);
    double f12=(f2-f1)/(x2-x1);
    double f23=(f3-f2)/(x3-x2);

    double f012=(f12-f01)/(x2-x0);
    double f123=(f23-f12)/(x3-x1);

    double f0123=(f123-f012)/(x3-x0);

    double term0=f0;
    double term1=f01*(x-x0);
    double term2=f012*(x-x0)*(x-x1);
    double term3=f0123*(x-x0)*(x-x1)*(x-x2);

    return term0+term1+term2+term3;
}

int main(){
    double x0=1,f0=0;
    double x1=4,f1=1.386294;
    double x2=5,f2=1.609438;
    double x3=6,f3=1.791752;

    double x=2;

    double r=interpCubica(x,x0,x1,x2,x3,f0,f1,f2,f3);

    printf("F(%.2f) por interpolacion cubica = %.7f\n",x,r);
    return 0;
}
