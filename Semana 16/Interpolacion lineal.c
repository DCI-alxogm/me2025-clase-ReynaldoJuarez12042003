#include <stdio.h>

double interpolacionLineal(double x, double x0, double x1, double fx0, double fx1) {
    return fx0+((fx1-fx0)/(x1- x0))*(x-x0);
}

int main() {
    double x0=1,fx0=0;
    double x1=4,fx1=1.386294;
    double x=2;

    double resultado = interpolacionLineal(x,x0,x1,fx0,fx1);

    printf("F(%.2f) por interpolacion lineal = %.6f\n", x, resultado);
    return 0;
}
