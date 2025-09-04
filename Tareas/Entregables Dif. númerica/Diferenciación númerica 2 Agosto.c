/*Reynaldo Hassan Juarez Aranda 
Diferenciacion numerica 02/sep/2025*/


#include <stdio.h>
#include <math.h>

int main () {
  float ximas=1, xi=0.5, ximenos=0, fximas=0.2, fxi=0.925, fximenos=1.2, error=-0.9125;
  float primeraadelante, primeraatras, primeracentrada, Eprimeraadelante, Eprimeraatras, Eprimeracentrada;

  /*Primera derivada hacia adelante*/
  primeraadelante=(fximas-fxi)/(ximas-xi);
  /*Primera derivada hacia atras*/
  primeraatras=(fxi-fximenos)/(xi-ximenos);
  /*Primera derivada centrada*/
  primeracentrada=(fximas-fximenos)/(ximas-ximenos);
  /*Error hacia adelante*/
  Eprimeraadelante=((error-primeraadelante)/(error))*100;
  /*Error hacia atras*/
  Eprimeraatras=((error-primeraatras)/(error))*100;
  /*Error centrado*/
  Eprimeracentrada=((error-primeracentrada)/(error))*100;

   printf("%-12s %-12s %-12s %-12s %-12s %-12s\n", "Adelante", "Atras", "Centrada", "Eadelante(%)", "Eatras(%)", "Ecentrado(%)");
   printf("----------------------------------------------------------------------------------------\n");
   printf("%12.2f" "%12.2f" "%12.2f" "%12.2f" "%12.2f" "%12.2f\n", primeraadelante, primeraatras, primeracentrada, Eprimeraadelante, 
   Eprimeraatras, Eprimeracentrada);
   return 0;


}