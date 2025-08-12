// Ejercicio en clase 8 de agosto, Reynaldo JUarez Aranda
/* Hacer un programa que use arreglos y que imprima
5 numeros flotantes y el valor de las funciones*/

 #include <stdio.h>
 #include <math.h>

 int main () {

 float arreglo[5];
 arreglo[0]=4;
arreglo[1]=3;
arreglo[2]=2;
arreglo[3]=9;
arreglo[4]=7;
float funcion1 [5];
float funcion2[5];
float funcion3[5];



for(int i=0; i<5; i=i+1){
  funcion1[i]=arreglo[i]*arreglo[i];
  funcion2[i]=log((arreglo[i]+1));
  funcion3[i]=exp(arreglo[i])+cos(arreglo[i]);
}
printf("\n");
printf("F1 x^2:\n");
for(int i=0; i<5; i=i+1) {
  printf("%f\t", funcion1[i]);
}
//En esta parte el log es natural
printf("\n");
printf("F2 log(x+1):\n");
for(int i=0; i<5; i=i+1) {
  printf("%f\t", funcion2[i]);
}

//El calculo del cos(x) lo hace en radianes C.
printf("\n");
printf("F3 exp(x)+cos(x):\n");
for(int i=0; i<5; i=i+1) {
  printf("%f\t", funcion3[i]);
}
return 0;


 }