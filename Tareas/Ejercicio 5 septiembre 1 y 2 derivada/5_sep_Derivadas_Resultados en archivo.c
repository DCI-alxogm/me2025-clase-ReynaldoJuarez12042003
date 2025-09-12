/*Reynaldo Hassan Juarez Aranda
05/09/2025*/

#include <stdio.h>
#include <math.h>
float fx(float x);

int main() {
  int i;
  float a=-2, b=2, h=0.25;
  int n=(int)((b-a)/h)+1;
  float x[n], fpa[n], fpb[n], fpc[n];//Primera derivada
  float fpa2[n], fpb2[n], fpc2[n]; //Segunda derivada 
  //Abrir archivo tipo txt 
  FILE*archivo=fopen("Primera y Segunda der.csv", "w");
  if(archivo==NULL){
    printf("Error al abrir el archivo.\n");
    return 1;
  }

  for(i=0;i<n;i++){
    x[i]=a+i*h;
    
  }

  //Primera derivada 
  printf("Aproximaciones primera derivada (x, adelante, atras, centrada):\n");
  fprintf(archivo, "Primera derivada\n");
  fprintf(archivo,"x,f'(adelante),f'(atras),f'(centrada)\n"); 
  for(i=0;i<n;i++){
    fpa[i]=(fx(x[i+1])-fx(x[i]))/h;
    fpb[i]=(fx(x[i])-fx(x[i-1]))/h;
    fpc[i]=(fx(x[i+1])-fx(x[i-1]))/(2*h);
     printf("%f\t %f\t %f\t %f\n", x[i],fpa[i], fpb[i], fpc[i]);
     fprintf(archivo, "%f,%f,%f,%f\n", x[i], fpa[i], fpb[i], fpc[i]); 
    }

    //Segunda derivada
    printf("Aproximaciones segunda derivada (x, adelante, atras, centrada):\n");
    fprintf(archivo, "\nSegunda derivada\n");
    fprintf(archivo, "x,f''(adelante),f''(atras),f''(centrada)\n");
    for(i=0;i<n;i++){
    fpa2[i]=(fx(x[i+2])-2*fx(x[i+1])+fx(x[i]))/(h*h);
    fpb2[i]=(fx(x[i-2])-2*fx(x[i-1])+fx(x[i]))/(h*h);
    fpc2[i]=(fx(x[i+1])-2*fx(x[i])+fx(x[i-1]))/(h*h);
    printf("%f\t %f\t %f\t %f\n", x[i],fpa2[i], fpb2[i], fpc2[i]);
    fprintf(archivo, "%f,%f,%f,%f\n", x[i], fpa2[i], fpb2[i], fpc2[i]);
    }
    fclose(archivo);
    printf("Resultados guardados en 'Primera y Segunda der.csv'\n ");
    return 0;
    }

float fx(float x) {
  float f;
  f=(x*x*x)-(2*x)-4;
  return f;
}

