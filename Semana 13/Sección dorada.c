#include <stdio.h>
#include <math.h>

float f(float x);

int main(){
    float Err_max=0.0001;
    float l=0,u=5,x1,x2,f1,f2,Err;
    float d=(sqrt(5)-1)/2; // Número áureo usando (√5-1)/2
    int iter=0;

    // Inicializamos los puntos internos según la proporción dorada
    x1=u-(u-l)*d;
    x2=l+(u-l)*d;
    f1=f(x1);
    f2=f(x2);

    printf("%4s %12s %12s %12s %12s %12s %12s %12s\n","Iter","l","u","x1","x2","f(x1)","f(x2)","Err");

    do{
        iter++;
        if(f1>f2){ // Máximo en [l, x2]
            u=x2;
            x2=x1;
            f2=f1;
            x1=u-(u-l)*d;
            f1=f(x1);
        }else{ // Máximo en [x1, u]
            l=x1;
            x1=x2;
            f1=f2;
            x2=l+(u-l)*d;
            f2=f(x2);
        }

        Err=fabs(u-l); // Error aproximado como ancho del intervalo

        printf("%4d %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f %12.6f\n",
               iter,l,u,x1,x2,f1,f2,Err);

    }while(Err>Err_max);

    float xmax=(l+u)/2;
    printf("\nEl MAXIMO aproximado se encuentra en x=%f\n",xmax);
    printf("Valor maximo f(x)=%f\n",f(xmax));

    return 0;
}

float f(float x){
    return -x*x+4*x+1;
}
