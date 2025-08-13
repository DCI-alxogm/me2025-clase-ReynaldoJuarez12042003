//Jerarquia de operaciones, 13 de agosto de 2025
//Reynaldo Hassan Juarez Aranda

#include <stdio.h>
#include <math.h>

int main () {
  float a=3, b=4, c=5, d=7;
  float e;

  printf("e=(a+b)*c/d=%f\n", (a+b)*c/d);
  printf("e=((a+b)*c)/d=%f\n", ((a+b)*c)/d);
  printf("e=a+b*c/d=%f\n", a+b*c/d);
  printf("e=a+(b*c)/d=%f\n", a+(b*c)/d);
}