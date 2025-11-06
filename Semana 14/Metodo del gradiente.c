#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Funcion
double f(double x,double y){
  return (2*x*y)+(2*x)-(pow(x,2))-(2*pow(y,2));
}
// Parcial respecto a x
double dfx(double x,double y){
  return (2*y)+2-(2*x);
}
// Parcial respecto a y
double dfy(double x,double y){
  return (2*x)-(4*y);
}

int main(){
  double x=-1,y=1;
  double fevaluada,dfxevaluada,dfyevaluada;
  double a,b,c,h_opt,gmax;
  double x0,y0,dx,dy;
  int iter=1;

  printf("=== METODO DEL GRADIENTE ===\n");

  while(1){
    //Calculo de derivadas parciales
    fevaluada=f(x,y);
    dfxevaluada=dfx(x,y);
    dfyevaluada=dfy(x,y);

    printf("\nITERACION %d\n",iter);
    printf("Punto actual: x = %.4f, y = %.4f\n",x,y);
    printf("f(x,y) = %.4f\n",fevaluada);
    printf("Gradiente: (%.4f, %.4f)\n",dfxevaluada,dfyevaluada);

    // Guardamos variables actuales
    x0=x;
    y0=y;
    dx=dfxevaluada;
    dy=dfyevaluada;
    
    //sustituir f(x,y) para formar g(h) a*h^2 + b*h + c
    // Coeficientes de g(h)
    double const1=f(x0,y0);
    double coefh=2*(x0*dy+y0*dx)+2*dx-2*x0*dx-4*y0*dy;
    double coefh2=2*dx*dy-pow(dx,2)-2*pow(dy,2);
    a=coefh2;
    b=coefh;
    c=const1;

    printf("g(h) = %.4f*h^2 + %.4f*h + %.4f\n",a,b,c);
    //Calcular el h que maximiza g(h)
    // h que maximiza g(h)
    h_opt=-b/(2*a);
    printf("h* = %.4f\n",h_opt);

    // Actualizar coordenadas
    //sustituir h* en las ecuaciones para actualizar x y y 
    x=x0+dx*h_opt;
    y=y0+dy*h_opt;

    printf("Nuevo punto: x = %.4f, y = %.4f\n",x,y);

    // Condición de parada
    if(fabs(dfxevaluada)<1e-4 && fabs(dfyevaluada)<1e-4) break;
    if(fabs(x-x0)<1e-4 && fabs(y-y0)<1e-4) break;
    if(iter>10) break; // límite de seguridad

    iter++;
  }

  printf("\n=== RESULTADO FINAL ===\n");
  printf("x = %.4f, y = %.4f\n",x,y);
  printf("f(x,y) = %.4f\n",f(x,y));
  return 0;
}
