#include <stdio.h> 
#include <stdlib.h> 
#include "utils.h"
 
//Defina e implemente TrocaInterios 
 
int main(){ 
 int n1, n2; 
 int *p1 = &n1, *p2 = &n2;

 while ( scanf("%d %d", &n1, &n2) == 2 ){ 
  if ( TrocaInterios(p1,p2) ){ 
   printf("TROCADO: %d %d\n", n1, n2); 
  } else { 
   printf("ORIGINAL: %d %d\n", n1, n2); 
  } 
 } 
  
    return 0;     
} 