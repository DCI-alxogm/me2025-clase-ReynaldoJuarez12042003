#include <stdio.h>
#include <math.h>

float f(float x);

int main(){
    float Err_max=0.0001;
    float x1=0.0,x2=1.0,x3=5.0;
    float f1,f2,f3,xmax,fmax,Err;
    int iter=0;

    f1=f(x1);
    f2=f(x2);
    f3=f(x3);

    printf("%4s %12s %12s %12s %12s %12s %12s %12s %12s\n",
           "Iter","x1","x2","x3","f(x1)","f(x2)","f(x3)","xmax","Err");

    do{
        iter++;

        float numerator=(pow(x2,2)-pow(x3,2))*f1+(pow(x3,2)-pow(x1,2))*f2+(pow(x1,2)-pow(x2,2))*f3;
        float denominator=(x2-x3)*f1+(x3-x1)*f2+(x1-x2)*f3;

        if(fabs(denominator)<1e-12) denominator=(denominator<0?-1e-12:1e-12);

        xmax=0.5*numerator/denominator;

        if(xmax<x1) xmax=x1+0.5*(x2-x1);
        if(xmax>x3) xmax=x3-0.5*(x3-x2);

        fmax=f(xmax);

        if(xmax<x2){
            if(fmax>f2){x3=x2; f3=f2; x2=xmax; f2=fmax;}
            else{x1=xmax; f1=fmax;}
        }else{
            if(fmax>f2){x1=x2; f1=f2; x2=xmax; f2=fmax;}
            else{x3=xmax; f3=fmax;}
        }

        Err=fabs(x3-x1);

        printf("%4d %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",
               iter,x1,x2,x3,f1,f2,f3,xmax,Err);

    }while(Err>Err_max);

    printf("\nEl MAXIMO aproximado se encuentra en x=%f\n",xmax);
    printf("Valor maximo f(x)=%f\n",f(xmax));

    return 0;
}

float f(float x){
    return -x*x+4*x+1;
}
